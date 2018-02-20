/* 
 * Name         : stock.cpp
 * Author       : Stanley
 * Sub Authors  : Benjamin
 *
 * Created on   : 140217
 *
 * Purpose      : contains includes and declaration of Transaction class
 * 
 * Changes      :
 * DATE         USER            DETAIL
 * 140217       Stanley         Original file conception
 * 150217       Benjamin        Accessor Mutator functions
 * 180217       Stanley         Merged and fixed changes
 */

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
	
    qty = qty - amt;
    Transaction* pt = new Transaction(GLOBALDATE, staffID, amt);
	
    transHist.push_front(*pt);
    transCount = transHist.size();
}

double Stock::getTotalSale()
{
    //
}

void Stock::getBoughtSold(int& bought, int& sold, Date date1, Date date2)
{
    list<Transaction>::iterator i;
    if (transHist.size() == 0)
        return;
    for (i = transHist.begin(); i != transHist.end(); ++i)
    {
        if(dateWithin(i->getDate(), date1, date2))
        {
            if(i->getQuantitySold() > 0)
                sold += i->getQuantitySold();
            else
                bought += -(i->getQuantitySold());
        }
    }
}

void Stock::getAllBoughtSold(int& bought, int& sold)
{
    list<Transaction>::iterator i;
    if (transHist.size() == 0)
        return;
    for (i = transHist.begin(); i != transHist.end(); ++i)
    {
        if(i->getQuantitySold() > 0)
            sold += i->getQuantitySold();
        else
            bought += -(i->getQuantitySold());
    }
}

void Stock::displaySummary(Date date1, Date date2)
{
    int bought = 0, sold = 0;
    double profits = 0.0;
    
    getBoughtSold(bought, sold, date1, date2);
    profits = sold*sellPrice - bought*buyPrice;
    
    cout << fixed << setprecision(2) << setfill(' ') << endl;
    cout << left << setw(10) << itemID << setw(10) << bought << setw(10)
         << sold << setw(10) << buyPrice << setw(10) << sellPrice
         << setw(20) << profits << endl << endl;
    	
    list<Transaction>::iterator i;
    for (i = transHist.begin(); i != transHist.end(); ++i)
    	i->displayTrans(date1, date2);
    
    cout << endl << endl;
}

void Stock::displaySummary()
{
    int bought = 0, sold = 0;
    double profits = 0.0;
    
    getAllBoughtSold(bought, sold);
    profits = sold*sellPrice - bought*buyPrice;
    
    cout << fixed << setprecision(2) << setfill(' ') << endl;
    cout << left << setw(10) << itemID << setw(10) << bought << setw(10)
         << sold << setw(10) << buyPrice << setw(10) << sellPrice
         << setw(20) << profits << endl;
    	
    list<Transaction>::iterator i;
    for (i = transHist.begin(); i != transHist.end(); ++i)
    	i->displayTrans();
}

// accessors
const char* Stock::getID() const
{
    return itemID;
}
const char* Stock::getDesc() const
{
    return itemDesc;
}
const char* Stock::getCat() const
{
    return itemCat;
}
const char* Stock::getSubCat() const
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
const char* Stock::getAlertMessage() const
{
    return alertMsg;
}
int Stock::getTransCount() const
{
    return transCount;   
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
void Stock::setCat(char* cat)
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
void Stock::setTransCount(int count)
{
    transCount = count;
}


