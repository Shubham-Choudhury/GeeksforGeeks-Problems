// Link: https://www.geeksforgeeks.org/problems/majority-element-1587115620/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &arr)
    {
        int count = 0, candidate = 0;
        for (int num : arr)
        {
            if (count == 0)
                candidate = num;
            count += (num == candidate) ? 1 : -1;
        }
        count = 0;
        for (int num : arr)
        {
            if (num == candidate)
                count++;
        }
        return count > arr.size() / 2 ? candidate : -1;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 1, 2, 1, 3, 5, 1};
    int result = obj.majorityElement(arr);
    cout << "Majority Element: " << result << endl;

    arr = {7};
    result = obj.majorityElement(arr);
    cout << "Majority Element: " << result << endl;

    arr = {2, 13};
    result = obj.majorityElement(arr);
    cout << "Majority Element: " << result << endl;
    return 0;
}