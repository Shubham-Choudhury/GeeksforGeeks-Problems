# Link: https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1


class Solution:
    def subarrayXor(self, arr, k):
        n = len(arr)
        cnt = 0
        XOR = 0
        freq_map = {0: 1}

        for i in range(n):
            XOR ^= arr[i]
            temp = XOR ^ k
            if temp in freq_map:
                cnt += freq_map[temp]
            if XOR in freq_map:
                freq_map[XOR] += 1
            else:
                freq_map[XOR] = 1

        return cnt


if __name__ == "__main__":
    object = Solution()
    arr = [4, 2, 2, 6, 4]
    k = 6
    print(object.subarrayXor(arr, k))

    arr = [5, 6, 7, 8, 9]
    k = 5
    print(object.subarrayXor(arr, k))
