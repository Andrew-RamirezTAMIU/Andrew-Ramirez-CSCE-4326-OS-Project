#include <iostream> // Input and Output library
#include <string> // String Library
#include <vector>
#include "auth.h" // Includes the authentication function
#include "Process.h"

using namespace std;

// Outputs message simulating an OS booting process
void booting() {
    cout << "Starting up...\n";
    cout << endl;
}

// Function to print scheduling results
void printResults(const vector<Process>& processes) {
    cout << "\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n";
    for (const auto& process : processes) {
        cout << process.getPID() << "\t"
            << process.getArrivalTime() << "\t"
            << process.getBurstTime() << "\t"
            << process.getWaitingTime() << "\t"
            << process.getTurnaroundTime() << "\n";
    }
}

int main() {
    booting();

    // Calls the authentication function
    if (authenticateUser()) {
        cout << "\nAccess Granted. Welcome... \n";
        cout << endl;

        // Calls the process function
        cout << "Initializing process management...\n";
        cout << endl;

        // Creating 5 test cases
        vector<Process> processes = {
            Process(1, 0, 10, 1, 100, false),
            Process(2, 2, 5, 2, 50, true),
            Process(3, 4, 8, 1, 75, false),
            Process(4, 6, 12, 3, 120, true),
            Process(5, 8, 7, 2, 60, false)
        };

        // Initial process states
        for (const auto& process : processes) {
            cout << "Process " << process.getPID() << " | State: NEW\n";
        }
        cout << endl;

        // Move all processes to READY state
        for (auto& process : processes) {
            process.updateState(READY);
        }
        cout << "All processes are READY.\n";

        // Simulate execution for some time
        for (auto& process : processes) {
            process.execute(3); // Simulate a portion of execution
        }

        // Display remaining execution time
        for (const auto& process : processes) {
            cout << "Process " << process.getPID() << " remaining time: " << process.getRemainingTime() << "\n";
        }
        cout << endl;

        // Finish execution
        for (auto& process : processes) {
            process.execute(10); // Simulate remaining execution
        }

        // End states
        for (const auto& process : processes) {
            cout << "Process " << process.getPID() << " | State: TERMINATED\n";
        }
        cout << endl;

        // **Scheduling Algorithms Execution**
        cout << "\n---- FCFS Scheduling ----\n";
        Process::FCFS_Scheduling(processes);
        printResults(processes);

        // Reset process states for the next scheduling test
        for (auto& process : processes) {
            process.setWaitingTime(0);
            process.setTurnaroundTime(0);
        }

        cout << "\n---- SJF Non-Preemptive Scheduling ----\n";
        Process::SJF_Nonpreemptive(processes);
        printResults(processes);

        // Reset process states again for the next test
        for (auto& process : processes) {
            process.setWaitingTime(0);
            process.setTurnaroundTime(0);
        }

        cout << "\n---- SJF Preemptive Scheduling ----\n";
        Process::SJF_PREEMPTIVE(processes);
        printResults(processes);

    }
    else {
        cout << "\nAccess Denied. This account may not be logged on to. Exiting... \n";
    }

    return 0; // Exits
}
