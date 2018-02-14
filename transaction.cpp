/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * Name         : transaction.cpp
 * Author       : Stanley
 * Sub Authors  :
 *
 * Created on   : 140217
 *
 * Purpose      : contains definitions of transaction class functions
 * 
 * Changes      :
 * DATE         USER            DETAIL
 * 140217       Stanley         Original file conception
 */

#include "transaction.h"

Transaction::Transaction(){};

Transaction::Transaction(int d, int m, int y, char* c, int amt)
{
    date.day = d;
    date.month = m;
    date.year = y;
    
    strcpy(staffID, c);
    qtySold = amt;
    invoiceNo = ++objCount;
}

Transaction::~Transaction(){};

void Transaction::displayTrans()
{
    // to be added
}

int Transaction::objCount = 0;




