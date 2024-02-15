#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>

class Student {
public:
    std::string surname;
    std::string name;
    std::string dateOfBirth;
    std::string phoneNumber;

    void setStudent(const std::string& s, const std::string& n, const std::string& dob, const std::string& pn) {
        surname = s;
        name = n;
        dateOfBirth = dob;
        phoneNumber = pn;
    }

    void showStudent() const {
        std::cout << std::left << std::setw(20) << surname
                  << std::left << std::setw(15) << name
                  << std::left << std::setw(20) << dateOfBirth
                  << std::left << std::setw(15) << phoneNumber << std::endl;
    }
};

class StudentGroup {
private:
    static const int maxSize = 100;
    Student students[maxSize];
    int numberOfStudents;

public:
    StudentGroup() : numberOfStudents(0) {}

    void addStudent(const Student& newStudent) {
        if (numberOfStudents < maxSize) {
            students[numberOfStudents++] = newStudent;
        } else {
            std::cout << "Error: Unable to add a new student. Group size limit reached." << std::endl;
        }
    }

    void removeStudent(const std::string& surname) {
        auto it = std::find_if(students, students + numberOfStudents,
                               [&surname](const Student& student) {
                                   return student.surname == surname;
                               });

        if (it != students + numberOfStudents) {
            *it = students[--numberOfStudents];
        } else {
            std::cout << "Student with the surname " << surname << " not found." << std::endl;
        }
    }

    Student findStudentBySurname(const std::string& surname) const {
        auto it = std::find_if(students, students + numberOfStudents,
                               [&surname](const Student& student) {
                                   return student.surname == surname;
                               });

        return (it != students + numberOfStudents) ? *it : Student{};
    }

    void sortStudentsBySurname() {
        std::sort(students, students + numberOfStudents,
                  [](const Student& a, const Student& b) {
                      return a.surname < b.surname;
                  });
    }

    void displayAllStudents() const {
        if (numberOfStudents == 0 || students->surname.empty()) {
            std::cout << "No students in the group." << std::endl;
            return;
        }

        std::cout << std::left << std::setw(20) << "Surname"
                  << std::left << std::setw(15) << "Name"
                  << std::left << std::setw(20) << "Date of Birth"
                  << std::left << std::setw(15) << "Phone Number" << std::endl;

        for (int i = 0; i < numberOfStudents; ++i) {
            students[i].showStudent();
        }
    }
};

void printMenu() {
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Add a student" << std::endl;
    std::cout << "2. Remove a student" << std::endl;
    std::cout << "3. Find a student by surname" << std::endl;
    std::cout << "4. Sort students by surname" << std::endl;
    std::cout << "5. Display all students" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Select an action: ";
}

int main() {
    StudentGroup group;

    while (true) {
        printMenu();

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "Enter student information:" << std::endl;
                std::string surname, name, dateOfBirth, phoneNumber;
                std::cout << "Surname: ";
                std::cin >> surname;
                std::cout << "Name: ";
                std::cin >> name;
                std::cout << "Date of Birth: ";
                std::cin >> dateOfBirth;
                std::cout << "Phone Number: ";
                std::cin >> phoneNumber;

                Student newStudent;
                newStudent.setStudent(surname, name, dateOfBirth, phoneNumber);
                group.addStudent(newStudent);
                break;
            }
            case 2: {
                std::cout << "Enter the surname of the student to remove: ";
                std::string surname;
                std::cin >> surname;
                group.removeStudent(surname);
                break;
            }
            case 3: {
                std::cout << "Enter the surname of the student to find: ";
                std::string surname;
                std::cin >> surname;

                Student foundStudent = group.findStudentBySurname(surname);
                if (!foundStudent.surname.empty()) {
                    std::cout << "\nFound student:\n";
                    foundStudent.showStudent();
                } else {
                    std::cout << "Student with the surname " << surname << " not found." << std::endl;
                }
                break;
            }
            case 4:
                group.sortStudentsBySurname();
                std::cout << "Students sorted by surname." << std::endl;
                break;
            case 5:
                group.displayAllStudents();
                break;
            case 0:
                std::cout << "Exiting the program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid input. Please choose again." << std::endl;
                break;
        }
    }
    return 0;
}
