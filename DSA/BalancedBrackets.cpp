#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool balanced(string s);
void test(string s);

int main() {
    test("((a+b)+{e-(a-b)})");
    test(")(");
    test("abcd");
    test("(((a+b)+{e-(a-b)})");
    return 0;
}

bool balanced(string s) {
    stack<char> stk;
    for (unsigned int i = 0; i < s.length(); i++) {
        // if open bracket, push
        // if close bracket, pop and compare
        if (s[i] != '{' && s[i] != '(' && s[i] != '}' && s[i] != ')') 
            continue;
        if (s[i] == '(' || s[i] == '{')
            stk.push(s[i]);
        else if (s[i] == ')' || s[i] == '}') {
            if (stk.empty()) return false;
            char test = stk.top();
            stk.pop();
            if (s[i] == ')' && test == '(')
                continue;
            if (s[i] == '}' && test == '{')
                continue;
            return false;
        }
    }
    if (stk.empty()) 
        return true;
    return false;
}

void test(string s) {
    cout << s << " is " << (balanced(s) ? "balanced" : "unbalanced") << endl;
}
