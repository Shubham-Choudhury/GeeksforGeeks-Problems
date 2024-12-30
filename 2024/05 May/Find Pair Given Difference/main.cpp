// Link: https://www.geeksforgeeks.org/problems/find-pair-given-difference1559/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPair(int n, int x, vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            int start = i + 1;
            int end = n - 1;
            int mid;
            int num = arr[i] + x;
            while (start <= end && start < n)
            {
                int mid = (start + end) / 2;
                if (arr[mid] < num)
                {
                    start = mid + 1;
                }
                else if (arr[mid] > num)
                {
                    end = mid - 1;
                }
                else
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }
        if (flag)
            return 1;
        else
            return -1;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {5, 20, 3, 2, 5, 80};
    int n = arr.size();
    int x = 78;
    cout << obj.findPair(n, x, arr) << endl;

    arr = {90, 70, 20, 80, 50};
    n = arr.size();
    x = 45;

    return 0;
}