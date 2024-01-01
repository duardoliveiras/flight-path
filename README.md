# Air Travel Flight Management System

## Project Description

Our project revolves around developing a user-friendly Flight Management System designed to facilitate access and understanding of the global air transport network. The primary goal is to provide effective assistance to users for exploring and planning air travel. Emphasizing usability and intuitive information delivery, the system utilizes real-world data encompassing details on airports, flights, and airlines worldwide.

## Installation and Usage

To run our application, follow these simple steps:

1. Open a terminal window.
2. Navigate to the src folder using the cd command:
   `cd src`
3. `cmake .` to generate Makefile
4. Execute the following command to compile and run the program:
   `make && ./a`

## Collaboration

- Clarisse Maria Teixeira de Carvalho, up202008444
- Eduardo Oliveira Silva, up202301394

## Features

#### Quantity

- Number of airports (All, by country, by city)
- Number of countries
- Number of cities (All, by country)
- Number of airlines (All, by country)
- Number of flights (All, by airport, by country, by city, by airline)
- Number of destinations from airport (unlimited stops, limited stops)
- Max Destination

#### Listing

- Ranking airports (more landings and takeoffs)
- Essential airports

#### Best Flights

- Filt by airplanes or whithout filter
- By airport to airport
- By airport to city (vice-versa)
- By airport to point (vice-versa)
- By city to point (vice-versa)
- By point to point (coordinates)
