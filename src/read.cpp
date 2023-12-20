#include "read.h"
#include "Airport.h"
#include <filesystem>

Graph<Airport> createGraph()
{
    Graph<Airport> airports = Graph<Airport>();
    std::cout << "Diretório Atual: " << std::filesystem::current_path() << std::endl;
    std::ifstream file("../dataset/airports.csv", ios::in);

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
        std::getline(iss, country, ',');
        std::getline(iss, city, ',');
        iss >> latitude;
        iss >> longitude;

        Airport airport(code, name, country, city, latitude, longitude);
        airport.display();
        //  airports.addVertex(airport);
    }

    return airports;
}