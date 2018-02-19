#include "AccountHeader.h"

AccountData database ("AccountData.dat");
Inventory inventory ("items.txt", "items.dat");

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

const char* User::login()
{
	cout << "Account ID: " ;
	cin >> staffID;
	cin.clear ();
	cin.ignore (MAXLEN, '\n');
	
	cout << "Password: " ;
	
	//Password masking in std out
	char c;
	int i = 0; 
	while ((c=_getch()) != '\r')
	{
	
	    password[i] = c;
	    cout <<'*';
		++i;
	}
	
	password [i] = '\0';
	cout << endl;
	
	if (database.getStatus (staffID) == false) //account is not locked
	{
		if (database.validateUser (staffID, password))
		{
			cout << "Login Success" << endl;
			return staffID;
		}
		else
		{
			cout << "Login Failure" << endl;
			database.addFailCount(staffID);
			return "Fail";
		}
	}
	else
	{
		cout << "Account with ID \'" << staffID 
			 << "\' is locked" << endl;
		return "Fail";
	}
}

void User::changePw()
{
	cout << "Account ID: " ;
	cin >> staffID;
	cin.clear ();
	cin.ignore (MAXLEN, '\n');
	
	cout << "Current Password: " ;
	//Password masking in std out
	char c;
	int i = 0; 
	while ((c=_getch()) != '\r')
	{
	
	    password[i] = c;
	    cout <<'*';
		++i;
	}
	
	password [i] = '\0';
	cout << endl;
	
	char newPwd [MAXPW];
	
	if (database.getStatus (staffID) == false) //account is not locked
	{
		if (database.validateUser (staffID, password)) 
		{
			bool checkPw;
			do
			{
				cout << "New Password: ";
		
				int j = 0; 
				while ((c=_getch()) != '\r')
				{
				
				    newPwd[j] = c;
				    cout <<'*';
					++j;
				}
				
				newPwd [j] = '\0';
				cout << endl;
				
				checkPw = validatePw(newPwd);
				if (checkPw == false)
				{
					cout << "Password length must be at least 8 characters \n";
					cout << "consisting of at least 7 alphanumeric characters \n";
					cout << "1 special symbol, 1 upper character and cannot have space." << endl;
				}
				
			} while (checkPw == false);
			
			database.changePw (staffID, newPwd);
			cout << "Password Change Success" << endl;
		}
		else
			cout << "Validation Failure" << endl;
	}
	else
	{
		cout << "Account with ID \'" << staffID 
			 << "\' is locked" << endl;
	}
}

void User::resetPw()
{
	cout << "Account ID: " ;
	cin >> staffID;
	cin.clear ();
	cin.ignore (MAXLEN, '\n');
	
	cout << "Email: " ;
	cin >> email;
	cin.clear ();
	cin.ignore (MAXLEN, '\n');
	
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
		cout << "Account with ID \'" << staffID 
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


bool User::validatePw(const char* pw)
{

	/* Pw requirements: Minimum 7 alphanumeric,
						1 capital letter,
						1 special symbol, no space */
	int length = 0;
	while (pw[length] != '\0') //to get length
		++length;
		
	if (length < 8)
		return false;
	else if (length > 14)
		return false;
	
	int alphanum = 0;
	int special = 0;
	int space = 0;
	int capital = 0;
	
	int i = 0;
	while (pw[i] != '\0')
	{
		if (isalnum (pw[i]))
			alphanum++;
		
		if (!isalnum (pw[i]))
			special++;
			
		if (isspace (pw[i]))
			space++;
			
		if (isupper (pw[i]))
			capital++;
			
		++i;
	}
	
	if (alphanum < 7)
		return false;
	else if (special < 1)
		return false;
	else if (space > 0)
		return false;
	else if (capital < 1)
		return false;
		
	return true;
}

