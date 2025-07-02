#include <iostream>

using namespace std;

struct joungjeck
{
    /* data */
    int     idx;
    char    name[20];
    int     name_idx;
};

int main()
{
    joungjeck status[1];

    cout << "IDX ? \n";
    cin  >> status[0].idx;

    cout << "name ?\n";
    cin  >> status[0].name;
    
    cout << "name_idx ?\n";
    cin  >> status[0].name_idx;


    cout << status[0].idx << " || " << status[0].name << " || " << status[0].name_idx;

    return 0;

}