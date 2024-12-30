# Link: https://www.geeksforgeeks.org/problems/find-all-triplets-with-zero-sum/1

from collections import defaultdict


class Solution:
    def findTriplets(self, arr):
        n = len(arr)
        mp = defaultdict(list)
        for i in range(n - 1, 1, -1):
            mp[arr[i]].append(i)
        ans = []
        for j in range(1, n):
            if j >= 2:
                mp[arr[j]].pop()
                if not mp[arr[j]]:
                    del mp[arr[j]]
            for i in range(j):
                sum_val = arr[i] + arr[j]
                if -sum_val in mp:
                    for k in mp[-sum_val]:
                        ans.append([i, j, k])
        return ans


if __name__ == "__main__":
    object = Solution()
    arr = [0, -1, 2, -3, 1]
    result = object.findTriplets(arr)
    for triplet in result:
        print("[", " ".join(map(str, triplet)), "]", end=" ")
    print()

    arr = [1, -2, 1, 0, 5]
    result = object.findTriplets(arr)
    for triplet in result:
        print("[", " ".join(map(str, triplet)), "]", end=" ")
    print()

    arr = [2, 3, 1, 0, 5]
    result = object.findTriplets(arr)
    for triplet in result:
        print("[", " ".join(map(str, triplet)), "]", end=" ")
    print()
