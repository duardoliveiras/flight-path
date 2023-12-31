#include "dbairport.h"

//------------------------------------------------------------

/**
 * @brief Function to get quantity of airports in the graph
 * Complexity: O(1)
 * @param airports The graph of airports.
 * @return int The quantity of airports in the graph.
 */
int quantityAirports(Graph<Airport> airports)
{
    return airports.getNumVertex();
}

/**
 * @brief Function to get quantity of airports in the graph by country
 * Complexity: O(n), where n is the number of airports in the graph
 * @param airports The graph of airports.
 * @param country The country to be searched.
 * @return int The quantity of airports in the country.
 */
int quantityAirportsCountry(Graph<Airport> airports, std::string country)
{
    int count = 0;
    for (auto v : airports.getVertexSet())
    {
        Airport a = v->getInfo();
        if (a.getCountry() == country)
        {
            count++;
        }
    }
    return count;
}

/**
 * @brief Function to get quantity of airports in the graph by city
 * Complexity: O(n), where n is the number of airports in the graph
 * @param airports The graph of airports.
 * @param city The city to be searched.
 * @return int The quantity of airports in the city.
 */
int quantityAirportsCity(Graph<Airport> airports, std::string city)
{
    int count = 0;
    for (auto v : airports.getVertexSet())
    {
        Airport a = v->getInfo();
        if (a.getCity() == city)
        {
            count++;
        }
    }
    return count;
}

//------------------------------------------------------------

/**
 * @brief Function to get quantity of unique countries in the graph
 * Complexity: O(n + m), where n is the number of airports, m is the number of
 * airlines
 * @param airports The graph of airports.
 * @param airlines The graph of airlines.
 * @return int The quantity of unique countries in the graph.
 */
int quantityCountries(Graph<Airport> airports, Graph<Airline> airlines)
{
    std::unordered_set<std::string> uniqueCountries;
    for (auto v : airports.getVertexSet())
    {
        Airport a = v->getInfo();
        std::string country = a.getCountry();
        uniqueCountries.insert(country);
    }
    for (auto v : airlines.getVertexSet())
    {
        Airline a = v->getInfo();
        std::string country = a.getCountry();
        uniqueCountries.insert(country);
    }
    return uniqueCountries.size();
}

//------------------------------------------------------------

/**
 * @brief Function to count the number of unique cities in the graph
 * Complexity: O(n), where n is the number of airports in the graph
 * @param airports The graph of airports.
 * @return int The quantity of unique cities in the graph.
 */
int quantityCities(Graph<Airport> airports)
{
    std::unordered_set<std::string> uniqueCities;
    for (auto v : airports.getVertexSet())
    {
        Airport a = v->getInfo();
        std::string city = a.getCity();
        uniqueCities.insert(city);
    }
    return uniqueCities.size();
}

/**
 * @brief Function to count the number of unique cities in the graph for a given country
 * Complexity: O(n), where n is the number of airports in the graph
 * @param airports The graph of airports.
 * @param country The country to be searched.
 * @return int The quantity of unique cities in the country.
 */
int quantityCitiesCountry(Graph<Airport> airports, std::string country)
{
    std::unordered_set<std::string> uniqueCities;
    for (auto v : airports.getVertexSet())
    {
        Airport a = v->getInfo();
        if (a.getCountry() == country)
        {
            std::string city = a.getCity();
            uniqueCities.insert(city);
        }
    }
    return uniqueCities.size();
}

//------------------------------------------------------------

// Update later to tree hashtable
/**
 * @brief Function to calculate the quantity of airlines in the graph
 * Complexity: O(1)
 * @param airlines The graph of airlines.
 * @return int The quantity of airlines in the graph.
 */
int quantityAirlines(Graph<Airline> airlines)
{
    return airlines.getNumVertex();
}

/**
 * @brief Function to calculate the quantity of airlines for a given country
 * Complexity: O(n), where n is the number of airlines in the graph
 * @param airlines The graph of airlines.
 * @param country The country to be searched.
 * @return int The quantity of airlines in the country.
 */
