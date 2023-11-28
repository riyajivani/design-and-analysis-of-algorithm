// C++ Program for Iterative Tower of Hanoi using STL
 
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
 
char rod[]={'S', 'A', 'D'};
vector<stack<int>> stacks(3); // 3 stacks for 3 rods
 
void moveDisk(int a, int b)
{
    if (stacks[b].empty() || (!stacks[a].empty() && stacks[a].top() < stacks[b].top()))
    {
        cout << "Move disk " << stacks[a].top() << " from rod " << rod[a] << " to rod " << rod[b] << "\n";
        stacks[b].push(stacks[a].top());
        stacks[a].pop();
    }
    else
        moveDisk(b, a);
}
 
void towerOfHanoi(int n)
{
    cout << "Tower of Hanoi for " << n << " disks:\n";
 
    int src = 0, aux = 1, dest = 2;
    for (int i = n; i > 0; i--)
        stacks[src].push(i);
 
    int totalMoves = (1 << n) - 1;
    if (n % 2 == 0)
        swap(aux, dest);
 
    for (int i = 1; i <= totalMoves; i++)
    {
        if (i % 3 == 0)
            moveDisk(aux, dest);
        else if (i % 3 == 1)
            moveDisk(src, dest);
        else
            moveDisk(src, aux);
    }
}
 
int main()
{
    int n = 3; // number of disks
    towerOfHanoi(n);
    return 0;
}