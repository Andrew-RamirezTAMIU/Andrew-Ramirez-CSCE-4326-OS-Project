#ifndef PROCESS_H //creating header file
#define PROCESS_H
#include <iostream>
using namespace std;

enum ProcessState { NEW, READY, RUNNING, WAITING, TERMINATED }; //establishing class for states using ENUM

//creating class
class Process {
private:
	int pid, priority;
	int arrival_time, burst_time, remaining_time, waiting_time, turnaround_time;
	double memory_required;
	ProcessState state;
	bool io_operations;
public:
	//creating constructors
	Process(int id, int arrival, int burst, int prior, double mem, bool io);


	// Creating method to decrement remaining time
	void updateState(ProcessState newState);
	void execute(int time);

	// Creating Getters and Setters
	int getPID() const;
	ProcessState getState() const;
	int getRemainingTime() const;

	void setWaitingTime(int time);
	void setTurnaroundTime(int time);

};

#endif