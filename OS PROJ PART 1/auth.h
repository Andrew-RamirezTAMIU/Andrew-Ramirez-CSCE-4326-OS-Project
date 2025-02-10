#include <iostream>
#include <string>

using namespace std;

bool authenticateUser() {
	string user, pass;
	const string correctUser = "admin";
	const string correctPass = "password123";

	cout << "Other User \n";

	cout << "Username: ";
	cin >> user;
	cout << "Password: ";
	cin >> pass;

	if (user == correctUser && pass == correctPass) {
		return true;
	}
	else {
		cout << "The username or password is incorrect. Try Again. \n";
		return false;
	}
}