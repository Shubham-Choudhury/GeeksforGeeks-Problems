# Link: https://www.geeksforgeeks.org/problems/play-with-or5515/1


class Solution:
    def game_with_number(self, arr, n):
        res = []
        for i in range(len(arr)):
            if i == n - 1:
                break
            res.append(arr[i] | arr[i + 1])
        res.append(arr[-1])
        return res


if __name__ == "__main__":
    obj = Solution()
    arr = [10, 11, 1, 2, 3]
    n = len(arr)
    print(obj.game_with_number(arr, n))
    arr = [5, 9, 2, 6]
    n = len(arr)
    print(obj.game_with_number(arr, n))
