// Link: https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void segregate0and1(vector<int> &arr)
    {
        int i = 0;
        int j = arr.size() - 1;
        while (i < j)
        {
            if (arr[i] == 1)
            {
                swap(arr[i], arr[j]);

                j--;
            }
            else
            {
                i++;
            }
        }
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {0, 0, 1, 1, 0};
    obj.segregate0and1(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = {1, 1, 1, 1};
    obj.segregate0and1(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}