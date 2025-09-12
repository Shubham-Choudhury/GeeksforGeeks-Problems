# Link: https://www.geeksforgeeks.org/problems/largest-number-in-one-swap1520/1


class Solution:
    def largestSwap(self, s):
        arr = list(s)
        maxDigit = "0"
        maxIndx, l, r = -1, -1, -1

        for i in range(len(arr) - 1, -1, -1):
            if arr[i] > maxDigit:
                maxDigit = arr[i]
                maxIndx = i
            elif arr[i] < maxDigit:
                l, r = i, maxIndx

        if l == -1:
            return s

        arr[l], arr[r] = arr[r], arr[l]
        return "".join(arr)


if __name__ == "__main__":
    sol = Solution()
    s = "768"
    result = sol.largestSwap(s)
    print(f"Input: {s}, Largest number after one swap: {result}")

    s = "333"
    result = sol.largestSwap(s)
    print(f"Input: {s}, Largest number after one swap: {result}")
