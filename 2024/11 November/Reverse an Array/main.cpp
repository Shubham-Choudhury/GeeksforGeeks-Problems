// Link: https://www.geeksforgeeks.org/problems/reverse-an-array/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void reverseArray(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n / 2; i++)
        {
            int temp = arr[i];
            arr[i] = arr[n - i - 1];
            arr[n - i - 1] = temp;
        }
    }
};

int main()
{
    Solution object;
    vector<int> arr = {1, 4, 3, 2, 6, 5};
    object.reverseArray(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = {4, 5, 2};
    object.reverseArray(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = {1};
    object.reverseArray(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}