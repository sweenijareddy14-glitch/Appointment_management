# Hospital Appointment Scheduling System (C Program)

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
Screenshots
1.Add New Appointment



