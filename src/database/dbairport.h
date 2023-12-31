#ifndef DBAIRPORT_H
#define DBAIRPORT_H

#include "../classes/Airline.h"
#include "../classes/Airport.h"
#include "../classes/Graph.h"
#include <algorithm>
#include <cmath>
#include <fstream>
#include <limits.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

struct Flight
{
  std::string code;
  std::string airline;
};

// Quantity Airports Functions
int quantityAirports(Graph<Airport> airports);
int quantityAirportsCountry(Graph<Airport> airports, std::string country);
int quantityAirportsCity(Graph<Airport> airports, std::string city);

// Quantity Countries Functions
int quantityCountries(Graph<Airport> airports, Graph<Airline> airlines);

// Quantity Cities Functions
int quantityCities(Graph<Airport> airports);
int quantityCitiesCountry(Graph<Airport> airports, std::string country);

// Quantity Airlines Functions
int quantityAirlines(Graph<Airline> airlines);
int quantityAirlinesCountry(Graph<Airline> airlines, std::string country);

// Quantity Flights Functions
int quantityFlights(Graph<Airport> airports);
int quantityFlightsAirport(Graph<Airport> airports, std::string airport);
int quantityFlightsCountry(Graph<Airport> airports, std::string country);
int quantityFlightsCity(Graph<Airport> airports, std::string city);
int quantityFlightsAirline(Graph<Airport> airports, std::string airline);

// Quantity Destination Functions
int quantityDestinationsCountry(Graph<Airport> airports,
                                std::string country);
int quantityDestinationsAirport(Graph<Airport> airports, std::string airport);
int quantityDestinationLimitedStop(Graph<Airport> airports,
                                   std::string airport, int stop);
int quantityDestinationMax(Graph<Airport> airports);

// Other functions
int quantityCountry(Graph<Airport> airports, std::string airport); // see later
std::pair<int, int> quantityFlights(Graph<Airport> airports, std::string code);
std::vector<std::string> dfsVisit(Vertex<Airport> *v,
                                  std::vector<std::string> &res);
std::vector<std::string> dfsVisit(Vertex<Airport> *v,
                                  std::vector<std::string> &res, int stop);
int dfsCount(Vertex<Airport> *v, std::string &tgt, vector<std::string> &path);
void resetVisited(Graph<Airport> &airports);
void rankingAirports(Graph<Airport> airports, int arg);
void getArticulations(Graph<Airport> airports);
void dfsArticulations(Graph<Airport> &airports, Vertex<Airport> *v,
                      unordered_set<string> &res, std::stack<string> &s, int i);
void calculateIndegree(Graph<Airport> &airports);

// Best Flights Functions
void findBestFlights(Graph<Airport> &airports, string src, string dest,
                     vector<string> &airplanes);
void findBestFlights(Graph<Airport> &airports, string countrySrc,
                     string citySrc, string countryDest, string cityDest,
                     vector<string> &airplanes);
void findBestFlights(Graph<Airport> &airports, double latOrigin,
                     double longOrigin, double latDest, double longDest,
                     int distMax, vector<string> &airplanes);
void findBestFlights(Graph<Airport> &airports, string country, string city,
                     string airport, int type, vector<string> &airplanes);
void findBestFlights(Graph<Airport> &airports, string country, string city,
                     double lat, double lon, int distMax, int type,
                     vector<string> &airplanes);
void findBestFlights(Graph<Airport> &airports, string airport, double lat,
                     double lon, int distMax, int type,
                     vector<string> &airplanes);
//------------------------------------------------------------
void showPath(vector<vector<Flight>> paths);
void showPath(Graph<Airport> &airports, vector<Vertex<Airport> *> source,
              vector<Vertex<Airport> *> dest, vector<vector<Flight>> paths,
              vector<string> &airplanes);
//------------------------------------------------------------
vector<Vertex<Airport> *> findAirports(Graph<Airport> &airports, string country,
                                       string city);
vector<Vertex<Airport> *> findAirports(Graph<Airport> &airports, double lat,
                                       double lon, int distMax);
//------------------------------------------------------------
vector<vector<Flight>> bfsPath(Vertex<Airport> *v, string &tgt,
                               vector<string> &airplanes);

void getPath(string current, vector<Flight> &path,
             unordered_map<string, vector<Flight>> &prev,
             vector<vector<Flight>> &paths, string startCode, string airline);

void dfsPath(Vertex<Airport> *v, string tgt, vector<string> &path,
             vector<vector<string>> &paths);

void findAllPaths(Vertex<Airport> *v, string tgt);

void dfsArtc(Vertex<Airport> *v, Vertex<Airport> *w);
void findArticulationPoints(Graph<Airport> &airports);

bool comparatorPath(const vector<Flight> a, const vector<Flight> b);

//---

void dfsConnectedComponents(Graph<Airport> &airports, Vertex<Airport> *v);
int connectedComponents(Graph<Airport> &airports);
void dfsMax(Vertex<Airport> *v, std::vector<std::string> &path, std::vector<std::string> &maxPath);

#endif // DBAIRPORT_H