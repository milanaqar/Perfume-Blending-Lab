// Perfume Blending System

#include <iostream>
#include <string>
#include <algorithm>   // for min function
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
    cout << "Alcohol: 1000 ml\n";
    cout << "Rose Essence: 300 ml\n";
    cout << "Vanilla Essence: 250 ml\n";
    cout << "Citrus Oil: 200 ml\n";
    cout << "Empty Bottles: 50\n";
    cout << "------------------\n";

}

int max_production()
{
    // stock 
    int alcohol = 1000;
    int rose = 300;
    int vanilla = 250;
    int citrus = 200;
    int bottles = 50;
    
    // recipe per bottle
    // Rose mist
    int rose_alcohol = 20;
    int rose_essence = 10;
    
    // Vanilla Dream
    int vanilla_alcohol = 25;
    int vanilla_essence = 12;
    
    // Citrus Dream 
    int citrus_alcohol = 18;
    int citrus_oil = 8;
    
    // calculation 
    int max_rose = min({alcohol / rose_alcohol, rose / rose_essence, bottles});
    int max_vanilla = min({alcohol / vanilla_alcohol, vanilla / vanilla_essence, bottles});
    int max_citrus = min({alcohol / citrus_alcohol, citrus / citrus_oil, bottles});
    
    // output
    cout << "\n--- MAX POSSIBLE PRODUCTION ---\n";
    cout << "Rose Mist: " << max_rose << " bottles\n";
    cout << "Vanilla Dream: " << max_vanilla << " bottles\n";
    cout << "Citrus Breeze: " << max_citrus << " bottles\n";
    cout << "--------------------------------\n";

    return max_rose, max_vanilla, max_citrus;
    
}

int choice_perfume(int max_rose)
{
    cout << "\n--- CREATE PERFUME ---\n";
    cout << "1. Rose Mist\n";
    cout << "2. Vanilla Dream\n";
    cout << "3. Citrus Breeze\n";
    cout << "------------------\n";

    int choice_perfume;
    cout << "Enter choice: ";
    cin >> choice_perfume;

    cout << "Enter quantity (number of bottles): ";
    int quantity;
    cin >> quantity;

    switch (choice_perfume)
    {
        case 1:
            cout << "Creating " << quantity << " bottles of Rose Mist...\n";
           
            if (quantity > max_rose)
            {
                cout << "Not enough stock to create " << quantity << " bottles of Rose Mist. Maximum possible: " << max_rose << " bottles.\n";
            } 
            break;
        case 2:
            cout << "Creating " << quantity << " bottles of Vanilla Dream...\n";
            break;
        case 3:
            cout << "Creating " << quantity << " bottles of Citrus Breeze...\n";
            break;
        default:
            cout << "Invalid choice. Returning to main menu.\n";
    }

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
    }
    else
    {
        cout << "3 failed attempts. Access denied.\n";
        return 0;
    }

    while (true)
    {
        int choice = main_menu();
        int max_rose = max_production();

        switch (choice)
        {
            case 1:
                start_stocks();
                break;
            case 2:                       // error : showing max production without need 
                cout << "\n--- RECIPES ---\n";
                cout << "Rose Mist: Αλκοόλη 20 ml, Άρωμα Τριαντάφυλλου 10 ml, Μπουκάλι 1.\n";
                cout << "Vanilla Dream: Vanilla Dream 25ml, Άρωμα Βανίλιας 12 ml, Μπουκάλι 1.\n";
                cout << "Citrus Breeze: Αλκοόλη  18 ml, Έλαιο Εσπεριδοειδών 8 ml, Μπουκάλι 1.\n";
                cout << "------------------\n";
                break;
            case 3:
                max_production();       // error: showing max production two times
                choice_perfume(max_rose);
                break;
            case 4:
                cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
