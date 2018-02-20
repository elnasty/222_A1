#include "SystemAdmin.cpp"

class Manager 
{
	public: 
		Manager();
		~Manager();
		void editStock();
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
							cin.getline (desc, LEN, '\n');
							
							for (i = inventory.stocks.begin(); i != inventory.stocks.end(); ++i)
							{
								if (strcmp(itemID, i->getID()) == 0)
								{
									i -> setDesc (desc);
								}
							}
						
				break;
										
				case 'b': 	char itemCat [LEN];
							cout << "New Category: ";
							cin >> itemCat;
							cin.clear ();
							cin.ignore (MAXLEN, '\n');
							
							
							for (i = inventory.stocks.begin(); i != inventory.stocks.end(); ++i)
							{
								if (strcmp(itemID, i->getID()) == 0)
								{
									i -> setCat (itemCat);
								}
							}
							
				break;
										
				case 'c': 	char itemSubCat [LEN];
							cout << "New Sub-Category: ";
							cin >> itemSubCat;
							cin.clear ();
							cin.ignore (MAXLEN, '\n');
							
							
							for (i = inventory.stocks.begin(); i != inventory.stocks.end(); ++i)
							{
								if (strcmp(itemID, i->getID()) == 0)
								{
									i -> setSubCat (itemSubCat);
								}
							}
				break;
										
				case 'd':	double buyPrice;
							cout << "New Buy Price: ";
							cin >> buyPrice;
							cin.clear ();
							cin.ignore (MAXLEN, '\n');
							
							
							for (i = inventory.stocks.begin(); i != inventory.stocks.end(); ++i)
							{
								if (strcmp(itemID, i->getID()) == 0)
								{
									i -> setBuyPrice (buyPrice);
								}
							}
				break;
				
				case 'e':	double sellPrice;
							cout << "New Sell Price: ";
							cin >> sellPrice;
							cin.clear ();
							cin.ignore (MAXLEN, '\n');
							
							
							for (i = inventory.stocks.begin(); i != inventory.stocks.end(); ++i)
							{
								if (strcmp(itemID, i->getID()) == 0)
								{
									i -> setSellPrice (sellPrice);
								}
							}
				break;
				
				case 'f':	int qty;
							cout << "New Quantity: ";
							cin >> qty;
							cin.clear ();
							cin.ignore (MAXLEN, '\n');
							
							
							for (i = inventory.stocks.begin(); i != inventory.stocks.end(); ++i)
							{
								if (strcmp(itemID, i->getID()) == 0)
								{
									i -> setQty (qty);
								}
							}
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
		cout << "Item with ID \'" << itemID
			 << "\' not found!" << endl;
			 
	}
}

