// Link: https://www.geeksforgeeks.org/problems/triplet-family/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool findTriplet(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        for (int i = 2; i < arr.size(); i++)
        {
            int it = 0;
            int jt = i - 1;
            while (it < jt)
            {
                if (arr[it] + arr[jt] == arr[i])
                {
                    return true;
                }
                else if (arr[it] + arr[jt] > arr[i])
                {
                    jt--;
                }
                else
                {
                    it++;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << obj.findTriplet(arr) << endl;

    arr = {5, 3, 4};
    cout << obj.findTriplet(arr) << endl;
    return 0;
}