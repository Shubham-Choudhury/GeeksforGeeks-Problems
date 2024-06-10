// Link: https://www.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1

#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void matchPairs(int n, char nuts[], char bolts[])
    {
        unordered_map<char, int> order = {{'!', 0}, {'#', 1}, {'$', 2}, {'%', 3}, {'&', 4}, {'*', 5}, {'?', 6}, {'@', 7}, {'^', 8}};

        sort(nuts, nuts + n, [&](char a, char b)
             { return order[a] < order[b]; });

        sort(bolts, bolts + n, [&](char a, char b)
             { return order[a] < order[b]; });
    }
};

int main()
{
    Solution obj;

    char nuts1[] = {'@', '%', '$', '#', '^'};
    char bolts1[] = {'%', '@', '#', '$', '^'};
    int n = sizeof(nuts1) / sizeof(char);
    obj.matchPairs(n, nuts1, bolts1);
    cout << "Nuts: ";
    for (char c : nuts1)
    {
        cout << c << " ";
    }
    cout << "\nBolts: ";
    for (char c : bolts1)
    {
        cout << c << " ";
    }
    cout << endl;

    char nuts2[] = {'^', '&', '%', '@', '#', '*', '$', '?', '!'};
    char bolts2[] = {'?', '#', '@', '%', '&', '*', '$', '^', '!'};
    n = sizeof(nuts2) / sizeof(char);
    obj.matchPairs(n, nuts2, bolts2);
    cout << "Nuts: ";
    for (char c : nuts2)
    {
        cout << c << " ";
    }
    cout << "\nBolts: ";
    for (char c : bolts2)
    {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
