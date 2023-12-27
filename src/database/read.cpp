#include "read.h"
#include "../classes/Airport.h"
#include <filesystem>

Graph<Airport> readAirports(std::string folder)
{
    Graph<Airport> airports = Graph<Airport>();
    // std::cout << "PWD " << std::filesystem::current_path() << std::endl;
    std::ifstream file("../dataset/" + folder + "/airports.csv", ios::in);

    if (!file.is_open())
    {
        std::cout << "Error opening file" << std::endl;
        return airports;
    }

    std::string line;
    std::getline(file, line);

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
        // airport.display();
        airports.addVertex(airport);
    }

    return airports;
}

Graph<Airport> readFlights(std::string folder)
{
    Graph<Airport> airports = readAirports(folder);
    std::ifstream file("../dataset/" + folder + "/flights.csv", ios::in);

    if (!file.is_open())
    {
        std::cout << "Error opening file" << std::endl;
        return airports;
    }

    std::string line;
    std::getline(file, line);

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

    return airports;
}