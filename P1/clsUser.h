#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include "clsUtil.h"

using namespace std;

class clsUser:public clsPerson
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 3 };

	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permission;

	bool _MarkForDelete = false;

	struct stLoginRegisterRecord;
	static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
	{
		stLoginRegisterRecord LoginRegisterRecord;


		vector <string> LoginRegisterDataLine = clsString::Split(Line, Seperator);
		LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
		LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
		LoginRegisterRecord.Password = clsUtil::DecryptText(LoginRegisterDataLine[2]);
		LoginRegisterRecord.Permission = stoi(LoginRegisterDataLine[3]);

		return LoginRegisterRecord;

	}

	string _PrepareLogInRecord(string Seperator = "#//#")
	{
		string LoginRecord = "";
		LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
		LoginRecord += UserName + Seperator;
		LoginRecord += clsUtil::EncryptText(Password) + Seperator;
		LoginRecord += to_string(Permissions);
		return LoginRecord;
	}

	static vector<clsUser> _LoadUserDataFromFile()
	{
		vector<clsUser> vUser;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				clsUser User = _ConvarteLineToUserOpject(line);
				vUser.push_back(User);
			}
			MyFile.close();
		}
		return vUser;
	}

	static clsUser _ConvarteLineToUserOpject(string Line, string Seperator = "#//#")
	{
		vector<string> vUser = clsString::Split(Line, Seperator);

		return clsUser(enMode::UpdateMode, vUser[0], vUser[1], vUser[2], vUser[3], vUser[4], clsUtil::DecryptText(vUser[5]), stoi(vUser[6]));
	}
	static string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#")
	{
		string stUserRecord = "";

		stUserRecord += User.FirstName + Seperator;
		stUserRecord += User.LastName + Seperator;
		stUserRecord += User.Email + Seperator;
		stUserRecord += User.Phone + Seperator;
		stUserRecord += User._UserName + Seperator;
		stUserRecord += clsUtil::EncryptText(User._Password) + Seperator;
		stUserRecord += to_string(User._Permission);
		return stUserRecord;
	}


	static void _SaveDateUserDataToFile(vector<clsUser> vUser)
	{
		fstream MyFile;

		MyFile.open("Users.txt", ios::out);

		if (MyFile.is_open())
		{
			string DataLine;

			for (clsUser U : vUser)
			{
				if (U._MarkForDelete == false)
				{
					DataLine = _ConvertUserObjectToLine(U);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}

	}

	void _Update()
	{
		vector<clsUser> vUser = _LoadUserDataFromFile();

		for (clsUser& U : vUser)
		{
			U = *this;
			break;
		}
		
		_SaveDateUserDataToFile(vUser);
	}

	void _AddDateLineToFile(string stDataLine)
	{
		fstream MyFile;

		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}
	void _AddNew()
	{
		_AddDateLineToFile(_ConvertUserObjectToLine(*this));
	}


	static clsUser _GetEmptyUserOpject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
public:

	enum enPermissions
	{
		eAll = -1, pListClient = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClient = 8,
		pFindClient = 16, pTransactions = 32, pManageUser = 64, pLoginRegister = 128
	};

	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, int Permission) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permission = Permission;
	}

	struct stLoginRegisterRecord
	{
		string DateTime;
		string UserName;
		string Password;
		int Permission;
	};


	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}
	bool MarkForDelete()
	{
		return _MarkForDelete;
	}

	void setUserName(string UserName)
	{
		_UserName = UserName;
	}
	string GetUserName()
	{
		return _UserName;
	}
	__declspec(property(get = GetUserName, put = setUserName))string UserName;

	void setPassword(string Password)
	{
		_Password = Password;
	}
	string GetPassword()
	{
		return _Password;
	}
	__declspec(property(get = GetPassword, put = setPassword))string Password;

	void setPermission(int Permission)
	{
		_Permission = Permission;
	}
	int GetPermission()
	{
		return _Permission;
	}
	__declspec(property(get = GetPermission, put = setPermission))int Permissions;

	static clsUser Find(string UserName)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				clsUser User = _ConvarteLineToUserOpject(line);
				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;
				}
			}
			MyFile.close();
		}
		return _GetEmptyUserOpject();
	}
	static clsUser Find(string UserName,string Password)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				clsUser User = _ConvarteLineToUserOpject(line);
				if (User.UserName == UserName && User.Password == Password)
				{
					MyFile.close();
					return User;
				}
			}
			MyFile.close();
		}
		return _GetEmptyUserOpject();
	}

	static bool IsUserExist(string UserName)
	{
		clsUser User = clsUser::Find(UserName);
		return (!User.IsEmpty());
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };
	enSaveResults Save()
	{

		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsEmpty())
			{
				return enSaveResults::svFaildEmptyObject;
			}
		}

		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;

			break;
		}

		case enMode::AddNewMode:
		{
			if (clsUser::IsUserExist(_UserName))
			{
				return enSaveResults::svFaildUserExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}

			break;
		}
		}

	}
	bool Delete()
	{
		vector<clsUser> vUser;
		vUser = _LoadUserDataFromFile();

		for (clsUser& U : vUser)
		{
			if (U.UserName == _UserName)
			{
				U._MarkForDelete = true;
				break;
			}
		}

		_SaveDateUserDataToFile(vUser);

		*this = _GetEmptyUserOpject();
		return true;

	}
	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	static vector <clsUser> GetUsersList()
	{
		return _LoadUserDataFromFile();
	}

	bool CheckAccessPermission(enPermissions Permission)
	{
		if (this->Permissions == enPermissions::eAll) 
		{
			return true;
		}

		if ((Permission & this->Permissions) == Permission)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	void RegisterLogin()
	{
		string stDateLine = _PrepareLogInRecord();
		fstream MyFile;

		MyFile.open("LoginRegister.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDateLine << endl;
			MyFile.close();
		}


	}

	 static  vector <stLoginRegisterRecord> GetLoginRegisterList()
     {
         vector <stLoginRegisterRecord> vLoginRegisterRecord;

         fstream MyFile;
         MyFile.open("LoginRegister.txt", ios::in);//read Mode

         if (MyFile.is_open())
         {

             string Line;

             stLoginRegisterRecord LoginRegisterRecord;

             while (getline(MyFile, Line))
             {

                 LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);

                 vLoginRegisterRecord.push_back(LoginRegisterRecord);

             }

             MyFile.close();

         }

         return vLoginRegisterRecord;

     }



};

