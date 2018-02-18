/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AccountData.cpp
 * Author: Xu Ke
 *
 * Created on February 14, 2018, 1:15 PM
 */
#include "User.cpp"


//Default constructor: will read default encrypted database
AccountData::AccountData ()
{
	userArray = new User [MAXUSER];
	readFile ("AccountData.dat");
}

//Constructor: will call readFile ();
AccountData::AccountData(const char* bFileName) 
{
	userArray = new User [MAXUSER];
	readFile (bFileName);
}

//Constructor: will call readFile ();
AccountData::AccountData(const char* txtFileName, const char* bFileName) 
{
	userArray = new User [MAXUSER];
	encryptFile (txtFileName, bFileName);
	readFile (bFileName);
}                

//Destructor: will call writeFile ();
AccountData::~AccountData ()
{
	cout << "\nUpdating the database..." << endl;
    writeFile ("AccountData.dat");
	
	delete [] userArray;
	userArray = NULL;
}
 
//Returns number of records
int AccountData::totalCount () const
{
    return this -> count;
}

//To create a binary file from plain text
void AccountData::encryptFile (const char* txtFileName, const char* binaryFilename)
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
		 
    //To store each field from txt file
	char buffer[MAXLEN]; 
	
	//Reach each field form txt file and write to binary
    while (txtfile >> buffer)
    {
        bfile.write (reinterpret_cast <const char*> (&buffer), 
					 sizeof(buffer));
		
		txtfile >> buffer;
		bfile.write (reinterpret_cast <const char*> (&buffer), 
					 sizeof(buffer));
		
		txtfile >> buffer;
		bfile.write (reinterpret_cast <const char*> (&buffer), 
					 sizeof(buffer));
		
		txtfile >> buffer;
		bfile.write (reinterpret_cast <const char*> (&buffer), 
					 sizeof(buffer));
    }
    
    txtfile.close ();
    bfile.close ();
}

//To populate array of Users from encrypted database returning number of records
int AccountData::readFile (const char* binaryFilename)
{
    fstream bfile;
	bfile.open (binaryFilename, ios::in | ios::binary);
	if (!bfile)
	{
		cout << "Failed to open " << binaryFilename << " for reading!" << endl;
        bfile.close ();
        exit (-1);
	}
	
	int i=0; //indicates the array User index
	
	char buffer [MAXLEN];
	bool status;
	
	while (bfile.read(reinterpret_cast<char *>(&buffer), sizeof(buffer)))
	{
		userArray [i].setStaffID (buffer);
		
		bfile.read(reinterpret_cast<char *>(&buffer), sizeof(buffer));
		userArray [i].setPwd (buffer);
		
		bfile.read(reinterpret_cast<char *>(&buffer), sizeof(buffer));
		userArray [i].setEmail (buffer);
		
		bfile.read(reinterpret_cast<char *>(&buffer), sizeof(buffer));
		
		if (strcmp (buffer, "Unlocked") == 0)
			status = false;
		else
			status = true;
		userArray [i].setAccLock (status);
		
		++i;
	}
	
	this -> count = i;
		
	bfile.close ();
}

//To write back to database after an edit
void AccountData::writeFile (const char* binaryFilename)
{
    fstream bfile;
	bfile.open (binaryFilename, ios::out | ios::binary);
	if (!bfile)
	{
		cout << "Failed to open " << binaryFilename << " for writing!" << endl;
        bfile.close ();
        exit (-1);
	}
	
	char buffer [MAXLEN];
	for (int i=0; i<this->count; i++)
	{
		strcpy (buffer, userArray[i].getStaffID ());
		bfile.write(reinterpret_cast<const char *> (&buffer), sizeof(buffer));
		
		strcpy (buffer, userArray[i].getPwd ());
		bfile.write(reinterpret_cast<const char *> (&buffer), sizeof(buffer));
		
		strcpy (buffer, userArray[i].getEmail ());
		bfile.write(reinterpret_cast<const char *> (&buffer), sizeof(buffer));
		
		if (userArray[i].getAccLock () == true)
				strcpy (buffer, "Locked");
		else
				strcpy (buffer, "Unlocked");
				
		bfile.write(reinterpret_cast<const char *> (&buffer), sizeof(buffer));
	}
	
	
	bfile.close ();
}

