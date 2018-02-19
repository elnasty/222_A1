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
    static int transCount;
    list<Transaction> transHist;
public:
    Stock();
    ~Stock();
    void modifyQty(int);
    double getTotalSale();
    void displaySummary();
    
    // accessors
    char* getID();
    char* getDesc();
    char* getCategory();
    char* getSubCat();
    double getBuyPrice();
    double getSellPrice();
    int getQty();
    int getThreshold();
    char* getAlertMessage();
    static int getTransCount();
    
    // mutators
    void setID(string id);
    void setDesc(string desc);
    void setCategory(string categroy);
    void setSubCat(string subCat);
    void setBuyPrice(double);
    void setSellPrice(double);
    void setQty(int quty);
    void setThreshold(int tHold);
    void setAlertMessage(string aMessage); 
};