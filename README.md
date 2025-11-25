# mohanreddy_1771


# 🧑‍⚕️ Discharge Management System (C Program)

A simple menu-driven **Hospital Discharge Management System** written entirely in C.

This program allows hospital staff to discharge patients, update discharge records, and search or view patient discharge information using structures and binary file storage.


## 👉 Abstract

The **Discharge Management System** is a lightweight, terminal-based C application designed to support hospitals in managing patient discharge information accurately and efficiently.
The system enables users to record new discharge entries, update existing discharge notes, view all discharged patients, and search patient discharge details by ID.
All information is stored persistently in a binary `.dat` file, ensuring that data remains saved even when the program is closed.

With a simple menu-driven interface and clean file-handling logic, this program is ideal for beginners learning C concepts such as structures, binary files, loops, conditional statements, and text-based user interaction.
This project provides a practical solution for tracking discharged patients in a small healthcare environment.

---

## 👉 Features of the Program

### ✔ Add Discharge Record

* Enter patient ID
* Enter patient name
* Enter disease/diagnosis
* Enter discharge notes or instructions
* Save the record into `discharge.dat`

### ✔ View All Discharged Patients

Displays:

* Patient ID
* Name
* Diagnosis
* Discharge Notes

### ✔ Search Discharge Record

* Search by patient ID
* Show complete discharge details
* Displays a “Record Not Found” message if absent

### ✔ Update Discharge Notes

* Load all records into an array
* Modify discharge details
* Save updated data back to the file

### ✔ Delete Discharge Record

* Confirm before deleting
* Remove entry permanently
* Rewrite updated records into `discharge.dat`

### ✔ Persistent Data Storage

* All discharge data stored in `discharge.dat`
* File automatically created if missing
* Records stored using binary `fread()` and `fwrite()`

### ✔ User-Friendly Interface

* Simple menu-driven navigation
* Clear input prompts
* Safe input handling using `fgets()`
* Loop continues until user chooses Exit

---

## 👉 Technical Requirements

### System Requirements

* Windows / Linux / macOS
* Terminal / Command Prompt
* Minimum RAM: 4 MB
* Small disk space for `discharge.dat`

### Software Requirements

* C Compiler: GCC / Clang / MSVC / MinGW
* Code editor: VS Code, Code::Blocks, Dev-C++, etc.

### Programming Requirements

* Language: **C**
* Standard: C89/C99/C11 supported

### Libraries Used

```c
#include <stdio.h>   // Input/Output, File handling
#include <string.h>  // String functions (fgets, strcpy, etc.)
```

(No `<stdlib.h>` required)

---

## 👉 File Handling Requirements

Program uses a binary file:

```
discharge.dat
```

Each `Discharge` structure is written using:

* `fwrite()` → store record
* `fread()` → read record

Program will:

* Create file automatically if it does not exist
* Append new entries safely
* Rewrite records when updated or deleted

---

## 👉 Functional Requirements

### 🔹 User Interface

* Fully command-line
* Clear menu options
* Input validation
* Continuous loop until Exit

---

### 🔹 Discharge Management Operations

#### ✔ Add Discharge Record

* Input patient ID
* Check if record already exists
* Enter patient name
* Enter diagnosis
* Enter doctor’s discharge notes
* Save new record to file

#### ✔ View All Discharge Records

Displays:

* ID
* Name
* Diagnosis
* Discharge Notes

Records are read directly from the file.

#### ✔ Search Patient Discharge Info

* Search by Patient ID
* Displays all details if found
* Otherwise shows error message

#### ✔ Update Discharge Details

* Read all records into an array
* Locate target ID
* Edit discharge notes / details
* Save all records back to file

#### ✔ Delete Discharge Record

* Load all records
* Confirm deletion
* Remove the selected entry
* Rewrite updated list to `discharge.dat`

---

## 👉 Data Management

* All data stored persistently
* Supports unlimited sessions
* Automatically creates file
* Uses arrays for editing and rewriting

---

## 👉 Program Flow

1. Display menu
2. User selects an option
3. Perform corresponding operation
4. Show success or error message
5. Return to menu
6. Exit when user chooses

---

## 👉 How to Run the Program

### 1. Compile the Program

Open terminal and run:

```
gcc discharge_management.c -o discharge_management
```

### 2. Run the Executable

Linux/macOS:

```
./discharge_management
```

Windows:

```
discharge_management.exe
```

### 3. Data File

The program automatically creates:

```
discharge.dat
```

All discharge records are stored here permanently.
