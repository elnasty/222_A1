#include "SystemAdmin.cpp"

class Manager 
{
	public: 
		Manager();
		~Manager();
		void editStock();
		void orderStock();
		void stockAlert();
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
    
}

void Manager :: orderStock()
{
    
}

void Manager :: stockAlert()
{
    
}

void Manager :: displayManagerMenu()
{
    cout << "--------------------------------------\n";
    cout << "Manager Menu\n";
    cout << "--------------------------------------\n";
    cout << "1) Edit Stock\n";
    cout << "2) Sort Stock\n";
    cout << "3) Order Stock\n";
    cout << "4) Review Transaction Summary\n";
    cout << "5) Manage Stock Alert\n";
    cout << "6) Logout\n";
	cout << "--------------------------------------\n";
}

