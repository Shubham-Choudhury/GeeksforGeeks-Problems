# Link: https://www.geeksforgeeks.org/problems/two-swaps--155623/1


class Solution:
    def checkSorted(self, arr):
        swap_map={}
        for i in range(len(arr)):
            if arr[i] in swap_map:
                arr[i]=swap_map[arr[i]]
            elif arr[i]!=i+1:
                swap_map[i+1]=arr[i]
                arr[i]=i+1
                
        return len(swap_map)<=2 and arr==sorted(arr)


if __name__ == "__main__":
    obj = Solution()
    arr = [4, 3, 2, 1]
    print(obj.checkSorted(arr))
    arr = [4, 3, 1, 2]
    print(obj.checkSorted(arr))
