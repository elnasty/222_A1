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
#include "stock.h"

class Inventory
{
 public:
    Inventory();
    ~Inventory();
    void readFile();
    void writeFile();
    void addStock();
    void removeStock();
    void updateStock();
    void viewSummary();
 private:
    int totalStock;
    list<Stock> stocks;
};

Inventory::Inventory(){}

Inventory::~Inventory(){}

void Inventory::addStock()
{
}

