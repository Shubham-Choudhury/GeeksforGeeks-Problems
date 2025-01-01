# Link: https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1


class Solution:
    def countSubarrays(self, arr, k):
        prefix_sum_count = {}
        current_sum = 0
        count = 0

        prefix_sum_count[0] = 1

        for num in arr:
            current_sum += num
            if (current_sum - k) in prefix_sum_count:
                count += prefix_sum_count[current_sum - k]
            if current_sum in prefix_sum_count:
                prefix_sum_count[current_sum] += 1
            else:
                prefix_sum_count[current_sum] = 1

        return count


if __name__ == "__main__":
    object = Solution()
    arr = [10, 2, -2, -20, 10]
    k = -10
    print(object.countSubarrays(arr, k))

    arr = [9, 4, 20, 3, 10, 5]
    k = 33
    print(object.countSubarrays(arr, k))

    arr = [1, 3, 5]
    k = 0
    print(object.countSubarrays(arr, k))
