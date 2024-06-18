# Link: https://www.geeksforgeeks.org/problems/rectangles-in-a-circle0457/1

import math
class Solution:
    def rectanglesInCircle(self, r):
        count = 0
        i = 0.5
        while i <= r:
            max_length = 2 * math.sqrt(r**2 - i**2)
            count += int(max_length)
            i += 0.5
        return count


if __name__ == "__main__":
    obj = Solution()
    r = 1
    print(obj.rectanglesInCircle(r))
    r = 2
    print(obj.rectanglesInCircle(r))
