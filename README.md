# 🏨 Hotel Reservation System (C++)

This is a simple command-line based Hotel Reservation System developed in C++. It supports both admin and user functionalities, allowing room booking, cancellation, status viewing, and user registration/login.

---

## 💡 Features

### 👤 User Panel
- User registration and secure password input
- User login authentication
- View hotel room status (vacant/occupied)
- Book a room (Standard, Deluxe, or Suite)
- Cancel a reservation
- Data persistence through file storage

### 🔐 Admin Panel
- Admin login with fixed credentials
- View all room statuses across 3 floors
- Save room data to a file
- Load room data from a file

---

## 🛠️ Technologies Used

- C++11 (Standard)
- File handling (fstream)
- Secure password input using `_getch()`
- CLI-based interface

---

## 🚀 How to Run

### ✅ Prerequisites
- A C++11 compatible compiler (e.g., `g++ 9.0+`)
- If on Windows, install MinGW-w64 via [MSYS2](https://www.msys2.org) or [WinLibs](https://winlibs.com/)

### 🔧 Compile

```bash
g++ -std=c++11 code.cpp -o hotel
````

### ▶️ Run

```bash
.\hotel.exe    # On Windows
```

---

## 📝 File Structure

```
Hotel_Reservation_System/
├── code.cpp                # Main source code
├── README.md               # Project documentation
├── hotel_data.txt          # Saved room states (auto-generated)
├── user_registration.txt   # Registered users (auto-generated)
```

---

## 👮 Admin Credentials

```
Username: mansoor
Password: 1234
```

---

## 📌 Notes

* Maximum of **10 registered users** allowed
* Each room holds **1 customer**
* There are **3 floors** with **9 rooms per floor**

---

## ✍️ Author

**Mian Mansoor**

---

## 📜 License

This project is open-source and free to use under the MIT License.

```

---
Let me know if you'd like a **shorter version**, or if you want a `requirements.txt`, `.gitignore`, or GitHub `repo description`!
```
