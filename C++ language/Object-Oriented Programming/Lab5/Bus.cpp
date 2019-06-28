#include "Bus.h" 

int Bus::rename(char *old_name, char *new_name) {
	if (strcmp(old_name, driver) == 0) {
		if (new_name != nullptr) {
			if (driver != nullptr)
				delete[] driver;
			driver = new char[strlen(new_name) + 1];
			strcpy(driver, new_name);
			if (driver == nullptr)
				return 1;
		}
	}
	return 0;
}

bool Bus::operator == (Bus& val){
	return ((strcmp(driver, val.driver) == 0) && (strcmp(route_number, val.route_number) == 0) && (strcmp(bus_number, val.bus_number)==0));
}

bool Bus::operator != (Bus& val) {
	return !(*this == val);
}

std::ostream& operator<<(std::ostream& stream, Bus &obj) {
	stream << "Bus Driver: " << obj.driver << "\nBus Number: " << obj.bus_number;
	stream << "\nRoute Number: " << obj.route_number << "\n\n";
	return stream;
}

std::istream& operator>>(std::istream& stream, Bus &obj) {
	obj.driver = nullptr;
	obj.bus_number = nullptr;
	obj.route_number = nullptr;
	char *line = nullptr;
	for (int i = 0; i < 3; i++) {
		line = new char[64];
		if(i == 2)
			stream.getline(line, 64, '\n');
		else
			stream.getline(line, 64, ';');
		switch (i) {
			case 0: {
				obj.driver = new char[strlen(line) + 1];
				strcpy(obj.driver, line);
				break;
				}
			case 1: {
				obj.bus_number = new char[strlen(line) + 1];
				strcpy(obj.bus_number, line);
				break;
			}
			case 2: {
				obj.route_number = new char[strlen(line) + 1];
				strcpy(obj.route_number, line);
				break;
			}
		}
		delete[] line;
	}
	return stream;
}

bool Bus::Print_route(char *route) {
	if (strcmp(route, route_number) == 0)
		return true;
	return false;
}
