#include <iostream>
using namespace std;
void leftshift()
{
    int x = 3;
    cout << (x << 1) << endl;
    cout << (x << 2) << endl;
    int y = 4;
    int z = (x << y);
    cout << z;
}

void rightshift()
{
    int x = 33;
    cout << (x >> 1) << endl;
    cout << (x >> 2) << endl;
    int y = 4;
    int z = (x >> y);
    cout << z;
}

void bitnot()
{
    unsigned int x = 1;
    cout << (~x) << endl;
    x = 5;
    cout << (~x) << endl;
}

int main()
{
    bitnot();
    return 0;
}