#include "operator.h"

void Operator :: DisOpMenu()
{
    cout << "Please select from Menu:\n"
    cout << "1) Add quantity\n"
    cout << "2) Remove quantity\n"
    cout << "9) Logout \n"
            
    int choice;
    
        if (choice ==1 )
            addQty();
    
        else if (choice == 2) 
            rmQty();
        
        else if (choice  == 9)
            //BACK TO LOGIN PAGE!!!!
        
        else 
            cout << "Invalid input! Please select either 1 / 2!"
            
  
}
