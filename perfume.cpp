// Perfume Blending System

#include <iostream>
#include <string>
using namespace std;

void main_menu()
{
    cout << "1. Show stocks \n";
    cout << "2. Show reciepts\n";
    cout << "3. Create perfume\n";
    cout << "4. Exit\n";

    int choice;
    cout << "\nEnter choice: ";
    cin >> choice;
}

void start_stocks()
{
    cout << "Alcohol: 100ml\nRose smell: 300ml\nVanilia smell\nCitrus smell: 200ml\nEmpty bottles: 50\n";
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


    
    if (int choiice = '1')
    {
        start_stocks();
        main_menu();
    }
    return 0;
}
