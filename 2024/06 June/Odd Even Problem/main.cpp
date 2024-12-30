// Link: https://www.geeksforgeeks.org/problems/help-nobita0532/1

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    string oddEven(string s)
    {
        unordered_map<char, int> d;
        for (char i : s)
        {
            d[i]++;
        }
        int ans = 0;
        for (char i : unordered_set<char>(s.begin(), s.end()))
        {
            if ((static_cast<int>(i) - 96) % 2 == d[i] % 2)
            {
                ans++;
            }
        }
        if (ans % 2 == 0)
        {
            return "EVEN";
        }
        return "ODD";
    }
};

int main()
{
    Solution obj;
    cout << obj.oddEven("abbbcc") << endl;
    cout << obj.oddEven("nobitaa") << endl;
    return 0;
}
