#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

static int number;
static int running_flag;

void inc_thr()
{
    auto start = chrono::system_clock::now();
    while(1)
    {
        auto now = chrono::system_clock::now();
        chrono::duration<double> elapsed = now - start;

        if(elapsed.count() >= 1.0){
            number += 1;
            cout << "elapsed : " << elapsed.count() << endl;
            start = now;
        }
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}

void pri_thr()
{
    auto start = chrono::system_clock::now();
    while(1)
    {
        auto now = chrono::system_clock::now();
        chrono::duration<double> elapsed = now - start;

        if(elapsed.count() >= 5.0){
            cout << "Print Number :" << number <<endl;
            start = now;
        }
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}

int main()
{
    number = 1;
    thread t1(inc_thr);
    thread t2(pri_thr);

    while(true)
    {
        _sleep(1);    
    }
    return 0;
}