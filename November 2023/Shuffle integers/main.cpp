// Link: https://www.geeksforgeeks.org/problems/shuffle-integers2401/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void shuffleArray(int arr[], int n)
    {
        // Your code goes here
        vector<int> v;
        int i = 0, mid = n / 2;
        while (i < n / 2 && mid < n)
        {
            v.push_back(arr[i]);
            v.push_back(arr[mid]);
            i++, mid++;
        }
        for (int i = 0; i < n; i++)
            arr[i] = v[i];
    }
};

int main()
{
    Solution obj;
    int arr[] = {1, 2, 9, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    obj.shuffleArray(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}