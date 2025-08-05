// Link: https://www.geeksforgeeks.org/problems/string-palindromic-ignoring-spaces4723/1

#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalinSent(string &s)
    {
        int i = 0, j = s.length() - 1;

        while (i < j)
        {
            if (!isalnum(s[i]))
                i++;
            else if (!isalnum(s[j]))
                j--;
            else if (tolower(s[i]) == tolower(s[j]))
                i++, j--;
            else
                return false;
        }

        return true;
    }
};

int main()
{
    Solution sol;
    string s = "Too hot to hoot";
    bool result = sol.isPalinSent(s);
    cout << "Is the sentence '" << s << "' a palindrome? " << boolalpha << result << endl;

    s = "Abc 012..## 10cbA";
    result = sol.isPalinSent(s);
    cout << "Is the sentence '" << s << "' a palindrome? " << boolalpha << result << endl;

    s = "ABC $. def01ASDF";
    result = sol.isPalinSent(s);
    cout << "Is the sentence '" << s << "' a palindrome? " << boolalpha << result << endl;

    return 0;
}