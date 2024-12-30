# Link: https://www.geeksforgeeks.org/problems/gray-to-binary-equivalent-1587115620/1


class Solution:
    def grayToBinary(self, n):
        def toBinary(gray):
            binary = gray[0]
            for i in range(1, len(gray)):
                binary += str(int(binary[-1]) ^ int(gray[i]))
            return binary

        def toBinaryFromDec(n):
            return bin(n)[2:]

        def toDecimal(binary):
            binary = binary[::-1]
            res = 0
            for i in range(len(binary)):
                res += int(binary[i]) * (2**i)
            return res

        def toGray(decimal):
            binary = toBinaryFromDec(decimal)
            gray = binary[0]
            for i in range(1, len(binary)):
                gray += str(int(binary[i]) ^ int(binary[i - 1]))
            return gray

        return toDecimal(toBinary(toBinary(toGray(n))))


if __name__ == "__main__":
    obj = Solution()
    n = 4
    print(obj.grayToBinary(n))
    n = 15
    print(obj.grayToBinary(n))
