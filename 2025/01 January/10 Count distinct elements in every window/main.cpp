// Link: https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> countDistinct(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> res;
        unordered_map<int, int> freq;

        for (int i = 0; i < k; i++)
            freq[arr[i]] += 1;

        res.push_back(freq.size());

        for (int i = k; i < n; i++)
        {
            freq[arr[i]] += 1;
            freq[arr[i - k]] -= 1;
            if (freq[arr[i - k]] == 0)
                freq.erase(arr[i - k]);

            res.push_back(freq.size());
        }
        return res;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;
    vector<int> result = object.countDistinct(arr, k);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

    arr = {4, 1, 1};
    k = 2;
    result = object.countDistinct(arr, k);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

    arr = {1, 1, 1, 1, 1};
    k = 3;
    result = object.countDistinct(arr, k);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}