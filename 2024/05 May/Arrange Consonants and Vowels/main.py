# Link: https://www.geeksforgeeks.org/problems/arrange-consonants-and-vowels/1


# Node Class
class Node:
    def __init__(self, val):
        self.data = val
        self.next = None


# Linked List Class
class Linked_List:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self, val):
        if self.head is None:
            self.head = Node(val)
            self.tail = self.head
        else:
            self.tail.next = Node(val)
            self.tail = self.tail.next


def printList(head):
    tmp = head
    while tmp:
        print(tmp.data, end=" ")
        tmp = tmp.next
    print()


class Solution:
    def arrangeCV(self, head):
        if head.next == None:
            return head
        v = []
        c = []
        length = 0
        vow = "aeiou"
        temp = head
        while temp:
            if temp.data in vow:
                v.append(temp.data)
            else:
                c.append(temp.data)
            temp = temp.next
            length += 1

        if length == len(v):
            return head

        elif length == len(c):
            return head

        else:
            l = v + c
            temp = head
            i = 0
            while temp:
                temp.data = l[i]
                temp = temp.next
                i += 1

        return head


if __name__ == "__main__":
    obj = Solution()
    values = ["a", "b", "c", "d", "e", "f", "g", "h", "i"]
    ll = Linked_List()
    node = ll.head
    for i in range(len(values)):
        ll.insert(values[i])
    printList(obj.arrangeCV(ll.head))

    values = ["a", "b", "a", "b", "d", "e", "e", "b"]
    ll = Linked_List()
    node = ll.head
    for i in range(len(values)):
        ll.insert(values[i])
    printList(obj.arrangeCV(ll.head))
