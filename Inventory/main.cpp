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
}

