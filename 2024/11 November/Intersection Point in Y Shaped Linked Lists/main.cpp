// Link: https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

vector<int> take()
{
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number)
    {
        arr.push_back(number);
    }
    return arr;
}

Node *inputList(int size, vector<int> v)
{
    if (size == 0)
        return NULL;

    int val = v[0];

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        val = v[i + 1];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

Node *createLinkedList(vector<int> &arr)
{
    return inputList(arr.size(), arr);
}

class Solution
{
public:
    int intersectPoint(Node *head1, Node *head2)
    {
        Node *f = head1, *s = head2;
        while (f != s)
        {
            f = f->next;
            if (f == NULL)
            {
                f = head2;
            }
            s = s->next;
            if (s == NULL)
            {
                s = head1;
            }
        }
        if (f != NULL)
        {
            return f->data;
        }
        return -1;
    }
};

int main()
{
    Solution object;
    vector<int> arr1 = {4, 4, 4, 4, 4};
    vector<int> arr2 = {4, 4, 4};
    Node *head1 = createLinkedList(arr1);
    Node *head2 = createLinkedList(arr2);
    cout << object.intersectPoint(head1, head2) << endl;

    arr1 = {4, 1, 8, 4, 5};
    arr2 = {5, 6, 1, 8, 4, 5};
    head1 = createLinkedList(arr1);
    head2 = createLinkedList(arr2);
    cout << object.intersectPoint(head1, head2) << endl;

    arr1 = {1, 2, 3};
    arr2 = {4, 5, 6};
    head1 = createLinkedList(arr1);
    head2 = createLinkedList(arr2);
    cout << object.intersectPoint(head1, head2) << endl;
    return 0;
}