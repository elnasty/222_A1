/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   accountData.
 * Author: Xu Ke
 *
 * Created on February 14, 2018, 1:15 PM
 */
#include "accountData.h"

//Constructor: will call readFile ();
accountData::accountData() 
{
	readFile ("accountData.dat");
}

//Constructor: will call readFile ();
accountData::accountData(const char* txtFileName) 
{
	encryptFile ("accountData.txt", "accountData.dat");
	readFile ("accountData.dat");
}                

//Destructor: will call writeFile ();
accountData::~accountData ()
{
    writeFile ("accountData.dat");
}
 
//Returns number of records
int accountData::totalCount () const
{
    return this -> count;
}

//To create a binary file from plain text
void accountData::encryptFile (const char* txtFileName, const char* binaryFilename)
{
    fstream txtfile, bfile;
    txtfile.open (txtFileName, ios::in);
    bfile.open (binaryFilename, ios::out | ios::binary);
    if (!txtfile)
    {
        cout << "Failed to open " << txtFileName << " for encryption!" << endl;
        txtfile.close ();
        exit (-1);
    }
    if (!bfile)
    {
        cout << "Failed to open " << binaryFilename << " for encryption!" << endl;
        bfile.close ();
        exit (-1);
    }
    
    
    cout << txtFileName << " and " << binaryFilename 
         << " opened for encryption" << endl;
    
    user userRecord;
	char buffer[50];
    
    while (txtfile >> buffer)
    {
        userRecord.setStaffID(buffer);
		txtfile >> buffer;
		userRecord.setPwd(buffer);
		txtfile >> buffer;
		userRecord.setEmail(buffer);
        bfile.write (reinterpret_cast <const char*> (&userRecord), sizeof(userRecord));
    }
    
    txtfile.close ();
    bfile.close ();
}

//To populate array of users from encrypted database returning number of records
int accountData::readFile (const char* binaryFilename)
{
    fstream bfile;
	bfile.open (binaryFilename, ios::in | ios::binary);
	if (!bfile)
	{
		cout << "Failed to open " << binaryFilename << " for reading!" << endl;
        bfile.close ();
        exit (-1);
	}
	
	int index=0; //indicates the array user index
	
	while (bfile.read(reinterpret_cast<char *>(&userArray[index]), sizeof(userArray[index])))
	{
		++index;
	}
	
	this -> count = index;
		
	bfile.close ();
}

//To write back to database after an edit
void accountData::writeFile (const char* binaryFilename)
{
    fstream bfile;
	bfile.open (binaryFilename, ios::out | ios::binary);
	if (!bfile)
	{
		cout << "Failed to open " << binaryFilename << " for writing!" << endl;
        bfile.close ();
        exit (-1);
	}
	
	
	for (int i=0; i<this->count; i++)
	{
		bfile.seekp (i * sizeof(userArray[i]));
		bfile.write(reinterpret_cast<const char *> 
		(&userArray[i]), sizeof(userArray[i]));
	}
	
	bfile.close ();
}

//Generate and returns a random password string
void accountData::generatePw (char* newPw, int size)
{
    const char ALPHANUMERIC[]=	{'0','1','2','3','4','5','6','7','8','9',
							'A','B','C','D','E','F','G','H','I','J',
							'K','L','M','N','O','P','Q','R','S','T',
							'U','V','W','X','Y','Z','a','b','c','d',
							'e','f','g','h','i','j','k','l','m','n',
							'o','p','q','r','s','t','u','v','w','x',
							'y','z'};
	
	for (int i=0; i<size; i++)
	{
		newPw[i] = ALPHANUMERIC[rand () % 62];
	}
	
	newPw[size] = '\0';
}

//Add a new account record
void accountData::createAccount ()
{
	char buffer[50];
	
	cout << "New Account ID: ";
	cin >> buffer;
	userArray[this -> count].setStaffID(buffer);
	
	cout << "New Account Password: ";
	cin >> buffer;
	userArray[this -> count].setPwd(buffer);
	
	cout << "New Account Email: ";
	cin >> buffer;
	userArray[this -> count].setEmail(buffer);
	
	cout << "User account with ID " << userArray[this -> count].getStaffID ()
		 << " successfully created!"<< endl;
		 
	++this -> count;
} 

//Remove an existing account record
void accountData::removeAccount ()
{
	char accRemove[MAXUSER];
	cout << "Account ID to be Removed: ";
	cin >> accRemove;
	
	user* temp = new user[MAXUSER];
	
	int j = 0;
	
	for (int i=0; i<this->count; i++)
	{
		if (strcmp (accRemove, userArray[i].getStaffID()) != 0)
		{
			temp[j].setStaffID (userArray[i].getStaffID ());
			temp[j].setPwd (userArray[i].getPwd ());
			temp[j].setEmail (userArray[i].getEmail ());
			++j;
		}
	}
	
	this -> count = j;
	
	for (int k=0; k<this->count; k++)
	{
		userArray[k].setStaffID (temp[k].getStaffID ());
		userArray[k].setPwd (temp[k].getPwd ());
		userArray[k].setEmail (temp[k].getEmail ());
	}
	
	userArray[j].setStaffID ('\0');
	userArray[j].setPwd ('\0');
	userArray[j].setEmail ('\0');
	
	cout << "Account ID: " << accRemove 
		 << "removed successfully!" << endl;
}

//Reset an account password
void accountData::resetPassword (const char staffID [], int size)
{
	char* newPw = new char [size];
	generatePw (newPw, size);
	
	for (int i=0; i<this->count; i++)
	{
		if (strcmp (staffID, userArray[i].getStaffID()) == 0)
		{
			userArray[i].setPwd (newPw);
		}
	}
}      

//Unlock a locked account
bool accountData::unlockAccount (const char * staffID)
{
	for (int i=0; i<this->count; i++)
	{
		if (strcmp (staffID, userArray[i].getStaffID()) == 0)
		{
			userArray[i].setStatus (false);
		}
	}
}

//Lock an unlocked account
bool accountData::lockAccount (const char * staffID)
{
	for (int i=0; i<this->count; i++)
	{
		if (strcmp (staffID, userArray[i].getStaffID()) == 0)
		{
			userArray[i].setStatus (true);
		}
	}
}       

//Validate through ID and password
bool accountData::validateUser (const char * staffID, const char * password)
{
	for (int i=0; i<this->count; i++)
	{
		if (strcmp(userArray[i].getStaffID(), staffID) == 0)
		{
			if (strcmp (userArray[i].getPwd(), password) == 0)
			{
				return true;
			}
		}
	}
		
	return false;
}

//Validate through ID and email
bool accountData::validateEmail (const char * staffID, const char * email) 
{
	for (int i=0; i<this->count; i++)
	{
		if (strcmp(userArray[i].getStaffID(), staffID) == 0)
		{
			if (strcmp (userArray[i].getEmail(), email) == 0)
			{
				return true;
			}
		}
	}
		
	return false;
}      

//Displays list of account ID and email
void accountData::displayAccounts ()
{
	cout << "No.\tStaff ID\tEmail" << endl;
	for (int i=0; i<this->count; i++)
	{
		cout << i+1  << '\t' << userArray [i].getStaffID ()
			 << '\t' << userArray [i].getEmail () << endl;
	}
}

