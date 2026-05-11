// Perfume Blending System

#include <iostream>
#include <string>
using namespace std;

int main_menu()
{
    cout << "1. Show stocks \n";
    cout << "2. Show reciepts\n";
    cout << "3. Create perfume\n";
    cout << "4. Exit\n";

    int choice;
    cout << "\nEnter choice: ";
    cin >> choice;
    
    return choice;
}

void start_stocks()
{
    cout << "\n--- STOCKS ---\n";
    cout << "Alcohol: 100ml\n";
    cout << "Rose smell: 300ml\n";
    cout << "Vanilla smell: 250ml\n";
    cout << "Citrus smell: 200ml\n";
    cout << "Empty bottles: 50\n";
    cout << "------------------\n";
}

int main()
{
    string user, pass;
    const string correctUser = "perfumer";
    const string correctPass = "blend123";
    bool loggedIn = false;

    for (int attempt = 1; attempt <= 3; attempt++)
    {
        cout << "Attempt " << attempt << " of 3\n";

        cout << "Enter username: ";
        cin >> user;

        cout << "Enter password: ";
        cin >> pass;

        if (user == correctUser && pass == correctPass)
        {
            loggedIn = true;
            break;  // βγαίνει από το loop
        }
        else
        {
            cout << "Incorrect username or password.\n";
        }
    }

    if (loggedIn)
    {
        cout << "Login successful! Welcome, " << correctUser << ".\n";
        main_menu();
    }
    else
    {
        cout << "3 failed attempts. Access denied.\n";
        return 0;
    }

    while (true)
    {
        int choice = main_menu();

        switch (choice)
        {
            case 1:
                start_stocks();
                break;
            case 2:
                cout << "\n--- RECIPES ---\n";
                cout << "Rose Mist: Αλκοόλη 20 ml, Άρωμα Τριαντάφυλλου 10 ml, Μπουκάλι 1.\n";
                cout << "Vanilla Dream: Vanilla Dream 25ml, Άρωμα Βανίλιας 12 ml, Μπουκάλι 1.\n";
                cout << "Citrus Breeze: Αλκοόλη  18 ml, Έλαιο Εσπεριδοειδών 8 ml, Μπουκάλι 1.\n";
                cout << "------------------\n";
                break;
            case 3:
                cout << "Feature not implemented yet.\n";
                break;
            case 4:
                cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
