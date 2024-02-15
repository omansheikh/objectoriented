#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Nomenclature
{
private:
    string productName;
    double wholesalePrice;
    double retailMargin;
    double quantityInStock;

public:
    // Constructor to initialize the object
    Nomenclature(const string& name, double wholesale, double margin, double quantity) :
        productName(name), wholesalePrice(wholesale), retailMargin(margin), quantityInStock(quantity)
    {
    }

    // Destructor
    ~Nomenclature()
    {
        cout << "Object for product '" << productName << "' is being destroyed." << endl;
    }

    // Function to calculate net income from the sale of the product
    double calculateNetIncome() const
    {
        double retailPrice = wholesalePrice * (1 + retailMargin / 100.0);
        double netIncome = retailPrice * quantityInStock - wholesalePrice * quantityInStock;
        return netIncome;
    }

    // Function to display all data about the product on the screen
    void displayProductData() const
    {
        cout << "\nProduct Name: " << productName << endl;
        cout << "Wholesale Price: $" << wholesalePrice << endl;
        cout << "Retail Margin: " << retailMargin << "%" << endl;
        cout << "Quantity in Stock: " << quantityInStock << endl;
        cout << "Net Income: $" << calculateNetIncome() << endl;
    }
};

int main()
{
    int choice = 1;
    double wholesalePrice, margin, quantity;
    string productName;
    // Example usage of Nomenclature class
    while (true)
    {
         cout << "\n\nDo you want to enter product details? (1/0): ";
         cin >> choice;
         if (choice == 0)
         {
             break;
         }
         cout << "\nEnter product details: \n";
         cout << "Enter product name: " << setw(2) ;
         cin >> productName;
         cout << "Enter wholesale price: " << setw(2) ;
         cin >> wholesalePrice;
         cout << "Enter retail margin: " << setw(2) ;
         cin >> margin;
         cout << "Enter quantity in stock: " << setw(2) ;
         cin >> quantity;
     
         Nomenclature product(productName, wholesalePrice, margin, quantity);
         product.displayProductData();
     }
    return 0;
}