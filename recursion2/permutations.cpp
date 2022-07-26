#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(vector<string> &output, string &str, int i)
{
    if (i == str.length())
    {
        output.push_back(str);
        return;
    }
    for (int j = i; j < str.length(); j++)
    {
        swap(str[i], str[j]);
        solve(output, str, i + 1);
        swap(str[i], str[j]);
    }
}

vector<string> permuatations(string str)
{
    vector<string> output;
    solve(output, str, 0);
    return output;
}

int main()
{
    string str = "abc";
    vector<string> output = permuatations(str);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}