int quantityAirlinesCountry(Graph<Airline> airlines, std::string country)
{
    int count = 0;
    for (auto v : airlines.getVertexSet())
    {
        Airline a = v->getInfo();
        if (a.getCountry() == country)
        {
            count++;
        }
    }
    return count;
}

//------------------------------------------------------------

/**
 * @brief Function to calculate the quatity of flights in the graph
 * Complexity: O(n),  where n is the number of airports in the graph
 * @param airports The graph of airports.
 * @return int The quantity of flights (edges) in the graph.
 */
int quantityFlights(Graph<Airport> airports)
{
    int count = 0;
    for (auto v : airports.getVertexSet())
    {
        count += v->getAdj().size();
    }
    return count;
}

/**
 * @brief Function to calculate the quatity of flights in a given airport
 * Complexity: O(n),  where n is the number of airports in the graph
 * @param airports The graph of airports.
 * @param airport The airport to be searched.
 * @return int The quantity of flights (edges) in the airport.
 */
int quantityFlightsAirport(Graph<Airport> airports, std::string airport)
{
    int count = 0;
    for (auto v : airports.getVertexSet())
    {
        if (v->getInfo().getCode() == airport)
        {
            count += v->getAdj().size();
        }
    }
    return count;
}

/**
 * @brief Function to calculate the quatity of flights in a given country
 * Complexity: O(n),  where n is the number of airports in the graph
 * @param airports The graph of airports.
 * @param country The country to be searched.
 * @return int The quantity of flights (edges) in the country.
 */
int quantityFlightsCountry(Graph<Airport> airports, std::string country)
{
    int count = 0;
    for (auto v : airports.getVertexSet())
    {
        if (v->getInfo().getCountry() == country)
        {
            count += v->getAdj().size();
        }
    }
    return count;
}

// Update later need country too cause have cities with same name
/**
 * @brief Function to calculate the quatity of flights in a given city
 * Complexity: O(n),  where n is the number of airports in the graph
 * @param airports The graph of airports.
 * @param city The city to be searched.
 * @return int The quantity of flights (edges) in the city.
 */
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

/**
 * @brief Function to calculate the quatity of flights in a given airline
 * Complexity: O(n + e),  where n is the number of airports in the graph and e
 * is the number of flights
 * @param airports The graph of airports.
 * @param airline The airline to be searched.
 * @return int The quantity of flights (edges) in the airline.
 */
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

//------------------------------------------------------------

// Update later the objective is to find many destinations is possible starting from a coutry
/**
 * @brief Function to calculate the quatity of flights in a given country
 * Complexity: O(n + e),  where n is the number of airports in the graph and e is the number of flights
 * @param airports The graph of airports.
 * @param airline The airline to be searched.
 * @return int The quantity of flights in same country.
 */
int quantityDestinationsCountry(Graph<Airport> airports, std::string country)
{
    int totalFlights = 0;
    for (auto v : airports.getVertexSet())
    {
        Airport sourceAirport = v->getInfo();
        if (sourceAirport.getCountry() == country)
        {
            for (auto &edge : v->getAdj())
            {
                Airport destinationAirport = edge.getDest()->getInfo();
                if (destinationAirport.getCountry() == country)
                {
                    totalFlights++;
                }
            }
        }
    }
    return totalFlights;
}

/**
 * @brief Function to calculate the number of different countries it is possible to go directly to from an airport
 * Complexity: O(n + e),  where n is the number of airports in the graph and e is the number of flights
 * @param airports The graph of airports.
 * @param airport The airport to be searched.
 * @return int The quantity of countries.
 */
int quantityDestinationsAirport(Graph<Airport> airports, std::string airport)
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

/**
 * @brief Function to calculate the number of different countries it is possible to go to from an airport with a given number of stops
 * Complexity: O(n + e),  where n is the number of airports in the graph and e is the number of flights
 * @param airports The graph of airports.
 * @param airport The airport to be searched.
 * @param stop The number of stops.
 * @return int The quantity of countries.
 */
int quantityDestinationLimitedStop(Graph<Airport> airports, std::string airport,
                                   int stop)
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

