# Link: https://www.geeksforgeeks.org/problems/number-of-subarrays-with-maximum-values-in-given-range5949/1


class Solution:
    def countSubarrays(self, a, n, L, R):
        # Complete the function
        def nC2(n):
            return n * (n + 1) // 2

        def count_subarrays_at_most(arr, maxi):
            count, curr_len = 0, 0
            for a in arr:
                if a <= maxi:
                    curr_len += 1
                else:
                    count += nC2(curr_len)
                    curr_len = 0
            count += nC2(curr_len)
            return count

        return count_subarrays_at_most(a, R) - count_subarrays_at_most(a, L - 1)


if __name__ == "__main__":
    obj = Solution()
    arr = [2, 0, 11, 3, 0]
    n = len(arr)
    L = 1
    R = 10
    print(obj.countSubarrays(arr, n, L, R))
