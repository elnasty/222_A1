/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   testAccountData.cpp
 * Author: Xu Ke
 *
 * Created on February 16, 2018, 3:25 PM
 */
 
#include "AccountData.cpp"

int main ()
{
	srand (time(NULL));

	cout << "Testing creation of database with 2 arg..." << endl;
	AccountData database ("AccountData.txt", "AccountData.dat");
	database.displayAccounts ();
	cout << endl;
	
	cout << "No. of records: " << database.totalCount () << endl;
	
	cout << "Testing creation of database1 with 1 arg..." << endl;
	AccountData database1 ("AccountData.dat");
	database1.displayAccounts ();
	cout << endl;
	
	cout << "No. of records: " << database1.totalCount () << endl;
	
	cout << "Testing creation of database2 wtih default constructor..." << endl;
	AccountData database2;
	database2.displayAccounts ();
	
	cout << "No. of records: " << database2.totalCount () << endl;
	
	cout <<"\nTesting create new account... " << endl;
	if (database2.createAccount () == false)
		cout <<"Error! Account already exists!" << endl;
	
	cout <<"\nTesting remove an account... " << endl;
	if (database2.removeAccount () == false)
		cout <<"Error! Account does not exists!" << endl;
		
	cout <<"\nTesting remove an account... " << endl;
	if (database2.removeAccount () == false)
		cout <<"Error! Account does not exists!" << endl;
		
	database.displayAccounts ();
	
	cout << "No. of records: " << database.totalCount () << endl;
	
	cout <<"\nTesting reset password for invalid user... " << endl;
	if (database.resetPassword ("nonexistance") == false)
		cout <<"Error! Account does not exists!" << endl;
		
	cout <<"\nTesting reset password for user1..." << endl;
	if (database.resetPassword ("user1") == false)
		cout <<"Error! Account does not exists!" << endl;
	
	cout <<"\nTesting lock account for user2 in database1..." << endl;
	if (database1.lockAccount ("user2") == false)
		cout <<"Error! Account does not exists!" << endl;
		
	database1.displayAccounts ();
	
	cout <<"\nTesting unlock account for user2 in database1..." << endl;
	if (database1.unlockAccount ("user2") == false)
		cout <<"Error! Account does not exists!" << endl;
	
	database1.displayAccounts ();
	
	cout <<"\nTesting validate user for user2 in database1..." << endl;
	if (database1.validateUser ("user2", "1234567"))
		cout << "Password correct!" << endl;
	else 
		cout << "Password wrong!" << endl;
		
	cout <<"\nTesting validate user for user2 in database1 (wrong password)..." << endl;
	if (database1.validateUser ("user2", "12567"))
		cout << "Password correct!" << endl;
	else 
		cout << "Password wrong!" << endl;
		
	cout <<"\nTesting validate user for user2 in database1 (wrong user)..." << endl;
	if (database1.validateUser ("user3", "1254567"))
		cout << "Password correct!" << endl;
	else 
		cout << "Password wrong!" << endl;
	
	cout <<"\nTesting validate email for user3 in database1..." << endl;
	if (database1.validateEmail ("user3", "five@yahoo.com.sg"))
		cout << "Email correct!" << endl;
	else 
		cout << "Email wrong!" << endl;
		
	cout <<"\nTesting validate email for user3 in database1 (wrong email)..." << endl;
	if (database1.validateEmail ("user3", "five@yahoo1.com.sg"))
		cout << "Email correct!" << endl;
	else 
		cout << "Email wrong!" << endl;
	
	
	return 1;
}

