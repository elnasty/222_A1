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
#include "stock.h"

void writeString(fstream&, const string&);
string readString(fstream&);

class Inventory
{
 public:
    Inventory();
    ~Inventory();
    void addStock();
    void removeStock();
    void updateStock();
    void viewSummary();
    void encryptFile(const char*, const char*);
    void readFile(const char*);
 private:
    int totalStock;
    list<Stock> stocks;
    void writeFile();
    //void encryptFile(const char*, const char*);
};

Inventory::Inventory(){}

Inventory::~Inventory(){}

void Inventory::viewSummary()
{
    list<Stock>::iterator i;
    for (i = stocks.begin(); i != stocks.end(); ++i)
    	i->displaySummary();
}

void Inventory::addStock()
{
}

void Inventory::encryptFile (const char* tFName, const char* bFName)
{
    fstream tFile, bFile;
    tFile.open (tFName, ios::in);
    bFile.open (bFName, ios::out | ios::binary);
    if (!tFile)
    {
        cout << "Failed to open " << tFName << " for encryption!" << endl;
        tFile.close ();
        exit (-1);
    }
    if (!bFile)
    {
        cout << "Failed to open " << bFName << " for encryption!" << endl;
        bFile.close ();
        exit (-1);
    }

    char buffer [LEN];
    //tFile >> noskipws;
    
    //Reach each field form txt file and write to binary, ignoring ':'
    while (tFile.getline(buffer, LEN))
    {
        cout << buffer << endl;
        writeString(bFile, buffer);
    }
    
    tFile.close ();
    bFile.close ();
}

void Inventory::readFile (const char* bFName)
{
    fstream bFile;
    bFile.open (bFName, ios::in | ios::binary);
    if (!bFile)	
    {
        cout << "Failed to open " << bFName << " for reading!" << endl;
        bFile.close ();
        exit (-1);
    }
    
    string str;
    double d;
    int num;
    char * buffer = new char [LEN];
    
    while(!bFile.eof())
    {
        Stock * ps;
		
        readString(bFile);
        strcpy(buffer,str.c_str());
        ps = new Stock;
        
        strcpy(buffer,str.c_str());
        ps->setID(buffer);
        
        readString(bFile);
        strcpy(buffer,str.c_str());
        ps->setDesc(buffer);
        
        readString(bFile);
        strcpy(buffer,str.c_str());
        ps->setCat(buffer);
        
        readString(bFile);
        strcpy(buffer,str.c_str());
        ps->setSubCat(buffer);
        
        bFile.read(reinterpret_cast<char *>(&d), sizeof(d));
        ps->setBuyPrice(d);
        
        bFile.read(reinterpret_cast<char *>(&d), sizeof(d));
        ps->setSellPrice(d);
        
        bFile.read(reinterpret_cast<char *>(&num), sizeof(num));
        ps->setQty(num);
        
        bFile.read(reinterpret_cast<char *>(&num), sizeof(num));
        ps->setThreshold(num);
        
        readString(bFile);
        strcpy(buffer,str.c_str());
        ps->setAlertMessage(buffer);
        
        bFile.read(reinterpret_cast<char *>(&num), sizeof(num));
        ps->setTransCount(num);
        
        stocks.push_back(*ps);
        ps->displaySummary();
    }
    
    totalStock = stocks.size();
    bFile.close();
}

void writeString(fstream& file, const string& str)
{
  // get the length of the string data
  unsigned len = str.size();

  // write the size:
  file.write( reinterpret_cast<const char*>( &len ), sizeof(len) );

  // write the actual string data:
  file.write( str.c_str(), len );
}

string readString(fstream& file)
{
  // this probably isn't the optimal way to do it, but whatever
  string str;

  // get the length
  unsigned len;
  file.read( reinterpret_cast<char*>( &len ), sizeof(len) );

  // we can't read to string directly, so instead, create a temporary buffer
  if(len > 0)
  {
    char* buf = new char[len];
    file.read( buf, len );
    str.append( buf, len );
    delete[] buf;
  }
  return str;
}

