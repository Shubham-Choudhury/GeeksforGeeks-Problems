// Link: https://www.geeksforgeeks.org/problems/sub-arrays-with-equal-number-of-occurences3901/1

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int sameOccurrence(vector<int> &arr, int x, int y)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == x)
                arr[i] = 1;
            else if (arr[i] == y)
                arr[i] = -1;
            else
                arr[i] = 0;
        }
        unordered_map<int, int> m;
        int sum = 0;
        int count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum = sum + arr[i];
            if (sum == 0)
            {
                count++;
            }
            if (m.find(sum) != m.end())
            {
                count = count + m[sum];
            }
            m[sum]++;
        }
        return count;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 2, 1};
    int x = 1, y = 2;
    cout << obj.sameOccurrence(arr, x, y) << endl;
    arr = {1, 2, 1};
    x = 4, y = 6;
    cout << obj.sameOccurrence(arr, x, y) << endl;
    return 0;
}