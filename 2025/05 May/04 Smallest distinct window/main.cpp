// Link: https://www.geeksforgeeks.org/problems/smallest-distant-window3132/1

#include <iostream>
#include <unordered_set>
#include <map>
using namespace std;

class Solution
{
public:
    int findSubString(string &str)
    {
        unordered_set<char> st;
        for (auto &i : str)
            st.insert(i);
        int count = st.size();
        map<int, int> mp;
        int n = str.length();
        int ans = n;
        int i = 0, j = 0;
        while (j < n)
        {
            mp[str[j]]++;
            while (mp.size() == count)
            {
                ans = min(ans, j - i + 1);
                mp[str[i]]--;
                if (mp[str[i]] == 0)
                    mp.erase(str[i]);
                i++;
            }
            j++;
        }
        while (mp.size() == count)
        {
            ans = min(ans, j - i + 1);
            mp[str[i]]--;
            if (mp[str[i]] == 0)
                mp.erase(str[i]);
            i++;
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    string str = "aabcbcdbca";
    cout << "The length of the smallest distinct window is: " << obj.findSubString(str) << endl;

    str = "aaab";
    cout << "The length of the smallest distinct window is: " << obj.findSubString(str) << endl;

    str = "geeksforgeeks";
    cout << "The length of the smallest distinct window is: " << obj.findSubString(str) << endl;
    return 0;
}