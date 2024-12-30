# Link:https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1


class Solution:
    def printLargest(self, arr):
        sorted_arr = sorted(arr, key=self.sortfunc)
        s = ""
        for a in reversed(sorted_arr):
            s += str(a)
        return s

    def sortfunc(self, a):
        aa = a
        while len(aa) < 18:
            aa += aa
        return aa


if __name__ == "__main__":
    obj = Solution()
    arr = ["3", "30", "34", "5", "9"]
    print(obj.printLargest(arr))
    arr = ["54", "546", "548", "60"]
    print(obj.printLargest(arr))
