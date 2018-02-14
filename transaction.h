/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * Name         : transaction.h
 * Author       : Stanley
 * Sub Authors  :
 *
 * Created on   : 140217
 *
 * Purpose      : contains includes and declaration of Transaction class
 * 
 * Changes      :
 * DATE         USER            DETAIL
 * 140217       Stanley         Original file conception
 */

#pragma once
#include <iomanip>
#include <iostream>
#include "date.h"

const int IDLEN = 8;

class Transaction
{
 public:
     Transaction();
     Transaction(int, int, int, char*, int);
     ~Transaction();
     void displayTrans();
 private: 
     struct Date
     {
         int day;
         int month;
         int year;
     };
     Date date;
     int qtySold;
     char staffID [IDLEN];
     int invoiceNo;
     static int objCount;
};

Transaction::Transaction(){}

Transaction::Transaction(int d, int m, int y, char* c, int amt)
{
    date.day = d;
    date.month = m;
    date.year = y;
    
    strcpy(staffID, c);
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

int Transaction::objCount = 0;