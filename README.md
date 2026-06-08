# 🏦 Bank Management System (C++)

![C++](https://img.shields.io/badge/C%2B%2B-17-blue)
![Status](https://img.shields.io/badge/status-active-success)
![Platform](https://img.shields.io/badge/platform-console-lightgrey)
![License](https://img.shields.io/badge/license-MIT-green)

---

## 📌 Overview

Bank Management System built using **C++ OOP principles**.  
The system simulates real banking operations such as managing clients, users, transactions, deposits, withdrawals, transfers, and login tracking.

It is designed with a **layered architecture** using classes, file storage, and access control system.

---

## 🚀 Features

### 👤 User Management
- Add new users
- Update users
- Delete users
- Find users
- List all users
- Login register tracking

### 🧾 Client Management
- Add / Update / Delete clients
- Search for client
- View client details

### 💰 Transactions
- Deposit money
- Withdraw money
- Transfer between accounts
- View total balances

### 🔐 Security System
- Permission-based access control
- Login authentication
- Activity logging

---

## 🧠 Technologies Used

- C++ (OOP)
- File Handling (TXT files)
- STL (vector, string)
- Modular Architecture
- Console UI

---

## 🏗️ Project Structure

```
Project/
│
├── clsPerson.h
├── clsUser.h
├── clsBankClient.h
├── clsScreen.h
├── clsInputValidate.h
├── Global.h
│
├── Screens/
│   ├── Manage Users
│   ├── Clients Screens
│   ├── Transactions Screens
│
└── Data Files/
    ├── Users.txt
    ├── Clients.txt
    ├── LoginRegister.txt
    ├── TransferLog.txt
```

---

## 🔐 Permissions System

The system uses bitwise permissions:

- pListClient
- pAddNewClient
- pDeleteClient
- pUpdateClient
- pFindClient
- pTransactions
- pManageUser
- pLoginRegister

---

## ⚙️ How It Works

1. User logs in
2. System checks permissions
3. Displays main menu
4. User selects operations:
   - Clients
   - Users
   - Transactions
5. All data is saved in text files

---

## 📊 Example Screens

### 🧑‍💼 User Screen
- List Users
- Add User
- Update User
- Delete User

### 💳 Transaction Screen
- Deposit
- Withdraw
- Transfer
- Balance report

---

## 💾 Data Storage

All data is stored locally using `.txt` files:
- Users.txt
- Clients.txt
- LoginRegister.txt
- TransferLog.txt

---

## 📸 Screenshots (Optional)

```
![Main Menu](screenshots/main-menu.png)
![Clients](screenshots/clients.png)
```

---

## 🧑‍💻 Author

- Developed by: **Ahmed Hatem**
- Project Type: Learning / Portfolio Project
- Language: C++ (OOP)

---

## 📌 Future Improvements

- GUI version (Qt / .NET)
- Database support (SQL Server / MySQL)
- Encryption upgrade
- Multi-language support
- Web version

---

## ⭐ Support

If you like this project, please give it a ⭐ on GitHub.
