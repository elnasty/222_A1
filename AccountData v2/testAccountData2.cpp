/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   testAccountData2.cpp
 * Author: Xu Ke
 *
 * Created on February 16, 2018, 20:25 PM
 */
 
#include "accountData.cpp"

int main ()
{
	AccountData database;
	
	database.displayAccounts ();
	cout << endl;
	
	database.createAccount ();
	cout << endl;
	database.removeAccount ();
	cout << endl;
	database.removeAccount ();
	cout << endl;
	
	database.displayAccounts ();
	cout << "\nRecords; " << database.totalCount () << endl;
	
	return 1;
}

