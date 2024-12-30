// Link: https://www.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void rearrange(vector<int> &arr)
    {
        vector<int> p;
        vector<int> n;
        for (int x : arr)
        {
            if (x < 0)
            {
                n.push_back(x);
            }
            else
            {
                p.push_back(x);
            }
        }
        int i = 0;

        while (i < p.size() && i < n.size())
        {
            arr[2 * i] = p[i];
            arr[2 * i + 1] = n[i];
            i++;
        }
        arr.resize(2 * i);
        arr.insert(arr.end(), p.begin() + i, p.end());
        arr.insert(arr.end(), n.begin() + i, n.end());
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {9, 4, -2, -1, 5, 0, -5, -3, 2};
    obj.rearrange(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    arr = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    obj.rearrange(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}