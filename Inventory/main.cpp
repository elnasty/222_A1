#include "inventory.h"
#include "stock.h"
#include "transaction.h"

Date GLOBALDATE;

int main ()
{
    Inventory inventory;
    updateDate(GLOBALDATE);
    displayDate(GLOBALDATE);
	
    inventory.encryptFile("items.txt", "items.dat");
    inventory.readFile("items.dat");
    inventory.viewSummary();
    inventory.writeFile("items2.dat");
    
    cout << "2nd read" << endl;
    inventory.readFile("items2.dat");
    cout << "Summary" << endl;
    inventory.viewSummary();
}

