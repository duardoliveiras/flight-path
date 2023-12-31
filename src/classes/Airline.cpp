#include "Airline.h"

// Constructor for Airline class
Airline::Airline(std::string code, std::string name, std::string callsign,
                 std::string country) {
  this->code = code;
  this->name = name;
  this->callsign = callsign;
  this->country = country;
}

// Constructor for Airline code class
Airline::Airline(std::string code) { this->code = code; }

// Function for comparing two  Airline code
bool Airline::operator==(const Airline &other) const {
  return this->code == other.code;
}

// Function to print the Aiport information
void Airline::display() {
  std::cout << "Code: " << this->code << " / ";
  std::cout << "Name: " << this->name << " / ";
  std::cout << "Callsign: " << this->callsign << " / ";
  std::cout << "Country: " << this->country << " / ";
}

// Setter for set/modifying the Airline code
void Airline::setCode(std::string code) { this->code = code; }

// Setter for set/modifying the Airline name
void Airline::setName(std::string name) { this->name = name; }

// Setter for set/modifying the Airline callsign
void Airline::setCallsign(std::string callsign) { this->callsign = callsign; }

// Setter for set/modifying the Airline country
void Airline::setCountry(std::string country) { this->country = country; }

// Getter for retrieving Airline code
std::string Airline::getCode() { return code; }

// Getter for retrieving Airline name
std::string Airline::getName() { return name; }

// Getter for retrieving Airline callsign
std::string Airline::getCallsign() { return callsign; }

// Getter for retrieving Airline country
std::string Airline::getCountry() { return country; }
