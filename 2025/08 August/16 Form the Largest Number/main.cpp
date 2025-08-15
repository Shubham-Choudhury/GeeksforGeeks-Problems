// Link: https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    static bool myCompare(string &s1, string &s2) { return (s1 + s2) > (s2 + s1); }

    string findLargest(vector<int> &arr)
    {

        vector<string> numbers;
        for (int ele : arr)
        {
            numbers.push_back(to_string(ele));
        }

        sort(numbers.begin(), numbers.end(), myCompare);

        if (numbers[0] == "0")
        {
            return "0";
        }

        string res = "";
        for (string &num : numbers)
        {
            res.append(num);
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {3, 30, 34, 5, 9};
    string result = sol.findLargest(arr);
    cout << "Largest number formed: " << result << endl;

    arr = {54, 546, 548, 60};
    result = sol.findLargest(arr);
    cout << "Largest number formed: " << result << endl;

    arr = {3, 4, 6, 5, 9};
    result = sol.findLargest(arr);
    cout << "Largest number formed: " << result << endl;
    return 0;
}