# Link: https://www.geeksforgeeks.org/problems/linked-list-matrix/1


class Node:

    def __init__(self, x):
        self.data = x
        self.right = None
        self.down = None


def display(head):
    Dp = head
    while Dp:
        Rp = Dp
        while Rp:
            print(Rp.data, end=" ")
            if Rp.right:
                print(Rp.right.data, end=" ")
            else:
                print("null", end=" ")
            if Rp.down:
                print(Rp.down.data, end=" ")
            else:
                print("null", end=" ")
            Rp = Rp.right
        Dp = Dp.down


class Solution:
    def constructLinkedMatrix(self, mat):
        n = len(mat)
        v = [[None] * n for _ in range(n)]

        for i in range(n):
            for j in range(n):
                v[i][j] = Node(mat[i][j])

        for i in range(n):
            for j in range(n):
                if i < n - 1:
                    v[i][j].down = v[i + 1][j]
                if j < n - 1:
                    v[i][j].right = v[i][j + 1]

        return v[0][0]


if __name__ == "__main__":
    obj = Solution()
    mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    head = obj.constructLinkedMatrix(mat)
    display(head)

    mat = [[23, 28], [23, 28]]
    head = obj.constructLinkedMatrix(mat)
    display(head)
