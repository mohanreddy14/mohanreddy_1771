# mohanreddy_1771


🧑‍⚕️ Discharge Management System (C Program)

A fully functional, menu-driven Hospital Discharge Management System created using C programming.
This program helps hospital staff store, update, search, and delete patient discharge information efficiently using binary file handling and structured data.

⭐ ABSTRACT

The Hospital Discharge Management System is a console-based C application designed to simplify how hospitals handle discharge records. This system allows healthcare staff to enter new discharge details, search for an existing patient, update discharge notes, and remove outdated information securely. All records are stored in a binary file, ensuring that patient data is safely preserved even when the program is closed.

By using structures, file handling (fread, fwrite), arrays, loops, and conditional logic, the system demonstrates strong practical applications of core C programming concepts. It is ideal for students and beginners learning how to create real-world management systems using the C language.

⭐ FEATURES OF THE PROGRAM
✔ Add Discharge Record

Record patient ID

Enter patient name, age, gender

Enter diagnosis

Enter the number of days admitted

Enter medicine charges, room charges, and other costs

Add final discharge notes

Save record permanently to discharge.dat

✔ View All Discharged Patients

Displays a table with:

Patient ID

Name

Age

Gender

Diagnosis

Days admitted

Total bill amount (auto-calculated)

Contact info

✔ Search Discharge Record

Search by Patient ID

Displays complete discharge summary

Shows “Record Not Found” if ID does not exist

✔ Update Discharge Details

Load all records into memory

Edit discharge notes, diagnosis, and billing charges

Write all updated records back to the file

Shows confirmation message after update

✔ Delete Discharge Record

Confirm before deletion

Remove the selected patient permanently

Rewrite the updated list into discharge.dat

✔ Binary File Storage

All data stored in a file named discharge.dat

Data stored using fwrite()

Read using fread()

File created automatically if not found

Supports unlimited records

✔ User-Friendly Interface

Clean text-based menu

Clear prompts

Uses fgets() for safe string input

Loops until the user selects Exit

⭐ TECHNICAL REQUIREMENTS
System Requirements

Windows / macOS / Linux

Terminal / Command Prompt

Any basic computer (very lightweight program)

Software Requirements

C Compiler: GCC, MinGW, MSVC, Clang

Text editor like:
Code::Blocks, VS Code, Dev-C++, Notepad++, etc.

Programming Requirements

Language: C

File Handling

Structures

Menu-driven interface

Binary file operations

⭐ LIBRARIES USED
#include <stdio.h>     // For I/O operations, file handling
#include <stdlib.h>    // For general utilities
#include <string.h>    // For string handling (fgets, strcpy, etc.)

⭐ FILE MANAGEMENT

A binary file named:

discharge.dat


is used to store records permanently.

Uses:

fwrite() to add/save data

fread() to access stored data

fopen() in ab / rb / wb modes

Automatically creates file if missing

File persists even after the program is closed.

⭐ FUNCTIONAL REQUIREMENTS
🔹 1. Add Discharge Record

Take patient details

Validate duplicate ID

Calculate total bill

Store record permanently

🔹 2. View All Discharge Records

Displays rows containing:

ID

Name

Diagnosis

Billing details

Contact

Total cost

🔹 3. Search Discharge Information

Search by ID only

Full details displayed if found

🔹 4. Update Discharge Record

Modifiable fields:

Diagnosis

Medicine cost

Other charges

Contact details

All changes rewritten to file.

🔹 5. Delete Discharge Record

Confirm deletion

Remove entry

Rewrite updated data

⭐ DATA MANAGEMENT

Each patient stored as a structure

All fields handled using arrays and file operations

Updating and deletion handled using temporary arrays

File rewritten after updates to maintain accuracy

⭐ PROGRAM FLOW

Display main menu

User selects an operation

Program performs the operation:

Add, View, Search, Update, or Delete

Displays confirmation or error message

Returns to the main menu

Exits when the user chooses option 6

 screen shots
 <img width="677" height="502" alt="Screenshot 2025-11-25 190223" src="https://github.com/user-attachments/assets/354a3176-1432-4369-b181-627878765282" />
 <img width="1009" height="316" alt="Screenshot 2025-11-25 190235" src="https://github.com/user-attachments/assets/9841b014-4485-4cfe-b5fa-f2d17525b512" />
 <img width="462" height="484" alt="Screenshot 2025-11-25 190246" src="https://github.com/user-attachments/assets/ea65a859-2a27-4b82-a23a-f8937b338871" />
<img width="439" height="347" alt="Screenshot 2025-11-25 190256" src="https://github.com/user-attachments/assets/c95225f5-735d-43b7-a69f-a3e4f9cb4d06" />
<img width="550" height="506" alt="Screenshot 2025-11-25 190309" src="https://github.com/user-attachments/assets/7961e8a2-8ea8-45ee-8933-51625f97ca38" />


⭐ HOW TO RUN THE PROGRAM
Step 1: Compile the code
gcc discharge_management_system.c -o discharge

Step 2: Run the executable

Windows:

discharge.exe


Linux/macOS:

./discharge

Step 3: File Creation

After running the program, it will automatically create:

discharge.dat


All discharge information will be saved here permanently.
