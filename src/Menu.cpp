#include "Menu.h"
#include <iostream>

// Global graph to store airport data
Graph<Airport> airports;

// Function Menu Main
void Menu(std::string folder) {
  int flag;

  if (!folder.empty())
    airports = readFlights(folder);

  system("clear");
  std::cout << "Welcome to Travel Management:" << std::endl;
  std::cout << "-------------------------------" << std::endl;
  std::cout << "1. Quantity calculation" << std::endl;
  std::cout << "2. Listing" << std::endl;
  std::cout << "3. Bests flights" << std::endl;
  std::cout << "0. Exit" << std::endl;
  std::cout << "-------------------------------" << std::endl;
  std::cin >> flag;

  switch (flag) {
  case 1:
    quantity();
    break;
  case 2:
    listing();
    break;
  case 3:
    bestFlights();
    break;
  case 0:
    exit(0);
    break;
  default:
    std::cout << "Invalid option. Please enter a valid option (0, 1, 2, or 3).";
    Menu("");
    break;
  }
}

// Function to handle quantity-related menu options
void quantity() {
  int flag;

  system("clear");
  std::cout << "Quantity Calculation Menu" << std::endl;
  std::cout << "-------------------------------" << std::endl;
  std::cout << "1. Number of airports" << std::endl;
  std::cout << "2. Number of flights" << std::endl;
  std::cout << "3. Number of destinations" << std::endl;
  std::cout << "0. Back to Main Menu" << std::endl;
  std::cout << "-------------------------------" << std::endl;
  std::cin >> flag;

  switch (flag) {
  case 1:
    system("clear");
    std::cout << "Quantity of airports: " << quantityAirports(airports)
              << std::endl;
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
    Menu("");
    break;
  default:
    std::cout << "Invalid option. Please enter a valid option (0, 1, 2, or 3).";

    quantity();
    break;
  }
}

// Function to handle listing-related menu options
void listing() {
  int flag;
  int arg;

  system("clear");
  std::cout << "Listing Menu: " << std::endl;
  std::cout << "-------------------------------" << std::endl;
  std::cout << "1. Ranking Airports (more landings and takeoffs)" << std::endl;
  std::cout << "2. Connecting airports" << std::endl;
  std::cout << "0. Back to Main Menu" << std::endl;
  std::cout << "-------------------------------" << std::endl;

  std::cin >> flag;

  switch (flag) {
  case (1):
    system("clear");
    std::cout << "Type the number of airports: " << std::endl;
    std::cin >> arg;
    std::cout << "-------------------------------" << std::endl;
    std::cout << "Ranking Airports: " << std::endl;
    std::cout << "-------------------------------" << std::endl;
    rankingAirports(airports, arg);
    std::cout << "-------------------------------" << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    listing();
    break;
  case (2):
    system("clear");
    std::cout << "Connecting airports: " << std::endl;
    std::cout << "-------------------------------" << std::endl;
    // getArticulations(airports);
    findArticulationPoints(airports);
    std::cout << "-------------------------------" << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    listing();
    break;
  case (0):
    Menu("");
    break;
  default:
    std::cout << "Invalid option. Please enter a valid option (0, 1, or 2).";

    listing();
    break;
  }
}

// Function to handle best flights menu options
int selectType(std::string arg) {
  int flag;

  system("clear");
  std::cout << "Bests Flights: " << std::endl;
  std::cout << "Select your " << arg << " option:" << std::endl;
  std::cout << "-------------------------------" << std::endl;
  std::cout << "1. By airports" << std::endl;
  std::cout << "2. By cities" << std::endl;
  std::cout << "3. By coordinates" << std::endl;
  std::cout << "0. Back to Best Flights" << std::endl;
  std::cout << "-------------------------------" << std::endl;
  std::cin >> flag;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                  '\n'); // ignore \n
  return flag;
}

// Function to input airport code based on the type and flag
std::string typeAirport(std::string type, int flag) {
  std::string arg;
  switch (flag) {
  case (1):
    std::cout << "Type the code of Airport of " << type << ": " << std::endl;
    std::cin >> arg;
    break;
  }
  return arg;
}

