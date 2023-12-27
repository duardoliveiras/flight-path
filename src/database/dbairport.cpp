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

void findBestFlights(Graph<Airport> &airports, string src, string dest)
{
    resetVisited(airports);

    auto s = airports.findVertex(Airport(src));
    auto d = airports.findVertex(Airport(dest));

    if (s == nullptr || d == nullptr)
        return;

    vector<vector<string>> paths;
    paths = bfsPath(s, dest);

    for (auto path : paths)
    {

        for (auto p : path)
        {
            std::cout << p << " -> ";
        }
        std::cout << std::endl;
    }
}

void findBestFlights(Graph<Airport> &airports, string countrySrc, string citySrc, string countryDest, string cityDest)
{
    vector<Vertex<Airport> *> src;
    vector<Vertex<Airport> *> dest;
    vector<vector<string>> paths;

    for (auto v : airports.getVertexSet())
    {
        if (v->getInfo().getCountry() == countrySrc && v->getInfo().getCity() == citySrc)
        {
            src.push_back(v);
        }
        if (v->getInfo().getCountry() == countryDest && v->getInfo().getCity() == cityDest)
        {
            dest.push_back(v);
        }
    }

    for (auto s : src)
    {
        std::cout << "Source: " << s->getInfo().getCode() << std::endl;
        vector<vector<string>> paths;
        for (auto d : dest)
        {
            std::cout << "Destination: " << d->getInfo().getCode() << std::endl;
            std::string tgt = d->getInfo().getCode();
            resetVisited(airports);
            paths = bfsPath(s, tgt);
            for (auto path : paths)
            {

                for (auto p : path)
                {
                    std::cout << p << " -> ";
                }
                std::cout << std::endl;
            }
        }
    }
}

void getPath(string current, vector<string> &path, unordered_map<string, vector<string>> &prev, vector<vector<string>> &paths, string startCode)
{
    path.push_back(current);
    if (current == startCode)
    {
        vector<string> validPath = path;
        reverse(validPath.begin(), validPath.end());
        paths.push_back(validPath);
    }
    else
    {
        for (auto &prevVertex : prev[current])
        {
            getPath(prevVertex, path, prev, paths, startCode);
        }
    }
    path.pop_back();
}

vector<vector<string>> bfsPath(Vertex<Airport> *v, string &tgt)
{
    vector<vector<string>> paths;
    unordered_map<string, vector<string>> prev;
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
            if (!w->isVisited())
            {
                q.push(w);
                w->setVisited(true);
                prev[w->getInfo().getCode()].push_back(vertex->getInfo().getCode());
                dist[w->getInfo().getCode()] = dist[vertex->getInfo().getCode()] + 1;
            }
            else if (dist[w->getInfo().getCode()] == dist[vertex->getInfo().getCode()] + 1)
            {
                prev[w->getInfo().getCode()].push_back(vertex->getInfo().getCode());
            }
        }
    }

    vector<string> path;
    getPath(tgt, path, prev, paths, v->getInfo().getCode());

    return paths;
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
