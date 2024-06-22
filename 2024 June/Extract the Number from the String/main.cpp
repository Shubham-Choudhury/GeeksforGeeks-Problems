// Link: https://www.geeksforgeeks.org/problems/extract-the-number-from-the-string3428/1

#include <iostream>
using namespace std;

class Solution
{
public:
    long long ExtractNumber(string sentence)
    {

        long long max = -1;
        for (int i = 0; i < sentence.size(); i++)
        {
            bool isNine = false;
            if (sentence[i] >= 48 && sentence[i] <= 57)
            {
                long long num = 0;
                while (sentence[i] >= 48 && sentence[i] <= 57)
                {
                    if (sentence[i] == 57)
                    {
                        isNine = true;
                    }
                    num = num * 10 + (sentence[i] - 48);
                    i++;
                }
                if (!isNine && num > max)
                {
                    max = num;
                }
            }
        }
        return max;
    }
};

int main()
{
    Solution obj;
    string sentence = "This is alpha 5057 and 97";
    cout << obj.ExtractNumber(sentence) << endl;

    sentence = "Another input 9007";
    cout << obj.ExtractNumber(sentence) << endl;
    return 0;
}