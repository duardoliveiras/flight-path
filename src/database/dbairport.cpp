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
    std::cout << "Consultando... " << std::endl;
    for (auto v : airports.getVertexSet())
    {
        if (!v->isVisited())
        {
            vector<std::string> path;

            int count = dfsCount(v, tgt, path);
            if (count > max)
            {
                src = v->getInfo().getCode();
                max = count;
            }
            resetVisited(airports);
        }
    }
    std::cout << "\nLeaving from:" << src << std::endl;
    std::cout << "To: " << tgt << std::endl;

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
    // v->setVisited(false);

    if (path.size() > pathLen)
    {
        tgt = v->getInfo().getCode();
        return path.size();
    }

    else
        return pathLen;
}

void resetVisited(Graph<Airport> &airports)
{
    for (auto v : airports.getVertexSet())
    {
        v->setVisited(false);
    }
}

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

void getArticulations(Graph<Airport> airports)
{
    unordered_set<string> res;
    unordered_set<string> visited;
    std::stack<string> s;
    int i = 1;

    resetVisited(airports);

    for (auto v : airports.getVertexSet())
    {
        dfsArticulations(airports, v, res, s, i);
    }

    for (auto &e : res)
    {
        std::cout << e << std::endl;
    }
}

void dfsArticulations(Graph<Airport> &airports, Vertex<Airport> *v, unordered_set<string> &res, std::stack<string> &s, int i)
{

    v->setLow(i);
    v->setNum(i);
    v->setVisited(true);
    v->setProcessing(true);
    s.push(v->getInfo().getCode());
    std::cout << "Visiting vertex: " << v->getInfo().getCode() << " Low: " << v->getLow() << " Num: " << v->getNum() << std::endl;
    i++;

    auto adjs = v->getAdj();
    int component = 0;
    for (auto &e : adjs)
    {
        component++;
        auto w = e.getDest();
        if (!w->isVisited())
        {
            dfsArticulations(airports, w, res, s, i);
            v->setLow(min(v->getLow(), w->getLow()));
            if (w->getLow() >= v->getNum() && component > 1)
            {
                std::cout << "Inserting articulation point: " << v->getInfo().getCode() << " Component: " << component << " - " << v->getAdj().size() << std::endl;
                res.insert(v->getInfo().getCode());
            }
        }
        else if (w->isProcessing())
        {
            v->setLow(min(v->getLow(), w->getNum()));
        }
    }

    if (v->getLow() == v->getNum())
    {
        while (s.top() != v->getInfo().getCode())
        {
            auto vertex = airports.findVertex(Airport(s.top()));
            vertex->setProcessing(false);
            s.pop();
        }
        v->setProcessing(false);
        s.pop();
    }
}

// Airport to Airport
void findBestFlights(Graph<Airport> &airports, string src, string dest, vector<string> &airplanes)
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

