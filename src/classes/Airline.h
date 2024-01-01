#ifndef AIRLINE_H
#define AIRLINE_H

#include <iostream>
#include <string>

class Airline {

public:
  // Constructor
  Airline(std::string code, std::string name, std::string callsign,
          std::string country);
  Airline(std::string code);

  // Getters
  std::string getCode();
  std::string getName();
  std::string getCallsign();
  std::string getCountry();

  // Setters
  void setCode(std::string code);
  void setName(std::string name);
  void setCallsign(std::string callsign);
  void setCountry(std::string country);

  // Other functions
  void display();
  bool operator==(const Airline &other) const;

private:
  std::string code;
  std::string name;
  std::string callsign;
  std::string country;
};

#endif