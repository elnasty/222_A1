#include "user.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>

using namespace std;

#define MAXUSER 100

class accountData
{
public:
    accountData ();             	//Constructor: will call readFile ();
	accountData (const char*); 		//Constructor: will call encryptFile() and readFile ();
    ~accountData ();            	//Destructor: will call writeFile ();
    void createAccount ();      	//Add a new account record
    void removeAccount ();      	//Remove an existing account record
    void resetPassword (const char*, int);      	  //Reset an account password
    bool unlockAccount (const char*);      			  //Unlock a locked account
    bool lockAccount (const char*);        	  	  	  //Lock an unlocked account
    bool validateUser (const char*, const char*);	  //Validate through ID and password
    bool validateEmail (const char*, const char*);	  //Validate through ID and email
	int totalCount () const;	   	   	  	  	  	  //Returns total number of records
	void displayAccounts ();	 	 	 	 	 	 	//Displays list of accounts ID and emails
    
private:
	//An array of user objects
    user userArray[MAXUSER];
	
	//To store number of user records 
	int count;
	                
	//To create a binary file from plain text
    void encryptFile (const char*, const char*);
	 
	//To populate array of users from binary file       
    int readFile (const char*);    
	
	//To write back to binary file after an edit       	  	  	  	  
    void writeFile (const char*);  
	
	//Generate and returns a random password string        	   	   	   
    void generatePw (char*, int size);  
};

