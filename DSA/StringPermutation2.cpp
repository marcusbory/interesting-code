#include <iostream>
#define N 4
using namespace std;

void swap(char *a, char *b);
void permutate(char* str, int l, int h);

int main()
{
    char string[4] = "ABC";
    permutate(string, 0, 2);
}

void swap(char *a, char *b)
{
    char temp = *b;
    *b = *a;
    *a = temp;
}

void permutate(char* str, int l, int h)
{
    // When low pointer is pointing on same char as high pointer, base case is reached -> print string
    if (l == h)
    {
        cout << str << endl;
    }
    else
    {
        // Point l at all alphabets in the string
        for (int i = l; i <= h; i++)
        {
            // First example: Swap A with A
            swap(str[i], str[l]);
            // Set l to l + 1
            // Next stack will be swap B with B, then set l to l + 1
            // Next stack will be swap C with C, then set l to l + 1, then break
            permutate(str, l + 1, h);
            // After "ABC" is printed, return to B's stack (since it enters if block)
            // Swaps B with B, then since i=l=1, for loop sets i=2, l=1, swaps B and C, then repeat
            swap(str[i], str[l]);
        }

    }
}