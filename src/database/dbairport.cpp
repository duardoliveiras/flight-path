#include "dbairport.h"

int quantityAirports(Graph<Airport> airports)
{
    return airports.getVertexSet().size();
}