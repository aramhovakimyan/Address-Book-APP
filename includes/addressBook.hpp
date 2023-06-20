#ifndef ADDRESS_BOOK_HPP
#define ADDRESS_BOOK_HPP

#include "contact.hpp"
#include "nlohmann/json.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>
#include <regex>

#define FILENAME "address_book.json"

using json = nlohmann::json;

class AddressBook {
public:
    AddressBook();
    ~AddressBook();

    void insertContact(Contact* con);
    void updateContact(const Contact* con);
    void deleteContact(int id);
    void search(const std::string& data);
    void printContact(const Contact* con);
    void printAddressBook();
    const std::vector<Contact*>& getContacts() const;
private:
    std::vector<Contact*> m_contacts;
    void m_readContactsFromFile();
    void m_writeContactsToFile();
};

#endif