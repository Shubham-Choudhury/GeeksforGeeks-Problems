# Link: https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1


class Solution:
    def insertAtBottom(self, st, x):
        st.reverse()
        st.append(x)
        st.reverse()
        return st


if __name__ == "__main__":
    obj = Solution()
    st = [4, 3, 2, 1, 8]
    x = 2
    print(obj.insertAtBottom(st, x))
    st = [5, 3, 1]
    x = 4
    print(obj.insertAtBottom(st, x))
