#include "SystemAdmin.cpp"

void displayLoginMenu ();

int main ()
{
	srand (time (NULL));
	int choice;
	char whichUser;
	User userLogin;
	
	do
	{
		displayLoginMenu ();
		cout << "Choice: ";
		cin >> choice;
		cin.clear();
		cin.ignore(MAXLEN, '\n');
		
		cout << endl;
		switch (choice)
		{
			case 1:	whichUser = userLogin.login();
					
					if (whichUser == 'A')
					{
						systemAdmin admin;
						int choice1;
						
						do
						{
							admin.displayAdminMenu ();
							cout << "Choice: ";
							cin >> choice1 ;
							cin.clear();
							cin.ignore(MAXLEN, '\n');
							cout << endl;
							
							switch (choice1)
							{
								case 1: admin.createAcc();
								break;
								
								case 2: admin.rmAcc();
								break;
								
								case 3: admin.accRecovery();
								break;
								
								case 4:
								break;
							
								default: cout << "Invalid choice! " << endl;
							}
							
							cout << endl;
							
						} while (choice1 != 4);
						
					}
					else if (whichUser == 'O')
					{
						cout << "Display Operator Menu" << endl;
					}
					else if (whichUser == 'M')
					{
						cout << "Display Manager Menu" << endl;
					} 
					
			break;
			
			case 2:	userLogin.changePw();
			break;
			
			case 3:	userLogin.resetPw();
			break;
			
			case 4: cout << "Thank you! See you soon!" << endl;
			break;
			
			default: cout << "Invalid choice!" << endl;
		}
		
		cout << endl;
		
	} while (choice != 4);
	
	
}

void displayLoginMenu ()
{
	cout << "--------------------------------------" << endl;
	cout << "Welcome to Warehouse Management System" << endl;
	cout << "--------------------------------------" << endl;
	cout << "1) Login " << endl;
	cout << "2) Change Password " << endl;
	cout << "3) Reset Password " << endl;
	cout << "4) Quit" << endl;
	cout << "--------------------------------------" << endl;
}

