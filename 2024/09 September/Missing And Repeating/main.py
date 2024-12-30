# Link: https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1


class Solution:
    def findTwoElement(self, arr):
        mp = {}
        twice = None
        for i in arr:
            if i in mp:
                mp[i] += 1
                if mp[i] == 2:
                    twice = i
                    break
            else:
                mp[i] = 1

        total_sum = sum(arr)
        n = len(arr)
        sumN = (n * (n + 1)) // 2
        result = []

        if total_sum > sumN:
            diff = total_sum - sumN
            B = abs(twice - diff)
            result.append(twice)
            result.append(B)
        else:
            diff = sumN - total_sum
            B = twice + diff
            result.append(twice)
            result.append(B)

        return result


if __name__ == "__main__":
    obj = Solution()
    arr = [2, 2]
    ans = obj.findTwoElement(arr)
    print(" ".join(map(str, ans)))

    arr = [1, 3, 3]
    ans = obj.findTwoElement(arr)
    print(" ".join(map(str, ans)))
