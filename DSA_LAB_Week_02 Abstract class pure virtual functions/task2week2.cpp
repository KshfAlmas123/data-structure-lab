
#include <iostream>
using namespace std;

// Abstract Class
class Employee {
public:
    virtual double calculateSalary() = 0;

    virtual ~Employee() {}
};

// Full Time Employee
class FullTimeEmployee : public Employee {
private:
    double fixedSalary;

public:
    FullTimeEmployee(double salary) {
        fixedSalary = salary;
    }

    double calculateSalary() override {
        return fixedSalary;
    }
};

// Part Time Employee
class PartTimeEmployee : public Employee {
private:
    double hoursWorked;
    double hourlyRate;

public:
    PartTimeEmployee(double hours, double rate) {
        hoursWorked = hours;
        hourlyRate = rate;
    }

    double calculateSalary() override {
        return hoursWorked * hourlyRate;
    }
};

int main() {

    FullTimeEmployee emp1(50000);

    PartTimeEmployee emp2(40, 500);

    cout << "Full Time Employee Salary: "
        << emp1.calculateSalary() << endl;

    cout << "Part Time Employee Salary: "
        << emp2.calculateSalary() << endl;

    return 0;
}
