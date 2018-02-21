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
		bool addNewStock ();
		bool removeStock ();
		void displayManagerMenu();
};

Manager::Manager ()
{

}

Manager::~Manager()
{

}

bool Manager::addNewStock ()
{
	Stock newStock;
	
	char itemID [LEN];
    char itemDesc [LEN];
    char itemCat [LEN];
    char itemSubCat [LEN];
    double price;
    
	int qty;
	
	cout << "Item ID: ";
	cin >> itemID;
	cin.clear();
	cin.ignore (MAXLEN, '\n');
	
	list<Stock>::iterator i;
	for (i = inventory.stocks.begin(); i != inventory.stocks.end(); ++i)
	{
		if (strcmp(itemID, i->getID()) == 0)
		{
			cout << "Item with ID \'" << itemID << "\' already exists!" << endl;
			return false;
		}
	}
	
	cout << "Item Description: ";
	cin.getline (itemDesc, LEN, '\n');
	
	cout << "Item Category: ";
	cin.getline (itemCat, LEN, '\n');
	
	cout << "Item Sub-Category: ";
	cin.getline (itemSubCat, LEN, '\n');
	
	cout << "Item Price: ";
	cin >> price;
	cin.clear();
	cin.ignore (MAXLEN, '\n');
	
	cout << "Item Quantity: ";
	cin >> qty;
	cin.clear();
	cin.ignore (MAXLEN, '\n');
	
	newStock.setID (itemID);
	newStock.setDesc (itemDesc);
	newStock.setCat (itemCat);
	newStock.setSubCat (itemSubCat);
	newStock.setPrice (price);
	newStock.setQty (qty);
	
	inventory.stocks.push_back (newStock);
	
	cout << "Item with ID \'" << itemID << "\' successfully created!" << endl;
	return true;
}

