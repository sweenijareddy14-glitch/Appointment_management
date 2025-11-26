 Hospital Appointment Scheduling System (C Program)

## **Abstract**
The Hospital Appointment Scheduling System is a lightweight, terminal-based application developed entirely in C for managing patient appointments efficiently. It allows users to add new appointments, view existing ones, search by name or date, and delete appointments as needed. All data is stored persistently in a binary `appointments.dat` file, ensuring that information remains intact across multiple program sessions.

This project demonstrates essential C programming concepts such as **structures**, **file handling**, **binary storage**, and a **menu-driven interface**, making it ideal for academic projects and small-scale hospital management applications.

---

## **Features**
- Add new appointments (name, date, time, description)
- View all existing appointments
- Search appointments by:
  - Patient Name
  - Appointment Date
- Delete appointments using Appointment ID
- Automatically generate unique IDs
- Persistent data storage using `.dat` file
- Fully terminal-based system
- Easy-to-understand C code structure
- Auto-creates data file if missing
- Basic error and input handling

---

## **Technical Requirements**

### **1. System Requirements**
- Operating System: Windows / Linux / macOS  
- Terminal or command-line interface  
- At least 4 MB RAM  
- Minimal disk space (a few KB for data file)

### **2. Software Requirements**
- C Compiler: GCC / MinGW / Clang / MSVC
- Any IDE/Text Editor (VS Code, Code::Blocks, Dev-C++, Notepad++, etc.)
- Optional: `make` utility for automated builds

### **3. Programming Requirements**
- Programming Language: C
- Standards Supported: C89 / C99 / C11
- Required Header Files:
  - `<stdio.h>`
  - `<stdlib.h>`
  - `<string.h>`
  - `<ctype.h>`

### **4. File Handling Requirements**
- Read/write access to working directory  
- Binary file: `appointments.dat`
- Uses `fread()` and `fwrite()` for record storage
- Creates the file automatically if not found

### **5. Compilation Requirements**
Use GCC to compile:

```
gcc appointment_system.c -o appointment_system
```

---

## **Functional Requirements**

### **1. User Interface**
- Menu-driven, user-friendly interface
- Input validation using `fgets()`
- Continuous loop until Exit is chosen

### **2. Appointment Operations**
- **Add Appointment:** Stores new data with a unique ID  
- **View Appointments:** Displays all stored records  
- **Search Appointment:**  
  - By Name (case-insensitive)  
  - By Date  
- **Delete Appointment:** Removes a record by ID using temporary file rewrite  

### **3. Data Management**
- Persistent storage in `appointments.dat`
- Reads and writes in binary format
- Uses C structures for data organization

### **4. Program Flow**
- Clear menu options
- Uses `switch-case` for operations
- Proper status/error messages displayed

---

## **Project File Structure**
```
hospital-appointment-system/
│
├── appointment_system.c      # Source code
├── appointments.dat          # Auto-created during first run
└── README.md                 # Documentation
```

---

## **How to Compile and Run**

### **Step 1: Compile the program**
```
gcc appointment_system.c -o appointment_system
```

### **Step 2: Run the executable**
**On Windows:**
```
appointment_system.exe
```

**On Linux/macOS:**
```
./appointment_system
```

### **Step 3: Data File**
- The system creates `appointments.dat` file automatically
- All appointment records are saved in this file

---
### **Screenshots**
1.Main Menu

<img width="1328" height="569" alt="Screenshot (43)" src="https://github.com/user-attachments/assets/88d7a360-9ede-4545-81bd-a8df4d83169e" />

2.Add New Appointment

<img width="1425" height="606" alt="Screenshot (39)" src="https://github.com/user-attachments/assets/4f8d1b5b-14ea-4011-832e-38dc255a06dc" />

3.update appointments:

<img width="1672" height="753" alt="Screenshot (55)" src="https://github.com/user-attachments/assets/522300ad-dd77-49f7-888a-69797eeabbe7" />


4.View All Appointments

<img width="1519" height="836" alt="Screenshot (41)" src="https://github.com/user-attachments/assets/58c81b69-9e44-4704-b932-3b48d040cf4a" />

5.Search Appointment

<img width="1296" height="749" alt="Screenshot (44)" src="https://github.com/user-attachments/assets/25c5087f-0f7f-4d22-a5a6-c26ea86c611b" />

6.Delete Appointment

<img width="1353" height="594" alt="Screenshot (40)" src="https://github.com/user-attachments/assets/ffab9c24-79f4-4a45-9760-aae35bf9852e" />

7.Exit.

<img width="1353" height="462" alt="Screenshot (42)" src="https://github.com/user-attachments/assets/deb0525d-eb2d-4dcb-9422-cfb703c779d9" />


