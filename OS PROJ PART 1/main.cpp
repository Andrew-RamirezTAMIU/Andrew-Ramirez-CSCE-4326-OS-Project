#include <iostream>
#include <string>
#include "auth.h"
using namespace std;

void booting() {
	cout << "Starting up...\n";
	cout << endl;
}

int main() {
	booting();
	if (authenticateUser()){
		cout << "\nAccess Granted. Welcome... \n";
	}
	else {
		cout << "\nAccess Denied. This account may not be logged on to. Exiting... \n";
	}
}