#include "Airport.h"

/**
 * @brief Constructor for Airport class
 * Complexity: O(1)
 * @param code The code of the airport.
 * @param name The name of the airport.
 * @param country The country of the airport.
 * @param city The city of the airport.
 * @param latitude The latitude of the airport.
 * @param longitude The longitude of the airport.
 */
Airport::Airport(std::string code, std::string name, std::string country,
                 std::string city, double latitude, double longitude)
{
  this->code = code;
  this->name = name;
  this->country = country;
  this->city = city;
  this->latitude = latitude;
  this->longitude = longitude;
}

/**
 * @brief Constructor for Airport class
 * Complexity: O(1)
 * @param code The code of the airport.
 */
Airport::Airport(std::string code) { this->code = code; }

/**
 * @brief Function for sorting Airport ranking
 * Complexity: O(1)
 * @param a The first ranking.
 * @param b The second ranking.
 * @return bool True if the first ranking is greater than the second ranking.
 */
bool comparator(const Ranking a, const Ranking b)
{
  if (b.count != a.count)
    return a.count > b.count;
  else
    return a.code < b.code;
}

/**
 * @brief Function for comparing two Airport code
 * Complexity: O(1)
 * @param other The other airport.
 * @return bool True if the two airports have the same code.
 */
bool Airport::operator==(const Airport &other) const
{
  return this->code == other.code;
}

/**
 * @brief Function to print the Aiport information
 * Complexity: O(1)
 * @return void
 */
void Airport::display()
{
  std::cout << "Code: " << this->code << " / ";
  std::cout << "Name: " << this->name << " / ";
  std::cout << "Country: " << this->country << " / ";
  std::cout << "City: " << this->city << " / ";
  std::cout << "Latitude: " << this->latitude << " / ";
  std::cout << "Longitude: " << this->longitude << std::endl;
}

/**
 * @brief Setter for set/modifying the Airport code
 * Complexity: O(1)
 * @param code The code of the airport.
 * @return void
 */
void Airport::setCode(std::string code) { this->code = code; }

/**
 * @brief Setter for set/modifying the Airport name
 * Complexity: O(1)
 * @param name The name of the airport.
 * @return void
 */
void Airport::setName(std::string name) { this->name = name; }

/**
 * @brief Setter for set/modifying the Airport country
 * Complexity: O(1)
 * @param country The country of the airport.
 * @return void
 */
void Airport::setCountry(std::string country) { this->country = country; }

/**
 * @brief Setter for set/modifying the Airport city
 * Complexity: O(1)
 * @param city The city of the airport.
 * @return void
 */
void Airport::setCity(std::string city) { this->city = city; }

/**
 * @brief Setter for set/modifying the Airport latitude
 * Complexity: O(1)
 * @param latitude The latitude of the airport.
 * @return void
 */
void Airport::setLatitude(double latitude) { this->latitude = latitude; }

/**
 * @brief Setter for set/modifying the Airport longitude
 * Complexity: O(1)
 * @param longitude The longitude of the airport.
 * @return void
 */
void Airport::setLongitude(double longitude) { this->longitude = longitude; }

/**
 * @brief Getter for retrieving Airport code
 * Complexity: O(1)
 * @return std::string The code of the airport.
 */
std::string Airport::getCode() { return code; }

/**
 * @brief Getter for retrieving Airport name
 * Complexity: O(1)
 * @return std::string The name of the airport.
 */
std::string Airport::getName() { return name; }

/**
 * @brief Getter for retrieving Airport country
 * Complexity: O(1)
 * @return std::string The country of the airport.
 */
std::string Airport::getCountry() { return country; }

/**
 * @brief Getter for retrieving Airport city
 * Complexity: O(1)
 * @return std::string The city of the airport.
 */
std::string Airport::getCity() { return city; }

/**
 * @brief Getter for retrieving Airport latitude
 * Complexity: O(1)
 * @return double The latitude of the airport.
 */
double Airport::getLatitude() { return latitude; }

/**
 * @brief Getter for retrieving Airport longitude
 * Complexity: O(1)
 * @return double The longitude of the airport.
 */
double Airport::getLongitude() { return longitude; }
