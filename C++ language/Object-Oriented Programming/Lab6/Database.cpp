#include "Database.h"

bool Database::LoadFromFile(const char *file) {
	if (file == nullptr)
		return false;
	std::ifstream ifs;
	ifs.open(file, std::ifstream::in);
	if (ifs.is_open() == false)
		return false;
	std::string buff;
	while (getline(ifs, buff)) {
		Employee *ne = nullptr;
		Manager	*nm = nullptr;
		int o_pos = 0, n_pos = 0, id = 0, age = 0, salary = 0;
		std::string f_name, l_name, dep;
		n_pos = buff.find(';', 2);
		std::string buff1;
		buff1.assign(buff, 2, n_pos - 2);
		id = stoi(buff1, nullptr, 10);
		if (If_Doubled(id) == true)
			continue;
		int flag = 0;
		while (flag < 5) {
			o_pos = n_pos + 1;
			if (flag == 4)
				n_pos = buff.size() - 1;
			else
				n_pos = buff.find(';', o_pos);
			switch (flag) {
				case 0: {
					f_name.assign(buff, o_pos, n_pos - o_pos);
					break;
				}
				case 1:{
					l_name.assign(buff, o_pos, n_pos - o_pos);
					break;
				}
				case 2: {
					buff1.assign(buff, o_pos, n_pos - o_pos);
					age = stoi(buff1, nullptr, 10);
					break;
				}
				case 3: {
					dep.assign(buff, o_pos, n_pos - o_pos);
					break;
				}
				case 4: {
					buff1.assign(buff, o_pos, n_pos - o_pos + 1);
					salary = stoi(buff1, nullptr, 10);
					break;
				}
			}
			flag++;
		}
		if (buff[0] == '0') {
			ne = new Employee(f_name, l_name, age, id);
			ne->SetDepartment(dep);
			ne->SetSalary(salary);
			employees.push_back(ne);
		}
		else {
			nm = new Manager(f_name, l_name, age, id);
			nm->SetDepartment(dep);
			nm->SetSalary(salary);
			employees.push_back(nm);
		}
	}
	ifs.close();
	return true;
}

void Database::ArrangeSubordinates() {
	for (std::vector<Person *>::iterator it = employees.begin(); it != employees.end(); it++) {
		if (typeid(**it) == typeid(Manager)) {
			for (std::vector<Person *>::iterator it1 = employees.begin(); it1 != employees.end(); it1++) {
				if ((typeid(**it1) == typeid(Employee)) && (dynamic_cast<Manager*>(*it)->GetDepartment() == dynamic_cast<Employee*>(*it1)->GetDepartment()))
					dynamic_cast<Manager*>(*it)->AddSubordinate(*it1);
			}
		}
	}
}

Person* Database::HireEmployee(Person *p) {
	if (p == nullptr)
		return nullptr;
	for (std::vector<Person*>::iterator it = employees.begin(); it != employees.end(); it++) {
		if (typeid(**it) == typeid(*p) && typeid(**it) == typeid(Employee)) {
			if (dynamic_cast<Employee*>(*it)->GetId() == dynamic_cast<Employee*>(p)->GetId())
				return nullptr;
		}
		else {
			if (typeid(**it) == typeid(*p) && typeid(**it) == typeid(Manager)) {
				if (dynamic_cast<Manager*>(*it)->GetId() == dynamic_cast<Manager*>(p)->GetId())
					return nullptr;
			}
		}
	}
	employees.push_back(p);
	return p;
}

void Database::DisplayDepartmentEmployees(std::string department) {
	for (std::vector<Person*>::iterator it = employees.begin(); it != employees.end(); it++) {
		if (dynamic_cast<Employee*>(*it)->GetDepartment() == department)
			(*it)->Display(false);
	}
}

bool Database::FireEmployee(int id) {
	bool flag = false;
	std::vector<Person*>::iterator it = employees.begin();
	while(it != employees.end()) {
		if (typeid(**it) == typeid(Employee)) {
			if (dynamic_cast<Employee*>(*it)->GetId() == id) {
				std::vector<Person*>::iterator it1 = it;
				it = employees.erase(it1);
				flag = true;
			}
			else
				it++;
		}
		else {
			if (typeid(**it) == typeid(Manager)) {
				flag = dynamic_cast<Manager*>(*it)->FireEmployee(id);
				if (dynamic_cast<Manager*>(*it)->GetId() == id) {
					std::vector<Person*>::iterator it1 = it; 
					it = employees.erase(it1);
					flag = true;
				}
				else
					it++;
			}
			else
				it++;
		}
	}
	if (flag == false)
		return false;
	return true;
}

void Database::DisplayAll() {
	for (std::vector<Person*>::iterator it = employees.begin(); it != employees.end(); it++) 
		(*it)->Display(false);
}

bool Database::If_Doubled(int id) {
	if (!employees.empty()) {
		for (std::vector<Person*>::iterator it = employees.begin(); it != employees.end(); it++) {
			if (typeid(**it) == typeid(Employee)) {
				if (dynamic_cast<Employee*>(*it)->GetId() == id)
					return true;
			}
			else {
				if (dynamic_cast<Manager*>(*it)->GetId() == id)
					return true;
			}
		}
	}
	return false;
}

