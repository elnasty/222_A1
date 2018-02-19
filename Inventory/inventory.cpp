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

#include "inventory.h"

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
    int i = 0;
    //Reach each field form txt file and write to binary, ignoring ':'
    while (tFile.getline(buffer, LEN))
    {
        char * pc;
        pc = strtok (buffer,":");
        while (pc != NULL)
        {
            cout << pc << endl;
            writeString(bFile, pc);
            pc = strtok (NULL, ":");
        }
    }
    
    tFile.close ();
    bFile.close ();
}

void Inventory::readFile (const char* bFName)
{
    stocks.clear();
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
    int i = 0;
    
    while(!bFile.eof())
    {
        Stock * ps;
        ps = new Stock;
		
        str = readString(bFile);      
        strcpy(buffer,str.c_str());
        ps->setID(buffer);
        
        str = readString(bFile);
        strcpy(buffer,str.c_str());
        ps->setDesc(buffer);
        
        str = readString(bFile);
        strcpy(buffer,str.c_str());
        ps->setCat(buffer);
        
        str = readString(bFile);
        strcpy(buffer,str.c_str());
        ps->setSubCat(buffer);
        
        str = readString(bFile);
        strcpy(buffer,str.c_str());
        d = atof (buffer);
        ps->setBuyPrice(d);
        
        str = readString(bFile);
        strcpy(buffer,str.c_str());
        d = atof (buffer);
        ps->setSellPrice(d);
        
        str = readString(bFile);
        strcpy(buffer,str.c_str());
        num = atoi (buffer);
        ps->setQty(num);
        
        str = readString(bFile);
        strcpy(buffer,str.c_str());
        num = atoi (buffer);
        ps->setThreshold(num);
        
        str = readString(bFile);
        strcpy(buffer,str.c_str());
        ps->setAlertMessage(buffer);
        
        str = readString(bFile);
        strcpy(buffer,str.c_str());
        num = atoi (buffer);
        ps->setTransCount(num);
        
        stocks.push_back(*ps);
    }
    
    stocks.pop_back();
    totalStock = stocks.size();
    cout << "number of stocks = " << totalStock << endl;
    delete [] buffer;
    bFile.close();
}

void Inventory::writeFile (const char* bFName)
{
    fstream bFile;
    bFile.open (bFName, ios::out | ios::binary);
    if (!bFile)
    {
        cout << "Failed to open " << bFName << " for writing!" << endl;
        bFile.close ();
        exit (-1);
    }
    
    string str;
    char buffer[LEN];
    list<Stock>::iterator i;
    for (i = stocks.begin(); i != stocks.end(); ++i)
    {
    	writeString(bFile, i->getID());
        writeString(bFile, i->getDesc());
        writeString(bFile, i->getCat());
        writeString(bFile, i->getSubCat());
        
        sprintf(buffer, "%f", i->getBuyPrice());
        writeString(bFile, buffer);
        sprintf(buffer, "%f", i->getSellPrice());
        writeString(bFile, buffer);
        
        itoa(i->getQty(), buffer, 10);
        writeString(bFile, buffer);
        itoa(i->getThreshold(), buffer, 10);
        writeString(bFile, buffer);
        
        writeString(bFile, i->getAlertMessage());
        
        itoa(i->getTransCount(), buffer, 10);
        writeString(bFile, buffer);
    }
    
    bFile.close ();
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

