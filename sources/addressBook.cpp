#include "addressBook.hpp"

AddressBook::AddressBook() {
    m_readContactsFromFile();
}

// Helper function to read contacts from a JSON file
void AddressBook::m_readContactsFromFile() {
    std::ifstream file(FILENAME);
    if (!file) {
        std::cerr << "ERROR: Failed to open file: " << FILENAME << std::endl;
        exit(1) ;
    }
    if (file.peek() == std::ifstream::traits_type::eof()) {
        file.close();
        return ;
    }

    json data;
    file >> data;
    file.close();
    for (const auto& contact : data) {
        Contact* c = new Contact();
        c->setID(contact["id"]);
        c->setName(contact["name"]);
        c->setSurname(contact["surname"]);
        c->setEmail(contact["email"]);
        c->setPhone(contact["phone"]);
        m_contacts.push_back(c);
    }
}

// Helper function to write contacts to a JSON file
void AddressBook::m_writeContactsToFile() {
    json data;
    for (const auto& contact : m_contacts) {
        json contactData;
        contactData["id"] = contact->getID();
        contactData["name"] = contact->getName();
        contactData["surname"] = contact->getSurname();
        contactData["email"] = contact->getEmail();
        contactData["phone"] = contact->getPhone();
        data.push_back(contactData);
    }

    std::ofstream file(FILENAME);
    if (!file) {
        std::cerr << "ERROR: Failed to create file: " << FILENAME << std::endl;
        return;
    }

    file << data.dump(4);
    file.close();
}

void AddressBook::insertContact(Contact* con) {
    m_contacts.push_back(con);
}

void AddressBook::updateContact(const Contact* con) {
    for (auto contact : m_contacts) {
        if (contact->getID() == con->getID()) {
            *contact = *con;
            break;
        }
    }
}

void AddressBook::deleteContact(int id) {
    for (auto it = m_contacts.begin(); it != m_contacts.end(); ++it) {
        if (id == (*it)->getID()) {
            delete *it;
            m_contacts.erase(it);
            break;
        }
    }
}

void AddressBook::search(const std::string& data) {
    bool flag = false;
    for (const auto& contact : m_contacts) {
        if (data == contact->getName() || data == contact->getSurname() ||
            data == contact->getEmail() || data == contact->getPhone() ||
            std::to_string(contact->getID()) == data) {
            printContact(contact);
            flag = true;
        }
    }
    if (!flag) {
        std::cout << "ERROR: No matching contact" << std::endl;
    }
}

void AddressBook::printContact(const Contact* con) {
    std::cout << std::endl;
    std::cout << "ID : " << con->getID() << std::endl;
    std::cout << "Name : " << con->getName() << std::endl;
    std::cout << "Surname : " << con->getSurname() << std::endl;
    std::cout << "Email : " << con->getEmail() << std::endl;
    std::cout << "Phone : " << con->getPhone() << std::endl;
}

void AddressBook::printAddressBook() {
    for (const auto& contact : m_contacts) {
        printContact(contact);
    }
}

const std::vector<Contact*>& AddressBook::getContacts() const {
    return m_contacts;
}

AddressBook::~AddressBook() {
    m_writeContactsToFile();
    for (auto contact : m_contacts) {
        delete contact;
    }
}