// Link: https://www.geeksforgeeks.org/problems/count-numbers-containing-43022/1

#include <iostream>
using namespace std;

class Solution
{
public:
    int countNumberswith4(int n)
    {
        int count = 0;
        for (int i = 4; i <= n; i++)
        {
            if (hasDigit4(i))
            {
                count++;
            }
        }
        return count;
    }

private:
    bool hasDigit4(int x)
    {
        while (x > 0)
        {
            if (x % 10 == 4)
            {
                return true;
            }
            x /= 10;
        }
        return false;
    }
};

int main()
{
    Solution obj;
    int n = 9;
    cout << obj.countNumberswith4(n) << endl;
    n = 14;
    cout << obj.countNumberswith4(n) << endl;
    return 0;
}
