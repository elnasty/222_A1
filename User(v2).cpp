#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

#define MAXLEN 100

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
				
				//Mutators
				void setStaffID (const char*);
				void setPwd(const char*);
				void setEmail(const char*);
				void setAccLock (bool);
				
				//Other key methods
				bool isEmpty ();
				void login();
				void changePw();
				void resetPw();

	private: 	bool validateLogin ();
				
				
				//Member attributes
	protected:	
				char* staffID;
				char* password;
				char* email;
				int failCount;
				bool accLock;	 
};

//Constructors
User::User ()
{
	staffID = new char [MAXLEN];
	password = new char [MAXLEN];
	email = new char [MAXLEN];
	strcpy (staffID, "");
	strcpy (password, "");
	strcpy (email, "");
	
	failCount = 0;
	accLock = false;
}

User::User (const char* SID, const char* PWD, const char* EA)
{
	staffID = new char [MAXLEN];
	password = new char [MAXLEN];
	email = new char [MAXLEN];
	failCount = 0;
	accLock = false;
	
	strcpy (staffID, SID);
	strcpy (password, PWD);
	strcpy (email, EA);
}

//Destructor free allocated memory
User::~User ()
{
	delete [] staffID;
	staffID = NULL;
	delete [] password;
	password = NULL;
	delete [] email;
	email = NULL;
}

//Accessors 
const char* User::getStaffID()
{
	return staffID;
}

const char* User::getPwd()
{
	return password;
}

const char* User::getEmail()
{
	return email;
}

bool User::getAccLock ()
{
	return accLock;
}

//Mutators
void User::setStaffID (const char* SID)
{
	strcpy (staffID, SID);
}

void User::setPwd(const char* PWD)
{
	strcpy (password, PWD);
}

void User::setEmail(const char* EA)
{	
	strcpy (email, EA);
}

void User::setAccLock (bool status)
{
	accLock = status;
}

//Other key methods
bool User::isEmpty ()
{
	return ((strcmp (getStaffID(), "") == 0) &&
			(strcmp (getPwd(), "") == 0) &&
			(strcmp (getEmail(), "") == 0));
}

void User::login()
{
	
}

void User::changePw()
{
	
}

void User::resetPw()
{
	
}

bool User::validateLogin ()
{

}


