#ifndef DBAIRPORT_H
#define DBAIRPORT_H

#include "../classes/Graph.h"
#include "../classes/Airport.h"
#include <set>
#include <map>
#include <fstream>
#include <algorithm>
#include <unordered_set>
#include <limits.h>
#include <cmath>

int quantityAirports(Graph<Airport> airports);
int quantityFlights(Graph<Airport> airports);
std::pair<int, int> quantityFlights(Graph<Airport> airports, std::string code);
int quantityFlightsCity(Graph<Airport> airports, std::string city);
int quantityFlightsAirline(Graph<Airport> airports, std::string airline);
int quantityCountry(Graph<Airport> airports, std::string airport);
int quantityCountryStop(Graph<Airport> airports, std::string airport, int stop);
std::vector<std::string> dfsVisit(Vertex<Airport> *v, std::vector<std::string> &res);
std::vector<std::string> dfsVisit(Vertex<Airport> *v, std::vector<std::string> &res, int stop);
int dfsCount(Vertex<Airport> *v, std::string &tgt, vector<std::string> &path);
void resetVisited(Graph<Airport> &airports);
int maxFlight(Graph<Airport> airports);
void rankingAirports(Graph<Airport> airports, int arg);
void getArticulations(Graph<Airport> airports);
void dfsArticulations(Graph<Airport> &airports, Vertex<Airport> *v, unordered_set<string> &res, std::stack<string> &s, int i);
void calculateIndegree(Graph<Airport> &airports);
//------------------------------------------------------------
void findBestFlights(Graph<Airport> &airports, string src, string dest);
void findBestFlights(Graph<Airport> &airports, string countrySrc, string citySrc, string countryDest, string cityDest);
void findBestFlights(Graph<Airport> &airports, double latOrigin, double longOrigin, double latDest, double longDest, int distMax);
void findBestFlights(Graph<Airport> &airports, string country, string city, string airport, int type);
//------------------------------------------------------------
void showPath(vector<vector<string>> paths);
void showPath(Graph<Airport> &airports, vector<Vertex<Airport> *> source, vector<Vertex<Airport> *> dest, vector<vector<string>> paths);
//------------------------------------------------------------
vector<Vertex<Airport> *> findAirports(Graph<Airport> &airports, string country, string city);
vector<Vertex<Airport> *> findAirports(Graph<Airport> &airports, double lat, double lon, int distMax);
//------------------------------------------------------------
vector<vector<string>> bfsPath(Vertex<Airport> *v, string &tgt);

void dfsPath(Vertex<Airport> *v, string tgt, vector<string> &path, vector<vector<string>> &paths);
void findAllPaths(Vertex<Airport> *v, string tgt);

#endif // DBAIRPORT_H