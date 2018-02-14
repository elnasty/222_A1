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

#ifndef STOCK_H
#define STOCK_H

#endif /* STOCK_H */

#include "transaction.h"

const int LEN = 200;

class Stock
{
 public:
     Stock();
     ~Stock();
     void modifyQty();
     void getTotalSale();
     void displaySummary();
 private:
     char itemID [LEN];
     char itemDesc [LEN];
     char itemCat [LEN];
     char itemSubCat [LEN];
     double amtPerUnit;
     int qty;
     int threshold;
     char alertMsg [LEN];
     Transaction transHist [LEN];
};