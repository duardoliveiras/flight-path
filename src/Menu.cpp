#include "Menu.h"
#include <iostream>

Graph<Airport> airports;

void Menu(std::string folder)
{
    airports = readFlights(folder);
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
    std::cout << "3. Number of destinations" << std::endl;
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
    case 3:
        system("clear");
        menuDestination();
        break;
    case 0:
        exit(0);
        break;
    }
}

void menuFlights()
{
    int flag;
    std::string arg;

    std::cout << "Number of flights:" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << "1. All flights" << std::endl;
    std::cout << "2. Flights by Airport" << std::endl;
    std::cout << "3. Flights by City" << std::endl;
    std::cout << "4. Flights by Airline" << std::endl;
    std::cout << "0. Exit" << std::endl;
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
        std::cin >> arg;

        system("clear");

        std::cout << "Flights by Airport: " << quantityFlights(airports, arg).first << std::endl;
        std::cout << "Airlines : " << quantityFlights(airports, arg).second << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << "Press any key to continue..." << std::endl;
        std::cin.ignore();
        std::cin.get();
        quantity();
        break;
    case 3:
        std::cout << "Type the name of city: " << std::endl;
        std::cin >> arg;

        system("clear");
        std::cout << "Flights by City: " << quantityFlightsCity(airports, arg) << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << "Press any key to continue..." << std::endl;
        std::cin.ignore();
        std::cin.get();
        quantity();
        break;
    case 4:
        std::cout << "Type the code of Airline: " << std::endl;
        std::cin >> arg;

        system("clear");
        std::cout << "Flights by Airline: " << quantityFlightsAirline(airports, arg) << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << "Press any key to continue..." << std::endl;
        std::cin.ignore();
        std::cin.get();
        quantity();
        break;
    case 0:
        exit(0);
        break;
    }
}

void menuDestination()
{
    int flag;
    std::string arg;
    int stop;

    system("clear");
    std::cout << "Number of Destinations:" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << "1. Unlimited Stops (Countries)" << std::endl;
    std::cout << "2. Limited Stops" << std::endl;
    std::cout << "3. Max destinations" << std::endl;
    std::cout << "-------------------------------" << std::endl;

    std::cin >> flag;

    switch (flag)
    {
    case (1):
        system("clear");
        std::cout << "Type Airport code: " << std::endl;
        std::cin >> arg;
        std::cout << "Number of Countries " << quantityCountry(airports, arg) << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << "Press any key to continue..." << std::endl;
        std::cin.ignore();
        std::cin.get();
        menuDestination();
        break;
    case (2):
        system("clear");
        std::cout << "Type Airport code: " << std::endl;
        std::cin >> arg;
        std::cout << "Type the number of stops: " << std::endl;
        std::cin >> stop;
        std::cout << "Number of Countries " << quantityCountryStop(airports, arg, stop) << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << "Press any key to continue..." << std::endl;
        std::cin.ignore();
        std::cin.get();
        menuDestination();
    case (3):
        system("clear");
        std::cout << "The maximum number of flights is: " << maxFlight(airports) << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << "Press any key to continue..." << std::endl;
        std::cin.ignore();
        std::cin.get();
        menuDestination();

    default:
        break;
    }
}