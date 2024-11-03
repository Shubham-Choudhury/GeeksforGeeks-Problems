// Link: https://www.geeksforgeeks.org/problems/linked-list-length-even-or-odd/1

#include <iostream>
#include <vector>
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

Node *createLinkedList(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

class Solution
{
public:
    bool isLengthEven(struct Node **head)
    {
        int n = 0;
        Node *temp = *head;
        while (temp != nullptr)
        {
            temp = temp->next;
            n++;
        }
        if (n % 2 == 0)
            return true;
        else
            return false;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {12, 52, 10, 47, 95, 0};
    Node *head = createLinkedList(arr);
    cout << boolalpha << object.isLengthEven(&head) << endl;

    arr = {9, 4, 3};
    head = createLinkedList(arr);
    cout << boolalpha << object.isLengthEven(&head) << endl;
    return 0;
}