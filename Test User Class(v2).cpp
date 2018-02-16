#include "User.cpp"

int main ()
{
	//Testing constructors
	User user;
	User user1 ("S12345", "abc123", "abc.gmail.com");
	User user2 ("54321", "12345", "maybenot.gmail.com");
	
	//Test mutators
	user2.setStaffID ("setala");
	user2.setPwd("setpw");
	user2.setEmail("set.gmail.com");
	user2.setAccLock (true);
	
	//Test Accessors
	cout<< user2.getStaffID() << '\t'
		<< user2.getPwd() << '\t'
		<< user2.getEmail() << '\t';
		
	if (user2.getAccLock () == true)
		cout << "Locked";
	else
		cout << "Unlocked";
	cout << endl;
	
	cout<< user1.getStaffID() << '\t'
		<< user1.getPwd() << '\t'
		<< user1.getEmail() << '\t';
		
	if (user1.getAccLock () == true)
		cout << "Locked";
	else
		cout << "Unlocked";
	cout << endl;
	
	cout<< user.getStaffID() << '\t'
		<< user.getPwd() << '\t'
		<< user.getEmail() << '\t';
		
	if (user.getAccLock () == true)
		cout << "Locked";
	else
		cout << "Unlocked";
	cout << endl;
	
	
	//Testing if user is empty
	if (strcmp (user.getStaffID(), "") == 0)
		cout << "Empty" << '\t';
		
	if (strcmp (user.getPwd(), "") == 0)
		cout << "Empty" << '\t';
		
	if (strcmp (user.getEmail(), "") == 0)
		cout << "Empty" << endl;
		
		
	if (user.isEmpty())
		cout << "This user is not allocated!" << endl;	  
}

