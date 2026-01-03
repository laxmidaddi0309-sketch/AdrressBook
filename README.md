**Addressbook project using C programming**

The AddressBook project is a contact management system developed in C. It allows users to efficiently store, manage, and retrieve contact information including Name, Mobile Number, and Email ID. The program ensures proper validation of inputs, maintains unique contacts, and stores the data in a file for persistent use.
It demonstrates key programming concepts such as structured programming, file handling, data validation, and modular design using separate header and source files

📌 Project Overview
The Address Book Project is designed to store and manage contact details such as Name, Mobile Number, and Email ID.
It supports creating, searching, editing, deleting, and saving contacts while enforcing strict input validation rules to ensure data integrity.

🚀 Features
Create new contacts with validation
Search contacts by:
Name
Mobile Number
Email ID
Edit contact details:
Name
Phone Number
Email ID
All fields
Delete existing contacts
Save contacts to a file
Alphabetical sorting of contacts before saving
Persistent storage using file handling
🗂️ File Structure
├── main.c # Main menu and program execution 
├── contact.c # Core logic (create, search, edit, delete, save) 
├── contact.h # Structure definitions and function declarations 
├── data.txt # Contact storage file (generated at runtime) 
└── README.md # Project documentation

**#Validation Rules Implemented** 
**🔹 Name Validation**

Only alphabets allowed

Spaces permitted

No digits or special characters

🔹** Mobile Number Validation**

Must start with digits 6 to 9

Exactly 10 digits

Numeric characters only

Must be unique

**🔹 Email ID Validation**

Exactly one @ symbol

Must contain .com

Only lowercase letters allowed

No spaces permitted

Domain must appear after @

Must be unique

🔍 Core Functional Modules

valid_name() – Validates contact name

valid_phone_number() – Validates phone number

valid_email_id() – Validates email ID

create_contact() – Adds new contact

list_contacts() – Displays all contacts

search_contacts() – Searches contacts

edit_contact() – Modifies contact details

delete_contact() – Removes a contact

save_contacts() – Saves contacts to file

💾 File Handling

Contacts are stored in data.txt

Data stored in CSV format

Uses standard C file operations:

fopen()
fprintf()
fclose()

Contacts are sorted alphabetically before saving

Ensures persistent storage across executions

How to Compile and Run (Linux) 
  --gcc main.c contact.c -o address_book ./address_book

🧪 Sample Data Format (data.txt) 
#3 Alex,9876543210,alex@gmail.com 
  John,9123456789,john@gmail.com 
  Ravi,9988776655,ravi@gmail.com
