// Link: https://www.geeksforgeeks.org/problems/armstrong-numbers2727/1

#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    string armstrongNumber(int n)
    {
        int d1 = n / 100;
        int d2 = (n / 10) % 10;
        int d3 = n % 10;

        int total = pow(d1, 3) + pow(d2, 3) + pow(d3, 3);

        if (total == n)
        {
            return "Yes";
        }
        else
        {
            return "No";
        }
    }
};

int main()
{
    Solution obj;
    cout << obj.armstrongNumber(153) << endl;
    cout << obj.armstrongNumber(370) << endl;
    cout << obj.armstrongNumber(372) << endl;
    return 0;
}
