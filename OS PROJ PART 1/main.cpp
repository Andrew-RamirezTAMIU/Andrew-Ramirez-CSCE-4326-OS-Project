#include <iostream> //Input and Output library
#include <string> //String Libary
#include "auth.h" //Includes the authentecation function
using namespace std;

//Outputs message simulating an OS
void booting() {
	cout << "Starting up...\n";
	cout << endl;
}

//calls the authentecation function
int main() {
	booting();
	if (authenticateUser()){
		cout << "\nAccess Granted. Welcome... \n";
	}
	else {
		cout << "\nAccess Denied. This account may not be logged on to. Exiting... \n";
	}

	return 0; //Exits
}