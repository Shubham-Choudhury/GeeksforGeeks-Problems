// Link: https://www.geeksforgeeks.org/problems/validate-an-ip-address-1587115621/1

#include <iostream>
using namespace std;

class Solution
{
public:
    int isValid(string str)
    {
        int cnt = 0;
        string word = "";
        int n = str.size();
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '.')
            {
                int num = stoi(word);
                if (num >= 0 and num <= 255)
                {
                    cnt++;
                    word = "";
                }
            }
            else
                word += str[i];
        }
        if (cnt == 3)
        {
            int num1 = stoi(word);
            if (num1 >= 0 and num1 <= 255)
                cnt++;
        }
        if (cnt == 4)
            return 1;
        else
            return 0;
    }
};

int main()
{
    Solution obj;
    string str = "222.111.111.111";
    cout << obj.isValid(str) << endl;

    str = "5555..555";
    cout << obj.isValid(str) << endl;
    return 0;
}