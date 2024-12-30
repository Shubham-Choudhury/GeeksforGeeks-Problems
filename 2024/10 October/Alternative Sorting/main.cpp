// Link: https://www.geeksforgeeks.org/problems/alternative-sorting1311/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{

public:
    vector<int> alternateSort(vector<int> &arr)
    {
        vector<int> distinct;
        sort(arr.begin(), arr.end());

        int len = arr.size();
        int i = 0, j = len - 1;
        while (i < j)
        {
            distinct.push_back(arr[j]);
            distinct.push_back(arr[i]);
            i++;
            j--;
        }
        if (i == j)
            distinct.push_back(arr[i]);
        return distinct;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {7, 1, 2, 3, 4, 5, 6};
    vector<int> result = obj.alternateSort(arr);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    arr = {1, 6, 9, 4, 3, 7, 8, 2};
    result = obj.alternateSort(arr);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}