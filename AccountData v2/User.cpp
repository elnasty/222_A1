#include "accountData.h"

//Constructors
User::User ()
{
	staffID = new char [MAXLEN];
	password = new char [MAXPW];
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
	password = new char [MAXPW];
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

void User::copyUser (User another)
{
	strcpy(this ->staffID, another.getStaffID());
	strcpy(this ->password, another.getPwd());
	strcpy(this ->email, another.getEmail());
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
	cout << "Staff ID: " ;
	cin >> staffID;
	cin.clear ();
	cin.ignore (MAXLEN, '\n');
	cout << endl;
	
	cout << "Password: " ;
	cin >> password;
	cin.clear ();
	cin.ignore (MAXLEN, '\n');
	cout << endl;
	
	if (database.getStatus (staffID) == false) //account is not locked
	{
		if (database.validateUser (staffID, password))
			cout << "Login Success" << endl;
		else
		{
			cout << "Login Failure" << endl;
			database.addFailCount(staffID);
		}
	}
	else
	{
		cout << "Account with Staff ID \'" << staffID 
			 << "\' is locked" << endl;
	}
}

void User::changePw()
{
	cout << "Staff ID: " ;
	cin >> staffID;
	cin.clear ();
	cin.ignore (MAXLEN, '\n');
	cout << endl;
	
	cout << "Password: " ;
	cin >> password;
	cin.clear ();
	cin.ignore (MAXLEN, '\n');
	cout << endl;
	
	char newPwd [MAXPW];
	
	if (database.getStatus (staffID) == false) //account is not locked
	{
		if (database.validateUser (staffID, password)) 
		{
			cout << "New Password: " << endl;
			cin >> newPwd;
			cin.clear ();
			cin.ignore (MAXLEN, '\n');
			cout << endl;
			
			database.changePw (staffID, newPwd);
			cout << "Password Change Success" << endl;
		}
		else
			cout << "Validation Failure" << endl;
	}
	else
	{
		cout << "Account with Staff ID \'" << staffID 
			 << "\' is locked" << endl;
	}
}

void User::resetPw()
{
	cout << "Staff ID: " ;
	cin >> staffID;
	cin.clear ();
	cin.ignore (MAXLEN, '\n');
	cout << endl;
	
	cout << "Email: " ;
	cin >> email;
	cin.clear ();
	cin.ignore (MAXLEN, '\n');
	cout << endl;
	
	if (database.getStatus (staffID) == false) //account is not locked
	{
		if (database.validateEmail (staffID, email))
		{
			database.resetPassword (staffID);
			cout << "Password Reset Success" << endl;
		}
		else
			cout << "Validation Failure" << endl;
	}
	else
	{
		cout << "Account with Staff ID \'" << staffID 
			 << "\' is locked" << endl;
	}
}

void User::incrementFailCount ()
{
	++failCount;
}

int User::getFailCount ()
{
	return failCount;
}

