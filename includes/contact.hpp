#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
    Contact() = default;
    
    void setID(int id);
    void setName(const std::string& name);
    void setSurname(const std::string& surname);
    void setEmail(const std::string& email);
    void setPhone(const std::string&  phone);
    int getID() const;
    const std::string& getName() const;
    const std::string& getSurname() const;
    const std::string& getEmail() const;
    const std::string& getPhone() const;
    bool operator==(const Contact* other);

private:
    int         m_id;
    std::string m_name;
    std::string m_surname;
    std::string m_email;
    std::string m_phone;
};

#endif