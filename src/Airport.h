#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>

class Airport
{
public:
    Airport(std::string code, std::string name, std::string country, std::string city, double latitude, double longitude);
    std::string getCode();
    std::string getName();
    std::string getCountry();
    std::string getCity();
    double getLatitude();
    double getLongitude();
    void setCode(std::string code);
    void setName(std::string name);
    void setCountry(std::string country);
    void setCity(std::string city);
    void setLatitude(double latitude);
    void setLongitude(double longitude);

private:
    std::string code;
    std::string name;
    std::string country;
    std::string city;
    double latitude;
    double longitude;
};

#endif