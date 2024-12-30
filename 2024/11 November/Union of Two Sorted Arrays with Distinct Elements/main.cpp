// Link: https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-with-distinct-elements/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b)
    {
        vector<int> result;
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (a[i] < b[j])
            {
                result.push_back(a[i]);
                i++;
            }
            else if (a[i] > b[j])
            {
                result.push_back(b[j]);
                j++;
            }
            else
            {
                result.push_back(a[i]);
                i++;
                j++;
            }
        }
        while (i < n)
        {
            result.push_back(a[i]);
            i++;
        }
        while (j < m)
        {
            result.push_back(b[j]);
            j++;
        }
        return result;
    }
};

int main()
{
    Solution object;
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {1, 2, 3, 6, 7};
    vector<int> result = object.findUnion(a, b);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    a = {2, 3, 4, 5};
    b = {1, 2, 3, 4};
    result = object.findUnion(a, b);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    a = {1};
    b = {2};
    result = object.findUnion(a, b);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}