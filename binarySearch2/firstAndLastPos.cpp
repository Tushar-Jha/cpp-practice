#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int firstPos(vector<int> arr, int k)
{
    int start = 0;
    int end = arr.size() - 1;
    int pos = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == k)
        {
            pos = mid;
            end = mid - 1;
        }
        else if (arr[mid] < k)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return pos;
}

int lastPos(vector<int> arr, int k)
{
    int start = 0;
    int end = arr.size() - 1;
    int pos = -1;
    while (start <= end)
    {
        /* code */
        int mid = start + (end - start) / 2;
        if (arr[mid] == k)
        {
            pos = mid;
            start = mid + 1;
        }
        else if (k < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return pos;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 4, 4, 4, 4, 5, 6, 7, 8};
    cout << firstPos(arr, 4) << " " << lastPos(arr, 4);
    return 0;
}