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

// constructor for new transaction
Transaction::Transaction(Date d, char* c, int amt)
{
    date.day = d.day;
    date.month = d.month;
    date.year = d.year;
    
    strncpy(staffID, c, IDLEN);
    qtySold = amt;
    invoiceNo = ++objCount;
}

// constructor for reading transaction with existing invoice number
Transaction::Transaction(Date d, char* c, int amt, int inv)
{
    date.day = d.day;
    date.month = d.month;
    date.year = d.year;
    
    strncpy(staffID, c, IDLEN);
    qtySold = amt;
    invoiceNo = inv;
    ++objCount;
}

Transaction::~Transaction(){}

void Transaction::displayTrans()
{
    if (qtySold > 0)
	cout << qtySold << " sold by ";
    else if (qtySold < 0)
	cout << -qtySold << " bought by ";
	
    cout << staffID << " on " << setfill('0') << setw(2) 
	 << date.day << "-" << setw(2) << date.month << "-" << date.year << endl;
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
void Transaction::setQuantityBought(int newQuantity)
{
    qtyBought = newQuantity;
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
int Transaction::getQuantityBought() const
{
    return qtyBought;
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

