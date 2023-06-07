// Consider a scenario for Hospital to cater services to different kinds of patients as Serious (top priority), b) non-serious (medium priority), c) General Checkup (Least priority). Implement the priority queue to cater services to the patients.
#include <iostream>
#include <string>
#include <queue>
using namespace std;

// Structure to represent a patient
struct Patient {
    string name;
    int priority;
};

// Function to compare two patients based on their priorities
bool operator<(const Patient& p1, const Patient& p2) {
    return p1.priority < p2.priority;
}

int main() {
    priority_queue<Patient> patientQueue;

    // Taking input from the user
    int numPatients;
    cout << "Enter the number of patients: ";
    cin >> numPatients;

    for (int i = 0; i < numPatients; i++) {
        Patient p;
        cout << "Enter the name of patient " << i+1 << ": ";
        cin >> p.name;
        cout << "Enter the priority of patient " << i+1 << " (3: Serious, 2: Non-serious, 1: General Checkup): ";
        cin >> p.priority;

        patientQueue.push(p);
    }

    // Serving patients in priority order
    cout << "\nServing patients:\n";
    while (!patientQueue.empty()) {
        Patient currentPatient = patientQueue.top();
        patientQueue.pop();
        cout << "Name: " << currentPatient.name << " | Priority: " << currentPatient.priority << endl;
    }

    return 0;
}


