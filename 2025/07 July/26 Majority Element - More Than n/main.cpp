// Link: https://www.geeksforgeeks.org/problems/majority-vote/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findMajority(vector<int> &arr)
    {
        int n = arr.size();

        int ele1 = -1, ele2 = -1, cnt1 = 0, cnt2 = 0;

        for (int ele : arr)
        {
            if (ele1 == ele)
            {
                cnt1++;
            }
            else if (ele2 == ele)
            {
                cnt2++;
            }
            else if (cnt1 == 0)
            {
                ele1 = ele;
                cnt1++;
            }
            else if (cnt2 == 0)
            {
                ele2 = ele;
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }

        vector<int> res;
        cnt1 = 0;
        cnt2 = 0;

        for (int ele : arr)
        {
            if (ele1 == ele)
                cnt1++;
            if (ele2 == ele)
                cnt2++;
        }

        if (cnt1 > n / 3)
            res.push_back(ele1);
        if (cnt2 > n / 3 && ele1 != ele2)
            res.push_back(ele2);

        if (res.size() == 2 && res[0] > res[1])
            swap(res[0], res[1]);

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {2, 2, 3, 1, 3, 2, 1, 1};
    vector<int> result = sol.findMajority(arr);
    cout << "Majority elements: ";
    for (int ele : result)
    {
        cout << ele << " ";
    }
    cout << endl;

    arr = {-5, 3, -5};
    result = sol.findMajority(arr);
    cout << "Majority elements: ";
    for (int ele : result)
    {
        cout << ele << " ";
    }
    cout << endl;

    arr = {3, 2, 2, 4, 1, 4};
    result = sol.findMajority(arr);
    cout << "Majority elements: ";
    for (int ele : result)
    {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}