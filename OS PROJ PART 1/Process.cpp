#include <iostream> //Input and Output Library
#include <string> //String Libary
#include <vector>
#include "Process.h"

using namespace std;

	//constructors
	Process::Process(int id, int arrival, int burst, int prior, double mem, bool io) {
		pid = id;
		arrival_time = arrival;
		burst_time = burst;
		remaining_time = burst;
		priority = prior;
		memory_required = mem;
		io_operations = io;
		state = NEW;
		waiting_time = 0;
		turnaround_time = 0;
	}

	void Process::updateState(ProcessState newState) {
		state = newState;
	}

	// decrement remaining time
	void Process::execute(int time) {
		if (remaining_time > 0) {
			remaining_time -= time;
		}
		if (remaining_time <= 0) {
			remaining_time = 0;
			state = TERMINATED;
		}
	}

	// Getters and Setters
	int Process::getPID() const {
		return pid;
	}	

	ProcessState Process::getState() const {
		return state;
	}
	int Process::getRemainingTime() const {
		return remaining_time;
	}
	void Process::setWaitingTime(int time) {
		waiting_time = time;
	}
	void Process::setTurnaroundTime(int time) {
		turnaround_time = time;
	}