# Link: https://www.geeksforgeeks.org/problems/triplet-family/1


class Solution:
    def findTriplet(self, arr):
        arr.sort()
        for i in range(2, len(arr)):
            it = 0
            jt = i - 1
            while it < jt:
                if arr[it] + arr[jt] == arr[i]:
                    return True
                elif arr[it] + arr[jt] > arr[i]:
                    jt -= 1
                else:
                    it += 1
        return False


if __name__ == "__main__":
    obj = Solution()
    arr = [1, 2, 3, 4, 5]
    print(obj.findTriplet(arr))

    arr = [5, 3, 4]
    print(obj.findTriplet(arr))
