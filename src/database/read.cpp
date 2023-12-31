#include "read.h"

unordered_map<string, Airport> airportsHash;
unordered_set<string> citiesHash;
unordered_set<string> countriesHash;
/**
 * @brief Function to read Airport data from CSV file and create graph of airports
 * Complexity: O(n), where n is the number of airports in the csv file
 * @param folder The folder where the CSV file is located.
 * @return Graph<Airport> The graph of airports.
 */
Graph<Airport> readAirports(std::string folder)
{
  // Inicialiate Graph
  Graph<Airport> airports = Graph<Airport>();

  // Open csv file
  std::ifstream file("../dataset/" + folder + "/airports.csv", ios::in);
  if (!file.is_open())
  {
    std::cout << "Error opening file" << std::endl;
    return airports;
  }

  // Read and ignore header line
  std::string line;
  if (!std::getline(file, line))
  {
    std::cout << "Error reading header line" << std::endl;
    file.close();
    return airports;
  }

  // Read each line and create an Airport object
  while (std::getline(file, line))
  {
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
    airportsHash.insert({code, airport});
    // airport.display();
    airports.addVertex(airport);
  }

  // Close file and return graph of airports
  file.close();
  return airports;
}

/**
 * @brief Function to read Flight data from CSV file and add edges to graph of airports
 * Complexity: O(n + v), where n is the number of airports and v is the number
 * of flights in the csv file
 * @param folder The folder where the CSV file is located.
 * @return Graph<Airport> The graph of airports with flights.
 */
Graph<Airport> readFlights(std::string folder)
{
  // Read airports
  Graph<Airport> airports = readAirports(folder);

  // Open csv file
  std::ifstream file("../dataset/" + folder + "/flights.csv", ios::in);
  if (!file.is_open())
  {
    std::cout << "Error opening flights file" << std::endl;
    return airports;
  }

  // Read and ignore header line
  std::string line;
  if (!std::getline(file, line))
  {
    std::cout << "Error reading flights header line" << std::endl;
    file.close();
    return airports;
  }

  // Read each line and add edges to graph
  while (std::getline(file, line))
  {
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

// Update later to tree hashtable
/**
 * @brief Function to read Airline data from CSV file and create a graph of airlines
 * Complexity: O(n), where n is the number of airlines in the CSV file.
 * @param folder The folder where the CSV file is located.
 * @return
 */
Graph<Airline> readAirlines(std::string folder)
{
  // Initialize Graph
  Graph<Airline> airlines = Graph<Airline>();

  // Open csv file
  std::ifstream file("../dataset/" + folder + "/airlines.csv", ios::in);
  if (!file.is_open())
  {
    std::cout << "Error opening file" << std::endl;
    return airlines;
  }

  // Read and ignore header line
  std::string line;
  if (!std::getline(file, line))
  {
    std::cout << "Error reading header line" << std::endl;
    file.close();
    return airlines;
  }

  // Read each line and create an Airline object
  while (std::getline(file, line))
  {
    std::istringstream iss(line);
    std::string code, name, callsign, country;

    std::getline(iss, code, ',');
    std::getline(iss, name, ',');
    std::getline(iss, callsign, ',');
    std::getline(iss, country, ',');

    Airline airline(code, name, callsign, country);
    // airline.display();
    airlines.addVertex(airline);
  }

  // Close file and return the graph of airlines
  file.close();
  return airlines;
}
