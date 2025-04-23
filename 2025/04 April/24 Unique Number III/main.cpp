// Link: https://www.geeksforgeeks.org/problems/find-element-occuring-once-when-all-other-are-present-thrice/1

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    int getSingle(vector<int> &arr)
    {
        map<int, int> freq;
        for (auto it : arr)
            freq[it]++;

        vector<int> ans;
        for (auto it : freq)
        {
            if (it.second == 1)
                return it.first;
        }
        return -1;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 10, 1, 1};
    cout << obj.getSingle(arr) << endl;

    arr = {3, 2, 1, 34, 34, 1, 2, 34, 2, 1};
    cout << obj.getSingle(arr) << endl;
    return 0;
}