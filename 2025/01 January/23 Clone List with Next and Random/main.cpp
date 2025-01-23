// Link: https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *random;

    Node(int x)
    {
        data = x;
        next = NULL;
        random = NULL;
    }
};

void print(Node *root)
{
    map<Node *, int> link;
    Node *temp = root;
    for (int i = 0; temp != NULL; i++)
    {
        link[temp] = i;
        temp = temp->next;
    }
    temp = root;
    cout << "[";
    while (temp->next != NULL)
    {
        if (!temp->random)
        {
            cout << "[" << temp->data << ", "
                 << "NULL"
                 << "], ";
        }
        else
            cout << "[" << temp->data << ", " << link[temp->random] + 1 << "], ";
        temp = temp->next;
    }
    if (!temp->random)
    {
        cout << "[" << temp->data << ", "
             << "NULL"
             << "]]\n";
    }
    else
        cout << "[" << temp->data << ", " << link[temp->random] + 1 << "]]\n";
}

bool validation(Node *res, map<Node *, int> &orgAddress)
{
    Node *temp = res;
    for (int i = 0; temp != NULL; i++)
    {
        if (orgAddress.find(temp) != orgAddress.end())
        {
            return false;
        }
        if (orgAddress.find(temp->random) != orgAddress.end())
        {
            return false;
        }
        temp = temp->next;
    }
    return true;
}

Node *buildLinkedList(vector<pair<int, int>> &v, map<Node *, int> &orgAddress)
{
    vector<Node *> address(v.size());
    Node *head = new Node(v[0].first);
    address[0] = head;
    Node *temp = head;
    orgAddress[head] = 0;
    for (int i = 1; i < v.size(); i++)
    {
        Node *newNode = new Node(v[i].first);
        orgAddress[newNode] = i;
        address[i] = newNode;
        temp->next = newNode;
        temp = temp->next;
    }
    temp = head;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].second != -1)
        {
            temp->random = address[v[i].second - 1];
        }
        temp = temp->next;
    }

    return head;
}

bool validateInput(map<Node *, int> &orgAddress, Node *head, vector<pair<int, int>> &v)
{
    vector<Node *> address(v.size());
    Node *temp = head;
    for (int i = 0; i < v.size(); i++)
    {
        if (orgAddress.find(temp) == orgAddress.end() || orgAddress[temp] != i)
        {
            return false;
        }
        address[i] = temp;
        temp = temp->next;
    }
    if (temp != NULL)
    {
        return false;
    }
    temp = head;
    for (int i = 0; i < v.size(); i++)
    {
        int value = v[i].first;
        int randomIndex = v[i].second;

        if (randomIndex == -1)
        {
            if (temp->random != NULL)
            {
                return false;
            }
        }
        else
        {
            Node *tempNode = address[randomIndex - 1];
            if (temp->random != tempNode)
            {
                return false;
            }
        }
        temp = temp->next;
    }
    return true;
}

class Solution
{
public:
    Node *cloneLinkedList(Node *head)
    {
        Node *temp = head;
        map<Node *, Node *> mp;

        while (temp)
        {
            Node *new_node = new Node(temp->data);
            mp[temp] = new_node;
            temp = temp->next;
        }

        temp = head;
        while (temp)
        {
            Node *new_node = mp[temp];
            new_node->next = mp[temp->next];
            new_node->random = mp[temp->random];
            temp = temp->next;
        }

        return mp[head];
    }
};

int main()
{
    Solution object;
    vector<pair<int, int>> v = {{1, 3}, {3, 3}, {5, NULL}, {9, 3}};
    map<Node *, int> orgAddress;
    Node *head = buildLinkedList(v, orgAddress);
    Node *res = object.cloneLinkedList(head);
    if (validateInput(orgAddress, res, v))
    {
        cout << "Output: ";
        print(res);
    }
    else
    {
        cout << "Output: [Invalid]\n";
    }
    return 0;
}