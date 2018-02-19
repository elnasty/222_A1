/* 
 * Name         : transaction.cpp
 * Author       : Stanley
 * Sub Authors  : How Wei
 *
 * Created on   : 140217
 *
 * Purpose      : contains definitions of Transaction class functions
 * 
 * Changes      :
 * DATE         USER            DETAIL
 * 140217       Stanley         Original file conception
 * 150217       How Wei         Accessor Mutator functions
 * 180217       Stanley         Merged and fixed changes
 */

#include "transaction.h"

Transaction::Transaction(){}

Transaction::Transaction(int d, int m, int y, char* c, int amt)
{
    date.day = d;
    date.month = m;
    date.year = y;
    
    strncpy(staffID, c, IDLEN);
    qtySold = amt;
    invoiceNo = ++objCount;
}

Transaction::~Transaction(){}

void Transaction::displayTrans()
{
    cout << qtySold;
    if (qtySold > 0)
	cout << " sold by ";
    else if (qtySold < 0)
	cout << " bought by";
	
    cout << staffID << " on " << setfill('0') << setw(2) 
	 << date.day << setw(2) << date.month << date.year << endl;
}

// mutators
void Transaction::setStaffID(char* SID)
{
    strncpy(staffID, SID, IDLEN);
}
void Transaction::setInvoiceNo(int newInvoice)
{
    invoiceNo = newInvoice;
}
void Transaction::setQuantitySold(int newQuantity)
{
    qtySold = newQuantity;
}
void Transaction::setDate(int d, int m, int y)
{
    date.day = d;
    date.month = m;
    date.year = y;
}

// accessors
int Transaction::getInvoiceNo() const
{
    return invoiceNo;
}
int Transaction::getQuantitySold() const
{
    return qtySold;
}
const char* Transaction::getStaffID() const
{
    return staffID;
}
Date Transaction::getDate() const
{
    return date;
}

// static
int Transaction::objCount = 0;
int Transaction::getObjCount()
{
    return objCount;
}
