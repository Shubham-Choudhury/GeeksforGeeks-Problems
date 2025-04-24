# Link: https://www.geeksforgeeks.org/problems/majority-element-1587115620/1


class Solution:
    def majorityElement(self, arr):
        count = 0
        candidate = 0
        for num in arr:
            if count == 0:
                candidate = num
            count += 1 if num == candidate else -1

        count = 0
        for num in arr:
            if num == candidate:
                count += 1

        return candidate if count > len(arr) / 2 else -1


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 1, 2, 1, 3, 5, 1]
    result = obj.majorityElement(arr)
    print("Majority Element:", result)

    arr = [7]
    result = obj.majorityElement(arr)
    print("Majority Element:", result)

    arr = [2, 13]
    result = obj.majorityElement(arr)
    print("Majority Element:", result)
