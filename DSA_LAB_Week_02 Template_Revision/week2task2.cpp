
#include <iostream>
using namespace std;

// Abstract class
class Employee
{
public:
    virtual double calculateSalary() = 0;
};

// FullTimeEmployee class
class FullTimeEmployee : public Employee
{
private:
    double fixedSalary;

public:
    FullTimeEmployee(double salary)
    {
        fixedSalary = salary;
    }

    double calculateSalary() override
    {
        return fixedSalary;
    }
};

// PartTimeEmployee class
class PartTimeEmployee : public Employee
{
private:
    int hoursWorked;
    double hourlyRate;

public:
    PartTimeEmployee(int hours, double rate)
    {
        hoursWorked = hours;
        hourlyRate = rate;
    }

    double calculateSalary() override
    {
        return hoursWorked * hourlyRate;
    }
};

// Main function
int main()
{
    FullTimeEmployee employee1(50000);

    PartTimeEmployee employee2(80, 500);

    cout << "Full Time Employee Salary: "
        << employee1.calculateSalary() << endl;

    cout << "Part Time Employee Salary: "
        << employee2.calculateSalary() << endl;

    return 0;
}
