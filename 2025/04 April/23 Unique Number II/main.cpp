// Link: https://www.geeksforgeeks.org/problems/finding-the-numbers0215/1

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> singleNum(vector<int> &arr)
    {
        map<int, int> mpp;
        for (auto it : arr)
            mpp[it]++;
        vector<int> v;
        for (auto it : mpp)
        {
            if (it.second == 1)
                v.push_back(it.first);
        }
        return v;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 3, 2, 1, 4};
    vector<int> result = sol.singleNum(arr);
    for (int i : result)
        cout << i << " ";
    cout << endl;

    arr = {2, 1, 3, 2};
    result = sol.singleNum(arr);
    for (int i : result)
        cout << i << " ";
    cout << endl;
    arr = {2, 1, 3, 3};
    result = sol.singleNum(arr);
    for (int i : result)
        cout << i << " ";
    cout << endl;
    return 0;
}