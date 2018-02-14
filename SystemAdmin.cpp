#include "SystemAdmin.h"

class systemAdmin
{
    public:
        systemAdmin ();
        void createAcc();
        void rmAcc();
        void accRecovery();
        
    private: 
        void disAdminMenu();
       
        
};

void systemAdmin :: createAcc()
{
    
}   

void systemAdmin :: rmAcc()
{
    
}

void systemAdmin :: accRecovery()
{
    
}

void systemAdmin :: disAdminMenu()
{
    cout << "Please select from Menu";
    cout << "1) Create new Account\n"
    cout << "2) Remove an account\n"
    cout << "3) Account Recovery\n"
    cout << "9) Quit";
    
    int choice;
    
    cin >> choice;
    
         if (choice ==1 )
            createAcc();
    
        else if (choice == 2) 
            rmAcc();
        
        else if (choice == 3) 
            accRecovery();
        
        else if (choice  == 9)
            //BACK TO LOGIN PAGE!!!!
        
        else 
            cout << "Invalid input! Please select either options!"
            
  
    
    
}