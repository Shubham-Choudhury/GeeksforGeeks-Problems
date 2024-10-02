// Link: https://www.geeksforgeeks.org/problems/majority-vote/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findMajority(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return {-1};

        int candidate1 = -1, candidate2 = -1, count1 = 0, count2 = 0;

        for (int num : nums)
        {
            if (num == candidate1)
            {
                count1++;
            }
            else if (num == candidate2)
            {
                count2++;
            }
            else if (count1 == 0)
            {
                candidate1 = num;
                count1 = 1;
            }
            else if (count2 == 0)
            {
                candidate2 = num;
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;

        for (int num : nums)
        {
            if (num == candidate1)
                count1++;
            else if (num == candidate2)
                count2++;
        }

        vector<int> result;
        if (count1 > n / 3)
            result.push_back(candidate1);
        if (count2 > n / 3)
            result.push_back(candidate2);

        return result.empty() ? vector<int>{-1} : result;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6};
    vector<int> result = obj.findMajority(nums);
    for (int i : result)
        cout << i << " ";
    cout << endl;
    nums = {1, 2, 3, 4, 5};
    result = obj.findMajority(nums);
    for (int i : result)
        cout << i << " ";
    cout << endl;
    return 0;
}