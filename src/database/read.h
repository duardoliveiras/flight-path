// read.h

#ifndef READ_H
#define READ_H

#include "../classes/Airport.h"
#include "../classes/Graph.h"
#include <fstream>
#include <iostream>
#include <sstream>

Graph<Airport> readAirports(std::string folder);
Graph<Airport> readFlights(std::string folder);

#endif // READ_H
