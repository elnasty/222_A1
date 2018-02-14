#include "Manager.h"

void Manager :: updateStk()
{
    
}
void Manager :: orderStk()
{
    
}

void Manager :: manageStkAlert()
{
    
}
void displayMgMenu()
{
    cout << "Welcome to Manager Menu\n";
    cout << "1) Add quantity\n";
    cout << "2) Remove quantity\n";
    cout << "3) Sort stock\n";
    cout << "4) Update stock\n";
    cout << "5) Order stock\n";
    cout << "6) Review Transaction Summary\n";
    cout << "7) Manage stock alert\n";
    cout << "9) Logout \n";
    cout << "Please select your choice: ";
    int choice;
    cin  >> choice;
    cout << endl;
    
    switch (choice)
    {
        case 1: addQty ();
             break;
        case 2: rmvQty ();
             break;
        case 3: sortStk ();
             break;
        case 4: updateStk ();
             break;
        case 5: orderStk ();
             break;
        case 6: viewTransSummary ();
             break;
        case 7: manageStkAlert ();
             break;
        case 9: // go back to login page
             break;
        default: 
        cout << "Invalid input! Please select either options!" << endl;
        cout << endl;
        displayMgMenu ();
             break; 
        
    }
}