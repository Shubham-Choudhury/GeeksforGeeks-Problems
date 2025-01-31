// Link: https://www.geeksforgeeks.org/problems/word-search/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool help(vector<vector<char>> &mat, string word, int i, int j, int index)
    {
        if (index == word.length())
            return true;
        if (i < 0 or j < 0 or i == mat.size() or j == mat[0].size() or mat[i][j] != word[index])
            return false;
        mat[i][j] = '-';
        index++;
        bool a = help(mat, word, i + 1, j, index) || help(mat, word, i - 1, j, index) || help(mat, word, i, j + 1, index) || help(mat, word, i, j - 1, index);
        mat[i][j] = word[index - 1];
        return a;
    }

    bool isWordExist(vector<vector<char>> &mat, string word)
    {
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == word[0])
                {
                    bool a = help(mat, word, i, j, 0);
                    if (a)
                        return a;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution object;
    vector<vector<char>> mat = {{'T', 'E', 'E'}, {'S', 'G', 'K'}, {'T', 'E', 'L'}};
    string word = "GEEK";
    cout << boolalpha << object.isWordExist(mat, word) << endl;

    mat = {{'T', 'E', 'U'}, {'S', 'G', 'K'}, {'T', 'E', 'L'}};
    word = "GEEK";
    cout << boolalpha << object.isWordExist(mat, word) << endl;

    mat = {{'A', 'B', 'A'}, {'B', 'A', 'B'}};
    word = "AB";
    cout << boolalpha << object.isWordExist(mat, word) << endl;
    return 0;
}