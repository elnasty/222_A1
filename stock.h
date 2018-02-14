/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * Name         : stock.h
 * Author       : Stanley
 * Sub Authors  :
 *
 * Created on   : 140217
 *
 * Purpose      : contains includes and declaration of Stock class
 * 
 * Changes      :
 * DATE         USER            DETAIL
 * 140217       Stanley         Original file conception
 */

#pragma once
#include <list>
#include "transaction.h"

const int LEN = 200;

class Stock
{
 public:
     Stock();
     ~Stock();
     void modifyQty(int);
     double getTotalSale();
     void displaySummary();
 private:
     char itemID [LEN];
     char itemDesc [LEN];
     char itemCat [LEN];
     char itemSubCat [LEN];
     double buyPrice;
     double sellPrice;
     int qty;
     //int threshold;
     //char alertMsg [LEN];
     int transCount;
     list<Transaction> transHist;
};

Stock::Stock(){}

Stock::~Stock(){}

void Stock::modifyQty(int amt)
{
    if(amt == 0)
    {
    	cout << "Transaction cannot have a quantity of 0!" << endl;
	return;
    }
	
    qty = qty + amt;
    Transaction transaction(DAY, MONTH, YEAR, "F1234567", amt);
	
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