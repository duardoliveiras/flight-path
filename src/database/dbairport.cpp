#include "dbairport.h"

int quantityAirports(Graph<Airport> airports)
{
    return airports.getVertexSet().size();
}

int quantityFlights(Graph<Airport> airports)
{
    int count = 0;
    for (auto v : airports.getVertexSet())
    {
        count += v->getAdj().size();
    }
    return count;
}

std::pair<int, int> quantityFlights(Graph<Airport> airports, std::string code)
{
    int count = 0;
    std::set<std::string> airlines;

    auto s = airports.findVertex(Airport(code));
    if (s != nullptr)
    {
        for (auto v : s->getAdj())
        {
            count++;
            airlines.insert(v.getRoute());
        }
    }
    return std::pair<int, int>(count, airlines.size());
}

int quantityFlightsCity(Graph<Airport> airports, std::string city)
{

    int count = 0;
    for (auto v : airports.getVertexSet())
    {
        if (v->getInfo().getCity() == city)
        {
            count += v->getAdj().size();
        }
    }
    return count;
}

int quantityFlightsAirline(Graph<Airport> airports, std::string airline)
{
    int count = 0;

    for (auto v : airports.getVertexSet())
    {
        for (auto e : v->getAdj())
        {
            if (e.getRoute() == airline)
            {
                count++;
            }
        }
    }

    return count;
}

int quantityCountry(Graph<Airport> airports, std::string airport)
{
    std::set<std::string> countries;

    for (auto v : airports.getVertexSet())
    {
        if (v->getInfo().getCode() == airport)
        {
            for (auto e : v->getAdj())
            {
                countries.insert(e.getDest()->getInfo().getCountry());
            }
        }
    }

    return countries.size();
}