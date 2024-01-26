#include <iostream>
#include <string>
using namespace std;

// Task 1: Function to calculate power with default exponent value
double power(double base, int exponent = 2) {
    double result = 1.0;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

// Task 2: Overloaded power function for different data types
double power(char n, int p = 2) {
    return power(static_cast<double>(n), p);
}

double power(short n, int p = 2) {
    return power(static_cast<double>(n), p);
}

double power(int n, int p = 2) {
    return power(static_cast<double>(n), p);
}

double power(long int n, int p = 2) {
    return power(static_cast<double>(n), p);
}

double power(float n, int p = 2) {
    return power(static_cast<double>(n), p);
}

// Task 3: Structure for employee information
struct Employee {
    string lastName;
    int age;
    string specialty;
    double avgSalary;
};

int main() {
    // Task 1
    double number;
    int exponent;

    cout << "Enter a number: ";
    cin >> number;

    cout << "Do you want to enter the exponent? (0 for default, 1 for custom): ";
    cin >> exponent;

    exponent = (exponent == 1) ? 2 : exponent;

    cout << "Result: " << power(number, exponent) << endl;

    // Task 2
    const char char_val = 'A';
    const short short_val = 10;
    const int int_val = 5;
    const long int long_int_val = 1000;
    const float float_val = 3.14;

    cout << "Overloaded power function results:" << endl;
    cout << "char: " << power(char_val) << endl;
    cout << "short: " << power(short_val) << endl;
    cout << "int: " << power(int_val) << endl;
    cout << "long int: " << power(long_int_val) << endl;
    cout << "float: " << power(float_val) << endl;

    // Task 3
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    int mechanics_count = 0;
    int turners_count = 0;

    auto* employees = new Employee[n];

    for (int i = 0; i < n; ++i) {
        cout << "Enter information for employee " << i + 1 << ":" << endl;
        cout << "Last name: ";
        cin >> employees[i].lastName;
        cout << "Age: ";
        cin >> employees[i].age;
        cout << "Specialty: ";
        cin >> employees[i].specialty;
        cout << "Average salary: ";
        cin >> employees[i].avgSalary;

        // Count mechanics and turners
        if (employees[i].specialty == "mechanic") {
            mechanics_count++;
        } else if (employees[i].specialty == "turner") {
            turners_count++;
        }
    }

    cout << "Number of mechanics: " << mechanics_count << endl;
    cout << "Number of turners: " << turners_count << endl;

    delete[] employees;

    return 0;
}
