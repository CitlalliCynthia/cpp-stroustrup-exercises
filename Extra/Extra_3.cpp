#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class Employee {

public:
	Employee(const std::string& nameArg)
		: name(nameArg) {}

	std::string getName() {
		return name;
	}

	virtual double calculateSalary() = 0;
	virtual ~Employee() {}
	
protected:
	std::string name;
};

class PermanentEmployee : public Employee {

public:
	PermanentEmployee(const std::string& nameArg, double salary) 
	: Employee(nameArg), monthlySalary(salary) {}
	
	double calculateSalary() {
		return monthlySalary;
	}

private:
	double monthlySalary;
};

class HourEmployee : public Employee {

public:
	HourEmployee(const std::string& nameArg, int hours, double salary)
		: Employee(nameArg), workedHours(hours), hourSalary(salary) {}

	double calculateSalary() {
		return workedHours * hourSalary;
	}

private:
	int workedHours;
	double hourSalary;
};

int main() {

	std::vector<Employee*> employeeList;

	employeeList.push_back(new PermanentEmployee("Ana",10000.21));
	employeeList.push_back(new HourEmployee("Maria", 160, 20.661));
	employeeList.push_back(new PermanentEmployee("Rosaline", 9700.33));
	employeeList.push_back(new HourEmployee("Josephine", 160, 56.341));

	std::cout << std::fixed << std::setprecision(2);
	for (size_t i = 0; i < employeeList.size(); i++) {
		std::cout << "Employee " << employeeList[i]->getName() << " makes " << employeeList[i]->calculateSalary() << "\n";
		delete employeeList[i];
	}

	employeeList.clear();
	return 0;
}