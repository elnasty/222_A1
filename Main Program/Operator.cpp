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

}

void Operator::rmStockQty ()
{

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

