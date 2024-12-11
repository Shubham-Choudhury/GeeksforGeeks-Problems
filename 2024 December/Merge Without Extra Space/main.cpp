// Link: https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void mergeArrays(vector<int> &a, vector<int> &b)
    {
        int n = a.size(), m = b.size(), i = n - 1, j = 0;
        while (i >= 0 and j < m)
        {
            if (a[i] > b[j])
            {
                int t = a[i];
                a[i] = b[j];
                b[j] = t;
            }
            i--;
            j++;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }
};

int main()
{
    Solution object;
    vector<int> a = {2, 4, 7, 10};
    vector<int> b = {2, 3};
    object.mergeArrays(a, b);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;

    a = {1, 5, 9, 10, 15, 20};
    b = {2, 3, 8, 13};
    object.mergeArrays(a, b);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;

    a = {0, 1};
    b = {2, 3};
    object.mergeArrays(a, b);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}