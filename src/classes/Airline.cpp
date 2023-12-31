#include "Airline.h"

/**
 * @brief Constructor for Airline class
 * Complexity: O(1)
 * @param code The code of the airline.
 * @param name The name of the airline.
 * @param callsign The callsign of the airline.
 * @param country The country of the airline.
 */
Airline::Airline(std::string code, std::string name, std::string callsign,
                 std::string country)
{
  this->code = code;
  this->name = name;
  this->callsign = callsign;
  this->country = country;
}

/**
 * @brief Constructor for Airline class
 * Complexity: O(1)
 * @param code The code of the airline.
 */
Airline::Airline(std::string code) { this->code = code; }

/**
 * @brief Function for comparing two Airline code
 * Complexity: O(1)
 * @param other The other airline.
 * @return bool True if the two airlines have the same code.
 */
bool Airline::operator==(const Airline &other) const
{
  return this->code == other.code;
}

/**
 * @brief Function to print the Airline information
 * Complexity: O(1)
 * @return void
 */
void Airline::display()
{
  std::cout << "Code: " << this->code << " / ";
  std::cout << "Name: " << this->name << " / ";
  std::cout << "Callsign: " << this->callsign << " / ";
  std::cout << "Country: " << this->country << " / ";
}

/**
 * @brief Setter for set/modifying the Airline code
 * Complexity: O(1)
 * @param code The code of the airline.
 * @return void
 */
void Airline::setCode(std::string code) { this->code = code; }

/**
 * @brief Setter for set/modifying the Airline name
 * Complexity: O(1)
 * @param name The name of the airline.
 * @return void
 */
void Airline::setName(std::string name) { this->name = name; }

/**
 * @brief Setter for set/modifying the Airline callsign
 * Complexity: O(1)
 * @param callsign The callsign of the airline.
 * @return void
 */
void Airline::setCallsign(std::string callsign) { this->callsign = callsign; }

/**
 * @brief Setter for set/modifying the Airline country
 * Complexity: O(1)
 * @param country The country of the airline.
 * @return void
 */
void Airline::setCountry(std::string country) { this->country = country; }

/**
 * @brief Getter for retrieving Airline code
 * Complexity: O(1)
 * @return std::string The code of the airline.
 */
std::string Airline::getCode() { return code; }

/**
 * @brief Getter for retrieving Airline name
 * Complexity: O(1)
 * @return std::string The name of the airline.
 */
std::string Airline::getName() { return name; }

/**
 * @brief Getter for retrieving Airline callsign
 * Complexity: O(1)
 * @return std::string The callsign of the airline.
 */
std::string Airline::getCallsign() { return callsign; }

/**
 * @brief Getter for retrieving Airline country
 * Complexity: O(1)
 * @return std::string The country of the airline.
 */
std::string Airline::getCountry() { return country; }