/**
 * @brief Function that calculates the maximum possible trip, with the greatest number of stops
 * and print the starting airport and the destination airport
 * Complexity: O(n * (n + e)),  where n is the number of airports in the graph and e is the number of flights
 * @param airports The graph of airports.
 * @return int The number of stops on the longest trip
 */
int quantityDestinationMax(Graph<Airport> airports)
{
    vector<string> path, maxPath;

    for (auto v : airports.getVertexSet())
    {
        // std::cout << "Consultando... " << v->getInfo().getCode() << std::endl;
        resetVisited(airports);
        path.clear();
        dfsMax(v, path, maxPath);
    }

    std::cout << "\nStarting in: " << maxPath[0] << std::endl;
    for (int i = 0; i < maxPath.size() - 1; i++)
    {
        std::cout << maxPath[i] << " -> ";
    }
    std::cout << "Ending in: " << maxPath[maxPath.size() - 1] << std::endl;
    return maxPath.size() - 1;
}

/**
 * @brief Function that performs a depth-first search and always updates the longest path
 * @param v The vertex to start the search
 * @param path The current path
 * @param maxPath The longest path
 * @return void
 */
void dfsMax(Vertex<Airport> *v, std::vector<std::string> &path, std::vector<std::string> &maxPath)
{
    v->setVisited(true);
    path.push_back(v->getInfo().getCode());
    auto adjs = v->getAdj();

    if (path.size() > maxPath.size())
    {
        maxPath = path;
    }

    for (auto &e : adjs)
    {
        auto w = e.getDest();

        if (!w->isVisited())
        {
            dfsMax(w, path, maxPath);
        }
    }
    path.pop_back();
}

//------------------------------------------------------------
//------------------------------------------------------------
//------------------------------------------------------------

/**
 * @brief Function to sort the vector with the best flights in increasing order by the number of stops.
 * @param a The first vector.
 * @param b The second vector.
 * @return bool True if the first vector is smaller than the second vector.
 */
bool comparatorPath(const vector<Flight> a, const vector<Flight> b)
{
    return a.size() < b.size();
}

/**
 * @brief Function to get quantity of flights in the graph and unique airlines for an Airport
 * Complexity: O(n), where n is the number of flights in the graph
 * @param airports The graph of airports.
 * @param code The airport to be searched.
 * @return pair<int, int> The quantity of flights and unique airlines.
 */
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

/**
 * @brief Search (depth-first) to visit vertices and collect connected countries
 * @param airports The graph of airports.
 * @param v The vertex to start the search
 * @return vector<string> The vector with the countries.
 */
std::vector<std::string> dfsVisit(Vertex<Airport> *v,
                                  std::vector<std::string> &res)
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

/**
 * @brief Search (depth-first) to visit vertices and collect connected countries
 * withing a number of stops
 * @param airports The graph of airports.
 * @param v The vertex to start the search
 * @param stop The number of stops.
 * @return vector<string> The vector with the countries.
 */
std::vector<std::string> dfsVisit(Vertex<Airport> *v,
                                  std::vector<std::string> &res, int stop)
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
            // std::cout << "\t Eu vou para: " << w->getInfo().getCode() <<
            // std::endl;
            dfsVisit(w, res, (stop - 1));
        }
    }
    return res;
}

/**
 * @brief Function to reset the visited status of all vertices in the graph
 * Complexity: O(n), where n is the number of airports in the graph
 * @param airports The graph of airports.
 * @return void
 */
void resetVisited(Graph<Airport> &airports)
{
    for (auto v : airports.getVertexSet())
    {
        v->setVisited(false);
    }
}

/**
 * @brief Function to calculate the in-degreee of each vertex in the graph
 * Complexity: O(n + e), where n is the number of airports and e is the number
 * of flights in the graph
 * @param airports The graph of airports.
 * @return void
 */
void calculateIndegree(Graph<Airport> &airports)
{
    for (auto v : airports.getVertexSet())
    {
        v->setIndegree(0);
    }
    for (auto v : airports.getVertexSet())
    {
        for (auto e : v->getAdj())
        {
            e.getDest()->setIndegree(e.getDest()->getIndegree() + 1);
        }
    }
}

