// Finding duplicate characters in a char string - test with "hello"
// Code only works for 2 duplicated letters
#include <iostream>
using namespace std;

void checkDupe(char* str);

int main()
{
    int x = 0;
    cout << "Enter number of letters followed by the string: " << endl;
    cin >> x;
    char* str = new char[x + 1];
    cin >> str;
    checkDupe(str);
}

void checkDupe(char* str)
{
    // Use 4 byte long int and check to store bitset to indicate presence
    // Require 32 bits as there are 26 alphabets
    // Initialise both to 000...0
    long int store = 0, check = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        check = 1;
        check = check << (str[i] - 97);
        if ((store & check) > 0)
        {
            cout << "'" << str[i] << "' is duplicated." << endl;
        }
        else
        {
            store = store | check;
        }
    }
}