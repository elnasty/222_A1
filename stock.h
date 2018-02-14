#include <iostream>
#include <string>
#include "transaction.h"
#ifndef STOCK_H
#define STOCK_H
using namespace std;

class stock
{
	private:
	string itemID;
	string itemDesc;
	string itemCategory;
	string itemSubCat;
	double amountPerUnit;
	int qty;
	int threshold;
	string alertMessage;
	//transaction trans;
	//trans transHistory[50];
	//get qtySold from transHistory
	//date,qtysold,staffid,invoice
	public:
	string stock();
	int addQty();
	int removeQty();
	double getTotalSale();
	string displaySummary();
	//
	string getID();
	string getDesc();
	string getCategory();
	string getSubCat();
	double getAmountPerUnit();
	int getQty();
	int getThreshold();
	string getAlertMessage();
	//
	void setID(string id);
	void setDesc(string desc);
	void setCategory(string categroy);
	void setSubCat(string subCat);
	void setAmountPerUnit(double APU);
	void setQty(int quty);
	void setThreshold(int tHold);
	void setAlertMessage(string aMessage); 
}




#endif
