# Link: https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1


class Solution:
    def countDistinct(self, arr, k):
        n = len(arr)
        res = []
        freq = {}

        for i in range(k):
            if arr[i] in freq:
                freq[arr[i]] += 1
            else:
                freq[arr[i]] = 1

        res.append(len(freq))

        for i in range(k, n):
            if arr[i] in freq:
                freq[arr[i]] += 1
            else:
                freq[arr[i]] = 1

            freq[arr[i - k]] -= 1
            if freq[arr[i - k]] == 0:
                del freq[arr[i - k]]

            res.append(len(freq))

        return res


if __name__ == "__main__":
    object = Solution()
    arr = [1, 2, 1, 3, 4, 2, 3]
    k = 4
    result = object.countDistinct(arr, k)
    print(" ".join(map(str, result)))

    arr = [4, 1, 1]
    k = 2
    result = object.countDistinct(arr, k)
    print(" ".join(map(str, result)))

    arr = [1, 1, 1, 1, 1]
    k = 3
    result = object.countDistinct(arr, k)
    print(" ".join(map(str, result)))