// Function to input city details based on the type and flag
pair<std::string, std::string> typeCity(std::string type, int flag) {
  std::string arg1;
  std::string arg2;
  switch (flag) {
  case (2):
    std::cout << "Type the name of City of " << type << ": " << std::endl;
    std::getline(std::cin, arg1);
    std::cout << "Type the name of Country of " << type << ": " << std::endl;
    std::getline(std::cin, arg2);
    break;
  }
  return make_pair(arg1, arg2);
}

// Function to input coordinates based on the type and flag
pair<double, double> typeCoordinates(std::string type, int flag) {
  double arg1;
  double arg2;
  switch (flag) {
  case (3):
    std::cout << "Type the latitude of " << type << ": " << std::endl;
    std::cin >> arg1;
    std::cout << "Type the longitude of " << type << ": " << std::endl;
    std::cin >> arg2;
    break;
  }
  return make_pair(arg1, arg2);
}

// Function to filter airplanes on the user input
vector<string> filterAirplanes() {
  vector<string> airplanes;
  string line;
  int flag;

  system("clear");
  std::cout << "Bests flights: " << std::endl;
  std::cout << "-------------------------------" << std::endl;
  std::cout << "1. Filter by airplanes" << std::endl;
  std::cout << "2. Without filter" << std::endl;
  std::cout << "0. Back to Main Menu" << std::endl;
  std::cout << "-------------------------------" << std::endl;
  std::cin >> flag;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                  '\n'); // ignore \n

  switch (flag) {
  case (1): {
    std::cout << "Type the name of airplane: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream iss(line);

    string airplane;

    while (iss >> airplane) {
      airplanes.push_back(airplane);
    }
    break;
  }
  case (2):
    break;
  case (0):
    Menu("");
    break;
  default:
    std::cout << "Invalid option. Please enter a valid option (0, 1, or 2).";

    filterAirplanes();
    break;
  }
  return airplanes;
}

// Function to find best flights based on the user input
void bestFlights() {
  vector<string> airplanes = filterAirplanes();

  std::string airportOrig;
  std::string airportDest;

  std::pair<std::string, std::string> cityOrig;
  std::pair<std::string, std::string> cityDest;

  std::pair<double, double> cordOrig;
  std::pair<double, double> cordDest;

  int maxDist;
  int flagOrigin = selectType("origin");

  switch (flagOrigin) {
  case (1):
    airportOrig = typeAirport("origin", flagOrigin);
    break;
  case (2):
    cityOrig = typeCity("origin", flagOrigin);
    break;
  case (3):
    cordOrig = typeCoordinates("origin", flagOrigin);
    std::cout << "Type the maximum distance in (km): " << std::endl;
    std::cin >> maxDist;
    break;
  case (0):
    bestFlights();
    break;
  default:
    std::cout << "Invalid option. Please enter a valid option (0, 1, 2, or 3).";
    bestFlights();
    break;
  }

  int flagDest = selectType("destination");
  switch (flagDest) {
  case (1):
    airportDest = typeAirport("destination", flagDest);
    break;
  case (2):
    cityDest = typeCity("destination", flagDest);
    break;
  case (3):
    cordDest = typeCoordinates("destination", flagDest);
    std::cout << "Type the maximum distance in (km): " << std::endl;
    std::cin >> maxDist;
    break;
  case (0):
    bestFlights();
    break;
  default:
    std::cout << "Invalid option. Please enter a valid option (0, 1, 2, or 3).";
    bestFlights();
    break;
  }

  switch (flagOrigin) {
  case (1):
    switch (flagDest) {
      {
      case (1): // airport to airport
        findBestFlights(airports, airportOrig, airportDest, airplanes);
        break;
      case (2): // airport to city
        findBestFlights(airports, cityDest.second, cityDest.first, airportOrig,
                        1, airplanes);
        break;
      case (3): // airport to coordinates
        findBestFlights(airports, airportOrig, cordDest.first, cordDest.second,
                        maxDist, 1, airplanes);
        break;
      }
    }
    break;
  case (2):
    switch (flagDest) {
      {
      case (1): // city to airport
        findBestFlights(airports, cityOrig.second, cityOrig.first, airportDest,
                        0, airplanes);
        break;
      case (2): // city to city
        findBestFlights(airports, cityOrig.second, cityOrig.first,
                        cityDest.second, cityDest.first, airplanes);
        break;
      case (3): // city to coordinates
        findBestFlights(airports, cityOrig.second, cityOrig.first,
                        cordDest.first, cordDest.second, maxDist, 0, airplanes);
        break;
      }
    }
    break;
  case (3):
    switch (flagDest) {
      {
      case (1): // coordinates to airport
        findBestFlights(airports, airportDest, cordOrig.first, cordOrig.second,
                        maxDist, 0, airplanes);
        break;
      case (2): // coordinates to city
        findBestFlights(airports, cityDest.second, cityDest.first,
                        cordOrig.first, cordOrig.second, maxDist, 1, airplanes);
        break;
      case (3): // coordinates to coordinates
        findBestFlights(airports, cordOrig.first, cordOrig.second,
                        cordDest.first, cordDest.second, maxDist, airplanes);
        break;
      }
    }
    break;
  }

  std::cout << "-------------------------------" << std::endl;
  std::cout << "Press any key to continue..." << std::endl;
  std::cin.ignore();
  std::cin.get();
  bestFlights();
}

