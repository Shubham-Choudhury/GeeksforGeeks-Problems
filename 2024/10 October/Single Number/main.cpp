// Link: https://www.geeksforgeeks.org/problems/single-number1014/1

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int getSingle(vector<int> &arr)
    {
        unordered_map<int, int> f;
        for (auto i : arr)
            f[i]++;
        for (auto i : f)
            if (i.second % 2 == 1)
                return i.first;
        return -1;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 1, 2, 2, 2};
    cout << obj.getSingle(arr) << endl;

    arr = {8, 8, 7, 7, 6, 6, 1};
    cout << obj.getSingle(arr) << endl;
    return 0;
}