/**
 * @brief Function to rank airport based of the sum of in-degrees and out-degrees
 * Complexity: O(n * log(n) + n * e), where n is the number of airports and e
 * is the number of flights in the graph (assuming sorting has a time
 * complexity of O(n * log(n)))
 * @param airports The graph of airports.
 * @param arg The number of airports to be shown.
 * @return void
 */
void rankingAirports(Graph<Airport> airports, int arg)
{
    std::vector<Ranking> vec;
    calculateIndegree(airports);

    for (auto v : airports.getVertexSet())
    {
        int total = v->getIndegree() + v->getAdj().size();
        Ranking rank = {v->getInfo().getCode(), total};
        vec.push_back(rank);
    }
    std::sort(vec.begin(), vec.end(), comparator);
    int i = 0;
    for (auto v : vec)
    {
        if (i < arg)
        {
            std::cout << "Code: " << v.code << " / ";
            std::cout << "Total: " << v.count << std::endl;
            i++;
        }
    }
}

// Function to find the best flights from a source airport to a destination
// airport Airport to Airport
// Complexity: O(n + e), where n is the number of airports and e is the
// number of flights in the graph
void findBestFlights(Graph<Airport> &airports, string src, string dest,
                     vector<string> &airplanes)
{
    resetVisited(airports);

    auto s = airports.findVertex(Airport(src));
    auto d = airports.findVertex(Airport(dest));

    if (s == nullptr || d == nullptr)
        return;

    vector<vector<Flight>> paths;
    paths = bfsPath(s, dest, airplanes);
    showPath(paths);
}

/**
 * @brief Finds the best flights between a city and an aiport (vice-verse)
 * This function uses breadth-first search (BFS) to find paths between a source and destination airport
 * Complexity: O(n + e), where n is the number of airports and e is the number of flights in the graph
 * @param airports The graph representing airports and available flights.
 * @param country The country of the source airport.
 * @param city The city of the source airport.
 * @param airport The destination airport.
 * @param type The type of search (0: City to Airport, 1: Airport to City).
 * @param airplanes A vector of strings representing allowed aircraft (can be empty to consider all).
 * @return void
 */
void findBestFlights(Graph<Airport> &airports, string country, string city,
                     string airport, int type, vector<string> &airplanes)
{
    vector<Vertex<Airport> *> vec;
    vector<vector<Flight>> paths;
    vec = findAirports(airports, country, city);

    if (type == 0)
    {
        for (auto v : vec)
        {
            // std::cout << "Source: " << v->getInfo().getCode() << std::endl;
            resetVisited(airports);
            paths = bfsPath(v, airport, airplanes);
            showPath(paths);
        }
    }
    else if (type == 1)
    {
        for (auto v : vec)
        {
            // std::cout << "Source: " << airport << std::endl;
            std::string tgt = v->getInfo().getCode();
            resetVisited(airports);
            paths = bfsPath(airports.findVertex(Airport(airport)), tgt, airplanes);
            showPath(paths);
        }
    }
}

/**
 * @brief Function to show a multi-path between multiple source and destination airports
 * Complexity: O(n + e), where n is the number of airports and e is the
 * number of flights in the graph
 * @param airports The graph representing airports and available flights.
 * @param source A vector of source airports.
 * @param dest A vector of destination airports.
 * @param paths A vector of vectors of flights representing the paths.
 * @param airplanes A vector of strings representing allowed aircraft (can be empty to consider all).
 * @return void
 */
