#pragma once

#include "Person.h"
#include "Employee.h"
#include "Manager.h"
#include <typeinfo>
#include <vector>
#include <list>
#include <fstream>

class Database {

public:
	Database() {};
	~Database() = default;
	//creates “flat” database
	bool LoadFromFile(const char *file);
	//arranges "flat" database after loading from the file
	void ArrangeSubordinates();
	//hire a new employee
	Person* HireEmployee(Person *p);
	void DisplayDepartmentEmployees(std::string _department);
	//fire the employee
	bool FireEmployee(int id);
	void DisplayAll();
	//Add here whatever you need
	bool If_Doubled(int id);
	std::vector<Person*> SQL(const char *field, const char * cond, const char* value);
	void ShowRecordSet(std::vector<Person*> rs);

private:
	std::vector<Person*> employees;
};
