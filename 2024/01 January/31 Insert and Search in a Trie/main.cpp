// Link: https://www.geeksforgeeks.org/problems/trie-insert-and-search0651/1

#include <bits/stdc++.h>
using namespace std;
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = NULL;
    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    if (pNode)
    {
        int i;
        pNode->isLeaf = false;
        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }
    return pNode;
}

class Solution
{
public:
    // Function to insert string into TRIE.
    void insert(struct TrieNode *root, string key)
    {
        // code here
        TrieNode *p = root;
        for (int i = 0; i < key.length(); i++)
        {
            if (!p->children[key[i] - 'a'])
                p->children[key[i] - 'a'] = getNode();
            p = p->children[key[i] - 'a'];
        }
        p->isLeaf = true;
    }

    // Function to use TRIE data structure and search the given string.
    bool search(struct TrieNode *root, string key)
    {
        // code here
        TrieNode *p = root;
        for (int i = 0; i < key.length(); i++)
        {
            if (!p || !p->children[key[i] - 'a'])
                return false;
            p = p->children[key[i] - 'a'];
        }
        if (p && p->isLeaf)
            return true;
        return false;
    }
};

int main()
{
    Solution obj;
    string lst[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    int n = sizeof(lst) / sizeof(lst[0]);
    struct TrieNode *root = getNode();
    for (int i = 0; i < n; i++)
        obj.insert(root, lst[i]);
    cout << obj.search(root, "the") << endl;
    cout << obj.search(root, "these") << endl;
    return 0;
}