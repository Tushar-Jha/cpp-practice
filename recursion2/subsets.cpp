#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void funcB(vector<int> &nums, vector<vector<int>> &output, vector<int> op, int i)
{
    if (i == nums.size())
    {
        output.push_back(op);
        return;
    }

    op.push_back(nums[i]);
    funcB(nums, output, op, i + 1);
    op.pop_back();
    funcB(nums, output, op, i + 1);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> output;
    vector<int> op;
    funcB(nums, output, op, 0);
    return output;
}

int main()
{

    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> fop = subsets(nums);
    for (int i = 0; i < fop.size(); i++)
    {
        for (int j = 0; j < fop[i].size(); j++)
        {
            cout << fop[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}