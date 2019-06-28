#include "Employee.h"

Employee::Employee(const Employee &e) {
	if (this != &e) {
		this->f_name = e.f_name;
		this->l_name = e.l_name;
		this->age = e.age;
		this->department = e.department;
		this->id = e.id;
		this->salary = e.salary;
	}
}

Employee& Employee::operator=(const Employee &e) {
	if (this != &e) {
		this->f_name = e.f_name;
		this->l_name = e.l_name;
		this->age = e.age;
		this->department = e.department;
		this->id = e.id;
		this->salary = e.salary;
	}
	return *this;
}

void Employee::SetSalary(int s) {
	this->salary = s;
}

void Employee::SetDepartment(std::string dept) {
	this->department = dept;
}

void Employee::SetId(int n) {
	this->id = n;
}

int Employee::GetId() {
	return this->id;
}

int Employee::GetSalary() {
	return this->salary;
}

int Employee::GetAge() {
	return this->age;
}

std::string Employee::GetDepartment() {
	return this->department;
}

void Employee::Display(bool Subordinates) {
	if (!Subordinates) {
		std::cout << "Employment type: Employee" << std::endl;
		std::cout << "ID: " << this->id << std::endl << "First and Last Name: " << this->f_name << " " << this->l_name << std::endl;
		std::cout << "Age: " << this->age << std::endl << "Salary: " << this->salary << std::endl << "Department: " << this->department << std::endl;
		std::cout << std::endl;
	}
	else {
		std::cout << "\tEmployment type: Employee" << std::endl;
		std::cout << "\tID: " << this->id << std::endl << "\tFirst and Last Name: " << this->f_name << " " << this->l_name << std::endl;
		std::cout << "\tAge: " << this->age << std::endl << "\tSalary: " << this->salary << std::endl << "\tDepartment: " << this->department << std::endl;
		std::cout << std::endl;
	}
}
