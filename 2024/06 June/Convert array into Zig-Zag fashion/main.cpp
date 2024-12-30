// Link: https://www.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion1638/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void zigZag(int n, vector<int> &arr)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (i % 2 == 0)
            {
                if (arr[i] > arr[i + 1])
                {
                    swap(arr[i], arr[i + 1]);
                }
            }
            else
            {
                if (arr[i] < arr[i + 1])
                {
                    swap(arr[i], arr[i + 1]);
                }
            }
        }
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {4, 3, 7, 8, 6, 2, 1};
    int n = arr.size();
    obj.zigZag(n, arr);
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    arr = {1, 4, 3, 2};
    n = arr.size();
    obj.zigZag(n, arr);
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
