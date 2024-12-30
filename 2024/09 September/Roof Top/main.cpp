// Link: https://www.geeksforgeeks.org/problems/roof-top-1587115621/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxStep(vector<int> &arr)
    {
        int n = arr.size();
        int max_steps = 0;
        int currentsteps = 0;

        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i + 1] > arr[i])
            {
                currentsteps++;
            }
            else
            {
                currentsteps = 0;
            }
            max_steps = max(currentsteps, max_steps);
        }
        return max_steps;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 2, 2, 3, 2};
    cout << obj.maxStep(arr) << endl;

    arr = {1, 2, 3, 4};
    cout << obj.maxStep(arr) << endl;
    return 0;
}