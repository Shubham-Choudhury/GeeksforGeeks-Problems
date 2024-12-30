// Link: https://www.geeksforgeeks.org/problems/sum-of-middle-elements-of-two-sorted-arrays2305/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2)
    {
        int n = arr1.size();
        int i = 0;
        int j = 0;
        int ct = 1;
        while (i < n && j < n && ct <= n)
        {
            if (arr1[i] <= arr2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
            ct++;
        }
        int rt = min(arr1[min(n - 1, i)], arr2[min(n - 1, j)]);
        int lf = max(arr1[max(i - 1, 0)], arr2[max(j - 1, 0)]);
        return (lf + rt);
    }
};

int main()
{
    Solution obj;
    vector<int> arr1 = {1, 2, 4, 6, 10};
    vector<int> arr2 = {4, 5, 6, 9, 12};
    cout << obj.SumofMiddleElements(arr1, arr2) << endl;

    arr1 = {1, 12, 15, 26, 38};
    arr2 = {2, 13, 17, 30, 45};
    cout << obj.SumofMiddleElements(arr1, arr2) << endl;
    return 0;
}