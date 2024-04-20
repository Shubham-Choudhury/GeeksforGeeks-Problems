// Link: https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> ans;
        int i = 0, j = 0;
        bool flag;
        while (i < n && j < m)
        {
            if (i > 0 && arr1[i] == arr1[i - 1])
            {
                i++;
                flag = 1;
            }
            if (j > 0 && arr2[j] == arr2[j - 1])
            {
                j++;
                flag = 1;
            }

            if (flag)
            {
                flag = 0;
                continue;
            }
            if (arr1[i] < arr2[j])
            {
                ans.push_back(arr1[i++]);
            }
            else if (arr2[j] < arr1[i])
            {
                ans.push_back(arr2[j++]);
            }
            else if (arr1[i] == arr2[j])
            {
                ans.push_back(arr1[i]);
                i++;
                j++;
            }
        }

        while (i < n)
        {
            if (i == 0)
                ans.push_back(arr1[i]);
            if (i > 0 && arr1[i] != arr1[i - 1])
            {
                ans.push_back(arr1[i]);
            }
            i++;
        }
        while (j < m)
        {
            if (j == 0)
                ans.push_back(arr2[j]);

            if (j > 0 && arr2[j] != arr2[j - 1])
            {
                ans.push_back(arr2[j]);
            }
            j++;
        }

        return ans;
    }
};

int main()
{
    Solution obj;
    int arr11[] = {1, 2, 3, 4, 5};
    int arr12[] = {1, 2, 3, 6, 7};
    int n = sizeof(arr11) / sizeof(arr11[0]);
    int m = sizeof(arr12) / sizeof(arr12[0]);
    vector<int> ans = obj.findUnion(arr11, arr12, n, m);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    int arr21[] = {2, 2, 3, 4, 5};
    int arr22[] = {1, 1, 2, 3, 4};
    n = sizeof(arr21) / sizeof(arr21[0]);
    m = sizeof(arr22) / sizeof(arr22[0]);
    ans = obj.findUnion(arr21, arr22, n, m);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    int arr31[] = {1, 1, 1, 1, 1};
    int arr32[] = {2, 2, 2, 2, 2};
    n = sizeof(arr31) / sizeof(arr31[0]);
    m = sizeof(arr32) / sizeof(arr32[0]);
    ans = obj.findUnion(arr31, arr32, n, m);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}