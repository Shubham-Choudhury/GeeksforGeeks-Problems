// Link: https://www.geeksforgeeks.org/problems/find-unique-number/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findUnique(vector<int> &arr)
    {

        int res = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            res ^= arr[i];
        }
        return res;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 2, 1, 5, 5};
    cout << "The unique number is: " << obj.findUnique(arr) << endl;

    arr = {2, 30, 2, 15, 20, 30, 15};
    cout << "The unique number is: " << obj.findUnique(arr) << endl;

    return 0;
}