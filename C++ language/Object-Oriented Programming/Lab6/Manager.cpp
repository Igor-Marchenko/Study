#include "Manager.h"

Manager::Manager(const Manager &m) {
	if (this != &m) {
		this->f_name = m.f_name;
		this->l_name = m.l_name;
		this->age = m.age;
		this->department = m.department;
		this->id = m.id;
		this->salary = m.salary;
		this->subordinates = m.subordinates;
	}
}

Manager& Manager::operator=(const Manager &m) {
	if (this != &m) {
		this->f_name = m.f_name;
		this->l_name = m.l_name;
		this->age = m.age;
		this->department = m.department;
		this->id = m.id;
		this->salary = m.salary;
		this->subordinates = m.subordinates;
	}
	return *this;
}

void Manager::Display(bool Subordinates) {
	std::cout << "Employment type: Manager" << std::endl;
	std::cout << "ID: " << this->id << std::endl << "First and Last Name: " << this->f_name << " " << this->l_name << std::endl;
	std::cout << "Age: " << this->age << std::endl << "Salary: " << this->salary << std::endl << "Department: " << this->department << std::endl;
	if (subordinates.empty())
		std::cout << "Subordinates: none\n" << std::endl;
	else {
		std::cout << "Subordinates:" << std::endl << std::endl;
		DisplaySubordinates();
	}
}

Person* Manager::AddSubordinate(Person *p) {
	if (p == nullptr)
		return nullptr;
	else {
		for (std::list<Person *>::iterator it = subordinates.begin(); it != subordinates.end(); it++) {
			if (dynamic_cast<Employee*>(*it)->GetId() == dynamic_cast<Employee*>(p)->GetId())
				return nullptr;
		}
		if (dynamic_cast<Employee*>(p)->GetDepartment() != this->GetDepartment())
			dynamic_cast<Employee*>(p)->SetDepartment(this->department);
		subordinates.push_back(p);
		return p;
	}
}

void Manager::DisplaySubordinates() {
	for (std::list<Person*>::iterator it = subordinates.begin(); it != subordinates.end(); it++)
		dynamic_cast<Employee*>(*it)->Display(true);
}

bool Manager::FireEmployee(int id) {
	bool flag = false;
	if (this->id == id) {
		subordinates.erase(subordinates.begin(), subordinates.end());
		flag = true;
	}
	else {
		for (std::list<Person*>::iterator it = subordinates.begin(); it != subordinates.end(); it++) {
			if (dynamic_cast<Employee*>(*it)->GetId() == id) {
				std::list<Person*>::iterator it1 = it;
				subordinates.erase(it1);
				flag = true;
				break;
			}
		}
	}
	if (flag == false)
		return false;
	return true;
}