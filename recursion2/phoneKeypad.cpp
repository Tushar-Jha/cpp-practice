#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(string digits, string op, vector<string> &output, int i, vector<string> keypad)
{
    if (i == digits.length())
    {
        output.push_back(op);
        return;
    }
    for (int j = 0; j < keypad[digits[i] - '0'].length(); j++)
    {
        op.push_back(keypad[digits[i] - '0'][j]);
        solve(digits, op, output, i + 1, keypad);
        op.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string op;
    vector<string> output;
    solve(digits, op, output, 0, keypad);
    return output;
}

int main()
{
    string digits = "23";
    vector<string> op = letterCombinations(digits);
    for (int i = 0; i < op.size(); i++)
    {
        cout << op[i] << endl;
    }
    return 0;
}