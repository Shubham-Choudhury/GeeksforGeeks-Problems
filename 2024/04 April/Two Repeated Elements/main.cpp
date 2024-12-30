// Link: https://www.geeksforgeeks.org/problems/two-repeated-elements-1587115621/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoRepeated(int arr[], int n)
    {
        vector<int> ans;

        for (int i = 0; i < n + 2; i++)
        {
            int index = abs(arr[i]);

            if (arr[index] < 0)
            {
                ans.push_back(index);
            }
            else
                arr[index] = -arr[index];
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    int arr1[] = {1, 2, 1, 3, 4, 3};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    vector<int> ans1 = obj.twoRepeated(arr1, n1);
    for (int i = 0; i < ans1.size(); i++)
        cout << ans1[i] << " ";
    cout << endl;

    int arr2[] = {1, 2, 2, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    vector<int> ans2 = obj.twoRepeated(arr2, n2);
    for (int i = 0; i < ans2.size(); i++)
        cout << ans2[i] << " ";
    cout << endl;
    return 0;
}
