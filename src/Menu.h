#ifndef MENU_H
#define MENU_H

#include "classes/Airport.h"
#include "database/dbairport.h"
#include "database/read.h"
#include <limits>

// Function to display menu
void Menu(std::string folder);
void quantity();
void listing();
void menuFlights();
void menuDestination();

// Function to handle the process of finding the best flight
void bestFlights();

// Function to filter airplanes
vector<string> filterAirplanes();

// Function to select type of origin or destination
int selectType(std::string arg);

// Functions to input info based on type and flag
std::string typeAirport(std::string type, int flag);
pair<std::string, std::string> typeCity(std::string type, int flag);
pair<double, double> typeCoordinates(std::string type, int flag);

#endif