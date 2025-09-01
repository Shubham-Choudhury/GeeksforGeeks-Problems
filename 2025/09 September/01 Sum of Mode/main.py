# Link: https://www.geeksforgeeks.org/problems/sum-of-mode/1

from collections import defaultdict
import bisect


class Solution:
    def sumOfModes(self, arr, k):
        n = len(arr)
        sum = 0

        mp = defaultdict(int)

        st = []

        for i in range(k):
            mp[arr[i]] += 1

        for key, val in mp.items():
            bisect.insort(st, (val, -key))

        mode = -st[-1][1]
        sum += mode

        for i in range(k, n):
            out = arr[i - k]
            in_ = arr[i]
            outFreq = mp[out]
            st.remove((outFreq, -out))
            mp[out] -= 1

            if mp[out] > 0:
                bisect.insort(st, (mp[out], -out))
            else:
                del mp[out]

            mp[in_] += 1

            bisect.insort(st, (mp[in_], -in_))

            mode = -st[-1][1]
            sum += mode

        return sum


if __name__ == "__main__":
    sol = Solution()
    arr = [1, 2, 3, 2, 5, 2, 4, 4]
    k = 3
    result = sol.sumOfModes(arr, k)
    print(f"Sum of modes for subarrays of size {k}: {result}")

    arr = [1, 2, 1, 3, 5]
    k = 3
    result = sol.sumOfModes(arr, k)
    print(f"Sum of modes for subarrays of size {k}: {result}")
