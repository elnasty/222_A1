#include "stock.h"

Stock::Stock(){}

Stock::~Stock(){}

void Stock::modifyQty(int amt, char* staffID)
{
    if(amt == 0)
    {
        cout << "Transaction cannot have a quantity of 0!" << endl;
	return;
    }
	
    qty = qty + amt;
    Transaction transaction(DAY, MONTH, YEAR, staffID, amt);
	
    transHist.push_front(transaction);
}

double Stock::getTotalSale()
{
    //
}

void Stock::displaySummary()
{
    cout << "Item ID           : " << itemID << endl;
    cout << "Item Category     : " << itemCat << endl;
    cout << "Item Sub Category : " << itemSubCat << endl;
    cout << "Item Description  : " << itemDesc << endl;
    cout << "Quantity          : " << qty << endl;
    cout << "Buy Price		   : " << buyPrice << endl;
    cout << "Sell Price		   : " << sellPrice << endl;
	
    list<Transaction>::iterator i;
    for (i = transHist.begin(); i != transHist.end(); ++i)
    	i->displayTrans();
}

// accessors
char* Stock::getID() const
{
    return itemID;
}
char* Stock::getDesc() const
{
    return itemDesc;
}
char* Stock::getCategory() const
{
    return itemCat;
}
char* Stock::getSubCat() const
{
    return itemSubCat;
}
double Stock::getBuyPrice() const
{
    return buyPrice;
}
double Stock::getSellPrice() const
{
    return sellPrice;
}
int Stock::getQty() const
{
    return qty;
}
int Stock::getThreshold() const
{
    return threshold;
}
char* Stock::getAlertMessage() const
{
    return alertMsg;
}

// mutators
void Stock::setID(char* id)
{
    strncpy(itemID, id, LEN);
}
void Stock::setDesc(char* desc)
{
    strncpy(itemDesc, desc, LEN);
}
void Stock::setCategory(char* cat)
{
    strncpy(itemCat, cat, LEN);
}
void Stock::setSubCat(char* subCat)
{
    strncpy(itemSubCat, subCat, LEN);
}
void Stock::setBuyPrice(double bP)
{
    buyPrice = bP;
}
void Stock::setSellPrice(double sP)
{
    sellPrice = sP;
}
void Stock::setQty(int q)
{
    qty = q;
}
void Stock::setThreshold(int tHold)
{
    threshold=tHold;
}
void Stock::setAlertMessage(char* aM)
{
    strncpy(alertMsg, aM, LEN);
}

// static
int Stock::transCount = 0;
static int Stock::getTransCount()
{
    return transCount;
}