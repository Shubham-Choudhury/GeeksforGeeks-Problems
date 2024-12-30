# Link: https://www.geeksforgeeks.org/problems/three-sum-closest/1

import sys


class Solution:
    def threeSumClosest(self, arr, target):
        arr.sort()
        prev_diff = sys.maxsize
        closest_sum = -sys.maxsize - 1

        for i in range(len(arr) - 2):
            start = i + 1
            end = len(arr) - 1

            while start < end:
                sum_val = arr[i] + arr[start] + arr[end]

                if sum_val == target:
                    return target

                current_diff = abs(sum_val - target)

                if current_diff < prev_diff or (
                    current_diff == prev_diff and sum_val > closest_sum
                ):
                    prev_diff = current_diff
                    closest_sum = sum_val

                if sum_val < target:
                    start += 1
                else:
                    end -= 1

        return closest_sum


if __name__ == "__main__":
    obj = Solution()
    arr = [-7, 9, 8, 3, 1, 1]
    target = 2
    print(obj.threeSumClosest(arr, target))

    arr = [5, 2, 7, 5]
    target = 13
    print(obj.threeSumClosest(arr, target))
