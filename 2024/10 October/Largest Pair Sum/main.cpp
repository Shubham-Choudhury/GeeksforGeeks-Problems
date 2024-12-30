// Link: https://www.geeksforgeeks.org/problems/pair-sum--120604/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int pairsum(vector<int> &arr)
    {
        int max = arr[0];
        int second_max = arr[1];
        if (second_max > max)
        {
            max = arr[1];
            second_max = arr[0];
        }
        for (int i = 2; i < arr.size(); i++)
        {
            if (arr[i] > max)
            {
                second_max = max;
                max = arr[i];
            }
            else if (arr[i] > second_max)
            {
                second_max = arr[i];
            }
        }
        return max + second_max;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {12, 34, 10, 6, 40};
    cout << obj.pairsum(arr) << endl;

    arr = {10, 20, 30};
    cout << obj.pairsum(arr) << endl;
    return 0;
}