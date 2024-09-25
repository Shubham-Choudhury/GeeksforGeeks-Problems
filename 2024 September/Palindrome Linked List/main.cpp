// Link: https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

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
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

class Solution
{
public:
    Node *reverseList(Node *head)
    {
        Node *prev = nullptr;
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    bool isPalindrome(Node *head)
    {
        if (!head || !head->next)
            return true;

        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *secondHalf = reverseList(slow);
        Node *firstHalf = head;

        Node *secondHalfCopy = secondHalf;
        while (secondHalf != nullptr)
        {
            if (firstHalf->data != secondHalf->data)
            {
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        reverseList(secondHalfCopy);

        return true;
    }
};

int main()
{
    vector<int> arr = {1, 2, 1, 1, 2, 1};
    Node *head = createLinkedList(arr);
    Solution obj;
    cout << obj.isPalindrome(head) << endl;

    arr = {1, 2, 3, 4};
    head = createLinkedList(arr);
    cout << obj.isPalindrome(head) << endl;
    return 0;
}