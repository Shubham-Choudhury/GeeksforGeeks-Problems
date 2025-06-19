// Link: https://www.geeksforgeeks.org/problems/group-balls-by-sequence/1

#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool validgroup(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == -1)
                continue;

            int count = 0;

            int curr = arr[i];

            for (int j = i; j < arr.size(); j++)
            {
                if (arr[j] == curr)
                {
                    count++;
                    curr++;
                    arr[j] = -1;
                }
                if (count == k)
                    break;
            }

            if (count != k)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {10, 1, 2, 11};
    int k = 3;
    bool result = sol.validgroup(arr, k);
    cout << boolalpha << result << endl;

    arr = {10, 1, 2, 11};
    k = 2;
    result = sol.validgroup(arr, k);
    cout << boolalpha << result << endl;

    arr = {7, 8, 9, 10, 11};
    k = 2;
    result = sol.validgroup(arr, k);
    cout << boolalpha << result << endl;

    return 0;
}