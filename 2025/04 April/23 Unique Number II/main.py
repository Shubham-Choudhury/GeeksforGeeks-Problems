# Link: https://www.geeksforgeeks.org/problems/finding-the-numbers0215/1


class Solution:
    def singleNum(self, arr):
        freq = {}
        for num in arr:
            if num in freq:
                freq[num] += 1
            else:
                freq[num] = 1
        return sorted([num for num in freq if freq[num] == 1])


if __name__ == "__main__":
    sol = Solution()
    arr = [1, 2, 3, 2, 1, 4]
    result = sol.singleNum(arr)
    print(" ".join(map(str, result)))

    arr = [2, 1, 3, 2]
    result = sol.singleNum(arr)
    print(" ".join(map(str, result)))

    arr = [2, 1, 3, 3]
    result = sol.singleNum(arr)
    print(" ".join(map(str, result)))
