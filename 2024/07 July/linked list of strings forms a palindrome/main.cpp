// Link: https://www.geeksforgeeks.org/problems/linked-list-of-strings-forms-a-palindrome/1

#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    string data;
    Node *next;

    Node(string x)
    {
        data = x;
        next = NULL;
    }
};

Node *newNode(string str)
{
    Node *new_node = new Node(str);
    new_node->next = NULL;
    return new_node;
}

void print(Node *root)
{
    Node *temp = root;

    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void createLinkedList(Node *&head, vector<string> elements)
{
    if (elements.size() == 0)
    {
        head = NULL;
        return;
    }

    head = newNode(elements[0]);
    Node *tail = head;

    for (int i = 1; i < elements.size(); i++)
    {
        tail->next = newNode(elements[i]);
        tail = tail->next;
    }
}

class Solution
{
public:
    bool compute(Node *head)
    {
        string str = "";
        Node *temp = head;
        while (temp)
        {
            str = str + temp->data;
            temp = temp->next;
        }
        int l = 0, r = str.size() - 1;
        while (l < r)
        {
            if (str[l] != str[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};

int main()
{
    Solution obj;
    vector<string> elements = {"a", "bc", "d", "dcb", "a"};
    Node *head;
    createLinkedList(head, elements);
    cout << obj.compute(head) << endl;

    elements = {"a", "bc", "d", "ba"};
    createLinkedList(head, elements);
    cout << obj.compute(head) << endl;
    return 0;
}