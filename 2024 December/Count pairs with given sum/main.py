# Link:  https://www.geeksforgeeks.org/problems/count-pairs-with-given-sum--150253/1


class Solution:
    def countPairs(self, arr, target):
        map = {}
        count = 0
        for i in range(len(arr)):
            if target - arr[i] in map:
                count += map[target - arr[i]]
            if arr[i] in map:
                map[arr[i]] += 1
            else:
                map[arr[i]] = 1
        return count


if __name__ == "__main__":
    object = Solution()
    arr = [1, 5, 7, -1, 5]
    target = 6
    print(object.countPairs(arr, target))

    arr = [1, 1, 1, 1]
    target = 2
    print(object.countPairs(arr, target))

    arr = [10, 12, 10, 15, -1]
    target = 125
    print(object.countPairs(arr, target))