// City - Airport
// type = 0. City to Airport
// type = 1. Airport to City
void findBestFlights(Graph<Airport> &airports, string country, string city, string airport, int type, vector<string> &airplanes)
{
    vector<Vertex<Airport> *> vec;
    vector<vector<Flight>> paths;
    vec = findAirports(airports, country, city);

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

// Show a multi-path
void showPath(Graph<Airport> &airports, vector<Vertex<Airport> *> source, vector<Vertex<Airport> *> dest, vector<vector<Flight>> paths, vector<string> &airplanes)
{
    for (auto s : source)
    {
        std::cout << "Source: " << s->getInfo().getCode() << std::endl;
        for (auto d : dest)
        {
            std::cout << "Destination: " << d->getInfo().getCode() << std::endl;
            std::string tgt = d->getInfo().getCode();
            resetVisited(airports);
            paths = bfsPath(s, tgt, airplanes);
            for (auto path : paths)
            {

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
    }
}

// Show a set of paths
void showPath(vector<vector<Flight>> paths)
{
    std::cout << std::endl;
    for (auto path : paths)
    {

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

// Find all airports in a city
vector<Vertex<Airport> *> findAirports(Graph<Airport> &airports, string country, string city)
{
    vector<Vertex<Airport> *> vec;
    for (auto v : airports.getVertexSet())
    {
        if (v->getInfo().getCountry() == country && v->getInfo().getCity() == city)
        {
            vec.push_back(v);
        }
    }
    return vec;
}

// City to City
void findBestFlights(Graph<Airport> &airports, string countrySrc, string citySrc, string countryDest, string cityDest, vector<string> &airplanes)
{
    vector<Vertex<Airport> *> src;
    vector<Vertex<Airport> *> dest;
    vector<vector<Flight>> paths;

    src = findAirports(airports, countrySrc, citySrc);
    dest = findAirports(airports, countryDest, cityDest);

    showPath(airports, src, dest, paths, airplanes);
}

double toRadians(const double degree)
{
    return (degree * M_PI / 180);
}

//-23.477461, -46.548338 Anywhere in Sao Paulo
//-23.432075, -46.469511 Garulhos GRU 10km

// 28.160090, -17.240129 Anywhere in La Gomera
// 28.029600, -17.214600 GMZ 30km

double distanceEarth(double latOrigin, double longOrigin, double latDest, double longDest)
{
    latOrigin = toRadians(latOrigin);
    longOrigin = toRadians(longOrigin);
    latDest = toRadians(latDest);
    longDest = toRadians(longDest);

    double dlong = longDest - longOrigin;
    double dlat = latDest - latOrigin;

    double ans = pow(sin(dlat / 2), 2) + cos(latOrigin) * cos(latDest) * pow(sin(dlong / 2), 2);

    ans = 2 * asin(sqrt(ans));

    double R = 6371;

    ans = ans * R;

    return ans;
}

// Find all airports around a point
vector<Vertex<Airport> *> findAirports(Graph<Airport> &airports, double lat, double lon, int distMax)
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

// Point to Point
void findBestFlights(Graph<Airport> &airports, double latOrigin, double longOrigin, double latDest, double longDest, int distMax, vector<string> &airplanes)
{
    vector<Vertex<Airport> *> src = findAirports(airports, latOrigin, longOrigin, distMax);
    vector<Vertex<Airport> *> dest = findAirports(airports, latDest, longDest, distMax);
    vector<vector<Flight>> paths;

    showPath(airports, src, dest, paths, airplanes);
}

// Airport - Point
// type = 0. Point to Airport
// type = 1. Airport to Point
void findBestFlights(Graph<Airport> &airports, string airport, double lat, double lon, int distMax, int type, vector<string> &airplanes)
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

// City - Point
// type = 0. City to Point
// type = 1. Point to City
void findBestFlights(Graph<Airport> &airports, string country, string city, double lat, double lon, int distMax, int type, vector<string> &airplanes)
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

void getPath(string current, vector<Flight> &path, unordered_map<string, vector<Flight>> &prev, vector<vector<Flight>> &paths, string startCode, string airline)
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
            getPath(prevVertex.code, path, prev, paths, startCode, prevVertex.airline);
        }
    }
    path.pop_back();
}

vector<vector<Flight>> bfsPath(Vertex<Airport> *v, string &tgt, vector<string> &airplanes)
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
            if (!w->isVisited() && (find(airplanes.begin(), airplanes.end(), e.getRoute()) != airplanes.end() || airplanes.size() == 0))
            {
                q.push(w);
                w->setVisited(true);
                prev[w->getInfo().getCode()].push_back({vertex->getInfo().getCode(), e.getRoute()});
                dist[w->getInfo().getCode()] = dist[vertex->getInfo().getCode()] + 1;
            }
            else if (dist[w->getInfo().getCode()] == dist[vertex->getInfo().getCode()] + 1 && (find(airplanes.begin(), airplanes.end(), e.getRoute()) != airplanes.end() || airplanes.size() == 0))
            {
                prev[w->getInfo().getCode()].push_back({vertex->getInfo().getCode(), e.getRoute()});
            }
        }
    }

    vector<Flight> path;
    getPath(tgt, path, prev, paths, v->getInfo().getCode(), "");

    return paths;
}

