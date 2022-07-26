//print abreviations using recursion

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(string str, string op, int count, int i, vector<string> &res)
{
    //base case
    if (i == str.length())
    {
        if (count != 0)
        {
            char x = (char)(count + 48);
            op.push_back(x);
        }
        res.push_back(op);
        return;
    }
    if (count > 0)
    {
        char x = (char)(count + 48);
        solve(str, op + x + str[i], 0, i + 1, res);
    }

    else
    {
        solve(str, op + str[i], 0, i + 1, res);
    }

    solve(str, op, count + 1, i + 1, res);
}

vector<string> printAbreviations(string &str)
{
    string op;
    vector<string> res;
    solve(str, op, 0, 0, res);
    return res;
}

int main()
{
    string str = "pepe";
    vector<string> res = printAbreviations(str);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}