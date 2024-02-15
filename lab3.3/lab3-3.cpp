#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Software
{
private:
    string programName;
    string developer;
    double volumeOccupied;
    time_t licenseExpirationDate;

public:
    // Constructor to initialize the object
    Software(const string& name, const string& dev, double volume, time_t expirationDate) :
        programName(name), developer(dev), volumeOccupied(volume), licenseExpirationDate(expirationDate)
    {
    }

    // Destructor
    ~Software()
    {
        cout << "Object for software '" << programName << "' is being destroyed." << endl;
    }

    // Function to count the number of days until the license expires
    int daysUntilExpiration() const
    {
        time_t currentTime;
        time(&currentTime);
        double secondsRemaining = difftime(licenseExpirationDate, currentTime);
        int daysRemaining = static_cast<int>(secondsRemaining / (24 * 3600));
        return daysRemaining;
    }

    // Function to display all installed software data on the screen
    void displaySoftwareData() const
    {
        cout << "Program Name: " << programName << endl;
        cout << "Developer: " << developer << endl;
        cout << "Volume Occupied: " << volumeOccupied << " GB" << endl;

        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &licenseExpirationDate);
        cout << "License Expiration Date: " << buffer;

        int daysRemaining = daysUntilExpiration();
        cout << "Days until License Expiration: " << daysRemaining << " days" << endl;

        if (daysRemaining <= 0)
        {
            cout << "Attention: The license has expired!" << endl;
        }
    }
};

time_t convertToDate(const string& dateString)
{
    struct tm expirationDate = {};
    sscanf_s(dateString.c_str(), "%d/%d/%d", &expirationDate.tm_mday, &expirationDate.tm_mon, &expirationDate.tm_year);
    expirationDate.tm_mon--; // Adjust month (January is 0 in tm struct)
    expirationDate.tm_year -= 1900; // Adjust year (years since 1900)
    return mktime(&expirationDate);
}

int main()
{
    char choice;

    while (true)
    {
        cout << "\nDo you want to enter software details? (1/0): ";
        cin >> choice;

        if (choice == '0')
        {
            break;
        }

        string programName, developer, expirationDateString;
        double volumeOccupied;

        cout << "\nEnter software details: \n";
        cout << "Enter program name: ";
        cin >> programName;
        cout << "Enter developer: ";
        cin >> developer;
        cout << "Enter volume occupied (in GB): ";
        cin >> volumeOccupied;
        cout << "Enter expiration date (e.g., 30/12/2333): ";
        cin >> expirationDateString;

        time_t expirationDate = convertToDate(expirationDateString);

        Software software(programName, developer, volumeOccupied, expirationDate);
        software.displaySoftwareData();
    }
    return 0;
}