void showPath(Graph<Airport> &airports, vector<Vertex<Airport> *> source,
              vector<Vertex<Airport> *> dest, vector<vector<Flight>> paths,
              vector<string> &airplanes)
{

    vector<vector<Flight>> flights;

    for (auto s : source)
    {
        // std::cout << "Source: " << s->getInfo().getCode() << std::endl;
        for (auto d : dest)
        {
            // std::cout << "Destination: " << d->getInfo().getCode() <<
            // std::endl;
            std::string tgt = d->getInfo().getCode();
            resetVisited(airports);
            flights = bfsPath(s, tgt, airplanes);
            paths.insert(paths.end(), flights.begin(), flights.end());
        }
    }

    if (paths.empty())
    {
        std::cout << "--------------------------------------------------"
                  << std::endl;
        std::cout << "Sorry, but there is no result with those inputs."
                  << std::endl;
        return;
    }
    else
    {

        std::sort(paths.begin(), paths.end(), comparatorPath);
        const int min = paths[0].size();

        for (auto &p : paths)
        {
            if (p.size() > min)
            {
                continue;
            }
            std::cout << "-------------------------------------------------"
                      << std::endl;
            for (auto &f : p)
            {
                if (!f.airline.empty())
                {
                    std::cout << f.code << " -(" << f.airline << ")"
                              << "-> ";
                }
                else
                {
                    std::cout << f.code;
                }
            }
            std::cout << std::endl;
        }
    }
}

// Function to show a set of paths
// Complexity: O(n), where n is the total number of flights in all paths

/**
 * @brief Function to show a set of paths
 * Complexity: O(n), where n is the total number of flights in all paths
 * @param paths A vector of vectors of flights representing the paths.
 * @return void
 */
void showPath(vector<vector<Flight>> paths)
{
    if (paths.empty())
    {
        std::cout << "--------------------------------------------------"
                  << std::endl;
        std::cout << "Sorry, but there is no result with those inputs."
                  << std::endl;
        return;
    }

    for (auto path : paths)
    {
        std::cout << "-------------------------------------------------"
                  << std::endl;
        for (auto p : path)
        {
            if (!p.airline.empty())
            {
                std::cout << p.code << " -(" << p.airline << ")"
                          << "-> ";
            }
            else
            {
                std::cout << p.code;
            }
        }
        std::cout << std::endl;
    }
}

/**
 * @brief Function to find all airports in a city
 * Complexity: O(n), where n is the number of airports in the graph
 * @param airports The graph representing airports and available flights.
 * @param country The country of the airport.
 * @param city The city of the airport.
 * @return vector<Vertex<Airport>*> A vector of airports.
 */
vector<Vertex<Airport> *> findAirports(Graph<Airport> &airports, string country,
                                       string city)
{
    vector<Vertex<Airport> *> vec;
    for (auto v : airports.getVertexSet())
    {
        if (v->getInfo().getCountry() == country &&
            v->getInfo().getCity() == city)
        {
            vec.push_back(v);
        }
    }
    return vec;
}

/**
 * @brief Function to find best flights between two cities
 * This function uses breadth-first search (BFS) to find paths between a source and destination airport
 * Complexity: O(n + e), where n is the number of airports and e is the number of flights in the graph.
 * @param airports The graph representing airports and available flights.
 * @param countrySrc The country of the source airport.
 * @param citySrc The city of the source airport.
 * @param countryDest The country of the destination airport.
 * @param cityDest The city of the destination airport.
 * @param airplanes A vector of strings representing allowed aircraft (can be empty to consider all).
 * @return void
 */
void findBestFlights(Graph<Airport> &airports, string countrySrc,
                     string citySrc, string countryDest, string cityDest,
                     vector<string> &airplanes)
{
    vector<Vertex<Airport> *> src;
    vector<Vertex<Airport> *> dest;
    vector<vector<Flight>> paths;

    src = findAirports(airports, countrySrc, citySrc);
    dest = findAirports(airports, countryDest, cityDest);

    showPath(airports, src, dest, paths, airplanes);
}

/**
 * @brief Function to convert Degrees in radians
 * Complexity: O(1)
 * @param degree The degree to be converted.
 * @return double The converted degree.
 */
double toRadians(const double degree) { return (degree * M_PI / 180); }

//-23.477461, -46.548338 Anywhere in Sao Paulo
//-23.432075, -46.469511 Garulhos GRU 10km

// 28.160090, -17.240129 Anywhere in La Gomera
// 28.029600, -17.214600 GMZ 30km

/**
 * @brief Function to calculate the distance between two points on the Earth
 * Complexity: O(1)
 * @param latOrigin The latitude of the origin point.
 * @param longOrigin The longitude of the origin point.
 * @param latDest The latitude of the destination point.
 * @param longDest The longitude of the destination point.
 * @return double The distance between the two points.
 */
