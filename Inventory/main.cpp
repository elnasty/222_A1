#include "inventory.h"
#include "stock.h"
#include "transaction.h"

 Date GLOBALDATE;
 Date d;

int main()
{
    Inventory inventory;
    updateDate(GLOBALDATE);
    displayDate(GLOBALDATE);
}
