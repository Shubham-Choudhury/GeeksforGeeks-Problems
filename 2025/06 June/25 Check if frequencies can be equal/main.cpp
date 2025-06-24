// Link: https://www.geeksforgeeks.org/problems/check-frequencies4211/1

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    bool sameFreq(string &s)
    {
        vector<int> freq(26, 0);

        for (char c : s)
        {
            freq[c - 'a']++;
        }

        int maxFreqValue = INT_MIN;
        int minFreqValue = INT_MAX;
        int maxFreqCounter = 0;
        int minFreqCounter = 0;

        for (int f : freq)
        {

            if (f == 0)
                continue;

            if (f == maxFreqValue)
            {

                maxFreqCounter++;
            }
            if (f == minFreqValue)
            {

                minFreqCounter++;
            }
            if (f > maxFreqValue)
            {

                maxFreqValue = f;
                maxFreqCounter = 1;
            }
            if (f < minFreqValue)
            {

                minFreqValue = f;
                minFreqCounter = 1;
            }
        }

        if ((maxFreqValue - minFreqValue) == 0)
        {
            return true;
        }
        else if ((maxFreqValue - minFreqValue) == 1 &&
                 (maxFreqCounter == 1 ||
                  (minFreqCounter == 1 && minFreqValue == 1)))
        {
            return true;
        }

        return false;
    }
};

int main()
{
    Solution sol;
    string s = "xyyz";
    bool result = sol.sameFreq(s);
    cout << (result ? "Frequencies can be made equal" : "Frequencies cannot be made equal") << endl;

    s = "xyyzz";
    result = sol.sameFreq(s);
    cout << (result ? "Frequencies can be made equal" : "Frequencies cannot be made equal") << endl;

    s = "xxxxyyzz";
    result = sol.sameFreq(s);
    cout << (result ? "Frequencies can be made equal" : "Frequencies cannot be made equal") << endl;

    return 0;
}