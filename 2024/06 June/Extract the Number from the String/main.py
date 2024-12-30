# Link: https://www.geeksforgeeks.org/problems/extract-the-number-from-the-string3428/1


class Solution:
    def ExtractNumber(self, sentence):
        max_num = -1
        i = 0
        while i < len(sentence):
            is_nine = False
            if sentence[i].isdigit():
                num = 0
                while i < len(sentence) and sentence[i].isdigit():
                    if sentence[i] == "9":
                        is_nine = True
                    num = num * 10 + int(sentence[i])
                    i += 1
                if not is_nine and num > max_num:
                    max_num = num
            else:
                i += 1
        return max_num


if __name__ == "__main__":
    obj = Solution()
    sentence = "This is alpha 5057 and 97"
    print(obj.ExtractNumber(sentence))
    sentence = "Another input 9007"
    print(obj.ExtractNumber(sentence))
