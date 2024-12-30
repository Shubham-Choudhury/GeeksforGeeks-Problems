# Link: https://www.geeksforgeeks.org/problems/intersection-of-two-arrays-with-duplicate-elements/1


class Solution:
    def intersection_with_duplicates(self, a, b):
        op = []
        s = set(a)
        t = set(b)

        for x in t:
            if x in s:
                op.append(x)

        return op


if __name__ == "__main__":
    object = Solution()
    a = [1, 2, 1, 3, 1]
    b = [3, 1, 3, 4, 1]
    op = object.intersection_with_duplicates(a, b)
    print(" ".join(map(str, op)))

    a = [1, 1, 1]
    b = [1, 1, 1, 1, 1]
    op = object.intersection_with_duplicates(a, b)
    print(" ".join(map(str, op)))

    a = [1, 2, 3]
    b = [4, 5, 6]
    op = object.intersection_with_duplicates(a, b)
    print(" ".join(map(str, op)))