double distanceEarth(double latOrigin, double longOrigin, double latDest,
                     double longDest)
{
    latOrigin = toRadians(latOrigin);
    longOrigin = toRadians(longOrigin);
    latDest = toRadians(latDest);
    longDest = toRadians(longDest);

    double dlong = longDest - longOrigin;
    double dlat = latDest - latOrigin;

    double ans = pow(sin(dlat / 2), 2) +
                 cos(latOrigin) * cos(latDest) * pow(sin(dlong / 2), 2);

    ans = 2 * asin(sqrt(ans));

    double R = 6371;

    ans = ans * R;

    return ans;
}

// Function to find all airports around a point withing a distance
// Complexity: O(n), where n is the number of airports in the graph

/**
 * @brief Function to find all airports around a point withing a distance
 * Complexity: O(n), where n is the number of airports in the graph
 * @param airports The graph representing airports and available flights.
 * @param lat The latitude of the point.
 * @param lon The longitude of the point.
 * @param distMax The maximum distance.
 * @return vector<Vertex<Airport>*> A vector of airports.
 */
vector<Vertex<Airport> *> findAirports(Graph<Airport> &airports, double lat,
                                       double lon, int distMax)
{
    vector<Vertex<Airport> *> vec;
    for (auto v : airports.getVertexSet())
    {
        double lat2 = v->getInfo().getLatitude();
        double lon2 = v->getInfo().getLongitude();

        double dist = distanceEarth(lat, lon, lat2, lon2);

        if (dist <= distMax)
        {
            vec.push_back(v);
        }
    }
    return vec;
}

/**
 * @brief Function to find the best flights between two points on Earth Point to Point
 * This function uses breadth-first search (BFS) to find paths between a source and destination airport
 * Complexity: O(n + e), where n is the number of airports and e is the number of flights in the graph
 * @param airports The graph representing airports and available flights.
 * @param latOrigin The latitude of the origin point.
 * @param longOrigin The longitude of the origin point.
 * @param latDest The latitude of the destination point.
 * @param longDest The longitude of the destination point.
 * @param distMax The maximum distance.
 * @param airplanes A vector of strings representing allowed aircraft (can be empty to consider all).
 * @return void
 */
void findBestFlights(Graph<Airport> &airports, double latOrigin,
                     double longOrigin, double latDest, double longDest,
                     int distMax, vector<string> &airplanes)
{
    vector<Vertex<Airport> *> src =
        findAirports(airports, latOrigin, longOrigin, distMax);
    vector<Vertex<Airport> *> dest =
        findAirports(airports, latDest, longDest, distMax);
    vector<vector<Flight>> paths;

    showPath(airports, src, dest, paths, airplanes);
}

/**
 * @brief Function to find best flights between an airport and a point on Earth
 * This function uses breadth-first search (BFS) to find paths between a source and destination airport
 * Complexity: O(p*(n + e)), where n is the number of airports, e is the number of flights in the graph and p is the number of source and destination airports
 * @param airports The graph representing airports and available flights.
 * @param airport The airport.
 * @param lat The latitude of the point.
 * @param lon The longitude of the point.
 * @param distMax The maximum distance.
 * @param type The type of search (0: Point to Airport, 1: Airport to Point).
 * @param airplanes A vector of strings representing allowed aircraft (can be empty to consider all).
 * @return void
 */
void findBestFlights(Graph<Airport> &airports, string airport, double lat,
                     double lon, int distMax, int type,
                     vector<string> &airplanes)
{
    vector<Vertex<Airport> *> vec;
    vector<vector<Flight>> paths;
    vec = findAirports(airports, lat, lon, distMax);

    if (type == 0)
    {
        for (auto v : vec)
        {
            std::cout << "Source: " << v->getInfo().getCode() << std::endl;
            resetVisited(airports);
            paths = bfsPath(v, airport, airplanes);
            showPath(paths);
        }
    }
    else if (type == 1)
    {
        for (auto v : vec)
        {
            std::cout << "Source: " << airport << std::endl;
            std::string tgt = v->getInfo().getCode();
            resetVisited(airports);
            paths = bfsPath(airports.findVertex(Airport(airport)), tgt, airplanes);
            showPath(paths);
        }
    }
}

