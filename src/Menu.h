#ifndef MENU_H
#define MENU_H

#include "classes/Airport.h"
#include "database/read.h"
#include "database/dbairport.h"
#include <limits>

void Menu(std::string folder);
void quantity();
void listing();
void bestFlights();
void menuFlights();
void menuDestination();

int selectType(std::string arg);
std::string typeAirport(std::string type, int flag);
pair<std::string, std::string> typeCity(std::string type, int flag);
pair<double, double> typeCoordinates(std::string type, int flag);

#endif