#include "AccountData.cpp"

class systemAdmin
{
    public:
        systemAdmin ();
		~systemAdmin ();
        void createAcc();
        void rmAcc();
        void accRecovery();
        void displayAdminMenu();
        void encryptAccount ();
        void encryptInventory ();
        
};

systemAdmin ::systemAdmin ()
{

}

systemAdmin ::~systemAdmin ()
{

}

void systemAdmin :: createAcc()
{
    if (database.createAccount ())
		cout << "Create Account Successful" << endl;
	else
		cout << "Create Account Failure" << endl;
}   

void systemAdmin :: rmAcc()
{
	if (database.removeAccount ())
		cout << "Create Account Successful" << endl;
	else
		cout << "Create Account Failure" << endl;
}

void systemAdmin :: accRecovery()
{
    int choice;
	char staffID [MAXLEN];
	do
	{
		cout << "--------------------------------------\n";
		cout << "Account Recovery\n";
		cout << "--------------------------------------\n";
	    	cout << "1) Unlock Account\n";
	   	cout << "2) Reset Password\n";
	    	cout << "3) Display Accounts\n";
		cout << "4) Back\n";
		cout << "--------------------------------------\n";
		cout << "Choice: ";
		cin >> choice;
		cin.clear();
		cin.ignore (MAXLEN, '\n');
		
		if (choice == 1)
		{
			cout << "Account ID: ";
			cin >> staffID;
			cin.clear();
			cin.ignore (MAXLEN, '\n'); 
			if (database.unlockAccount (staffID))
				cout << "Unlock Account Successful" << endl;
			else
			{
				cout << "Account ID \'" << staffID 
					 << "\' does not exists!" << endl;
				cout << "Unlock Account Failure" << endl;
			}
		}
		else if (choice == 2)
		{
			cout << "Account ID: ";
			cin >> staffID;
			cin.clear();
			cin.ignore (MAXLEN, '\n'); 
			if (database.resetPassword (staffID))
				cout << "Reset Password Successful" << endl;
			else
			{
				cout << "Account ID \'" << staffID 
					 << "\' does not exists!" << endl;
				cout << "Reset Password Failure" << endl;
			}
		}
		else if (choice == 3)
		{
			database.displayAccounts ();
		}
	
	} while (choice != 4);
}

void systemAdmin :: displayAdminMenu()
{
    cout << "--------------------------------------\n";
	cout << "Administrator Menu\n";
	cout << "--------------------------------------\n";
    cout << "1) Create Account\n";
    cout << "2) Remove Account\n";
    cout << "3) Account Recovery\n";
    cout << "4) Encrypt Account Database\n";
    cout << "5) Encrypt Inventory Database\n";
    cout << "6) Back\n";
	cout << "--------------------------------------\n";
}

 void systemAdmin :: encryptAccount ()
 {
       char txtFileName[MAXLEN];
       cout << "Enter filename to encrypt: ";
       cin >> txtFileName;
       cin.clear ();
       cin.ignore (MAXLEN, '\n');
       database.encryptFile (txtFileName, "AccountData.dat");
       database.readFile ("AccountData.dat");
 }
 
 void systemAdmin :: encryptInventory ()
 {
       char txtFileName[MAXLEN];
       cout << "Enter filename to encrypt: ";
       cin >> txtFileName;
       cin.clear ();
       cin.ignore (MAXLEN, '\n');
       inventory.encryptFile (txtFileName, "items.dat");
       inventory.readFile ("items.dat");
 }

