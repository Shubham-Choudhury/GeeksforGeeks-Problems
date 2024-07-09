// Link: https://www.geeksforgeeks.org/problems/three-sum-closest/1

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int threeSumClosest(std::vector<int> &arr, int target)
    {
        sort(arr.begin(), arr.end());

        int prevDiff = INT_MAX;
        int closestSum = INT_MIN;

        for (int i = 0; i < arr.size() - 2; i++)
        {
            int start = i + 1;
            int end = arr.size() - 1;

            while (start < end)
            {
                int sum = arr[i] + arr[start] + arr[end];

                if (sum == target)
                    return sum;

                int currentDiff = abs(sum - target);

                if (currentDiff < prevDiff || (currentDiff == prevDiff && sum > closestSum))
                {
                    prevDiff = currentDiff;
                    closestSum = sum;
                }

                if (sum < target)
                {
                    start++;
                }
                else
                {
                    end--;
                }
            }
        }
        return closestSum;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {-7, 9, 8, 3, 1, 1};
    int target = 2;
    cout << obj.threeSumClosest(arr, target) << endl;

    arr = {5, 2, 7, 5};
    target = 13;
    cout << obj.threeSumClosest(arr, target) << endl;

    return 0;
}