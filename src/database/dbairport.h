#ifndef DBAIRPORT_H
#define DBAIRPORT_H

#include "../classes/Graph.h"
#include "../classes/Airport.h"
#include <set>

int quantityAirports(Graph<Airport> airports);
int quantityFlights(Graph<Airport> airports);
std::pair<int, int> quantityFlights(Graph<Airport> airports, std::string code);
int quantityFlightsCity(Graph<Airport> airports, std::string city);
int quantityFlightsAirline(Graph<Airport> airports, std::string airline);
int quantityCountry(Graph<Airport> airports, std::string airport);
int quantityCountryStop(Graph<Airport> airports, std::string airport, int stop);
std::vector<std::string> dfsVisit(Vertex<Airport> *v, std::vector<std::string> &res);
std::vector<std::string> dfsVisit(Vertex<Airport> *v, std::vector<std::string> &res, int stop);
void resetVisited(Graph<Airport> airports);

#endif // DBAIRPORT_H