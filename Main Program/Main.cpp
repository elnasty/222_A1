#include "Operator.cpp"

void displayLoginMenu ();

Date GLOBALDATE;

int main ()
{
	srand (time (NULL));
    updateDate(GLOBALDATE);
	int choice;
	char whichUser;
	char userID [MAXLEN];
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
			case 1:	strcpy (userID, userLogin.login());
					whichUser = userID [0];
					
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
						int choice2;
						Operator opr(userID);
						
						do
						{
							opr.displayOperatorMenu ();
							cout << "Choice: ";
							cin >> choice2 ;
							cin.clear();
							cin.ignore(MAXLEN, '\n');
							
							
							switch (choice2)
							{
								case 1: opr.addStockQty ();
								break;
								
								case 2: opr.rmStockQty ();
								break;
								
								case 3: 
								break;
								
							
								default: cout << "Invalid choice! " << endl;
							}
							
							cout << endl;
							
							
						} while (choice2 != 3);
					}
					else if (whichUser == 'M')
					{
						int choice3;
						Manager manager;
						do
						{
							manager.displayManagerMenu ();
							cout << "Choice: ";
							cin >> choice3 ;
							cin.clear();
							cin.ignore(MAXLEN, '\n');
							cout << endl;
							switch (choice3)
							{
								case 1: manager.addNewStock();
								break;
								
								case 2:	manager.removeStock();
								break;
								
								case 3: manager.editStock();
								break;
								
								case 4: manager.searchStock();
								break;
								
								case 5: manager.reviewTransactionSummary();
								break;
								
								case 6: manager.stockAlert();
								break;
								
								case 7: 
								break;
								
								default:	cout << "Invalid choice! " << endl;
							
							}
							
							cout << endl;
							
						} while (choice3 != 7);
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

