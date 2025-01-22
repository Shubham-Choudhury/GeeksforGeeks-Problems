// Link: https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

#include <iostream>
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

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

Node *createLinkedList(int arr[], int n)
{
    Node *head = NULL;
    Node *tail = NULL;
    for (int i = 0; i < n; i++)
    {
        if (head == NULL)
        {
            head = new Node(arr[i]);
            tail = head;
        }
        else
        {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
    }
    return head;
}

class Solution
{
public:
    Node *addTwoLists(Node *num1, Node *num2)
    {
        string str1 = "", str2 = "";
        while (num1 != nullptr)
        {
            str1 += (num1->data + '0');
            num1 = num1->next;
        }
        while (num2 != nullptr)
        {
            str2 += (num2->data + '0');
            num2 = num2->next;
        }
        string ans = "";
        int carry = 0;
        int i = str1.size() - 1, j = str2.size() - 1;
        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry;
            if (i >= 0)
                sum += (str1[i--] - '0');
            if (j >= 0)
                sum += (str2[j--] - '0');
            carry = sum / 10;
            ans += (sum % 10 + '0');
        }
        Node *newHead = new Node(ans[0] - '0');
        Node *ptr = newHead;
        for (size_t k = 1; k < ans.size(); k++)
        {
            ptr->next = new Node(ans[k] - '0');
            ptr = ptr->next;
        }
        newHead = reverse(newHead);
        while (newHead->data == 0)
        {
            newHead = newHead->next;
        }
        return newHead;
    }

    Node *reverse(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        Node *newHead = reverse(head->next);
        Node *front = head->next;
        front->next = head;
        head->next = nullptr;
        return newHead;
    }
};

/*
class Solution
{
public:
    Node *addTwoLists(Node *num1, Node *num2)
    {
        long long int number1 = 0, number2 = 0;

        while (num1 != nullptr)
        {
            // If we append a digit to the number, then the new number will be number * 10 + digit
            number1 = number1 * 10 + num1->data;
            num1 = num1->next;
        }
        while (num2 != nullptr)
        {
            number2 = number2 * 10 + num2->data;
            num2 = num2->next;
        }
        long long int sum = number1 + number2;
        Node *newHead = new Node(sum % 10);
        sum /= 10;
        Node *ptr = newHead;
        while (sum)
        {
            Node *temp = new Node(sum % 10);
            temp->next = newHead;
            newHead = temp;
            sum /= 10;
        }
        return newHead;
    }
};
*/

int main()
{
    Solution object;
    int arr11[] = {4, 5};
    int arr12[] = {3, 4, 5};
    int n1 = sizeof(arr11) / sizeof(arr11[0]);
    int n2 = sizeof(arr12) / sizeof(arr12[0]);
    Node *num1 = createLinkedList(arr11, n1);
    Node *num2 = createLinkedList(arr12, n2);
    Node *result = object.addTwoLists(num1, num2);
    printList(result);

    int arr21[] = {0, 0, 6, 3};
    int arr22[] = {0, 0, 7};
    n1 = sizeof(arr21) / sizeof(arr21[0]);
    n2 = sizeof(arr22) / sizeof(arr22[0]);
    num1 = createLinkedList(arr21, n1);
    num2 = createLinkedList(arr22, n2);
    result = object.addTwoLists(num1, num2);
    printList(result);

    return 0;
}