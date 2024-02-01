// Link: https://www.geeksforgeeks.org/problems/pangram-checking-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkPangram(string s)
    {
        set<char> st;
        for (auto e : s)
        {
            if (e >= 'a' && e <= 'z')
            {
                st.insert(e);
            }
            else if (e >= 'A' && e <= 'Z')
            {
                st.insert(e + 32);
            }
        }
        return (st.size() == 26);
    }
};

int main()
{
    Solution obj;
    string s = "Bawds jog, flick quartz, vex nymph";
    cout << obj.checkPangram(s) << endl;
    s = "sdfs";
    cout << obj.checkPangram(s) << endl;
    return 0;
}