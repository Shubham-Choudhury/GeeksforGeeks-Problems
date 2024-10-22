// Link: https://www.geeksforgeeks.org/problems/find-the-sum-of-last-n-nodes-of-the-linked-list/1

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

Node *createLinkedList(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *tail = head;
    for (int i = 1; i < arr.size(); i++)
    {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    return head;
}

class Solution
{
public:
    int sumOfLastN_Nodes(struct Node *head, int n)
    {
        int i = 0;
        int j = -1;
        Node *t1 = head;
        Node *t2 = head;

        int sum = 0;
        while (t2)
        {
            sum += t2->data;
            j++;
            while (j - i + 1 > n)
            {
                sum -= t1->data;
                i++;
                t1 = t1->next;
            }
            t2 = t2->next;
        }
        return sum;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {5, 6, 9, 3, 4, 10};
    int n = 3;
    Node *head = createLinkedList(arr);
    cout << obj.sumOfLastN_Nodes(head, n) << endl;

    arr = {1, 2};
    n = 2;
    head = createLinkedList(arr);
    cout << obj.sumOfLastN_Nodes(head, n) << endl;
    return 0;
}