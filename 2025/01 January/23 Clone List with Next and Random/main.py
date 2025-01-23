# Link: https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1


class Node:

    def __init__(self, x):
        self.data = x
        self.next = None
        self.random = None


def print_linked_list(root):
    link = {}
    temp = root
    index = 0
    while temp:
        link[temp] = index
        temp = temp.next
        index += 1

    temp = root
    result = []
    while temp:
        random_index = "NULL" if not temp.random else link.get(temp.random) + 1
        result.append(f"[{temp.data}, {random_index}]")
        temp = temp.next

    print(f"[{', '.join(result)}]")


def build_linked_list(v, org_address):
    address = [None] * len(v)
    head = Node(v[0][0])
    address[0] = head
    org_address[head] = 0
    temp = head

    for i in range(1, len(v)):
        new_node = Node(v[i][0])
        org_address[new_node] = i
        address[i] = new_node
        temp.next = new_node
        temp = temp.next

    temp = head
    for i in range(len(v)):
        random_index = v[i][1]
        if random_index != -1:
            temp.random = address[random_index - 1]
        temp = temp.next

    return head


def validate_input(org_address, head, v):
    address = [None] * len(v)
    temp = head
    for i in range(len(v)):
        if temp not in org_address or org_address[temp] != i:
            return False
        address[i] = temp
        temp = temp.next

    if temp is not None:
        return False

    temp = head
    for i in range(len(v)):
        value = v[i][0]
        random_index = v[i][1]

        if random_index == -1:
            if temp.random is not None:
                return False
        else:
            temp_node = address[random_index - 1]
            if temp.random != temp_node:
                return False
        temp = temp.next
    return True


def validation(res, org_address):
    temp = res
    while temp:
        if temp in org_address:
            return False
        if temp.random in org_address:
            return False
        temp = temp.next
    return True


class Solution:
    def cloneLinkedList(self, head):
        new = []
        rand = []
        dct = {}

        dummy = Node(None)
        ncur = dummy

        idx = 0
        cur = head
        while cur:
            ncur.next = Node(None)
            ncur = ncur.next
            ncur.data = cur.data
            new.append(ncur)
            dct[cur] = idx
            rand.append(cur.random)
            cur = cur.next
            idx += 1

        cur = dummy.next
        for nd in rand:
            if nd:
                cur.random = new[dct[nd]]
            cur = cur.next

        return dummy.next


if __name__ == "__main__":
    solution = Solution()
    v = [[7, 0], [13, 0], [11, 4], [10, 2], [1, 0]]
    org_address = {}
    head = build_linked_list(v, org_address)
    res = solution.cloneLinkedList(head)
    print_linked_list(res)
    print(validate_input(org_address, res, v))
    print(validation(res, org_address))
