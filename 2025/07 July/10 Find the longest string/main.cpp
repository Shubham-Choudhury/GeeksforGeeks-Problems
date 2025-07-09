// Link: https://www.geeksforgeeks.org/problems/find-the-longest-string--170645/1

#include <iostream>
#include <vector>
using namespace std;

struct TrieNode
{
    TrieNode *children[26];
    bool isEnd;

    TrieNode()
    {
        isEnd = false;
        fill(begin(children), end(children), nullptr);
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie() { root = new TrieNode(); }

    void insert(const string &word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            int idx = ch - 'a';
            if (!node->children[idx])
            {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool allPrefixesExist(const string &word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            int idx = ch - 'a';
            node = node->children[idx];

            if (!node || !node->isEnd)
            {
                return false;
            }
        }
        return true;
    }
};

class Solution
{
public:
    string longestString(vector<string> &arr)
    {
        Trie trie;
        for (string &word : arr)
        {
            trie.insert(word);
        }

        string result = "";

        for (string &word : arr)
        {
            if (trie.allPrefixesExist(word))
            {
                if (word.length() > result.length() ||
                    (word.length() == result.length() && word < result))
                {
                    result = word;
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<string> arr = {"p", "pr", "pro", "probl", "problem", "pros", "process", "processor"};
    string result = sol.longestString(arr);
    cout << "Longest string: " << result << endl;

    arr = {"ab", "a", "abc", "abd"};
    result = sol.longestString(arr);
    cout << "Longest string: " << result << endl;
    return 0;
}