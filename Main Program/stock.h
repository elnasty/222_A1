/* 
 * Name         : stock.h
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

#pragma once
#include <list>
#include "transaction.h"

const int LEN = 200;

class Stock
{
 private:
    char itemID [LEN];
    char itemDesc [LEN];
    char itemCat [LEN];
    char itemSubCat [LEN];
    double buyPrice;
    double sellPrice;
    int qty;
    int threshold;
    char alertMsg [LEN];
    int transCount;
 public:
    Stock();
    ~Stock();
    void modifyQty(int, char*);
    double getTotalSale();
    void displaySummary(Date, Date);
    void getBoughtSold(int&, int&, Date, Date);
    list<Transaction> transHist;
    
    // accessors
    const char* getID() const;
    const char* getDesc() const;
    const char* getCat() const;
    const char* getSubCat() const;
    double getBuyPrice() const;
    double getSellPrice() const;
    int getQty() const;
    int getThreshold() const;
    const char* getAlertMessage() const;
    int getTransCount() const;
    
    // mutators
    void setID(char*);
    void setDesc(char*);
    void setCat(char*);
    void setSubCat(char*);
    void setBuyPrice(double);
    void setSellPrice(double);
    void setQty(int quty);
    void setThreshold(int tHold);
    void setAlertMessage(char*); 
    void setTransCount(int);
};



