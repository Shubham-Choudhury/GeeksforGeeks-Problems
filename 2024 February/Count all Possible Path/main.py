# Link: https://www.geeksforgeeks.org/problems/castle-run3644/1

class Solution:
    def isPossible(self, paths):
        for i in range(len(paths)):
            c = 0
            for j in range(len(paths)):
                if paths[i][j] == 1:
                    c += 1
            if c % 2:
                return 0
        return 1
    
if __name__=="__main__":
    obj=Solution()

    paths = [[0, 1, 1, 1, 1], [1, 0, 0, 1, 0], [1, 0, 0, 1, 0], [1, 1, 1, 0, 1], [1, 0, 0, 1, 0]]
    print(obj.isPossible(paths))

    paths = [[0, 1, 1, 0], [1, 0, 1, 1], [1, 1, 0, 0], [0, 1, 0, 0]]
    print(obj.isPossible(paths))

    