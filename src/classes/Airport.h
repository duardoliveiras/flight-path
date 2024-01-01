#ifndef AIRPORT_H
#define AIRPORT_H

#include <iostream>
#include <string>

struct Ranking {
  std::string code;
  int count;
};

bool comparator(const Ranking a, const Ranking b);
class Airport {

public:
  // Constructor
  Airport(std::string code, std::string name, std::string country,
          std::string city, double latitude, double longitude);
  Airport(std::string code);

  // Getters
  std::string getCode();
  std::string getName();
  std::string getCountry();
  std::string getCity();
  double getLatitude();
  double getLongitude();

  // Setters
  void setCode(std::string code);
  void setName(std::string name);
  void setCountry(std::string country);
  void setCity(std::string city);
  void setLatitude(double latitude);
  void setLongitude(double longitude);

  // Other functions
  void display();
  bool operator==(const Airport &other) const;

private:
  std::string code;
  std::string name;
  std::string country;
  std::string city;
  double latitude;
  double longitude;
};

#endif