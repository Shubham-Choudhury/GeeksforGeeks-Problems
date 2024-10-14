# Link: https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/1


class Node:

    def __init__(self, data):
        self.data = data
        self.next = None


def createLinkedList(arr):
    head = Node(arr[0])
    temp = head

    for i in range(1, len(arr)):
        temp.next = Node(arr[i])
        temp = temp.next

    return head


class Solution:
    def getCount(self, head):
        count = 0
        temp = head

        while temp:
            count += 1
            temp = temp.next

        return count


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 2, 3, 4, 5]
    head = createLinkedList(arr)
    print(obj.getCount(head))
    arr = [2, 4, 6, 7, 5, 1, 0]
    head = createLinkedList(arr)
    print(obj.getCount(head))
