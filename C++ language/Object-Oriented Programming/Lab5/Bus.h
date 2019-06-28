#pragma once

#include <iostream>
#include <string.h>

class Bus{
	char *driver;
	char *bus_number;
	char *route_number;

public:
	Bus() : driver(NULL), bus_number(NULL), route_number(NULL) {}

	friend std::ostream& operator<<(std::ostream& stream, Bus &obj);
	friend std::istream& operator>>(std::istream& stream, Bus &obj);
    
	bool operator ==(Bus& val);
	bool operator !=(Bus& val);

	bool Print_route(char *route);
	
	int rename(char *old_name, char* new_name);
}; 
