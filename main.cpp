#include <iostream>
#include <string>

using namespace std;

struct Product {
    int id;
    string name;
    int quantity;
    double price;
};

Product inventory[100];
int productCount = 0;

void addProduct() {
    if (productCount < 100) {
        cout << "\n--- Enter Product Details ---" << endl;
        cout << "ID: ";
        cin >> inventory[productCount].id;
        cout << "Name: ";
        cin.ignore();
        getline(cin, inventory[productCount].name);
        cout << "Quantity: ";
        cin >> inventory[productCount].quantity;
        cout << "Price: ";
        cin >> inventory[productCount].price;

        productCount++;
        cout << "\n[Success] Product added to the array!" << endl;
    } else {
        cout << "\n[Error] Inventory is full!" << endl;
    }
}

void displayProducts() {
    if (productCount == 0) {
        cout << "\n[Alert] Inventory is empty!" << endl;
        return;
    }

    cout << "\nID\tName\t\tQty\tPrice" << endl;
    cout << "--------------------------------------------" << endl;
    for (int i = 0; i < productCount; i++) {
        cout << inventory[i].id << "\t"
             << inventory[i].name << "\t\t"
             << inventory[i].quantity << "\t$"
             << inventory[i].price << endl;
    }
}

void searchProduct() {
    int searchId;
    cout << "\nEnter ID to search: ";
    cin >> searchId;

    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == searchId) {
            cout << "\nProduct Found!" << endl;
            cout << "Name: " << inventory[i].name << endl;
            cout << "Price: $" << inventory[i].price << endl;
            return;
        }
    }
    cout << "\n[Alert] Product ID not found." << endl;
}

int main() {
    int choice;

    while (true) {
        cout << "\n==== STORE MANAGEMENT SYSTEM ====" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Display All" << endl;
        cout << "3. Search by ID" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            addProduct();
        } else if (choice == 2) {
            displayProducts();
        } else if (choice == 3) {
            searchProduct();
        } else if (choice == 4) {
            cout << "Exiting program..." << endl;
            break;
        } else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
