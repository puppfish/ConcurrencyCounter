
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void countUp()
{
    cout << "Thread 1: Counting Up" << endl;

    for (int i = 1; i <= 20; i++)
    {
        cout << "Count Up: " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    cout << "Thread 1 finished!" << endl;
}

void countDown()
{
    cout << "\nThread 2: Counting Down" << endl;

    for (int i = 20; i >= 0; i--)
    {
        cout << "Count Down: " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    cout << "Thread 2 finished!" << endl;
}

int main()
{
    cout << "Starting Concurrency Counter Application" << endl;

    thread thread1(countUp);
    thread1.join();

    thread thread2(countDown);
    thread2.join();

    cout << "\nBoth threads have completed successfully!" << endl;

    return 0;
}
