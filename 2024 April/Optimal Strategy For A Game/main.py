# Link: https://www.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1

# User function Template for python3


# Function to find the maximum possible amount of money we can win.
class Solution:
    def optimalStrategyOfGame(self, n, arr):
        self.memorize = [[-1 for _ in range(n)] for _ in range(n)]
        return self.maximumAmountHelper(arr, 0, n - 1)

    def maximumAmountHelper(self, arr, left_i, right_i):
        if left_i > right_i:
            return 0
        if left_i == right_i:
            return arr[left_i]

        if self.memorize[left_i][right_i] != -1:
            return self.memorize[left_i][right_i]

        take_left = arr[left_i] + min(
            self.maximumAmountHelper(arr, left_i + 2, right_i),
            self.maximumAmountHelper(arr, left_i + 1, right_i - 1),
        )

        take_right = arr[right_i] + min(
            self.maximumAmountHelper(arr, left_i, right_i - 2),
            self.maximumAmountHelper(arr, left_i + 1, right_i - 1),
        )

        best_move = max(take_left, take_right)

        if self.memorize[left_i][right_i] == -1:
            self.memorize[left_i][right_i] = best_move

        return best_move


if __name__ == "__main__":
    obj = Solution()
    arr = [5, 3, 7, 10]
    n = len(arr)
    print(obj.optimalStrategyOfGame(n, arr))
    arr = [8, 15, 3, 7]
    n = len(arr)
    print(obj.optimalStrategyOfGame(n, arr))
