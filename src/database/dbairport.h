#ifndef DBAIRPORT_H
#define DBAIRPORT_H

#include "../classes/Graph.h"
#include "../classes/Airport.h"
#include <set>

int quantityAirports(Graph<Airport> airports);
int quantityFlights(Graph<Airport> airports);
std::pair<int, int> quantityFlights(Graph<Airport> airports, std::string code);
int quantityFlightsCity(Graph<Airport> airports, std::string city);

#endif // DBAIRPORT_H