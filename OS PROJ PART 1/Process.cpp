#include <iostream> // Input and Output Library
#include <string> // String Library
#include <vector> //vectors
#include <algorithm> //sorting 
#include <climits> //for INT_MAX
#include "Process.h"

using namespace std;

// Constructors
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

// Decrement remaining time
void Process::execute(int time) {
    if (remaining_time > 0) {
        remaining_time -= time;
    }
    if (remaining_time <= 0) {
        remaining_time = 0;
        state = TERMINATED;
    }
}

// Setters
void Process::setWaitingTime(int time) {
    waiting_time = time;
}

void Process::setTurnaroundTime(int time) {
    turnaround_time = time;
}

// Getters
int Process::getPID() const {
    return pid;
}

ProcessState Process::getState() const {
    return state;
}

int Process::getRemainingTime() const {
    return remaining_time;
}

int Process::getWaitingTime() const {
    return waiting_time;
}

int Process::getTurnaroundTime() const {
    return turnaround_time;
}

int Process::getArrivalTime() const {
    return arrival_time;
}

int Process::getBurstTime() const {
    return burst_time;
}

int Process::getPriority() const {
    return priority;
}

// First Come First Serve (FCFS) Scheduling
void Process::FCFS_Scheduling(vector<Process>& processes) {
    // Sort processes by arrival time
    //sorting in ascending order
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.getArrivalTime() < b.getArrivalTime();
        });

    int current_time = 0;

    // Auto is a placeholder for Process
    for (auto& process : processes) {
        if (current_time < process.getArrivalTime()) {
            current_time = process.getArrivalTime();
        }
        current_time += process.getBurstTime();

        int turnaround = current_time - process.getArrivalTime();
        int waiting = turnaround - process.getBurstTime();

        process.setTurnaroundTime(turnaround);
        process.setWaitingTime(waiting);
    }
}

// Shortest Job First (SJF) Non-Preemptive 
void Process::SJF_Nonpreemptive(vector<Process>& processes) {
    int n = processes.size();
    //setting everything to zero
    vector<int> completion_time(n, 0), turnaround_time(n, 0), waiting_time(n, 0);
    int current_time = 0, shortest = 0;

    // Sort by arrival time first like FCFS, then by burst time like SJF
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return (a.getArrivalTime() == b.getArrivalTime()) ? (a.getBurstTime() < b.getBurstTime()) : (a.getArrivalTime() < b.getArrivalTime());
        });

    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].getArrivalTime()) {
            current_time = processes[i].getArrivalTime(); // Idle until next process arrives
        }

        completion_time[i] = current_time + processes[i].getBurstTime();
        turnaround_time[i] = completion_time[i] - processes[i].getArrivalTime();
        waiting_time[i] = turnaround_time[i] - processes[i].getBurstTime();

        processes[i].setWaitingTime(waiting_time[i]);
        processes[i].setTurnaroundTime(turnaround_time[i]);

        current_time = completion_time[i]; // Move time
    }
}

// Shortest Job First (SJF) Preemptive 
void Process::SJF_PREEMPTIVE(vector<Process>& processes) {
    int n = processes.size();
    vector<int> remaining_time(n), waiting_time(n, 0), turnaround_time(n, 0), completion_time(n, 0);

    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].getBurstTime();
    }

    int completed = 0, current_time = 0, min_burst = INT_MAX, shortest = -1;
    bool found = false;

    while (completed < n) {
        found = false;
        min_burst = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (processes[i].getArrivalTime() <= current_time && remaining_time[i] > 0) {
                if (remaining_time[i] < min_burst) {
                    min_burst = remaining_time[i];
                    shortest = i;
                    found = true;
                }
            }
        }

        if (!found) {
            current_time++;
            continue;
        }

        // shortest job
        remaining_time[shortest]--;
        current_time++;

        if (remaining_time[shortest] == 0) {
            completed++;
            completion_time[shortest] = current_time;

            turnaround_time[shortest] = completion_time[shortest] - processes[shortest].getArrivalTime();
            waiting_time[shortest] = turnaround_time[shortest] - processes[shortest].getBurstTime();

            // Updating the process object
            processes[shortest].setWaitingTime(waiting_time[shortest]);
            processes[shortest].setTurnaroundTime(turnaround_time[shortest]);
        }
    }
}