// Function Menu Flights
void menuFlights() {
  int flag;
  std::string arg;

  system("clear");
  std::cout << "Number of flights:" << std::endl;
  std::cout << "-------------------------------" << std::endl;
  std::cout << "1. All flights" << std::endl;
  std::cout << "2. Flights by Airport" << std::endl;
  std::cout << "3. Flights by City" << std::endl;
  std::cout << "4. Flights by Airline" << std::endl;
  std::cout << "0. Back to Main Menu" << std::endl;
  std::cout << "-------------------------------" << std::endl;
  std::cin >> flag;

  switch (flag) {
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
    std::cout << "Flights by Airport: " << quantityFlights(airports, arg).first
              << std::endl;
    std::cout << "Airlines : " << quantityFlights(airports, arg).second
              << std::endl;
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
    std::cout << "Flights by City: " << quantityFlightsCity(airports, arg)
              << std::endl;
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
    std::cout << "Flights by Airline: " << quantityFlightsAirline(airports, arg)
              << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    quantity();
    break;
  case 0:
    quantity();
    break;
  default:
    std::cout << "Invalid option. Please enter a valid option (0, 1, 2, or 3).";
    menuFlights();
    break;
  }
}

// Function Menu Destination
void menuDestination() {
  int flag;
  std::string arg;
  int stop;

  system("clear");
  std::cout << "Number of Destinations:" << std::endl;
  std::cout << "-------------------------------" << std::endl;
  std::cout << "1. Unlimited Stops (Countries)" << std::endl;
  std::cout << "2. Limited Stops" << std::endl;
  std::cout << "3. Max destinations" << std::endl;
  std::cout << "0. Back to Main Menu" << std::endl;
  std::cout << "-------------------------------" << std::endl;

  std::cin >> flag;

  switch (flag) {
  case (1):
    system("clear");
    std::cout << "Type Airport code: " << std::endl;
    std::cin >> arg;
    std::cout << "Number of Countries " << quantityCountry(airports, arg)
              << std::endl;
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
    std::cout << "Number of Countries "
              << quantityCountryStop(airports, arg, stop) << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    menuDestination();
  case (3):
    system("clear");
    std::cout << "The maximum number of flights is: " << maxFlight(airports)
              << " stops" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    menuDestination();
  case (0):
    Menu("");
    break;
  default:
    std::cout << "Invalid option. Please enter a valid option (0, 1, 2, or 3).";
    menuDestination();
    break;
  }
}