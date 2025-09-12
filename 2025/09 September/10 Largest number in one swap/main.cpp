// Link: https://www.geeksforgeeks.org/problems/largest-number-in-one-swap1520/1

#include <iostream>
using namespace std;

class Solution
{
public:
    string largestSwap(string &s)
    {
        char maxDigit = '0';
        int maxIndx = -1;
        int l = -1, r = -1;

        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] > maxDigit)
            {
                maxDigit = s[i];
                maxIndx = i;
            }

            else if (s[i] < maxDigit)
            {
                l = i;
                r = maxIndx;
            }
        }

        if (l == -1)
            return s;

        swap(s[l], s[r]);

        return s;
    }
};

int main()
{
    Solution sol;
    string s = "768";
    cout << "Input: " << s;
    string result = sol.largestSwap(s);
    cout << ", Largest number after one swap: " << result << endl;

    s = "333";
    cout << "Input: " << s;
    result = sol.largestSwap(s);
    cout << ", Largest number after one swap: " << result << endl;
    return 0;
}