//Generate and returns a random password string
void AccountData::generatePw (char* newPw, int size)
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
bool AccountData::createAccount ()
{
	char buffer[MAXLEN];
	bool check;
	
	do
	{
		cout << "New Account ID: ";
		cin >> buffer;
		cin.clear ();
		cin.ignore (MAXLEN , '\n');
		
		check = checkCreateID (buffer);
		if (check == false)
		{
			cout << "Account ID must be of the following format: \n";
			cout << "Administrator: AXXXXXX\n";
			cout << "Operator:      OXXXXXX\n";
			cout << "Manager:       MXXXXXX\n";
		}
		
		cout << endl;
	} while (check == false);
	
	//To test if account already exists
	if (validateExist (buffer))
	{
		cout << "Account with ID \'" << buffer 
			 << "\' already exists! " << endl;
		return false;
	}
	else
	{
		userArray[this -> count].setStaffID(buffer);
			
		bool checkPw;
		do
		{
			cout << "New Account Password: ";
			char c;
			int i = 0; 
			while ((c=_getch()) != '\r')
			{
			
			    buffer[i] = c;
			    cout <<'*';
				++i;
			}
			
			buffer [i] = '\0';
			cout << endl;
			
			checkPw = userArray[this -> count].validatePw(buffer);
			if (checkPw == false)
			{
				cout << "Password length must be at least 8 characters consisting of at least 7 alphanumeric\n";
				cout << "characters + 1 special symbol + 1 upper character and cannot have space." << endl;
			}
			cout << endl;
			
		} while (checkPw == false);
			
		userArray[this -> count].setPwd(buffer);
			
		cout << "New Account Email: ";
		cin >> buffer;
		userArray[this -> count].setEmail(buffer);
			
		cout << "User account with ID \'" << userArray[this -> count].getStaffID ()
			 << "\' successfully created!"<< endl<<endl;
				 
		++this -> count;
		return true;
	}
} 

//Remove an existing account record
bool AccountData::removeAccount ()
{
	char accRemove[MAXUSER];
	cout << "Account ID to be Removed: ";
	cin >> accRemove;
	
	//Check if account exists
	if (validateExist (accRemove))
	{
		User* temp = new User[MAXUSER];
	
		int j = 0; //To store index of temp database
		for (int i=0; i<this->count; i++)
		{
			if (strcmp (accRemove, userArray[i].getStaffID()) != 0)
			{
				temp[j].setStaffID (userArray[i].getStaffID ());
				temp[j].setPwd (userArray[i].getPwd ());
				temp[j].setEmail (userArray[i].getEmail ());
				temp[j].setAccLock (userArray[i].getAccLock ());
				++j;
			}
		}
		
		this -> count = j;
		
		for (int k=0; k<this->count; k++)
		{
			userArray[k].setStaffID (temp[k].getStaffID ());
			userArray[k].setPwd (temp[k].getPwd ());
			userArray[k].setEmail (temp[k].getEmail ());
			userArray[k].setAccLock (temp[k].getAccLock());
		}
		
		userArray[j].setStaffID ("");
		userArray[j].setPwd ("");
		userArray[j].setEmail ("");
		
		cout << "Account with ID \'" << accRemove 
			 << "\' removed successfully!" << endl;
		return true;
	}
	else
	{ 
		cout << "Account with ID \'" << accRemove 
			 << "\' does not exists! " << endl;
		return false;
	}
	
}

