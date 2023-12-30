#include "read.h"
#include "../classes/Airport.h"
#include <filesystem>

// Function to read Airport data from CSV file and create graph of airports
// Complexity: O(n), where n is the number of airports in the csv file
Graph<Airport> readAirports(std::string folder) {
  // Inicialiate Graph
  Graph<Airport> airports = Graph<Airport>();

  // Open csv file
  std::ifstream file("../dataset/" + folder + "/airports.csv", ios::in);
  if (!file.is_open()) {
    std::cout << "Error opening file" << std::endl;
    return airports;
  }

  // Read and ignore header line
  std::string line;
  if (!std::getline(file, line)) {
    std::cout << "Error reading header line" << std::endl;
    file.close();
    return airports;
  }

  // Read each line and create an Airport object
  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::string code, name, country, city;
    double latitude, longitude;

    std::getline(iss, code, ',');
    std::getline(iss, name, ',');
    std::getline(iss, city, ',');
    std::getline(iss, country, ',');

    iss >> latitude;
    iss.ignore();
    iss >> longitude;

    Airport airport(code, name, country, city, latitude, longitude);
    // airport.display();
    airports.addVertex(airport);
  }

  // Close file and return graph of airports
  file.close();
  return airports;
}

// Function to read Flight data from CSV file and add edges to graph of airports
// Complexity: O(n + v), where n is the number of airports and vis the number
// of flights in the csv file
Graph<Airport> readFlights(std::string folder) {
  // Read airports
  Graph<Airport> airports = readAirports(folder);

  // Open csv file
  std::ifstream file("../dataset/" + folder + "/flights.csv", ios::in);
  if (!file.is_open()) {
    std::cout << "Error opening flights file" << std::endl;
    return airports;
  }

  // Read and ignore header line
  std::string line;
  if (!std::getline(file, line)) {
    std::cout << "Error reading flights header line" << std::endl;
    file.close();
    return airports;
  }

  // Read each line and add edges to graph
  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::string source, target, airline;

    std::getline(iss, source, ',');
    std::getline(iss, target, ',');
    std::getline(iss, airline, ',');

    Airport src = Airport(source);
    Airport tgt = Airport(target);

    airports.addEdge(src, tgt, 0, airline);
  }

  // Close file and return the updated graph of airports with flights
  file.close();
  return airports;
}