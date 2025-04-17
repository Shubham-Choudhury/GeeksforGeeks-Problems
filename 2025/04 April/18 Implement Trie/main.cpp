// Link: https://www.geeksforgeeks.org/problems/trie-insert-and-search0651/1

#include <iostream>
using namespace std;

class Trie
{
private:
    struct S
    {
        bool ed = false;
        S *c[26];
        S()
        {
            for (int i = 0; i < 26; ++i)
                c[i] = 0;
        }
    };
    S *root = 0;

public:
    Trie()
    {
        root = new S{};
    }

    void insert(string &word)
    {
        auto *cr = root;
        for (auto &&x : word)
        {
            if (cr->c[x - 'a'] == 0)
                cr->c[x - 'a'] = new S{};
            cr = cr->c[x - 'a'];
        }
        cr->ed = true;
    }

    bool search(string &word, bool full = true)
    {
        auto cr{root};
        for (auto &&x : word)
        {
            if (cr->c[x - 'a'] == 0)
                return false;
            cr = cr->c[x - 'a'];
        }
        return full ? cr->ed : true;
    }

    bool isPrefix(string &word)
    {
        return search(word, false);
    }
};

int main()
{
    Trie t1;
    string s = "abcd";
    t1.insert(s);
    s = "abc";
    t1.insert(s);
    s = "bcd";
    t1.insert(s);
    s = "bc";
    cout << boolalpha << t1.search(s) << endl;
    cout << boolalpha << t1.isPrefix(s) << endl;
    s = "abc";
    cout << boolalpha << t1.search(s) << endl;

    Trie t2;
    s = "gfg";
    t2.insert(s);
    s = "geeks";
    t2.insert(s);
    s = "fg";
    cout << boolalpha << t2.isPrefix(s) << endl;
    s = "geek";
    cout << boolalpha << t2.isPrefix(s) << endl;
    s = "for";
    cout << boolalpha << t2.search(s) << endl;
    return 0;
}