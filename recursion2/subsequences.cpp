#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(string &str, string op, vector<string> &output, int i)
{
    if (i == str.length())
    {
        output.push_back(op);
        return;
    }
    solve(str, op, output, i + 1);
    op.push_back(str[i]);
    solve(str, op, output, i + 1);
}

vector<string> subsequences(string &str)
{
    string op;
    vector<string> output;
    solve(str, op, output, 0);
    return output;
}

int main()
{
    string str = "abc";
    vector<string> output = subsequences(str);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}