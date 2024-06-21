// Link: https://www.geeksforgeeks.org/problems/compare-two-fractions4438/1

#include <iostream>
using namespace std;

class Solution
{
public:
    string compareFrac(string str)
    {
        size_t commaPos = str.find(", ");
        string frac1 = str.substr(0, commaPos);
        string frac2 = str.substr(commaPos + 2);

        size_t slashPos1 = frac1.find('/');
        int a = stoi(frac1.substr(0, slashPos1));
        int b = stoi(frac1.substr(slashPos1 + 1));

        size_t slashPos2 = frac2.find('/');
        int c = stoi(frac2.substr(0, slashPos2));
        int d = stoi(frac2.substr(slashPos2 + 1));

        if (a * d > b * c)
        {
            return to_string(a) + "/" + to_string(b);
        }
        else if (a * d < b * c)
        {
            return to_string(c) + "/" + to_string(d);
        }
        else
        {
            return "equal";
        }
    }
};

int main()
{
    Solution obj;
    string s = "5/6, 11/45";
    cout << obj.compareFrac(s) << endl;

    s = "8/1, 8/1";
    cout << obj.compareFrac(s) << endl;

    s = "10/17, 9/10";
    cout << obj.compareFrac(s) << endl;

    return 0;
}