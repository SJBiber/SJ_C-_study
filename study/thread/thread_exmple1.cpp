#include <iostream>
#include <thread>

using namespace std;
int func1(int &ret )
{
    cout << ret + 1 << endl;
    ret = 99;
    return 1;
}

int main ()
{
    int ret = 0 ;
    thread t1(func1,ref(ret));
    t1.join();
    cout << "Return : " << ret << endl;
    return 0;
}