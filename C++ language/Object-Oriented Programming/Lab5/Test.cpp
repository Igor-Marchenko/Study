#include "List.h"
#include "Bus.h"
#include "Iterator.h"
#include <fstream>

bool load(const char* filename, List<Bus> &buses){
	if (filename == nullptr)
		return false;
	std::ifstream stream;
	stream.open(filename);
	if (stream.is_open() == false) 
		exit(10);
	List<Bus>::node_type *t;
	while (stream.eof() != true) {
		t = new List<Bus>::node_type();
		stream >> t->data;
		buses.push_front(*t);
		delete t;
	}
	buses.pop_front();
	stream.close();
	return true;
}

int main() {
	List<Bus> in_park; 
	List<Bus> on_route;
	in_park.load("In_Park.csv");
	load("On_Route.csv", on_route);
	std::cout << "Buses currently on some route:\n\n";
	on_route.Print();
	std::cout << "\n\nBuses currently in park:\n\n";
	in_park.Print();
	in_park.clear();
	if (in_park.empty() == true) {
		std::cout << "\n\nThere are no buses currently in park\n\n";
		load("In_Park.csv", in_park);
	}
	std::cout << "\n\nBuses currently in park:\n\n";
	in_park.Print();
	List<Bus>::iterator it;
	std::cout << "\n\nAll the buses on the route 175:\n\n";
	for (it = on_route.begin(); it != on_route.end(); it++) {
		if ((*it).data.Print_route("175"))
			std::cout << (*it).data;
	}
	std::cout << "\n\nChanging driver:\n\n";
	for (it = in_park.begin(); it != in_park.end(); it++)
		(*it).data.rename("Logan Twirck", "Jacob Sina");
	std::cout << "\n\nBuses currently in park:\n\n";
	in_park.Print();
	for (it = on_route.begin(); it != on_route.end(); it++)
		(*it).data.rename("Oskar Blank", "Ernest Hemingway");
	std::cout << "\n\nBuses currently on some route:\n\n";
	on_route.Print();
	std::cout << "\n\nMoving second bus from the park onto the route:\n\n";
	it = in_park.begin();
	it++;
	in_park.splice(it, on_route);
	std::cout << "\n\nBuses currently on some route:\n\n";
	on_route.Print();
	std::cout << "\n\nBuses currently in park:\n\n";
	in_park.Print();
	std::cout << "\n\nMoving first bus from the route into the park:\n\n";
	it = on_route.begin();
	it;
	on_route.splice(it, in_park);
	std::cout << "\n\nBuses currently in park:\n\n";
	in_park.Print();
	std::cout << "\n\nBuses currently on some route:\n\n";
	on_route.Print();
	in_park.clear();
	on_route.clear();
	system("pause");
	exit (0);
}
