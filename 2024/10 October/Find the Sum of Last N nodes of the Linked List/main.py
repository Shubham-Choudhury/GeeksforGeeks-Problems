# Link: https://www.geeksforgeeks.org/problems/find-the-sum-of-last-n-nodes-of-the-linked-list/1


class Node:
    def __init__(self, x):
        self.data = x
        self.next = None


def createLinkedList(arr):
    head = Node(arr[0])
    tail = head
    for i in range(1, len(arr)):
        tail.next = Node(arr[i])
        tail = tail.next
    return head


class Solution:
    def sumOfLastN_Nodes(self, head, n):
        i = 0
        j = -1
        t1 = head
        t2 = head

        total_sum = 0
        while t2:
            total_sum += t2.data
            j += 1
            while j - i + 1 > n:
                total_sum -= t1.data
                i += 1
                t1 = t1.next
            t2 = t2.next
        return total_sum


if __name__ == "__main__":
    obj = Solution()
    arr = [5, 6, 9, 3, 4, 10]
    n = 3
    head = createLinkedList(arr)
    print(obj.sumOfLastN_Nodes(head, n))

    arr = [1, 2]
    n = 2
    head = createLinkedList(arr)
    print(obj.sumOfLastN_Nodes(head, n))
