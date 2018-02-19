#include "Manager.cpp"

class Operator 
{
	public: 
		Operator();
		Operator(const char*);
		~Operator();
		void displayOperatorMenu();
		void addStockQty ();
		void rmStockQty ();
		
	private:
		char* staffID;
		
};

Operator::Operator ()
{
	
}

Operator::Operator (const char* ID)
{
	staffID = new char [MAXLEN];
	strcpy (staffID, ID);
}

Operator::~Operator ()
{

}

void Operator::addStockQty ()
{
	char itemID [LEN];
	int qty;
	
	cout << "Please enter Item ID: ";
	cin >> itemID;
	cin.clear();
	cin.ignore (MAXLEN, '\n');
	cout << "Please enter Qty: ";
	cin >> qty;
	cin.clear();
	cin.ignore (MAXLEN, '\n');
	
	list<Stock>::iterator i;
    for (i = inventory.stocks.begin(); i != inventory.stocks.end(); ++i)
    {
    	if (strcmp(itemID, i->getID()) == 0)
		{
	    	i->modifyQty(-(qty), staffID);
		}
    }
}

void Operator::rmStockQty ()
{
	char itemID [LEN];
	char staffID [LEN];
	int qty;
	
	cout << "Please enter Item ID: ";
	cin >> itemID;
	cin.clear();
	cin.ignore (MAXLEN, '\n');
	cout << "Please enter Qty: ";
	cin >> qty;
	cin.clear();
	cin.ignore (MAXLEN, '\n');
	
	list<Stock>::iterator i;
    for (i = inventory.stocks.begin(); i != inventory.stocks.end(); ++i)
    {
    	if (strcmp(itemID, i->getID()) == 0)
		{
			i->modifyQty(qty, staffID);
		}
    }
}

void Operator :: displayOperatorMenu()
{
	cout << "--------------------------------------\n";
    cout << "Operator Menu\n";
    cout << "--------------------------------------\n";
    cout << "1) Add Stock Quantity\n";
    cout << "2) Remove Stock Quantity\n";
    cout << "3) Logout \n";
	cout << "--------------------------------------\n";
}

