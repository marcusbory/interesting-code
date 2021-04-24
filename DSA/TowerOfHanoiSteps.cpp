// Solving Tower of Hanoi problems in minimal steps using recursion to print out steps
// Try out the game at https://www.mathsisfun.com/games/towerofhanoi.html
#include <iostream>
#define A 'A'
#define B 'B'
#define C 'C'
using namespace std;

void towerOfHanoi(int ndisks, char a, char b, char c);

int main()
{
    int noOfDisks;
    cout << "Number of disks in play: ";
    cin >> noOfDisks;
    towerOfHanoi(noOfDisks, A, B, C);
}

void towerOfHanoi(int ndisks, char a, char b, char c)
{
    static int steps = 1;
    // 1 Disk is trivial, so that will serve as minimal case
    if (ndisks > 0)
    {
        towerOfHanoi(ndisks - 1, a, c, b);
        cout << "Step " << steps << ". From " << a << " to " << c << endl;
        steps++;
        towerOfHanoi(ndisks - 1, b, a, c);
    }
}