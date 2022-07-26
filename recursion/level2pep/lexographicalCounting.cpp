#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int stringToNumber(string str)
{
    int x = 0;
    for (int i = 0; i < str.length(); i++)
    {
        x = x * 10 + (str[i] - '0');
    }
    return x;
}

void lexographicalCounting(int n, string op)
{
    //basecase
    if (stringToNumber(op) < n)
    {
        cout << op << " ";
    }
    if (stringToNumber(op) >= n)
    {
        return;
    }
    for (int i = 0; i <= 9; i++)
    {
        //excluding
        lexographicalCounting(n, op);
        //including
        char ch = (char)(i + 48);
        op.push_back(ch);
        lexographicalCounting(n, op);
        op.pop_back();
    }
}
//bada bhaiya
void lexicographicalPrintBadaBhaiya(const int& n)
{
    std::vector<int> indexPrinted(n, 0);
    std::vector<int> lexArray(n, 0);

    int lexNum = 1;
    for (int i = 0; i < n; ++i)
    {
        lexArray[i] = lexNum;
        indexPrinted[lexNum - 1] = 1;
        cout << lexNum<<" ";

        lexNum *= 10;

        if (n < lexNum)
        {
            lexNum = (lexNum / 10) + 1;

            while (0 == lexNum % 10)
                lexNum /= 10;

            if (n < lexNum)
                lexNum = (lexNum / 10) + 1;
        }
    }

    cout << "\nmissing numbers: ";
    for (int j = 0; j < n; ++j)
    {
        if (0 == indexPrinted[j])
            cout << j + 1 << " ";
    }

    
    for (int k = 1; k < n; ++k)
    {
        string prevNum = to_string(lexArray[k - 1]);
        string currNum = to_string(lexArray[k]);
        if (!lexicographical_compare(prevNum.begin(), prevNum.end(), currNum.begin(), currNum.end()))
            cout << "\nIncorrect output: ";
    }
}


void lexicographicalPrint(int n,int num){
    //basecase
    if(num>=n){
        return;
    }
    cout<<num<<" ";
    for(int i=0;i<10;i++){
        lexicographicalPrint(n,num*10+i);
    }
}

void abc(int n){
    for(int i=1;i<10;i++){
        lexicographicalPrint(n,i);
    }
    return;
}

int main()
{
    // lexicographicalPrint(100,1);
    //abc(1000);
    lexicographicalPrintBadaBhaiya(984327);
    return 0;
}
