// Link: https://www.geeksforgeeks.org/problems/max-sum-path-in-two-arrays/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2)
    {
        int sum1 = 0;
        int sum2 = 0;
        int n1 = arr1.size();
        int n2 = arr2.size();
        int i = n1 - 1, j = n2 - 1;
        while (i >= 0 && j >= 0)
        {
            if (arr1[i] > arr2[j])
            {
                sum1 += arr1[i];
                i--;
            }
            if (arr1[i] < arr2[j])
            {
                sum2 += arr2[j];
                j--;
            }
            if (arr1[i] == arr2[j])
            {
                if (sum1 > sum2)
                {
                    sum1 += arr1[i];
                    sum2 = sum1;
                }
                else
                {
                    sum2 += arr2[j];
                    sum1 = sum2;
                }
                i--, j--;
            }
        }
        while (i >= 0)
        {
            sum1 += arr1[i];
            i--;
        }
        while (j >= 0)
        {
            sum2 += arr2[j];
            j--;
        }
        return max(sum1, sum2);
    }
};

int main()
{
    Solution obj;
    vector<int> arr1 = {2, 3, 7, 10, 12};
    vector<int> arr2 = {1, 5, 7, 8};
    cout << obj.maxPathSum(arr1, arr2) << endl;

    arr1 = {1, 2, 3};
    arr2 = {3, 4, 5};
    cout << obj.maxPathSum(arr1, arr2) << endl;
    return 0;
}