void findArticulationPoints(Graph<Airport> &airports)
{

    for (auto v : airports.getVertexSet())
    {
        std::cout << " Analisando o vertice: " << v->getInfo().getCode() << std::endl;
        resetVisited(airports);
        int component = 0;
        for (auto w : airports.getVertexSet())
        {
            std::cout << "\tAnalisando o vertice: " << w->getInfo().getCode() << std::endl;
            if (!w->isVisited() && w->getInfo().getCode() != v->getInfo().getCode())
            {
                std::cout << "\t\tChamando o DFS component++" << std::endl;
                dfsArtc(v, w);
                component++;
            }
        }
        if (component > 2)
        {
            std::cout << "\n"
                      << v->getInfo().getCode() << "\n"
                      << std::endl;
        }
    }
}

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

// vector<vector<string>> bfsPath(Vertex<Airport> *v, string &tgt)
// {
//     vector<vector<string>> paths;
//     unordered_map<string, string> prev;
//     queue<Vertex<Airport> *> q;

//     q.push(v);
//     v->setVisited(true);

//     while (!q.empty())
//     {
//         auto vertex = q.front();
//         q.pop();
//         auto adjs = vertex->getAdj();

//         for (auto &e : adjs)
//         {
//             auto w = e.getDest();
//             if (!w->isVisited())
//             {
//                 q.push(w);
//                 w->setVisited(true);
//                 prev[w->getInfo().getCode()] = vertex->getInfo().getCode();
//             }
//             else
//             {
//                 break;
//             }
//         }
//     }

//     vector<string> path;
//     string current = tgt;

//     while (current != v->getInfo().getCode())
//     {
//         path.push_back(current);
//         current = prev[current];
//     }
//     path.push_back(v->getInfo().getCode());

//     reverse(path.begin(), path.end());
//     paths.push_back(path);
//     return paths;
// }

// vector<vector<string>> bfsPath(Vertex<Airport> *v, string &tgt)
// {
//     vector<vector<string>> paths;
//     unordered_map<string, vector<string>> prev;
//     queue<Vertex<Airport> *> q;

//     q.push(v);
//     v->setVisited(true);

//     while (!q.empty())
//     {
//         auto vertex = q.front();
//         q.pop();
//         auto adjs = vertex->getAdj();

//         for (auto &e : adjs)
//         {
//             auto w = e.getDest();
//             if (!w->isVisited())
//             {
//                 w->setVisited(true);
//                 q.push(w);
//                 prev[w->getInfo().getCode()].push_back(vertex->getInfo().getCode());
//             }
//         }
//         // vertex->setVisited(false);
//     }

//     for (const auto &pair : prev)
//     {
//         const string &current = pair.first;
//         const vector<string> &predecessors = pair.second;

//         for (const auto predecessor : predecessors)
//         {
//             vector<string> path;
//             string temp = current;

//             while (temp != v->getInfo().getCode())
//             {
//                 path.push_back(temp);
//                 temp = prev[temp].front();
//             }
//             path.push_back(v->getInfo().getCode());
//             reverse(path.begin(), path.end());
//             paths.push_back(path);
//         }
//     }

//     return paths;
// }

void dfsPath(Vertex<Airport> *v, string tgt, vector<string> &path, vector<vector<string>> &paths)
{
    std::cout << "Visiting: " << v->getInfo().getCode() << std::endl;
    v->setVisited(true);
    path.push_back(v->getInfo().getCode());

    if (v->getInfo().getCode() == tgt)
    {
        paths.push_back(path);
    }
    else
    {
        for (auto &e : v->getAdj())
        {
            auto w = e.getDest();
            if (!w->isVisited())
            {
                dfsPath(w, tgt, path, paths);
            }
        }
    }

    path.pop_back();
    v->setVisited(false);
}

void findAllPaths(Vertex<Airport> *v, string tgt)
{

    vector<vector<string>> paths;
    vector<string> path;

    dfsPath(v, tgt, path, paths);

    for (auto path : paths)
    {
        for (auto p : path)
        {
            std::cout << p << " ";
        }
        std::cout << std::endl;
    }
}
