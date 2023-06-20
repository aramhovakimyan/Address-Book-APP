#include "contact.hpp"

void Contact::setID(int id) {
    m_id = id;
}

void Contact::setName(const std::string& name) {
        m_name = name;
}

void Contact::setSurname(const std::string& surname) {
    m_surname = surname;
}

void Contact::setEmail(const std::string& email) {
    m_email = email;
}

void Contact::setPhone(const std::string& phone) {
    m_phone = phone;
}

int Contact::getID() const {
    return m_id;
}

const std::string& Contact::getName() const {
    return m_name;
}

const std::string& Contact::getSurname() const {
    return m_surname;
}

const std::string& Contact::getEmail() const {
    return m_email;
}

const std::string& Contact::getPhone() const {
    return m_phone;
}

bool Contact::operator==(const Contact* other) {
    if (m_name != other->m_name || m_surname != other->m_surname  || \
        m_email != other->m_email || m_phone != other->m_phone)
        return false;
    return true;
}
