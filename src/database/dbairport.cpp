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
    std::vector<std::string> res;
    resetVisited(airports);

    auto s = airports.findVertex(Airport(airport));

    if (s == nullptr)
        return 0;

    Graph<Airport> g;

    res = dfsVisit(s, res);

    for (auto c : res)
    {
        countries.insert(c);
    }

    return countries.size();
}

std::vector<std::string> dfsVisit(Vertex<Airport> *v, std::vector<std::string> &res)
{

    v->setVisited(true);
    res.push_back(v->getInfo().getCountry());
    auto adjs = v->getAdj();

    for (auto &e : adjs)
    {
        auto w = e.getDest();

        if (!w->isVisited())
        {
            dfsVisit(w, res);
        }
    }

    return res;
}

int quantityCountryStop(Graph<Airport> airports, std::string airport, int stop)
{
    std::set<std::string> countries;
    std::vector<std::string> res;
    resetVisited(airports);

    auto s = airports.findVertex(Airport(airport));

    if (s == nullptr)
        return 0;

    res = dfsVisit(s, res, (stop + 1));

    for (auto c : res)
    {
        countries.insert(c);
    }

    return countries.size();
}

std::vector<std::string> dfsVisit(Vertex<Airport> *v, std::vector<std::string> &res, int stop)
{
    if (stop == 0)
        return res;

    // std::cout << "Saindo de " << v->getInfo().getCode() << std::endl;

    v->setVisited(true);
    res.push_back(v->getInfo().getCountry());
    auto adjs = v->getAdj();

    for (auto &e : adjs)
    {
        auto w = e.getDest();

        if (!w->isVisited())
        {
            // std::cout << "\t Eu vou para: " << w->getInfo().getCode() << std::endl;
            dfsVisit(w, res, (stop - 1));
        }
    }

    return res;
}

int maxFlight(Graph<Airport> airports)
{
    int max = 0;

    std::string src;
    std::string tgt;

    resetVisited(airports);
    for (auto v : airports.getVertexSet())
    {
        if (!v->isVisited())
        {
            vector<std::string> path;
            std::cout << "Visitando " << v->getInfo().getCode() << std::endl;
            int count = dfsCount(v, tgt, path);
            std::cout << "Count: " << count - 1 << std::endl;
            std::cout << "Target: " << tgt << std::endl;
            if (count > max)
            {
                src = v->getInfo().getCode();
                max = count;
            }
        }
    }

    return max - 1;
}

int dfsCount(Vertex<Airport> *v, std::string &tgt, vector<std::string> &path)
{
    int pathLen = 0;
    path.push_back(v->getInfo().getCode());
    v->setVisited(true);
    std::string lastNode;

    auto adjs = v->getAdj();

    for (auto &e : adjs)
    {
        auto w = e.getDest();

        if (!w->isVisited())
        {
            int childPathLen = dfsCount(w, tgt, path);
            if (childPathLen > pathLen)
            {
                pathLen = childPathLen;
            }
        }
    }

    path.pop_back();
    v->setVisited(false);

    if (path.size() > pathLen)
    {
        tgt = v->getInfo().getCode();
        return path.size();
    }

    else
        return pathLen;
}

void resetVisited(Graph<Airport> airports)
{
    for (auto v : airports.getVertexSet())
    {
        v->setVisited(false);
    }
}