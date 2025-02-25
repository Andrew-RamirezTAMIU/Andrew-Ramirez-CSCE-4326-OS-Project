#include <iostream> //Input and Output library
#include <string> //String Libary
#include "auth.h" //Includes the authentecation function
#include "Process.h"
using namespace std;

//Outputs message simulating an OS
void booting() {
	cout << "Starting up...\n";
	cout << endl;
}


int main() {
	booting();
	//calls the authentecation function
	if (authenticateUser()) {
		cout << "\nAccess Granted. Welcome... \n";
		cout << endl;

		//calls the process function
		cout << "Initializing process management...\n";
		cout << endl;

		//creating 5 test cases
		Process p1(1, 0, 10, 1, 100, false);
		Process p2(2, 2, 5, 2, 50, true);
		Process p3(3, 4, 8, 1, 75, false);
		Process p4(4, 6, 12, 3, 120, true);
		Process p5(5, 8, 7, 2, 60, false);

		//initial states
		cout << "Process " << p1.getPID() << " | State: NEW\n";
		cout << "Process " << p2.getPID() << " | State: NEW\n";
		cout << "Process " << p3.getPID() << " | State: NEW\n";
		cout << "Process " << p4.getPID() << " | State: NEW\n";
		cout << "Process " << p5.getPID() << " | State: NEW\n";
		cout << endl;

		//ready state
		p1.updateState(READY);
		p2.updateState(READY);
		p3.updateState(READY);
		p4.updateState(READY);
		p5.updateState(READY);

		cout << "All processes are READY.\n";

		//simulate execution
		p1.execute(3);
		p2.execute(2);
		p3.execute(4);
		p4.execute(5);
		p5.execute(3);

		cout << "Process " << p1.getPID() << " remaining time: " << p1.getRemainingTime() << "\n";
		cout << "Process " << p2.getPID() << " remaining time: " << p2.getRemainingTime() << "\n";
		cout << "Process " << p3.getPID() << " remaining time: " << p3.getRemainingTime() << "\n";
		cout << "Process " << p4.getPID() << " remaining time: " << p4.getRemainingTime() << "\n";
		cout << "Process " << p5.getPID() << " remaining time: " << p5.getRemainingTime() << "\n";
		cout << endl;

		//finish execution
		p1.execute(7);
		p2.execute(3);
		p3.execute(4);
		p4.execute(7);
		p5.execute(4);

		//end states
		cout << "Process " << p1.getPID() << " | State: TERMINATED\n";
		cout << "Process " << p2.getPID() << " | State: TERMINATED\n";
		cout << "Process " << p3.getPID() << " | State: TERMINATED\n";
		cout << "Process " << p4.getPID() << " | State: TERMINATED\n";
		cout << "Process " << p5.getPID() << " | State: TERMINATED\n";
		cout << endl;

	}

	else {
		cout << "\nAccess Denied. This account may not be logged on to. Exiting... \n";
	}

	return 0; //Exits
}