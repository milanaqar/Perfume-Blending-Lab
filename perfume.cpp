// Perfume Blending System

#include <iostream>
#include <string>
using namespace std;

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

    
}

function main_menu()
{

}