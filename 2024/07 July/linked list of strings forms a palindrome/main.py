# Link: https://www.geeksforgeeks.org/problems/linked-list-of-strings-forms-a-palindrome/1


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Llist:
    def __init__(self):
        self.head = None

    def insert(self, data, tail):
        node = Node(data)

        if not self.head:
            self.head = node
            return node

        tail.next = node
        return node


def createLinkedList(elements):
    llist = Llist()
    tail = None
    for element in elements:
        tail = llist.insert(element, tail)
    return llist.head


class Solution:
    def compute(self, head):
        string = ""
        temp = head
        while temp:
            string += temp.data
            temp = temp.next

        l, r = 0, len(string) - 1
        while l < r:
            if string[l] != string[r]:
                return False
            l += 1
            r -= 1

        return True


if __name__ == "__main__":
    obj = Solution()
    elements = ["a", "bc", "d", "dcb", "a"]
    head = createLinkedList(elements)
    print(obj.compute(head))

    elements = ["a", "bc", "d", "ba"]
    head = createLinkedList(elements)
    print(obj.compute(head))
