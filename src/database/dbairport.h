#ifndef DBAIRPORT_H
#define DBAIRPORT_H

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

int quantityAirports(Graph<Airport> airports);
int quantityFlights(Graph<Airport> airports);
std::pair<int, int> quantityFlights(Graph<Airport> airports, std::string code);
int quantityFlightsCity(Graph<Airport> airports, std::string city, std::string country);
int quantityFlightsAirline(Graph<Airport> airports, std::string airline);
int quantityCountry(Graph<Airport> airports, std::string airport);
int quantityCountryStop(Graph<Airport> airports, std::string airport, int stop);
std::vector<std::string> dfsVisit(Vertex<Airport> *v,
                                  std::vector<std::string> &res);
std::vector<std::string> dfsVisit(Vertex<Airport> *v,
                                  std::vector<std::string> &res, int stop);
int dfsCount(Vertex<Airport> *v, std::string &tgt, vector<std::string> &path);
void resetVisited(Graph<Airport> &airports);
int maxFlight(Graph<Airport> airports);
void rankingAirports(Graph<Airport> airports, int arg);
void getArticulations(Graph<Airport> airports);
void dfsArticulations(Graph<Airport> &airports, Vertex<Airport> *v,
                      unordered_set<string> &res, std::stack<string> &s, int i);
void calculateIndegree(Graph<Airport> &airports);
//------------------------------------------------------------
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

#endif // DBAIRPORT_H