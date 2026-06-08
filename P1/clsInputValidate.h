#pragma once

#include <iostream>
#include "clsDate.h"

using namespace std;


class clsInputValidate
{
public:
	static bool IsNumberBetween(short Number, short From, short To)
	{
		return (Number >= From && Number <= To) ? true : false;
	}
	static bool IsNumberBetween(int Number, int From, int To)
	{
		return (Number >= From && Number <= To) ? true : false;
	}
	static bool IsNumberBetween(float Number, float From, float To)
	{
		return (Number >= From && Number <= To) ? true : false;
	}
	static bool IsNumberBetween(double Number, double From, double To)
	{
		return (Number >= From && Number <= To) ? true : false;
	}

	static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo)
	{
		if ((clsDate::IsDate1AfterDate2(Date, DateFrom) || clsDate::IsDate1EqualDate2(Date, DateFrom))
			&&
			(clsDate::IsDate1BeforeDate2(Date, DateTo) || clsDate::IsDate1EqualDate2(Date, DateTo)))
			return true;

		if ((clsDate::IsDate1AfterDate2(Date, DateTo) || clsDate::IsDate1EqualDate2(Date, DateTo))
			&&
			(clsDate::IsDate1BeforeDate2(Date, DateFrom) || clsDate::IsDate1EqualDate2(Date, DateFrom)))
			return true;

		return false;

	}

	static string ReadString()
	{
		string S1;
		getline(cin >> ws, S1);
		return S1;
	}

	static int ReadIntNumber(string Message="Invalid Number, Enter again:")
	{
		int Number = 0;
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Message << endl;
			cin >> Number;
		}
		return Number;
	}
	static short ReadshortNumber(string Message = "Invalid Number, Enter again:")
	{
		short Number = 0;
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Message << endl;
			cin >> Number;
		}
		return Number;
	}
	static double ReadDoubleNumber(string Message = "Invalid Number, Enter again: ")
	{
		double Number = 0;
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Message << endl;
			cin >> Number;
		}
		return Number;
	}
	static int ReadIntNumberBetween(int From, int To, string Messag="Number is not whithin range, Enter again: ")
	{
		int Number = ReadIntNumber();
		while (!IsNumberBetween(Number,From,To))
		{
			cout << Messag;
			Number = ReadIntNumber();
		}
		return Number;
	}
	static short ReadShortNumberBetween(short From, short To, string Messag = "Number is not whithin range, Enter again: ")
	{
		short Number = ReadIntNumber();
		while (!IsNumberBetween(Number, From, To))
		{
			cout << Messag;
			Number = ReadIntNumber();
		}
		return Number;
	}
	static double ReaddoubleNumberBetween(double From, double To, string Messag = "Number is not whithin range, Enter again: ")
	{
		double Number = ReadIntNumber();
		while (!IsNumberBetween(Number, From, To))
		{
			cout << Messag;
			Number = ReadIntNumber();
		}
		return Number;
	}

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

};

