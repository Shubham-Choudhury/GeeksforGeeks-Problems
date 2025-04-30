// Link: https://www.geeksforgeeks.org/problems/pascal-triangle0652/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> nthRowOfPascalTriangle(int n)
    {
        n -= 1;
        vector<int> res;
        int prev = 1;
        res.push_back(prev);

        for (int i = 1; i <= n; ++i)
        {
            int curr = (prev * (n - i + 1)) / i;
            res.push_back(curr);
            prev = curr;
        }

        return res;
    }
};

int main()
{
    Solution obj;
    int n = 4;
    vector<int> result = obj.nthRowOfPascalTriangle(n);
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    n = 5;
    result = obj.nthRowOfPascalTriangle(n);
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    n = 1;
    result = obj.nthRowOfPascalTriangle(n);
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