std::vector<Person*> Database::SQL(const char *field, const char * cond, const char* value) {
	std::vector<Person*> tmp;
	for (std::vector<Person*>::iterator it = employees.begin(); it != employees.end(); it++) {
		if (strcmp(field, "id") == 0) {
			int id = atoi(value);
			if (typeid(**it) == typeid(Employee)) {
				if (strcmp(cond, "eq") == 0) {
					if (dynamic_cast<Employee*>(*it)->GetId() == id)
						tmp.push_back(dynamic_cast<Employee*>(*it));
				}
				if (strcmp(cond, "lt") == 0) {
					if (dynamic_cast<Employee*>(*it)->GetId() < id)
						tmp.push_back(dynamic_cast<Employee*>(*it));
				}
				if (strcmp(cond, "gt") == 0) {
					if (dynamic_cast<Employee*>(*it)->GetId() > id)
						tmp.push_back(dynamic_cast<Employee*>(*it));
				}
			}
			if (typeid(**it) == typeid(Manager)) {
				if (strcmp(cond, "eq") == 0) {
					if (dynamic_cast<Manager*>(*it)->GetId() == id)
						tmp.push_back(dynamic_cast<Manager*>(*it));
				}
				if (strcmp(cond, "lt") == 0) {
					if (dynamic_cast<Manager*>(*it)->GetId() < id)
						tmp.push_back(dynamic_cast<Manager*>(*it));
				}
				if (strcmp(cond, "gt") == 0) {
					if (dynamic_cast<Manager*>(*it)->GetId() > id)
						tmp.push_back(dynamic_cast<Manager*>(*it));
				}
			}
		}
		if (strcmp(field, "department") == 0) {
			std::string department = value;
			if (typeid(**it) == typeid(Employee)) {
				if (strcmp(cond, "eq") == 0) {
					if (dynamic_cast<Employee*>(*it)->GetDepartment() == department)
						tmp.push_back(dynamic_cast<Employee*>(*it));
				}
				if (strcmp(cond, "lt") == 0) {
					if (dynamic_cast<Employee*>(*it)->GetDepartment() < department)
						tmp.push_back(dynamic_cast<Employee*>(*it));
				}
				if (strcmp(cond, "gt") == 0) {
					if (dynamic_cast<Employee*>(*it)->GetDepartment() > department)
						tmp.push_back(dynamic_cast<Employee*>(*it));
				}
			}
			if (typeid(**it) == typeid(Manager)) {
				if (strcmp(cond, "eq") == 0) {
					if (dynamic_cast<Manager*>(*it)->GetDepartment() == department)
						tmp.push_back(dynamic_cast<Manager*>(*it));
				}
				if (strcmp(cond, "lt") == 0) {
					if (dynamic_cast<Manager*>(*it)->GetDepartment() < department)
						tmp.push_back(dynamic_cast<Manager*>(*it));
				}
				if (strcmp(cond, "gt") == 0) {
					if (dynamic_cast<Manager*>(*it)->GetDepartment() > department)
						tmp.push_back(dynamic_cast<Manager*>(*it));
				}
			}
		}
		if (strcmp(field, "salary") == 0) {
			int salary = atoi(value);
			if (typeid(**it) == typeid(Employee)) {
				if (strcmp(cond, "eq") == 0) {
					if (dynamic_cast<Employee*>(*it)->GetSalary() == salary)
						tmp.push_back(dynamic_cast<Employee*>(*it));
				}
				if (strcmp(cond, "lt") == 0) {
					if (dynamic_cast<Employee*>(*it)->GetSalary() < salary)
						tmp.push_back(dynamic_cast<Employee*>(*it));
				}
				if (strcmp(cond, "gt") == 0) {
					if (dynamic_cast<Employee*>(*it)->GetSalary() > salary)
						tmp.push_back(dynamic_cast<Employee*>(*it));
				}
			}
			if (typeid(**it) == typeid(Manager)) {
				if (strcmp(cond, "eq") == 0) {
					if (dynamic_cast<Manager*>(*it)->GetSalary() == salary)
						tmp.push_back(dynamic_cast<Manager*>(*it));
				}
				if (strcmp(cond, "lt") == 0) {
					if (dynamic_cast<Manager*>(*it)->GetSalary() < salary)
						tmp.push_back(dynamic_cast<Manager*>(*it));
				}
				if (strcmp(cond, "gt") == 0) {
					if (dynamic_cast<Manager*>(*it)->GetSalary() > salary)
						tmp.push_back(dynamic_cast<Manager*>(*it));
				}
			}
		}
		if (strcmp(field, "age") == 0) {
			int age = atoi(value);
			if (typeid(**it) == typeid(Employee)) {
				if (strcmp(cond, "eq") == 0) {
					if (dynamic_cast<Employee*>(*it)->GetAge() == age)
						tmp.push_back(dynamic_cast<Employee*>(*it));
				}
				if (strcmp(cond, "lt") == 0) {
					if (dynamic_cast<Employee*>(*it)->GetAge() < age)
						tmp.push_back(dynamic_cast<Employee*>(*it));
				}
				if (strcmp(cond, "gt") == 0) {
					if (dynamic_cast<Employee*>(*it)->GetAge() > age)
						tmp.push_back(dynamic_cast<Employee*>(*it));
				}
			}
			if (typeid(**it) == typeid(Manager)) {
				if (strcmp(cond, "eq") == 0) {
					if (dynamic_cast<Manager*>(*it)->GetAge() == age)
						tmp.push_back(dynamic_cast<Manager*>(*it));
				}
				if (strcmp(cond, "lt") == 0) {
					if (dynamic_cast<Manager*>(*it)->GetAge() < age)
						tmp.push_back(dynamic_cast<Manager*>(*it));
				}
				if (strcmp(cond, "gt") == 0) {
					if (dynamic_cast<Manager*>(*it)->GetAge() > age)
						tmp.push_back(dynamic_cast<Manager*>(*it));
				}
			}
		}
	}
	return tmp;
}

void Database::ShowRecordSet(std::vector<Person*> rs) {
	if (!rs.empty()) {
		for (std::vector<Person*>::iterator it = rs.begin(); it != rs.end(); it++) {
			(*it)->Display(false);
		}
	}
}