// Function to find best flights between a city and a point on the Earth
// type = 0: City to Point, type = 1: Point to City
// Complexity: O(n^2 + n * e), where n is the number of airports and e is
// the number of flights in the graph

/**
 * @brief Function to find best flights between a city and a point on the Earth
 * This function uses breadth-first search (BFS) to find paths between a source and destination airport
 * Complexity: O(p*(n + e)), where n is the number of airports, e is the number of flights in the graph and p is the number of source and destination airports
 * @param airports The graph representing airports and available flights.
 * @param country The country of the source airport.
 * @param city The city of the source airport.
 * @param lat The latitude of the point.
 * @param lon The longitude of the point.
 * @param distMax The maximum distance.
 * @param type The type of search (0: City to Point, 1: Point to City).
 * @param airplanes A vector of strings representing allowed aircraft (can be empty to consider all).
 * @return void
 */
void findBestFlights(Graph<Airport> &airports, string country, string city,
                     double lat, double lon, int distMax, int type,
                     vector<string> &airplanes)
{
    vector<Vertex<Airport> *> vec_point;
    vector<Vertex<Airport> *> vec_city;
    vector<vector<Flight>> paths;

    vec_point = findAirports(airports, lat, lon, distMax);
    vec_city = findAirports(airports, country, city);

    if (type == 0)
    {
        for (auto c : vec_city)
        {
            std::cout << "Source: " << c->getInfo().getCode() << std::endl;
            for (auto p : vec_point)
            {
                std::cout << "Destination: " << p->getInfo().getCode() << std::endl;
                resetVisited(airports);
                std::string tgt = p->getInfo().getCode();
                paths = bfsPath(c, tgt, airplanes);
                showPath(paths);
            }
        }
    }
    else if (type == 1)
    {
        for (auto p : vec_point)
        {
            std::cout << "Source: " << p->getInfo().getCode() << std::endl;
            for (auto c : vec_city)
            {
                std::cout << "Destination: " << c->getInfo().getCode() << std::endl;
                resetVisited(airports);
                std::string tgt = c->getInfo().getCode();
                paths = bfsPath(p, tgt, airplanes);
                showPath(paths);
            }
        }
    }
}

/**
 * @brief Function to find a path from the current airport to start airport
 * Complexity: O(n), where n is the number of airports in the graph
 * @param current The current airport.
 * @param path The current path.
 * @param prev A map with the previous airports.
 * @param paths A vector of vectors of flights representing the paths.
 * @param startCode The code of the start airport.
 * @param airline The airline of the flight.
 * @return void
 */
void getPath(string current, vector<Flight> &path,
             unordered_map<string, vector<Flight>> &prev,
             vector<vector<Flight>> &paths, string startCode, string airline)
{
    path.push_back({current, airline});

    if (current == startCode)
    {
        vector<Flight> validPath = path;
        reverse(validPath.begin(), validPath.end());
        paths.push_back(validPath);
    }
    else
    {
        for (auto &prevVertex : prev[current])
        {
            getPath(prevVertex.code, path, prev, paths, startCode,
                    prevVertex.airline);
        }
    }

    path.pop_back();
}

/**
 * @brief Function to perfom breadth-first search to find paths between two airport
 * Complexity: O(n + e), where n is the number of airports and e is the number of flights in the graph
 * @param v The vertex to start the search
 * @param tgt The target airport.
 * @param airplanes A vector of strings representing allowed aircraft (can be empty to consider all).
 * @return vector<vector<Flight>> A vector of vectors of flights representing the paths.
 */
