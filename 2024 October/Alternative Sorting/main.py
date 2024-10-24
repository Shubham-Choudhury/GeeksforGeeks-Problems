# Link: https://www.geeksforgeeks.org/problems/alternative-sorting1311/1


class Solution:
    def alternateSort(self, arr):
        distinct = []
        arr.sort()

        len_arr = len(arr)
        i, j = 0, len_arr - 1
        while i < j:
            distinct.append(arr[j])
            distinct.append(arr[i])
            i += 1
            j -= 1
        if i == j:
            distinct.append(arr[i])
        return distinct


if __name__ == "__main__":
    obj = Solution()
    arr = [7, 1, 2, 3, 4, 5, 6]
    result = obj.alternateSort(arr)
    print(" ".join(map(str, result)))

    arr = [1, 6, 9, 4, 3, 7, 8, 2]
    result = obj.alternateSort(arr)
    print(" ".join(map(str, result)))
