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

#ifndef TRANSACTION_H
#define TRANSACTION_H

#endif /* TRANSACTION_H */

#include <iomanip>
#include <iostream>

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