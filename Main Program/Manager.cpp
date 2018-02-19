#include "SystemAdmin.cpp"

class Manager 
{
	public: 
		Manager();
		~Manager();
		void editStock();
		void orderStock();
		void stockAlert();
		void searchStock();
		void reviewTransactionSummary();
		
		void displayManagerMenu();
};

Manager::Manager ()
{

}

Manager::~Manager()
{

}

void Manager :: editStock()
{
    char itemID [LEN];
	char choice;
	cout << "Please enter Item ID: ";
	cin >> itemID;
	cin.clear();
	cin.ignore (MAXLEN, '\n');
	
	list<Stock>::iterator i;
	bool found = false;
	
	for (i = inventory.stocks.begin(); i != inventory.stocks.end() && !found; ++i)
	{
		if (strcmp(itemID, i->getID()) == 0)
		{
			found = true;
		}
	}
	
	if (found)
	{
		do
		{
			cout << "--------------------------------------\n";
		    cout << "Edit Stock Menu\n";
		    cout << "--------------------------------------\n";
			cout << "a) Item Description\n";
			cout << "b) Category\n";
			cout << "c) Sub-Category\n";
			cout << "d) Buy Price\n";
			cout << "e) Sell Price\n";
			cout << "f) Quantity\n";
			cout << "g) Back\n";
			cout << "--------------------------------------\n";
			cout << "Choice: ";
			cin >> choice;
			cin.clear ();
			cin.ignore (MAXLEN, '\n');
			
			switch (choice)
			{
				case 'a':	char desc[LEN];
							cout << "New Item Desciption: ";
							cin >> desc;
							cin.clear ();
							cin.ignore (MAXLEN, '\n');
							i -> setDesc (desc);
						
				break;
										
				case 'b': 	char itemCat [LEN];
							cout << "New Category: ";
							cin >> itemCat;
							cin.clear ();
							cin.ignore (MAXLEN, '\n');
							i -> setCat (itemCat);
				break;
										
				case 'c': 	char itemSubCat [LEN];
							cout << "New Sub-Category: ";
							cin >> itemSubCat;
							cin.clear ();
							cin.ignore (MAXLEN, '\n');
							i -> setSubCat (itemSubCat);
				break;
										
				case 'd':	double buyPrice;
							cout << "New Buy Price: ";
							cin >> buyPrice;
							cin.clear ();
							cin.ignore (MAXLEN, '\n');
							i -> setBuyPrice (buyPrice);
				break;
				
				case 'e':	double sellPrice;
							cout << "New Sell Price: ";
							cin >> sellPrice;
							cin.clear ();
							cin.ignore (MAXLEN, '\n');
							i -> setSellPrice (sellPrice);
				break;
				
				case 'f':	int qty;
							cout << "New Quantity: ";
							cin >> qty;
							cin.clear ();
							cin.ignore (MAXLEN, '\n');
							i -> setQty (qty);
				break;
				
				case 'g':
				break;
									
				default: cout << "Invalid choice! " << endl;
			}
			cout << endl;
		
		} while (choice != 'g');
	}
	else
	{
		cout << "Item with ID /'" << itemID
			 << "/' not found!" << endl;
			 
	}
}

void Manager :: searchStock()
{
	char choice;
	cout << "--------------------------------------\n";
	cout << "Search Stock Menu\n";
	cout << "--------------------------------------\n";
	cout << "a) Item Description\n";
	cout << "b) Category\n";
	cout << "c) Sub-Category\n";
	cout << "d) Buy Price\n";
	cout << "e) Sell Price\n";
	cout << "f) Quantity\n";
	cout << "g) Back\n";
	cout << "--------------------------------------\n";
	cout << "Choice: ";
	cin >> choice;
	cin.clear ();
	cin.ignore (MAXLEN, '\n');
}

void Manager :: reviewTransactionSummary()
{

}

void Manager :: orderStock()
{
    
}

void Manager :: stockAlert()
{
    int threshold;
	char alert[MAXLEN];
	list<Stock>::iterator i;
	char choice;
	
	do
	{
		cout << "--------------------------------------\n";
		cout << "Stock Alert Menu\n";
		cout << "--------------------------------------\n";
		cout << "a) Set Threshold\n";
		cout << "b) Set Alert Message\n";
		cout << "c) Back\n";
		cout << "--------------------------------------\n";
		cout << "Choice: ";
		cin >> choice;
		cin.clear ();
		cin.ignore (MAXLEN, '\n');
		
		switch (choice)
		{
		
			case 'a':	for (i = inventory.stocks.begin(); i != inventory.stocks.end(); ++i)
						{
							i -> setThreshold (threshold);
						}
			break;
			
			case 'b': 	for (i = inventory.stocks.begin(); i != inventory.stocks.end(); ++i)
						{
							i -> setAlertMessage (alert);
						}
			break;
			
			case 'c':
			break;
			
			default: cout << "Invalid choice! " << endl;
		}
		cout << endl;
	
	} while (choice != 'c');
	
	
}

void Manager :: displayManagerMenu()
{
    cout << "--------------------------------------\n";
    cout << "Manager Menu\n";
    cout << "--------------------------------------\n";
    cout << "1) Edit Stock\n";
    cout << "2) Search Stock\n";
    cout << "3) Order Stock\n";
    cout << "4) Review Transaction Summary\n";
    cout << "5) Manage Stock Alert\n";
    cout << "6) Logout\n";
	cout << "--------------------------------------\n";
}

