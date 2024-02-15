#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

class Aeroflot {
public:
    // Fields
    int flightNumber;
    std::string departurePoint; 
    std::string destination;
    std::string arrivalTime;
    std::string departureTime;
    int checkInSection;

    // Constructor
    Aeroflot(int flightNumber, const std::string& departurePoint, const std::string& destination,
            const std::string& arrivalTime, const std::string& departureTime, int checkInSection)
        : flightNumber(flightNumber), departurePoint(departurePoint), destination(destination),
          arrivalTime(arrivalTime), departureTime(departureTime), checkInSection(checkInSection) {}

    // Default constructor
    Aeroflot() : flightNumber(0), checkInSection(0) {}

    // Display the information as a table
    void display() const {
        std::cout << std::setw(12) << flightNumber
                  << std::setw(20) << departurePoint
                  << std::setw(20) << destination
                  << std::setw(15) << arrivalTime
                  << std::setw(15) << departureTime
                  << std::setw(15) << checkInSection << std::endl;
    }
};

int main() {
    const int MAX_FLIGHTS = 3; // For testing, set a small number

    std::vector<Aeroflot> flights;

    // Input values for each flight from the keyboard
    for (int i = 0; i < MAX_FLIGHTS; ++i) {
        Aeroflot flight;
        std::cout << "Enter information for Flight " << i + 1 << ":" << std::endl;
        std::cout << "Flight Number: ";
        std::cin >> flight.flightNumber;
        std::cout << "Departure Point: ";
        std::cin >> flight.departurePoint;
        std::cout << "Destination: ";
        std::cin >> flight.destination;
        std::cout << "Arrival Time: ";
        std::cin >> flight.arrivalTime;
        std::cout << "Departure Time: ";
        std::cin >> flight.departureTime;
        std::cout << "Check-in Section: ";
        std::cin >> flight.checkInSection;

        flights.push_back(flight);
    }

    // Sort flights by destination name
    std::sort(flights.begin(), flights.end(), [](const Aeroflot& a, const Aeroflot& b) {
        return a.destination < b.destination;
    });
    std::cout << "/n";
    // Display the table header
    std::cout << std::setw(12) << "Flight #"
              << std::setw(20) << "Departure Point"
              << std::setw(20) << "Destination"
              << std::setw(15) << "Arrival Time"
              << std::setw(15) << "Departure Time"
              << std::setw(15) << "Check-in Section" << std::endl;

    // Display the sorted flights
    for (const auto& flight : flights) {
        flight.display();
    }

    // Display a message if there are no flights
    if (flights.empty()) {
        std::cout << "No flights available." << std::endl;
    }

    return 0;
}
