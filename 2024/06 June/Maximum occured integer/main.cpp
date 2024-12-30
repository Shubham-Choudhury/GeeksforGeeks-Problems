// Link: https://www.geeksforgeeks.org/problems/maximum-occured-integer4602/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxOccured(int n, int l[], int r[], int maxx)
    {
        vector<int> diff(maxx + 2, 0);

        for (int i = 0; i < n; i++)
        {
            diff[l[i]]++;
            diff[r[i] + 1]--;
        }

        int max_freq = 0;
        int result = 0;
        int curr_freq = 0;
        for (int i = 0; i <= maxx; i++)
        {
            curr_freq += diff[i];
            if (curr_freq > max_freq)
            {
                max_freq = curr_freq;
                result = i;
            }
        }

        return result;
    }
};

int main()
{
    Solution obj;

    int l1[] = {1, 4, 3, 1};
    int r1[] = {15, 8, 5, 4};
    int maxx = 15;
    int n = sizeof(l1) / sizeof(int);
    cout << obj.maxOccured(n, l1, r1, maxx) << endl;

    int l2[] = {1, 5, 9, 13, 21};
    int r2[] = {15, 8, 12, 20, 30};
    maxx = 30;
    n = sizeof(l2) / sizeof(int);
    cout << obj.maxOccured(n, l2, r2, maxx) << endl;

    return 0;
}
