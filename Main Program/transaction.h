/* 
 * Name         : transaction.h
 * Author       : Stanley
 * Sub Authors  : How Wei
 *
 * Created on   : 140217
 *
 * Purpose      : contains includes and declaration of Transaction class
 * 
 * Changes      :
 * DATE         USER            DETAIL
 * 140217       Stanley         Original file conception
 * 150217       How Wei         Accessor Mutator functions
 * 180217       Stanley         Merged and fixed changes
 */

#pragma once
#include "date.h"

const int IDLEN = 8;

class Transaction
{
 public:
     Transaction();
     Transaction(Date, char*, int);
     Transaction(Date, char*, int, int);
     ~Transaction();
     void displayTrans(Date, Date);
     void displayTrans();
     
     
     // mutator accessor
     void setQuantitySold(int);
     void setQuantityBought(int);
     //void setStaffID(char*);
     void setInvoiceNo(int);
     void setDate(int, int, int);
     
     int getQuantitySold() const;
     int getQuantityBought() const;
     //const char* getStaffID() const;
     int getInvoiceNo() const;
     Date getDate () const;
     static int getObjCount();

 private: 
     Date date;
     int qtySold;
     int qtyBought;
     //char staffID [IDLEN];
     int invoiceNo;
     static int objCount;
};
