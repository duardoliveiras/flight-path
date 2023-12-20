#include "Airport.h"

Airport::Airport(std::string code, std::string name, std::string country, std::string city, double latitude, double longitude)
{
    this->code = code;
    this->name = name;
    this->country = country;
    this->city = city;
    this->latitude = latitude;
    this->longitude = longitude;
}

void Airport::setCode(std::string code)
{
    this->code = code;
}

void Airport::setName(std::string name)
{
    this->name = name;
}

void Airport::setCountry(std::string country)
{
    this->country = country;
}

void Airport::setCity(std::string city)
{
    this->city = city;
}

void Airport::setLatitude(double latitude)
{
    this->latitude = latitude;
}

void Airport::setLongitude(double longitude)
{
    this->longitude = longitude;
}

std::string Airport::getCode()
{
    return code;
}

std::string Airport::getName()
{
    return name;
}

std::string Airport::getCountry()
{
    return country;
}

std::string Airport::getCity()
{
    return city;
}

double Airport::getLatitude()
{
    return latitude;
}

double Airport::getLongitude()
{
    return longitude;
}
