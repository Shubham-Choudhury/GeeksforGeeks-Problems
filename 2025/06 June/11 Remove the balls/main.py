# Link: https://www.geeksforgeeks.org/problems/remove-the-balls--170647/1


class Solution:
    def findLength(self, color, radius):
        n = len(color)
        st = []

        for i in range(n):
            if st and color[i] == color[st[-1]] and radius[i] == radius[st[-1]]:
                st.pop()
            else:
                st.append(i)

        return len(st)


if __name__ == "__main__":
    obj = Solution()
    color = [2, 3, 5]
    radius = [3, 3, 5]
    result = obj.findLength(color, radius)
    print(result)

    color = [2, 2, 5]
    radius = [3, 3, 5]
    result = obj.findLength(color, radius)
    print(result)
