# Link: https://www.geeksforgeeks.org/problems/decode-the-string2444/1


class Solution:
    def decodedString(self, s):
        st = []

        for i in range(len(s)):
            if s[i] != "]":
                st.append(s[i])
            else:
                temp = []

                while st and st[-1] != "[":
                    temp.append(st.pop())
                temp.reverse()
                st.pop()

                num = []
                while st and st[-1].isdigit():
                    num.insert(0, st.pop())

                number = int("".join(num))
                repeat = "".join(temp) * number

                st.extend(repeat)

        return "".join(st)


if __name__ == "__main__":
    obj = Solution()
    s = "3[b2[ca]]"
    result = obj.decodedString(s)
    print(f"Encoded string: {s}, Decoded string: {result}")

    s = "3[ab]"
    result = obj.decodedString(s)
    print(f"Encoded string: {s}, Decoded string: {result}")
