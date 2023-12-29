#include "Airport.h"

// Constructor for Airport class
Airport::Airport(std::string code, std::string name, std::string country,
                 std::string city, double latitude, double longitude) {
  this->code = code;
  this->name = name;
  this->country = country;
  this->city = city;
  this->latitude = latitude;
  this->longitude = longitude;
}

// Constructor for Airport code class
Airport::Airport(std::string code) { this->code = code; }

// Function for sorting Airport ranking
bool comparator(const Ranking a, const Ranking b) {
  if (b.count != a.count)
    return a.count > b.count;
  else
    return a.code < b.code;
}

// Function for comparing two  Airport code
bool Airport::operator==(const Airport &other) const {
  return this->code == other.code;
}

// Function to print the Aiport information
void Airport::display() {
  std::cout << "Code: " << this->code << " / ";
  std::cout << "Name: " << this->name << " / ";
  std::cout << "Country: " << this->country << " / ";
  std::cout << "City: " << this->city << " / ";
  std::cout << "Latitude: " << this->latitude << " / ";
  std::cout << "Longitude: " << this->longitude << std::endl;
}

// Setter for set/modifying the Airport code
void Airport::setCode(std::string code) { this->code = code; }

// Setter for set/modifying the Airport name
void Airport::setName(std::string name) { this->name = name; }

// Setter for set/modifying the Airport country
void Airport::setCountry(std::string country) { this->country = country; }

// Setter for set/modifying the Airport city
void Airport::setCity(std::string city) { this->city = city; }

// Setter for set/modifying the Airport latitude
void Airport::setLatitude(double latitude) { this->latitude = latitude; }

// Setter for set/modifying the Airport longitude
void Airport::setLongitude(double longitude) { this->longitude = longitude; }

// Getter for retrieving Airport code
std::string Airport::getCode() { return code; }

// Getter for retrieving Airport name
std::string Airport::getName() { return name; }

// Getter for retrieving Airport country
std::string Airport::getCountry() { return country; }

// Getter for retrieving Airport city
std::string Airport::getCity() { return city; }

// Getter for retrieving Airport latitude
double Airport::getLatitude() { return latitude; }

// Getter for retrieving Airport longitude
double Airport::getLongitude() { return longitude; }
