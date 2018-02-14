#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip>
#include "stock.h"
using namespace std;

stock::stock()
{
	itemID="";
	itemDesc="";
	itemCategory="";
	itemSubCat="";
	amountPerUnit=0.0;
	qty=0;
	threshold=0;
	alertMessage="";
	
}
int stock::addQty(int quty)
{
	int amount
}
int stock::removeQty(int quty)
{
	int amount
}
double stock::getTotalSale()
{
	double totalSale;

//get qtySold from transHistory
	totalSale = (trans.getQtySold() * amountPerUnit);
	return totalSale;
}
//string stock::displaySummary(string itemID, string itemDesc, string itemCategory, string itemSubCat, double amountPerUnit, int qty, double getTotalSale)
string stock::displaySummary()
{	
	//alignment needs working on....
	//output will change depending on first entry
	cout<<"ID"<<setw(10)<<"Description"<<setw(10)<<"Category"<<setw(10)<<"SubCat"<<setw(10)<<"Amount PerUnit"<<setw(10)<<"Qty"<<setw(10)<<"Total Sales"<<endl;
	cout<<itemID<<setw(10)<<itemDesc<<setw(10)<<itemCategory<<setw(10)<<itemSubCat<<setw(10)<<amountPerUnit<<setw(10)<<qty<<setw(10)<<getTotalSale<<endl;
}
//get
string stock::getID()
{
	return id;
}
string stock::getDesc()
{
	return desc;
}
string stock::getCategory()
{
	return category;
}
string stock::getSubCat()
{
	return subCat;
}
double stock::getAmountPerUnit()
{
	return APU;
}
int stock::getQty()
{
	return quty;
}
int stock::getThreshold()
{
	return tHold;
}
string stock::getAlertMessage()
{
	return aMessage;
}
//set
void stock::setID(string id)
{
	itemID=id;
}
void stock::setDesc(string desc)
{
	itemDesc=desc;
}
void stock::setCategory(string categroy)
{
	itemCategory=category;
}
void stock::setSubCat(string subCat)
{
	itemSubCat=subCat;
}
void stock::setAmountPerUnit(double APU)
{
	amountPerUnit=APU;
}
void stock::setQty(int quty)
{
	qty=quty;
}
void stock::setThreshold(int tHold)
{
	threshold=tHold;
}
void stock::setAlertMessage(string aMessage)
{
	alertMessage=aMessage;
}
