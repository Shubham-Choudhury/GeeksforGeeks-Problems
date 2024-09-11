# Link: https://www.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1


class node:

    def __init__(self):
        self.data = None
        self.next = None


# Linked List Class
class Linked_List:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self, data):
        if self.head == None:
            self.head = node()
            self.tail = self.head
            self.head.data = data
        else:
            new_node = node()
            new_node.data = data
            new_node.next = None
            self.tail.next = new_node
            self.tail = self.tail.next


def printlist(head):
    temp = head
    while temp is not None:
        print(temp.data, end=" ")
        temp = temp.next
    print("")


def buildList(arr):
    if len(arr) == 0:
        return None
    lis = Linked_List()
    for i in arr:
        lis.insert(i)
    return lis.head


class Solution:
    def get_middle(self, head):
        slow = head
        fast = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        return slow.data


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 2, 3, 4, 5]
    head = buildList(arr)
    print(obj.get_middle(head))

    arr = [2, 4, 6, 7, 5, 1]
    head = buildList(arr)
    print(obj.get_middle(head))
