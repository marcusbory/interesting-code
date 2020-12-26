#include <iostream>
#define N 4
using namespace std;

void permutate(char* str, int k);

int main()
{
    char string[N] = "ABC";
    permutate(string, 0);
}

/*
* This method uses 1 loop, 1 recursive call, and 2 static arrays (for storing bitset of alphabets used
* and results). 
* Base case: If permutation is complete (reach end of string), then print string
* Else: Look through bitset and see which other characters are unused, and fill up the letter at current index k
* Recursive call: Once k character is filled, permutate and fill k + 1 character. Continue until base case is reached,
* then count is reset to 0 (count[i] = 0), and continue looking for other characters to fill up.
*/
void permutate(char* str, int k)
{
    // Bitset to keep track of whether an alphabet has been "used"
    static int count[N] = { 0 };
    static char res[N];

    // Since it is recursive, it will check and print once a permutation is complete
    if (str[k] == '\0')
    {
        res[k] = '\0';
        cout << res << endl;
    }
    // Else, if not complete...
    else 
    {
        // Look through bitset to check (in ascending order) which alphabets are still free
        for (int i = 0; i < N - 1; i++)
        {
            // When an alphabet is free,
            if (count[i] == 0)
            {
                // Log the alphabet into position k in res
                res[k] = str[i];
                // Update the counter to 1 (indicate alphabet "used")
                count[i] = 1;
                // Shift position of k by 1 (aka move on to next alphabet) and continue permutation
                permutate(str, k + 1);
                // Once permutation at lower levels are down, backtrack and set counter to 0
                // Free up the alphabet for next permutation
                count[i] = 0;
            }
        }
    }
}