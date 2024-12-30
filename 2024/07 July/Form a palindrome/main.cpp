// Link: https://www.geeksforgeeks.org/problems/form-a-palindrome1455/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countMin(string str)
    {
        int i;
        int n = str.length();
        vector<int> palin[n];
        for (i = 0; i < n; i++)
        {
            palin[i].resize(n, 0);
        }
        for (int gap = 1; gap < n; gap++)
        {
            for (int j = 0, i = gap; i < n; j++, i++)
            {
                if (str[i] == str[j])
                    palin[j][i] = palin[j + 1][i - 1];
                else
                    palin[j][i] = min(palin[j + 1][i], palin[j][i - 1]) + 1;
            }
        }
        return palin[0][n - 1];
    }
};

int main()
{
    Solution obj;
    string str = "abcd";
    cout << obj.countMin(str) << endl;

    str = "aa";
    cout << obj.countMin(str) << endl;

    return 0;
}