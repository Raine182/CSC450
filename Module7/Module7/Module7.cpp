// Module7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

using namespace std;

// Function for the first thread to count up to 20
void countUp(atomic<bool>& doneFlag) {
    for (int i = 0; i <= 20; ++i) {
        cout << "Count up: " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(100)); // Simulate work
    }
    doneFlag.store(true);
}

// Function for the second thread to count down to 0
void countDown(atomic<bool>& doneFlag) {
    while (!doneFlag.load()) {
        this_thread::yield(); // Wait until the first thread is done
    }

    for (int i = 20; i >= 0; --i) {
        cout << "Count down: " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(100)); // Simulate work
    }
}

int main() {
    atomic<bool> doneFlag(false);

    // Create the threads
    thread t1(countUp, ref(doneFlag));
    thread t2(countDown, ref(doneFlag));

    // Join the threads with the main thread
    t1.join();
    t2.join();

    return 0;
}