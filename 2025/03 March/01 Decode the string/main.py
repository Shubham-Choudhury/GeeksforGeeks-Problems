# Link: https://www.geeksforgeeks.org/problems/decode-the-string2444/1


class Solution:
    def decodedString(self, s):
        stack = []
        num = 0
        curr_str = ""

        for char in s:
            if char.isdigit():
                num = num * 10 + int(char)
            elif char == "[":
                stack.append((curr_str, num))
                curr_str, num = "", 0
            elif char == "]":
                prev_str, repeat = stack.pop()
                curr_str = prev_str + curr_str * repeat
            else:
                curr_str += char
        return curr_str


if __name__ == "__main__":
    obj = Solution()
    s = "1[b]"
    print(obj.decodedString(s))

    s = "3[b2[ca]]"
    print(obj.decodedString(s))
