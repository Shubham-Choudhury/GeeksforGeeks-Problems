// Link: https://www.geeksforgeeks.org/problems/count-pairs-in-an-array4145/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPairs(int arr[], int n)
    {
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back(i * arr[i]);
        }
        vector<int> temp = v;
        sort(temp.begin(), temp.end());

        int ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int x = upper_bound(temp.begin(), temp.end(), v[i]) - temp.begin();
            int y = lower_bound(temp.begin(), temp.end(), v[i]) - temp.begin();

            ans = ans + (temp.size() - x);

            temp.erase(temp.begin() + y);
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    int arr1[] = {8, 4, 2, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << obj.countPairs(arr1, n1) << endl;
    int arr2[] = {5, 0, 10, 2, 4, 1, 6};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << obj.countPairs(arr2, n2) << endl;
    return 0;
}