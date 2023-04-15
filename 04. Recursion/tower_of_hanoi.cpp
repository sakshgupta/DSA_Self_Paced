#include <iostream>
using namespace std;

void TOH(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 0)
    {
        return;
    }
    TOH(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from " << from_rod << " to " << to_rod << endl;
    TOH(n - 1, aux_rod, to_rod, from_rod);
}
 
int main()
{
    int N = 3;
    TOH(N, 'A', 'C', 'B');
    return 0;
}
