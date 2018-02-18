#include <iostream>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <conio.h>

using namespace std;

#define MAXUSER 100
#define MAXLEN 100
#define MAXPW 15

class User 
{
	public: 
				//Constructors
				User ();
				User (const char*, const char*, const char*);
				
				//Destructor free allocated memory
				~User ();
				
				//Accessors 
				const char* getStaffID();
				const char* getPwd();
				const char* getEmail();
				bool getAccLock ();
				int getFailCount ();
				
				//Mutators
				void setStaffID (const char*);
				void setPwd(const char*);
				void setEmail(const char*);
				void setAccLock (bool);
				void incrementFailCount ();
				
				//Copy constructor
				void copyUser (User);
				bool isEmpty ();
				
				//Other key methods
				char login();
				void changePw();
				void resetPw();
				bool validatePw(const char*);
				
	protected:	
				char* staffID;
				char* password;
				char* email;
				int failCount;
				bool accLock;	 
};

class AccountData
{
public:
	
	//Default constructor: will read default encrypted database
    AccountData ();
	
	//Other constructor: will read from specified encrypted database
    AccountData (const char*);   
	
	//Other constructor: will read from plain text and create an encrypted file         	
	AccountData (const char*, const char*); 		
	
	//Destructor: will call writeFile ();
    ~AccountData ();            
	
	//Functions that manage user accounts	 
    bool createAccount ();      	
    bool removeAccount ();      	
    bool resetPassword (const char*);      	     
    bool unlockAccount (const char*);      			  
    bool lockAccount (const char*);
	bool getStatus (const char*); 
	void changePw (const char*, const char*);
	void addFailCount (const char*);
	int getFail (const char*);      	   
	
	//Functions that do user validations
    bool validateUser (const char*, const char*);	  
    bool validateEmail (const char*, const char*);
	
	//Accessors
	int totalCount () const;	   	   	  	  	  	  
	void displayAccounts ();	 	 	 	 	 	 	
    
private:
	//An array of User objects
    User* userArray;
	
	//To store number of User records 
	int count;
	                
	//To create a binary file from plain text
    void encryptFile (const char*, const char*);
	 
	//To populate array of Users from binary file       
    int readFile (const char*);    
	
	//To write back to binary file after an edit       	  	  	  	  
    void writeFile (const char*);  
	
	//Generate and returns a random password string        	   	   	   
    void generatePw (char*, int size);  
	
	//To validate if staff ID currently exists
	bool validateExist (const char*);
	
	//To validate if creation of ID follows format
	bool checkCreateID (const char*);
};



