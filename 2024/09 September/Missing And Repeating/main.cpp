// Link: https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        unordered_map<int, int> mp;
        int twice;
        for (auto i : arr)
        {
            mp[i]++;
            if (mp[i] == 2)
            {
                twice = i;
                break;
            }
        }
        int sum = 0;
        for (auto i : arr)
            sum += i;
        int sumN = (arr.size() * (arr.size() + 1)) / 2;
        vector<int> vt;
        if (sum > sumN)
        {
            int diff = sum - sumN;
            int B = abs(twice - diff);
            vt.push_back(twice);
            vt.push_back(B);
        }
        else
        {
            int diff = sumN - sum;
            int B = twice + diff;
            vt.push_back(twice);
            vt.push_back(B);
        }
        return vt;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {2, 2};
    vector<int> ans = obj.findTwoElement(arr);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;

    arr = {1, 3, 3};
    ans = obj.findTwoElement(arr);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}