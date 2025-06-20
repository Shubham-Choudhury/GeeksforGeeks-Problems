// Link: https://www.geeksforgeeks.org/problems/police-and-thieves--141631/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int catchThieves(vector<char> &arr, int k)
    {
        int n = arr.size();
        int i = 0, j = 0;
        int count = 0;

        while (i < n && j < n)
        {
            while (i < n && arr[i] != 'P')
                i++;

            while (j < n && arr[j] != 'T')
                j++;

            if (i < n && j < n && abs(i - j) <= k)
            {
                count++;
                i++;
                j++;
            }

            else if (j < n && j < i)
            {
                j++;
            }

            else if (i < n && i < j)
            {
                i++;
            }
        }
        return count;
    }
};

int main()
{
    Solution sol;
    vector<char> arr = {'P', 'T', 'T', 'P', 'T'};
    int k = 1;
    int result = sol.catchThieves(arr, k);
    cout << "Number of thieves caught: " << result << endl;

    arr = {'T', 'T', 'P', 'P', 'T', 'P'};
    k = 2;
    result = sol.catchThieves(arr, k);
    cout << "Number of thieves caught: " << result << endl;

    return 0;
}