bool Manager ::removeStock ()
{
	char itemID [LEN];
	cout << "Item ID: ";
	cin >> itemID;
	cin.clear();
	cin.ignore (MAXLEN, '\n');
	
	list<Stock>::iterator i;
	for (i = inventory.stocks.begin(); i != inventory.stocks.end(); ++i)
	{
		if (strcmp(itemID, i->getID()) == 0)
		{
			inventory.stocks.erase(i);
			cout << "Item with ID \'" << itemID << "\' removed!" << endl;
			return true;
		}
	}
	
	cout << "Item with ID \'" << itemID << "\' does not exists!" << endl;
	return false;
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
			cout << "d) Price\n";
			cout << "e) Quantity\n";
			cout << "f) Back\n";
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
							cin.getline (itemCat, LEN, '\n');
							
							
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
							cin.getline (itemSubCat, LEN, '\n');
							
							
							for (i = inventory.stocks.begin(); i != inventory.stocks.end(); ++i)
							{
								if (strcmp(itemID, i->getID()) == 0)
								{
									i -> setSubCat (itemSubCat);
								}
							}
				break;
										
				case 'd':	double price;
							cout << "New Price: ";
							cin >> price;
							cin.clear ();
							cin.ignore (MAXLEN, '\n');
							
							
							for (i = inventory.stocks.begin(); i != inventory.stocks.end(); ++i)
							{
								if (strcmp(itemID, i->getID()) == 0)
								{
									i -> setPrice (price);
								}
							}
				break;
				
				
				case 'e':	int qty;
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
				
				case 'f':
				break;
									
				default: cout << "Invalid choice! " << endl;
			}
			cout << endl;
		
		} while (choice != 'f');
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
		cout << "d) Price Range\n";
		cout << "e) Quantity Range\n";
		cout << "f) Back\n";
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
                                                cout<< left << setw(5) << "ID";
                                                cout<< left << setw(20) << "Category";
                                                cout<< left << setw(20) << "Sub-Category";
                                                cout<< left << setw(25) << "Description";
                                                cout<< left << setw(10) << "Quantity";
                                                cout<< left << setw(10) << "Price" << endl;
                                                cout<<"-------------------------------------------------------------------------------------" << endl;
						if (!inventory.searchStockID(buffer))
						{
							cout << "No item of ID \'" 
								 << buffer << "\' found!" << endl;
						}
			break;
			
			case 'b': 	cout << "Please enter Item Category: ";
						cin.getline (buffer, MAXLEN, '\n');
                                                cout<< left << setw(5) << "ID";
                                                cout<< left << setw(20) << "Category";
                                                cout<< left << setw(20) << "Sub-Category";
                                                cout<< left << setw(25) << "Description";
                                                cout<< left << setw(10) << "Quantity";
                                                cout<< left << setw(10) << "Price" << endl;
                                                cout<<"-------------------------------------------------------------------------------------" << endl;
						if (!inventory.searchStockCat(buffer))
						{
							cout << "No item of Category \'" 
								 << buffer << "\' found!" << endl;
						}
			break;
			
			case 'c':	cout << "Please enter Item Sub-Category: ";
						cin.getline (buffer, MAXLEN, '\n');
                                                cout<< left << setw(5) << "ID";
                                                cout<< left << setw(20) << "Category";
                                                cout<< left << setw(20) << "Sub-Category";
                                                cout<< left << setw(25) << "Description";
                                                cout<< left << setw(10) << "Quantity";
                                                cout<< left << setw(10) << "Price" << endl;
                                                cout<<"-------------------------------------------------------------------------------------" << endl;
						if (!inventory.searchStockSubCat(buffer))
						{
							cout << "No item of Sub-Category \'" 
								 << buffer << "\' found!" << endl;
						}
			break;
			
			case 'd':	cout << "Please enter Item Price lower range: ";
						cin >> lower;
						cin.clear ();
						cin.ignore (MAXLEN, '\n');
						cout << "Please enter Item Price upper range: ";
						cin >> upper;
						cin.clear ();
						cin.ignore (MAXLEN, '\n');
                                                cout<< left << setw(5) << "ID";
                                                cout<< left << setw(20) << "Category";
                                                cout<< left << setw(20) << "Sub-Category";
                                                cout<< left << setw(25) << "Description";
                                                cout<< left << setw(10) << "Quantity";
                                                cout<< left << setw(10) << "Price" << endl;
                                                cout<<"-------------------------------------------------------------------------------------" << endl;
						if (!inventory.searchStockPrice(lower, upper))
						{
							cout << "No item found within range!" << endl;
						}
			break;
			
			
			case 'e':	cout << "Please enter Item Quantity lower range: ";
						cin >> lower1;
						cin.clear ();
						cin.ignore (MAXLEN, '\n');
						cout << "Please enter Item Quantity upper range: ";
						cin >> upper1;
						cin.clear ();
						cin.ignore (MAXLEN, '\n');
                                                cout<< left << setw(5) << "ID";
                                                cout<< left << setw(20) << "Category";
                                                cout<< left << setw(20) << "Sub-Category";
                                                cout<< left << setw(25) << "Description";
                                                cout<< left << setw(10) << "Quantity";
                                                cout<< left << setw(10) << "Price" << endl;
                                                cout<<"-------------------------------------------------------------------------------------" << endl;
						if (!inventory.searchStockQtyRange(lower1, upper1))
						{
							cout << "No item found within range!" << endl;
						}
			break;
			
			case 'f':
			break;
			
			default: cout << "Invalid choice! " << endl;
		}
		
		cout << endl;
	}
	while (choice != 'f');
}

void Manager :: reviewTransactionSummary()
{
    Date date1, date2;
    
    inputDates(date1, date2);
    
    if(!validDate(date1) || !validDate(date2))
    {
        if(!validDate(date1))
        {
            displayDate(date1);
            cout << " is not a valid date!" << endl;
        }
        if(!validDate(date2))
        {
            displayDate(date2);
            cout << " is not a valid date!" << endl;
        }
        return;
    }
    
    /*if(daysBetween(date1, date2) > 366)
    {
        cout << "Range between dates must be within a year!";
        return;
    }*/
    
    if (dateEarlierDate(date1, date2))
        inventory.viewSummary(date1, date2);
    else
        inventory.viewSummary(date2, date1);
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
			
			case 'c':           cout<< left << setw(5) << "ID";
					    cout<< left << setw(20) << "Category";
					    cout<< left << setw(20) << "Sub-Category";
					    cout<< left << setw(25) << "Description";
					    cout<< left << setw(10) << "Quantity";
					    cout<< left << setw(10) << "Price" << endl;
                                            cout<<"-------------------------------------------------------------------------------------" << endl;
                                
                        for (i = inventory.stocks.begin(); i != inventory.stocks.end(); ++i)
						{
							if (i->getQty() <= i->getThreshold())
							{
								i -> viewStock();
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
	cout << "1) Add New Stock\n";
	cout << "2) Remove Stock\n";
    cout << "3) Edit Stock\n";
    cout << "4) Search Stock\n";
    cout << "5) Review Transaction Summary\n";
    cout << "6) Manage Stock Alert\n";
    cout << "7) Logout\n";
	cout << "--------------------------------------\n";
}

