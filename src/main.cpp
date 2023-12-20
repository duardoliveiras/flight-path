#include "Menu.h"
#include <stdio.h>
#include "Airport.h"
#include "read.h"
#include <iostream>

int main()
{
    // printf("Hello!\n");
    // Airport airport("code", "name", "country", "city", 0.0, 0.0);
    // std::cout << airport.getCity() << std::endl;
    // Graph<Airport> airports = createGraph();
    auto airports = createGraph();
    Menu();
    return 0;
}