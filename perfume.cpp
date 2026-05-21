// Perfume Blending Lab

#include <iostream>
#include <string>
#include <algorithm>  // for min function
using namespace std;

// ===== GLOBAL VARIABLES =====
int alcohol = 1000;            //μπήκαν εδώ γιατί μεσα στη συνάρτηση max_production κάθε φορά τα επανέφερε στις αρχικές ποσότητες
int rose    = 300;
int vanilla = 250;
int citrus  = 200;
int bottles = 50;

int max_rose    = 0;
int max_vanilla = 0;
int max_citrus  = 0;

int rose_produced = 0;     // για να κρατάει πόσα αρώματα έχουν παραχθεί
int vanilla_produced = 0;
int citrus_produced = 0;

// ===== MAIN MENU =====
int main_menu()
{
    cout << "\n--- MAIN MENU ---\n";
    cout << "1. Show stocks\n";
    cout << "2. Show recipes\n";
    cout << "3. Create perfume\n";
    cout << "4. Produced perfumes\n";
    cout << "5. Exit\n";

    int choice;
    cout << "\nEnter choice: ";
    cin >> choice;

    return choice;
}



// ===== STOCKS =====
void start_stocks()
{
    cout << "\n--- STOCKS ---\n";
    cout << "Alcohol: " << alcohol << " ml\n";
    cout << "Rose Essence: " << rose << " ml\n";
    cout << "Vanilla Essence: " << vanilla << " ml\n";
    cout << "Citrus Oil: " << citrus << " ml\n";
    cout << "Empty Bottles: " << bottles << "\n";
    cout << "------------------\n";
}



// ===== MAX PRODUCTION CALCULATION =====
void max_production()                    
{
    // Recipe per bottle
    int rose_alcohol    = 20;
    int rose_essence    = 10;

    int vanilla_alcohol = 25;
    int vanilla_essence = 12;

    int citrus_alcohol  = 18;
    int citrus_oil      = 8;

    // Update global variables
    max_rose    = min({alcohol / rose_alcohol,    rose    / rose_essence,    bottles});
    max_vanilla = min({alcohol / vanilla_alcohol, vanilla / vanilla_essence, bottles});
    max_citrus  = min({alcohol / citrus_alcohol,  citrus  / citrus_oil,      bottles});
}



// ===== PRINT MAX PRODUCTION =====
void print_max_production()        //ξεχωριστή συνάρτηση για εκτύπωση
{
    cout << "\n--- MAX POSSIBLE PRODUCTION ---\n";
    cout << "Rose Mist:     " << max_rose    << " bottles\n";
    cout << "Vanilla Dream: " << max_vanilla << " bottles\n";
    cout << "Citrus Breeze: " << max_citrus  << " bottles\n";
    cout << "--------------------------------\n";
}



