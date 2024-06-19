# Link: https://www.geeksforgeeks.org/problems/magical-box5306/1

import math

class Solution:
    def maxVolume(self, perimeter, area):
        temp_value = perimeter - math.sqrt(perimeter * perimeter - (24 * area))
        base_side_length = (temp_value / 12) ** 2
        height = perimeter / 4 - (2 * (temp_value / 12))
        volume = base_side_length * height
        return volume


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxVolume(22, 15))
    print(obj.maxVolume(20, 5))
