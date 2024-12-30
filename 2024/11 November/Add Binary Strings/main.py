# Link: https://www.geeksforgeeks.org/problems/add-binary-strings3805/1


class Solution:
    def addBinary(self, s1, s2):
        carry = 0
        i = len(s1) - 1
        j = len(s2) - 1
        result = ""

        while i >= 0 or j >= 0 or carry == 1:
            sum = carry
            if i >= 0:
                sum += int(s1[i])
                i -= 1
            if j >= 0:
                sum += int(s2[j])
                j -= 1
            result += str(sum % 2)
            carry = sum // 2

        result = result[::-1]
        idx = 0
        while idx < len(result) - 1 and result[idx] == "0":
            idx += 1

        return result[idx:]


# Example usage
if __name__ == "__main__":
    object = Solution()
    s1 = "1101"
    s2 = "111"
    print(object.addBinary(s1, s2))
    s1 = "00100"
    s2 = "010"
    print(object.addBinary(s1, s2))
