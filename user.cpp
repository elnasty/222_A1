#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

class user 
{
	public: 
				//constructor
				user ();
				user (string, string, string);
				//destructor 
				~user ();
				// get function
				string getStaffID();
				string getPwd();
				string getEmail();
				// set function
				void setStaffID ();
				void setPwd();
				void setEmail();
				// other function
				void login();
				void changePw();
				void resetPw();

	private: 	bool validateLogin ();
				bool accLock ();

	protected:
				string staffID;
				string password;
				string email;
				int failCount;
				bool status;	
};


user::user ()
{
	staffID = "";
	password = "";
	email = "";
	failCount = 0;
}
user::user (string SID, string PWD, string EA)
{
	strcpy (staffID,SID);
	strcpy (password,PWD);
	strcpy (email,EA);
}
user::~user ()
{
	
}
// get function
string user::getStaffID()
{
	return staffID;
}
string user::getPwd()
{
	return password;
}
string user::getEmail()
{
	return email;
}
// set function
void user::setStaffID (string SID)
{
	staffID = SID;
}
void user::setPwd(string PWD)
{
	password = PWD:
}
void user::setEmail(string EA)
{	
	email = EA;
}
void user::login()
{
	cout << "User: ";
	cin  >> SID;
	cout << endl;
	cout << "Password: ";
	cin  >> PWD;
	cout << endl;
	
}
void user::changePw()
{
	
}
void user::resetPw()
{
	
}
bool user::validateLogin ()
bool user::accLock ()

