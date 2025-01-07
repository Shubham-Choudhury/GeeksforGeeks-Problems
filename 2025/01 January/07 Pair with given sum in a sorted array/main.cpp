// Link: https://www.geeksforgeeks.org/problems/pair-with-given-sum-in-a-sorted-array4940/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countPairs(vector<int> &arr, int target)
    {
        int n = arr.size();
        int ans = 0;
        int i = 0, j = n - 1;
        while (i < j)
        {
            if (arr[i] + arr[j] == target)
            {
                int ele1 = arr[i], c1 = 0, ele2 = arr[j], c2 = 0;
                while (i <= j && arr[i] == ele1)
                {
                    c1++;
                    i++;
                }
                while (i <= j && arr[j] == ele2)
                {
                    c2++;
                    j--;
                }
                if (ele1 == ele2)
                    ans += (c1 * (c1 - 1)) / 2;
                else
                    ans += (c1 * c2);
            }
            else if (arr[i] + arr[j] < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return ans;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {-1, 1, 5, 5, 7};
    int target = 6;
    cout << object.countPairs(arr, target) << endl;

    arr = {1, 1, 1, 1};
    target = 2;
    cout << object.countPairs(arr, target) << endl;

    arr = {-1, 10, 10, 12, 15};
    target = 125;
    cout << object.countPairs(arr, target) << endl;

    return 0;
}