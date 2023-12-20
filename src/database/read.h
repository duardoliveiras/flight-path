// read.h

#ifndef READ_H
#define READ_H

#include <fstream>
#include <sstream>
#include <iostream>
#include "../classes/Graph.h"
#include "../classes/Airport.h"

Graph<Airport> readAirports();
Graph<Airport> readFlights();

#endif // READ_H