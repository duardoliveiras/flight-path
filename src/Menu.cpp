#include "Menu.h"
#include <iostream>

Graph<Airport> airports = readAirports();

void Menu()
{
    int flag;
    std::cout << "Welcome to Travel Management" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << "1. Quantity calculation" << std::endl;
    std::cout << "2. Listing" << std::endl;
    std::cout << "3. Bests flights" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cin >> flag;

    switch (flag)
    {
    case 1:
        quantity();
        break;
    case 2:
        std::cout << "Listing" << std::endl;
        break;
    case 3:
        std::cout << "Bests flights" << std::endl;
        break;
    case 0:
        exit(0);
        break;
    }
}

void quantity()
{
    int flag;
    system("clear");
    std::cout << "Quantity calculation" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << "1. Quantity of airports" << std::endl;
    std::cout << "2. Quantity of flights" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cin >> flag;

    switch (flag)
    {
    case 1:
        system("clear");
        std::cout << "Quantity of airports: " << quantityAirports(airports) << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << "Press any key to continue..." << std::endl;
        std::cin.ignore();
        std::cin.get();
        quantity();
        break;
    case 2:
        std::cout << "Quantity of routes" << std::endl;
        break;
    case 0:
        exit(0);
        break;
    }
}