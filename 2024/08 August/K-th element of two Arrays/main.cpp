// Link: https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int kthElement(vector<int> &arr1, vector<int> &arr2, int k)
    {
        int m = arr1.size();
        int n = arr2.size();
        int l = m + n;
        vector<int> ans;
        int i = 0;
        int j = 0;
        while (i < m && j < n)
        {
            if (arr1[i] < arr2[j])
            {
                ans.push_back(arr1[i]);
                i++;
            }
            else if (arr1[i] > arr2[j])
            {
                ans.push_back(arr2[j]);
                j++;
            }
            else
            {
                ans.push_back(arr1[i]);
                i++;
            }
        }
        while (i < m)
        {
            ans.push_back(arr1[i]);
            i++;
        }
        while (j < n)
        {
            ans.push_back(arr2[j]);
            j++;
        }
        return ans[k - 1];
    }
};

int main()
{
    Solution obj;
    vector<int> arr1 = {2, 3, 6, 7, 9};
    vector<int> arr2 = {1, 4, 8, 10};
    int k = 5;
    cout << obj.kthElement(arr1, arr2, k) << endl;

    arr1 = {100, 112, 256, 349, 770};
    arr2 = {72, 86, 113, 119, 265, 445, 892};
    k = 7;
    cout << obj.kthElement(arr1, arr2, k) << endl;
    return 0;
}