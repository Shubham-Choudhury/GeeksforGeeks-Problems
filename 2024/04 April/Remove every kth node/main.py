# Link: https://www.geeksforgeeks.org/problems/remove-every-kth-node/1


class node:

    def __init__(self, x):
        self.data = x
        self.next = None


def createLinkedList(arr):
    head = node(arr[0])
    curr = head
    for i in range(1, len(arr)):
        new_node = node(arr[i])
        curr.next = new_node
        curr = curr.next

    return head


def printlist(ptr):
    while ptr != None:
        print(ptr.data, end=" ")
        ptr = ptr.next
    print()


class Solution:
    def deleteK(self, head, k):
        if k == 1:
            return None
        node = head
        while node != None:
            for i in range(k - 2):
                if node == None:
                    return head
                node = node.next
            if node == None:
                return head
            if node.next != None:
                node.next = node.next.next
            node = node.next

        return head


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 2, 3, 4, 5, 6, 7, 8]
    k = 2
    head = createLinkedList(arr)
    head = obj.deleteK(head, k)
    printlist(head)

    arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    k = 3
    head = createLinkedList(arr)
    head = obj.deleteK(head, k)
    printlist(head)
