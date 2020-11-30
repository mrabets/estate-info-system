#include "Client.h"

Client::Client() : fullName(0), age(0), passport(0)
{
     
}

Client::Client(const Client& object)
{
    fullName = object.fullName;
    age = object.age;
    passport = object.passport;
}

Client::Client(string fullName, int age, string passport)
{
    this->fullName = fullName;
    this->age = age;
    this->passport = passport;
   
}

Client::~Client()
{
}

//void Client::setPrice(Estate& estate, float price)
//{
//    estate.price = price;
//}
//
//void Client::setAddress(Estate& estate, string address)
//{
//    estate.address = address;
//}

string Client::getFullName()
{
    return this->fullName;
}

int Client::getAge()
{
    return this->age;
}

string Client::getPassport()
{
    return this->passport;
}
