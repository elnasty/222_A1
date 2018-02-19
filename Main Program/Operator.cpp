#include "Manager.cpp"

class Operator 
{
	public: 
		Operator();
		~Operator();
		void displayOperatorMenu();
		void addStockQty ();
		void rmStockQty ();
		
};

Operator::Operator ()
{
	
}

Operator::~Operator ()
{

}

void Operator::addStockQty ()
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
    	if (strcmp(itemID, i->getID()))
		{
			i->modifyQty(i->getQty() + qty, staffID);
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
    	if (strcmp(itemID, i->getID()))
		{
			i->modifyQty(i->getQty() - qty, staffID);
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

