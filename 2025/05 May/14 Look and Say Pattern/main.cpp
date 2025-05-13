// Link: https://www.geeksforgeeks.org/problems/decode-the-pattern1138/1

#include <iostream>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";

        string curr = "1";

        for (int i = 2; i <= n; i++)
        {
            string next = "";

            int cnt = 1;

            for (int j = 1; j < curr.length(); j++)
            {
                if (curr[j] == curr[j - 1])
                {
                    cnt++;
                }
                else
                {
                    next += to_string(cnt) + curr[j - 1];
                    cnt = 1;
                }
            }

            next += to_string(cnt) + curr.back();
            curr = next;
        }

        return curr;
    }
};

int main()
{
    Solution sol;
    int n = 5;
    cout << "The " << n << "th term in the Look and Say sequence is: " << sol.countAndSay(n) << endl;

    n = 3;
    cout << "The " << n << "th term in the Look and Say sequence is: " << sol.countAndSay(n) << endl;
    return 0;
}