void Manager :: searchStock()
{
	char choice;
	double lower, upper;
	int lower1, upper1;
	char buffer [LEN];
	
	do
	{
		cout << "--------------------------------------\n";
		cout << "Search Stock Menu\n";
		cout << "--------------------------------------\n";
		cout << "a) Item ID\n";
		cout << "b) Category\n";
		cout << "c) Sub-Category\n";
		cout << "d) Buy Price Range\n";
		cout << "e) Sell Price Range\n";
		cout << "f) Quantity Range\n";
		cout << "g) Back\n";
		cout << "--------------------------------------\n";
		cout << "Choice: ";
		cin >> choice;
		cin.clear ();
		cin.ignore (MAXLEN, '\n');
		cout << endl;
		
		switch (choice)
		{
			case 'a': 	cout << "Please enter Item ID: ";
						cin >> buffer;
						cin.clear ();
						cin.ignore (MAXLEN, '\n');
						if (!inventory.searchStockID(buffer))
						{
							cout << "No item of ID \'" 
								 << buffer << "\' found!" << endl;
						}
			break;
			
			case 'b': 	cout << "Please enter Item Category: ";
						cin >> buffer;
						cin.clear ();
						cin.ignore (MAXLEN, '\n');
						if (!inventory.searchStockCat(buffer))
						{
							cout << "No item of Category \'" 
								 << buffer << "\' found!" << endl;
						}
			break;
			
			case 'c':	cout << "Please enter Item Sub-Category: ";
						cin >> buffer;
						cin.clear ();
						cin.ignore (MAXLEN, '\n');
						if (!inventory.searchStockSubCat(buffer))
						{
							cout << "No item of Sub-Category \'" 
								 << buffer << "\' found!" << endl;
						}
			break;
			
			case 'd':	cout << "Please enter Item Buy Price lower range: ";
						cin >> lower;
						cin.clear ();
						cin.ignore (MAXLEN, '\n');
						cout << "Please enter Item Buy Price upper range: ";
						cin >> upper;
						cin.clear ();
						cin.ignore (MAXLEN, '\n');
						if (!inventory.searchStockBuyPrice(lower, upper))
						{
							cout << "No item found within range!" << endl;
						}
			break;
			
			case 'e':	cout << "Please enter Item Sell Price lower range: ";
						cin >> lower;
						cin.clear ();
						cin.ignore (MAXLEN, '\n');
						cout << "Please enter Item Sell Price upper range: ";
						cin >> upper;
						cin.clear ();
						cin.ignore (MAXLEN, '\n');
						if (!inventory.searchStockSellPrice(lower, upper))
						{
							cout << "No item found within range!" << endl;
						}
			break;
			
			case 'f':	cout << "Please enter Item Quantity lower range: ";
						cin >> lower1;
						cin.clear ();
						cin.ignore (MAXLEN, '\n');
						cout << "Please enter Item Quantity upper range: ";
						cin >> upper1;
						cin.clear ();
						cin.ignore (MAXLEN, '\n');
						if (!inventory.searchStockQtyRange(lower1, upper1))
						{
							cout << "No item found within range!" << endl;
						}
			break;
			
			case 'g':
			break;
			
			default: cout << "Invalid choice! " << endl;
		}
		
		cout << endl;
	}
	while (choice != 'g');
}

void Manager :: reviewTransactionSummary()
{
	inventory.viewSummary();
}

void Manager :: stockAlert()
{
    int threshold;
	int j;
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
		cout << "c) View Stock Alert\n";
		cout << "d) Back\n";
		cout << "--------------------------------------\n";
		cout << "Choice: ";
		cin >> choice;
		cin.clear ();
		cin.ignore (MAXLEN, '\n');
		
		switch (choice)
		{
		
			case 'a':	cout << "Enter new Threshold: ";
						cin >> threshold;
						cin.clear ();
						cin.ignore (MAXLEN, '\n');
						
						for (i = inventory.stocks.begin(); i != inventory.stocks.end(); ++i)
						{
							i -> setThreshold (threshold);
						}
						
						cout << "Threshold: \'" << threshold << "\' set for all stocks!" << endl;
			break;
			
			case 'b': 	cout << "Enter Alert Message: ";
						cin.getline (alert, MAXLEN, '\n');
						
						for (i = inventory.stocks.begin(); i != inventory.stocks.end(); ++i)
						{
							i -> setAlertMessage (alert);
						}
						
						cout << "Alert Message: \'" << alert << "\' set for all stocks!" << endl;
			break;
			
			case 'c':	for (i = inventory.stocks.begin(); i != inventory.stocks.end(); ++i)
						{
							if (i->getQty() <= i->getThreshold())
							{
								i -> displaySummary();
								++j;
							}
						}
						
						cout << endl;
						cout << j << " stocks are below threshold! " << endl;
						cout << "Alert Message: " << inventory.stocks.begin() -> getAlertMessage() << endl;
			break;
			
			case 'd':
			break;
			
			default: cout << "Invalid choice! " << endl;
		}
		
		cout << endl;
	
	} while (choice != 'd');
	
	
}

void Manager :: displayManagerMenu()
{
    cout << "--------------------------------------\n";
    cout << "Manager Menu\n";
    cout << "--------------------------------------\n";
    cout << "1) Edit Stock\n";
    cout << "2) Search Stock\n";
    cout << "3) Review Transaction Summary\n";
    cout << "4) Manage Stock Alert\n";
    cout << "5) Logout\n";
	cout << "--------------------------------------\n";
}

