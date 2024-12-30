# Link: https://www.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1


class Solution:
    def rearrange(self, arr):
        p = []
        n = []
        for x in arr:
            if x < 0:
                n.append(x)
            else:
                p.append(x)
        i = 0

        while i < len(p) and i < len(n):
            arr[2 * i] = p[i]
            arr[2 * i + 1] = n[i]
            i += 1
        arr[2 * i :] = []
        arr += p[i:]
        arr += n[i:]


if __name__ == "__main__":
    obj = Solution()
    arr = [9, 4, -2, -1, 5, 0, -5, -3, 2]
    obj.rearrange(arr)
    print(" ".join(map(str, arr)))
    arr = [-5, -2, 5, 2, 4, 7, 1, 8, 0, -8]
    obj.rearrange(arr)
    print(" ".join(map(str, arr)))