// ===== CREATE PERFUME =====
void choice_perfume()                          //Χωρίς παραμέτρους, διαβάζει τα globals
{
    cout << "\n--- CREATE PERFUME ---\n";
    cout << "1. Rose Mist\n";
    cout << "2. Vanilla Dream\n";
    cout << "3. Citrus Breeze\n";
    cout << "------------------\n";

    int choice;
    cout << "Enter choice: ";
    cin >> choice;

    while (choice < 1 || choice > 3 ||              // Έλεγχος με while γιατί ζητούσε την ποσότητα ακόμα κι αν είχε πατήσει λάθος επιλογή
          (choice == 1 && max_rose == 0)    ||
          (choice == 2 && max_vanilla == 0) ||  // Αν επιλέξει αρωμα που το max του είναι 0, δεν τον αφήνει να προχωρήσει και του ζητά νέα επιλογή 
          (choice == 3 && max_citrus == 0)) 
    {  
                            
          if (choice >= 1 && choice <= 3)
          {
              cout << "Not enough stock for that perfume! Choose another: ";
          }
          else
          {
              cout << "Enter a valid choice (1-3) : ";
          }
          cin >> choice;
    }

        int quantity;
        cout << "Enter quantity (number of bottles): ";
        cin >> quantity;


        if (quantity <= 0)
        {
            cout << "Please enter a positive quantity.\n";
            choice_perfume();  // καλεί ξανά τη συνάρτηση για να επιλέξει ξανά
            return;           // επιστρέφει για να μην εκτελεστεί ο υπόλοιπος κώδικας
        }

    switch (choice)
    {
        case 1:
            if (quantity > max_rose)
            {
                cout << "Not enough stock! Maximum possible: " << max_rose << " bottles.\n";
                choice_perfume();  // καλεί ξανά τη συνάρτηση για να επιλέξει ξανά
            } 
            else
            {                                      // αφαίρεση υλικών σε κάθε else για να αλλάζει το stock
                alcohol -= 20 * quantity;
                rose    -= 10 * quantity;
                bottles -= quantity;
                cout << "Creating " << quantity << " bottles of Rose Mist!\n";
                rose_produced += quantity;  // ενημέρωση παραχθέντων αρωμάτων
            }
            break;


        case 2:
            if (quantity > max_vanilla)
            {
                cout << "Not enough stock! Maximum possible: " << max_vanilla << " bottles.\n";
                choice_perfume();  // καλεί ξανά τη συνάρτηση για να επιλέξει ξανά
            }   
            else
            {
                alcohol -= 25 * quantity;
                vanilla -= 12 * quantity;
                bottles -= quantity;
                cout << "Creating " << quantity << " bottles of Vanilla Dream!\n";
                vanilla_produced += quantity;
            }
            break;


        case 3:
            if (quantity > max_citrus)
            {
                cout << "Not enough stock! Maximum possible: " << max_citrus << " bottles.\n";
                choice_perfume();  // καλεί ξανά τη συνάρτηση για να επιλέξει ξανά
            }     
            else
            {
                alcohol -= 18 * quantity;
                citrus  -=  8 * quantity;
                bottles -= quantity;
                cout << "Creating " << quantity << " bottles of Citrus Breeze!\n";
                citrus_produced += quantity;
            }
            break;
    }

    max_production();  // for each time new max production 
}




// ===== MAIN =====
int main()
{
    // --- Login ---
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
            break;
        }
        else
        {
            cout << "Incorrect username or password.\n";
        }
    }

    if (loggedIn)
    {
        cout << "Login successful! Welcome, " << correctUser << "!\n";
    }
    else
    {
        cout << "3 failed attempts. Access denied.\n";
        return 0;
    }
 
    

    // --- Main Loop ---
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
                cout << "Rose Mist:     Alcohol 20ml, Rose Essence 10ml, 1 Bottle\n";
                cout << "Vanilla Dream: Alcohol 25ml, Vanilla Essence 12ml, 1 Bottle\n";
                cout << "Citrus Breeze: Alcohol 18ml, Citrus Oil 8ml, 1 Bottle\n";
                cout << "------------------\n";
                break;


            case 3:
                max_production();       // υπολογισμός
                
                if (max_rose == 0 && max_vanilla == 0 && max_citrus == 0)
                {        // αν και τα 3 max είναι 0, δεν υπάρχει κανένα άρωμα που μπορεί να παραχθεί, οπότε τερματίζει.
                        cout << "Sorry... There is no more alcohol available... Exiting program...\n";
                        return 0;
                }

                print_max_production(); // εκτύπωση
                choice_perfume();       // επιλογή χρήστη
                break;
            

            case 4: 
                cout << "\n--- PRODUCED PERFUMES ---\n";                      // εκτύπωση παραχθέντων αρωμάτων
                cout << "Rose Mist:     " << rose_produced << " bottles\n";     
                cout << "Vanilla Dream: " << vanilla_produced << " bottles\n";
                cout << "Citrus Breeze: " << citrus_produced << " bottles\n";
                cout << "------------------\n";
                break;


            case 5:
                cout << "Exiting program. Goodbye!\n";
                return 0;


            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
 