//Reset an account password
bool AccountData::resetPassword (const char staffID [])
{
	if (validateExist(staffID))
	{
		int pwLen = 7;
		char* newPw = new char [pwLen];
		generatePw (newPw, pwLen);
		
		for (int i=0; i<this->count; i++)
		{
			if (strcmp (staffID, userArray[i].getStaffID()) == 0)
			{
				userArray[i].setPwd (newPw);
				cout << "New Password: " << userArray[i].getPwd () << endl;
			}
		}
		
		return true;
	}
	else 
		return false;
}      

//Unlock a locked account
bool AccountData::unlockAccount (const char * staffID)
{
	if (validateExist (staffID))
	{
		for (int i=0; i<this->count; i++)
		{
			if (strcmp (staffID, userArray[i].getStaffID()) == 0)
			{
				userArray[i].setAccLock (false);
			}
		}
		return true;
	}
	else
		return false;
}

//Lock an unlocked account
bool AccountData::lockAccount (const char * staffID)
{
	if (validateExist (staffID))
	{
		for (int i=0; i<this->count; i++)
		{
			if (strcmp (staffID, userArray[i].getStaffID()) == 0)
			{
				userArray[i].setAccLock (true);
			}
		}
		return true;
	}
	else 	
		return false;
}

void AccountData::changePw (const char* staffID, const char* newPwd)
{
	for (int i=0; i<this->count; i++)
	{
		if (strcmp (staffID, userArray[i].getStaffID()) == 0)
		{
			userArray[i].setPwd (newPwd);
		}
	}
}       

//Validate through ID and password
bool AccountData::validateUser (const char * staffID, const char * password)
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
bool AccountData::validateEmail (const char * staffID, const char * email) 
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
void AccountData::displayAccounts ()
{
	cout<<left<<setw(5)<<"No";
	cout<<left<<setw(15)<<"Staff ID";
	cout<<left<<setw(35)<<"Email";
	cout<<left<<setw(10)<<"Status" << endl;
	cout<<"-------------------------------------------------------------" <<endl;
	
	for (int i=0; i<this->count; i++)
	{	 	  
		cout<<left<<setw(5)<< i+1;
		cout<<left<<setw(15)<< userArray [i].getStaffID ();
		cout<<left<<setw(35)<< userArray [i].getEmail ();
			 
		if (userArray [i].getAccLock () == true)
			cout<<left<<setw(10)<< "Locked";
		else
			cout<<left<<setw(10)<< "Unlocked";
			
		cout << endl;
	}
}

bool AccountData::validateExist (const char* staffID)
{
	for (int i=0; i<this->count; i++)
	{
		if (strcmp (staffID, userArray[i].getStaffID()) == 0)
		{
			return true;
		}
	}
	
	return false;
}

void AccountData::addFailCount (const char* staffID)
{
	for (int i=0; i<this->count; i++)
	{
		if (strcmp (staffID, userArray[i].getStaffID()) == 0)
		{
			userArray[i].incrementFailCount ();
			if (userArray[i].getFailCount() > 2) //lock account if failcount is 3 and above
			{
				userArray[i].setAccLock(true);
			}
		}
	}
}


int AccountData::getFail (const char* staffID)
{
	for (int i=0; i<this->count; i++)
	{
		if (strcmp (staffID, userArray[i].getStaffID()) == 0)
		{
			return userArray[i].getFailCount ();
		}
	}
}

bool AccountData::getStatus (const char* staffID)
{
	for (int i=0; i<this->count; i++)
	{
		if (strcmp (staffID, userArray[i].getStaffID()) == 0)
		{
			return userArray[i].getAccLock ();
		}
	}
}

bool AccountData::checkCreateID (const char* staffID)
{
	int length = 0;
	while (staffID[length] != '\0')
	{
		if (isalnum(staffID[length]))
			++ length;
	}
		
	if (length != 7)
		return false;
	else if (staffID[0] != 'A' && staffID[0] != 'O' && staffID[0] != 'M')
		return false;
	
	return true;
}

