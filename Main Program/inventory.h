/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * Filename     : inventory.h
 * Author       : Le Buff
 * Sub Authors  :
 * Created on     14 February, 2018, 2:57 PM
 * 
 * Description  :
 */

#pragma once
#include <fstream>
#include <sstream>
#include "stock.h"

void writeString(fstream&, const string&);
string readString(fstream&);

class Inventory
{
 public:
    Inventory();
	Inventory(const char*);
	Inventory(const char*, const char*);
    ~Inventory();
    void addStock();
    void removeStock();
    void updateStock();
    void viewSummary(Date, Date);
    void encryptFile(const char*, const char*);
    void readFile(const char*);
    void writeFile(const char*);
    bool searchStockID(const char*);
    bool searchStockCat(const char*);
	bool searchStockSubCat(const char*);
	bool searchStockPrice(double, double);
	bool searchStockQtyRange(int, int);
	
 
    int totalStock;
    list<Stock> stocks;
    //void encryptFile(const char*, const char*);
};



