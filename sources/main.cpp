#include "addressBook.hpp"

namespace utility {
    enum Operations {
        INSERT_CONTACT = 1,
        UPDATE_CONTACT,
        DELETE_CONTACT,
        SEARCH_CONTACT,
        PRINT,
        EXIT
    };

    bool checkID(const AddressBook* addrBook, int id) {
        auto contacts = addrBook->getContacts();
        for (const auto& con : contacts) {
            if (con->getID() == id) {
                return true;
            }
        }
        return false;
    }

    bool checkEmail(const AddressBook* addrBook, const std::string& email) {
        auto contacts = addrBook->getContacts();
        for (const auto& con : contacts) {
            if (con->getEmail() == email) {
                return true;
            }
        }
        return false;
    }

    bool checkPhone(const AddressBook* addrBook, const std::string& phone) {
        auto contacts = addrBook->getContacts();
        for (const auto& con : contacts) {
            if (con->getPhone() == phone) {
                return true;
            }
        }
        return false;
    }

    bool isValidEmail(const std::string& email) {
        // Regular expression pattern for email validation
        const std::regex pattern("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$");

        return std::regex_match(email, pattern);
    }

    bool isValidPhone(const std::string& phone) {
        // Regular expression pattern for Armenian phone number validation
        const std::regex pattern("^(077|099|094|093|091|096|033|055|095)[0-9]{6}$");

        return std::regex_match(phone, pattern);
    }
};

int main() {
    AddressBook addressBook;

    int choice;
    while (true) {
        std::cout << std::endl;
        std::cout << "===== Address Book Menu =====" << std::endl;
        std::cout << "1. Insert Contact" << std::endl;
        std::cout << "2. Update Contact" << std::endl;
        std::cout << "3. Delete Contact" << std::endl;
        std::cout << "4. Search Contact" << std::endl;
        std::cout << "5. Print Address Book" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "ERROR: Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice == utility::Operations::INSERT_CONTACT) {
            Contact* newContact = new Contact();
            int id;
            std::string name, surname, email, phone;

            std::cout << "Enter ID: ";
            std::cin >> id;
            if (id < INT_MIN || id > INT_MAX || utility::checkID(&addressBook, id)) {
                delete newContact;
                std::cout << "ERROR: Invalid ID" << std::endl;
                continue;
            }
            newContact->setID(id);

            std::cout << "Enter Name: ";
            std::cin >> name;
            newContact->setName(name);

            std::cout << "Enter Surname: ";
            std::cin >> surname;
            newContact->setSurname(surname);

            std::cout << "Enter Email: ";
            std::cin >> email;
            if (utility::checkEmail(&addressBook, email)) {
                delete newContact;
                std::cout << "ERROR: Email is used." << std::endl;
                continue;
            }
            if (!utility::isValidEmail(email)) {
                delete newContact;
                std::cout << "ERROR: Invalid email address." << std::endl;
                continue;
            }
            newContact->setEmail(email);

            std::cout << "Enter Phone: ";
            std::cin >> phone;
            if (utility::checkPhone(&addressBook, phone)) {
                delete newContact;
                std::cout << "ERROR: Phone is used." << std::endl;
                continue;
            }
            if (!utility::isValidPhone(phone)) {
                delete newContact;
                std::cout << "ERROR: Invalid phone number." << std::endl;
                continue;
            }
            newContact->setPhone(phone);

            addressBook.insertContact(newContact);
            std::cout << "Contact added successfully!" << std::endl;
        }
        else if (choice == utility::Operations::UPDATE_CONTACT) {
            int id;
            std::cout << "Enter the ID of the contact to update: ";
            std::cin >> id;

            if (!utility::checkID(&addressBook, id)) {
                std::cout << "ERROR: No matching contact with that ID" << std::endl;
                continue;
            }

            Contact* updatedContact = new Contact();
            updatedContact->setID(id);

            std::string name, surname, email, phone;

            std::cout << "Enter Name: ";
            std::cin >> name;
            updatedContact->setName(name);

            std::cout << "Enter Surname: ";
            std::cin >> surname;
            updatedContact->setSurname(surname);

            std::cout << "Enter Email: ";
            std::cin >> email;
            updatedContact->setEmail(email);

            std::cout << "Enter Phone: ";
            std::cin >> phone;
            updatedContact->setPhone(phone);

            addressBook.updateContact(updatedContact);
            std::cout << "Contact updated successfully!" << std::endl;
            delete updatedContact;
        }
        else if (choice == utility::Operations::DELETE_CONTACT) {
            int id;
            std::cout << "Enter the ID of the contact to delete: ";
            std::cin >> id;

            if (!utility::checkID(&addressBook, id)) {
                std::cout << "ERROR: No matching contact with that ID" << std::endl;
                continue;
            }

            addressBook.deleteContact(id);
            std::cout << "Contact deleted successfully!" << std::endl;
        }
        else if (choice == utility::Operations::SEARCH_CONTACT) {
            std::string searchQuery;
            std::cout << "Enter the search query: ";
            std::cin >> searchQuery;

            addressBook.search(searchQuery);
        }
        else if (choice == utility::Operations::PRINT) {
            addressBook.printAddressBook();
        }
        else if (choice == utility::Operations::EXIT) {
            std::cout << "Program ended. Address book data saved." << std::endl;
            break;
        }
        else if (choice > 6 || choice < 1){
            std::cout << "ERROR: Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
