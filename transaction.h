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
     
     // mutator accessor
     void setQuantitySold(int);
     int getQuantitySold();
     void setStaffID(char*);
     char * getStaffID();
     void setInvoiceNo(int);
     int getInvoiceNo();
     void setDate(int, int, int);
     Date getDate ();
     static int getCount();

 private: 
     Date date;
     int qtySold;
     char staffID [IDLEN];
     int invoiceNo;
     static int objCount;
};