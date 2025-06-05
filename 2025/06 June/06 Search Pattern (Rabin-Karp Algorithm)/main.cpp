// Link: https://www.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> search(string &pat, string &txt)
    {
        int d = 256;
        int q = 101;
        int m = pat.length();
        int n = txt.length();
        int ph = 0;
        int th = 0;
        int h = 1;

        vector<int> res;

        for (int i = 0; i < m - 1; i++)
            h = (h * d) % q;

        for (int i = 0; i < m; i++)
        {
            ph = (d * ph + pat[i]) % q;
            th = (d * th + txt[i]) % q;
        }

        for (int i = 0; i <= n - m; i++)
        {
            if (ph == th)
            {
                bool ok = true;
                for (int j = 0; j < m; j++)
                {
                    if (txt[i + j] != pat[j])
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                    res.push_back(i + 1);
            }

            if (i < n - m)
            {
                th = (d * (th - txt[i] * h) + txt[i + m]) % q;
                if (th < 0)
                    th += q;
            }
        }

        return res;
    }
};

int main()
{
    Solution obj;
    string text = "birthdayboy", pattern = "birth";
    vector<int> result = obj.search(pattern, text);
    if (result.empty())
    {
        cout << "Pattern not found" << endl;
    }
    else
    {
        cout << "Pattern found at indices: ";
        for (int index : result)
        {
            cout << index << " ";
        }
        cout << endl;
    }

    text = "geeksforgeeks", pattern = "geek";
    result = obj.search(pattern, text);
    if (result.empty())
    {
        cout << "Pattern not found" << endl;
    }
    else
    {
        cout << "Pattern found at indices: ";
        for (int index : result)
        {
            cout << index << " ";
        }
        cout << endl;
    }

    return 0;
}