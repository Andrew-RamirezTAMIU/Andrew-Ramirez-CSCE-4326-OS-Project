#include <iostream> //Input and Output Library
#include <string> //String Library
#include "auth.h"
using namespace std;

bool authenticateUser() {
	string user, pass;

	//hardcoded Password
	const string correctUser = "admin";
	const string correctPass = "password123";

	//user prompt to input their credentials
	cout << "Other User \n";
	cout << "Username: ";
	cin >> user;
	cout << "Password: ";
	cin >> pass;

	//Checks if the user credentials are correct, otherwise will output incorrect
	if (user == correctUser && pass == correctPass) {
		return true; //Correct Credentials
	}
	else {
		cout << "\nThe username or password is incorrect. Try Again. \n"; //Wrong Credentials
		return false;
	}
}