#ifndef MENU_H
#define MENU_H

#include "database/dbairport.h"
#include "database/read.h"
#include <iostream>
#include <limits>

// Function to display menu
void Menu(std::string folder);
void menuQuantity();
void menuListing();
void menuAirports();
void menuCountries();
void menuCities();
void menuAirlines();
void menuFlights();
void menuDestination();

// Function to handle the process of finding the best flight
void bestFlights();
int selectType(std::string arg);
std::string typeAirport(std::string type, int flag);
pair<std::string, std::string> typeCity(std::string type, int flag);
pair<double, double> typeCoordinates(std::string type, int flag);

// Function to filter airplanes
vector<string> filterAirplanes();

#endif