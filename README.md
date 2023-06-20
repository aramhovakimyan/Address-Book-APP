
# Address Book App

The Address Book App is a console-based program written in C++. It allows you to manage contacts in an address book, including inserting, updating, deleting, searching, and printing contacts.

## How to Use

1. Launch the program by running the `addressBook` executable file.
2. The program will display a menu with options to perform various actions.
3. Choose the desired action by entering the corresponding number and pressing Enter.
4. Follow the prompts to provide the necessary information for each action.
5. The program will execute the chosen action and display the results or feedback accordingly.
6. Repeat steps 3-5 to perform additional actions or exit the program.

## Menu Options

1. Insert Contact: Add a new contact to the address book.
2. Update Contact: Modify the information of an existing contact.
3. Delete Contact: Remove a contact from the address book.
4. Search Contacts: Find contacts based on specific criteria (name, surname, email, phone, or ID).
5. Print Address Book: Display all contacts in the address book.
6. Save and Exit: Save the address book to a file and exit the program.

## How to Build

To build the Address Book App, follow these steps:

1. Ensure that you have a C++ compiler (e.g., GCC) and `make` utility installed on your system.
2. Clone or download the source code from the repository.
3. Open a terminal or command prompt and navigate to the directory containing the source code.
4. Run the `make` command to build the program. This will compile the source files and generate an executable named `addressBook`.
5. Once the build process completes successfully, you can run the program by executing the `addressBook` executable.

If you encounter any issues during the build process, ensure that you have the necessary dependencies and development tools installed on your system.

## Dependencies

The Address Book App depends on the following:

- C++ compiler with C++11 support
- nlohmann/json library (included in the source code)
- Make utility (for building the program)

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
