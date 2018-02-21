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

Inventory::Inventory()
{
	readFile ("items.dat");
}

Inventory::Inventory (const char* bFileName)
{
	readFile (bFileName);
}

Inventory::Inventory(const char* txtFileName, const char* bFileName)
{
	encryptFile (txtFileName, bFileName);
	readFile (bFileName);
}

Inventory::~Inventory()
{
    writeFile("items.dat");
}

void Inventory::viewSummary(Date date1, Date date2)
{
    cout << "Transaction Summary between ";
    displayDate(date1);
    cout << " and ";
    displayDate(date2);
    cout << endl << endl;
    
    cout << setfill(' ');
    cout << left << setw(10) << "Stock ID" << setw(10) << "In" << setw(10)
         << "Out" << setw(25) << "Amount (Per Unit)" << setw(15) << "Profits" 
         << endl << endl;
    
    list<Stock>::iterator i;
    for (i = stocks.begin(); i != stocks.end(); ++i)
    	i->displaySummary(date1, date2);
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
            writeString(bFile, pc);
            pc = strtok (NULL, ":");
        }
    }
    
    cout << tFName << " and " << bFName << " opened for encryption" << endl;
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
    int num, year2d; // year 2 digits
    char buffer[LEN];
    
    // for transaction construction
    int qty;
    bool found = false;
    
    while(!bFile.eof())
    {
        if(bFile.eof())
            break;
        
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
        ps->setPrice(d);
        
        str = readString(bFile);
        strcpy(buffer,str.c_str());
        num = atoi (buffer);
        ps->setQty(ps->getQty()+num);
        
        Transaction * pt;
        qty = num;
        Date date;
        found = false;
        
        list<Stock>::iterator i;
        stringstream ss;
        for (i = stocks.begin(); i != stocks.end(); i++)
        {
            if(ps->stockMatch(*i))
            {
                found = true;
                i->setQty(i->getQty()+num);
                
                str = readString(bFile); // this gets the dd-mm-yy into str
                ss << str;               // dd-mm-yy into stringstream
                
                ss >> date.day;          // dd will come out first
                
                ss.get(); // first '-' is discarded
                ss.getline(buffer, 4, '-'); // buffer now contains 3char month
                
                date.month = monthToInt(buffer);
                
                ss >> year2d;              // yy will come out last
                date.year = year2d + 2000;

                pt = new Transaction(date, qty);
                i->transHist.push_back(*pt);
            }
        }
        
        if(!found)
        {            
            str = readString(bFile); // this gets the dd-mm-yy into str
            ss << str;               // dd-mm-yy into stringstream
              
            ss >> date.day;          // dd will come out first
               
            ss.get(); // first '-' is discarded
            ss.getline(buffer, 4, '-'); // buffer now contains 3char month
                
            date.month = monthToInt(buffer);
                
            ss >> year2d;              // yy will come out last
            date.year = year2d + 2000;

            pt = new Transaction(date, qty);
            ps->transHist.push_back(*pt);
            stocks.push_back(*ps);
        }
    }
    
    stocks.pop_back();
    totalStock = stocks.size();
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
    Date date;
    char buffer[LEN];
    char buffer2[LEN];
    list<Stock>::iterator i;
    for (i = stocks.begin(); i != stocks.end(); i++)
    {
        list<Transaction>::iterator it;
        for(it = i->transHist.begin(); it != i->transHist.end(); it++)
        {
            writeString(bFile, i->getID());
            writeString(bFile, i->getDesc());
            writeString(bFile, i->getCat());
            writeString(bFile, i->getSubCat());

            sprintf(buffer, "%f", i->getPrice());
            writeString(bFile, buffer);
            
            // beneath here should be 'it', since it's the transaction portion
            itoa(it->getQuantitySold(), buffer, 10);
            writeString(bFile, buffer);
            
            date = it->getDate();
            itoa(date.day, buffer, 10); // buffer now holds dd
            
            switch(date.month) // buffer will hold dd-mmm-
            {
                case 1:
                    strcat(buffer, "-Jan-");
                    break;
                case 2:
                    strcat(buffer, "-Feb-");
                    break;
                case 3:
                    strcat(buffer, "-Mar-");
                    break;
                case 4:
                    strcat(buffer, "-Apr-");
                    break;
                case 5:
                    strcat(buffer, "-May-");
                    break;
                case 6:
                    strcat(buffer, "-Jun-");
                    break;
                case 7:
                    strcat(buffer, "-Jul-");
                    break;
                case 8:
                    strcat(buffer, "-Aug-");;
                    break;
                case 9:
                    strcat(buffer, "-Sep-");
                    break;
                case 10:
                    strcat(buffer, "-Oct-");
                    break;
                case 11:
                    strcat(buffer, "-Nov-");
                    break;
                case 12:
                    strcat(buffer, "-Dec-");;
                    break;
                default:
                    strcat(buffer, "-???-");
            }
            itoa((date.year-2000), buffer2, 10); // buffer2 holds yy
            strcat(buffer, buffer2);      // buffer now holds dd-mmm-yy
            writeString(bFile, buffer);
        }    
    }
    bFile.close ();
}

bool Inventory::searchStockID(const char* ID)
{
    bool found = false;
	list<Stock>::iterator i;
    for (i = stocks.begin(); i != stocks.end(); ++i)
    {
        if(strcmp(i->getID(), ID) == 0)
		{
            i->viewStock();
			found = true;
		}
    }
	
	return found;
}

bool Inventory::searchStockCat(const char* cat)
{
	bool found = false;
    list<Stock>::iterator i;
    for (i = stocks.begin(); i != stocks.end(); ++i)
    {
        if(strcmp(i->getCat(), cat) == 0)
		{
            i->viewStock();
			found = true;
		}
    }
	
	return found;
}

bool Inventory::searchStockSubCat(const char* subCat)
{
    bool found = false;
	list<Stock>::iterator i;
    for (i = stocks.begin(); i != stocks.end(); ++i)
    {
        if(strcmp(i->getSubCat(), subCat) == 0)
		{
            i->viewStock();
			found = true;
		}
    }
	
	return found;
}

bool Inventory::searchStockPrice(double lower, double upper)
{
	bool found = false;
    list<Stock>::iterator i;
    for (i = stocks.begin(); i != stocks.end(); ++i)
    {
        if(i->getPrice() >= lower && i->getPrice() <= upper)
		{
            i->viewStock();
			found = true;
		}
    }
	
	return found;
}

bool Inventory::searchStockQtyRange(int lower, int upper)
{
    bool found = false;
	list<Stock>::iterator i;
    for (i = stocks.begin(); i != stocks.end(); ++i)
    {
        if(i->getQty() >= lower && i->getQty() <= upper)
		{
            i->viewStock();
			found = true;
		}
    }
	
	return found;
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