vector<vector<Flight>> bfsPath(Vertex<Airport> *v, string &tgt,
                               vector<string> &airplanes)
{
    vector<vector<Flight>> paths;
    unordered_map<string, vector<Flight>> prev;
    unordered_map<string, int> dist;
    queue<Vertex<Airport> *> q;

    q.push(v);
    v->setVisited(true);
    dist[v->getInfo().getCode()] = 0;

    while (!q.empty())
    {
        auto vertex = q.front();
        q.pop();
        auto adjs = vertex->getAdj();

        for (auto &e : adjs)
        {
            auto w = e.getDest();
            if (!w->isVisited() && (find(airplanes.begin(), airplanes.end(),
                                         e.getRoute()) != airplanes.end() ||
                                    airplanes.size() == 0))
            {
                q.push(w);
                w->setVisited(true);
                prev[w->getInfo().getCode()].push_back(
                    {vertex->getInfo().getCode(), e.getRoute()});
                dist[w->getInfo().getCode()] = dist[vertex->getInfo().getCode()] + 1;
            }
            else if (dist[w->getInfo().getCode()] ==
                         dist[vertex->getInfo().getCode()] + 1 &&
                     (find(airplanes.begin(), airplanes.end(), e.getRoute()) !=
                          airplanes.end() ||
                      airplanes.size() == 0))
            {
                prev[w->getInfo().getCode()].push_back(
                    {vertex->getInfo().getCode(), e.getRoute()});
            }
        }
    }

    vector<Flight> path;
    getPath(tgt, path, prev, paths, v->getInfo().getCode(), "");

    return paths;
}

/**
 * @brief Function that uses a depth-first search to find the number of connected components in a graph.
 * Complexity: O(n + e), where n is the number of airports and e is the number of flights in the graph
 * @param airports The graph representing airports and available flights.
 * @return int The number of connected components.
 */
int connectedComponents(Graph<Airport> &airports)
{
    int component = 0;
    resetVisited(airports);
    Graph<Airport> g = airports;

    for (auto v : g.getVertexSet())
    {
        if (!v->isVisited())
        {
            dfsConnectedComponents(g, v);
            component++;
        }
    }
    // std::cout << "Number of connected components: " << component <<
    // std::endl;
    return component;
}

/**
 * @brief Function DFS starting from a vertex to find connected components
 * Complexity: O(n + e), where n is the number of airports and e is the number of flights in the graph
 * @param airports The graph representing airports and available flights.
 * @param v The vertex to start the search
 * @return void
 */
void dfsConnectedComponents(Graph<Airport> &airports, Vertex<Airport> *v)
{
    v->setVisited(true);
    auto adjs = v->getAdj();

    for (auto &e : adjs)
    {
        auto w = e.getDest();
        if (!w->isVisited())
        {
            dfsConnectedComponents(airports, w);
        }
    }
}

/**
 * @brief Function to find and show articulation points in the graph. Points (airports) that, if removed, make certain regions of the map inaccessible
 * Complexity: O(n^2), where n is the number of airports in the graph
 * @param airports The graph representing airports and available flights.
 * @return void
 */
void findArticulationPoints(Graph<Airport> &airports)
{

    int connected = connectedComponents(airports);
    for (auto v : airports.getVertexSet())
    {
        // std::cout << " Analisando o vertice: " << v->getInfo().getCode() <<
        // std::endl;
        resetVisited(airports);
        int component = 0;
        for (auto w : airports.getVertexSet())
        {
            // std::cout << "\tAnalisando o vertice: " << w->getInfo().getCode()<<
            // std::endl;
            if (!w->isVisited() && w->getInfo().getCode() != v->getInfo().getCode())
            {
                // std::cout << "\t\tChamando o DFS component++" << std::endl;
                dfsArtc(v, w);
                component++;
            }
        }
        if (component > connected)
        {
            std::cout << v->getInfo().getCode() << std::endl;
        }
    }
}

/**
 * @brief Function DFS modified to find articulation points
 * @param v The vertex to start the search
 * @param w The vertex to be visited
 * @return void
 */
void dfsArtc(Vertex<Airport> *v, Vertex<Airport> *w)
{
    w->setVisited(true);
    auto adjs = w->getAdj();

    for (auto &e : adjs)
    {
        auto t = e.getDest();
        if (!t->isVisited() && t->getInfo().getCode() != v->getInfo().getCode())
        {
            dfsArtc(v, t);
        }
    }
}
