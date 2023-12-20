#include "Menu.h"
#include <iostream>

Graph<Airport> airports = readFlights();

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
    std::cout << "1. Number of airports" << std::endl;
    std::cout << "2. Number of flights" << std::endl;
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
        system("clear");
        menuFlights();
        break;
    case 0:
        exit(0);
        break;
    }
}

void menuFlights()
{
    int flag;
    std::cout << "Number of flights:" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << "1. All flights" << std::endl;
    std::cout << "2. Flights by Airport" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cin >> flag;

    switch (flag)
    {
    case 1:
        system("clear");
        std::cout << "All flights: " << quantityFlights(airports) << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << "Press any key to continue..." << std::endl;
        std::cin.ignore();
        std::cin.get();
        quantity();
        break;
    case 2:
        std::cout << "Type Airport code: " << std::endl;
        std::string code;
        std::cin >> code;
        system("clear");
        std::cout << "Flights by Airport" << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << "Press any key to continue..." << std::endl;
        std::cin.ignore();
        std::cin.get();
        quantity();
        break;
    }
}