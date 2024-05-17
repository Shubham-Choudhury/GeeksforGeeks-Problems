// Link: https://www.geeksforgeeks.org/problems/find-the-highest-number2259/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &a)
    {

        int n = a.size();
        int low = 0, high = a.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int next = (mid + 1) % n;
            int pre = (mid + n - 1) % n;
            if (a[mid] > a[next] && a[mid] > a[pre])
            {
                return a[mid];
            }
            else if (a[mid] > a[mid - 1])
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
    }
};

int main()
{
    Solution obj;
    vector<int> a = {1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};
    cout << obj.findPeakElement(a) << endl;

    a = {1, 2, 3, 4, 5};
    cout << obj.findPeakElement(a) << endl;

    return 0;
}
