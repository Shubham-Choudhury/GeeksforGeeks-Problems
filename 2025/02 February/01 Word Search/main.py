# Link: https://www.geeksforgeeks.org/problems/word-search/1


class Solution:
    def help(self, mat, word, i, j, index):
        if index == len(word):
            return True
        if (
            i < 0
            or j < 0
            or i == len(mat)
            or j == len(mat[0])
            or mat[i][j] != word[index]
        ):
            return False
        temp = mat[i][j]
        mat[i][j] = "-"
        index += 1
        a = (
            self.help(mat, word, i + 1, j, index)
            or self.help(mat, word, i - 1, j, index)
            or self.help(mat, word, i, j + 1, index)
            or self.help(mat, word, i, j - 1, index)
        )
        mat[i][j] = temp
        return a

    def isWordExist(self, mat, word):
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                if mat[i][j] == word[0]:
                    if self.help(mat, word, i, j, 0):
                        return True
        return False


if __name__ == "__main__":
    object = Solution()
    mat = [["T", "E", "E"], ["S", "G", "K"], ["T", "E", "L"]]
    word = "GEEK"
    print(object.isWordExist(mat, word))

    mat = [["T", "E", "U"], ["S", "G", "K"], ["T", "E", "L"]]
    word = "GEEK"
    print(object.isWordExist(mat, word))

    mat = [["A", "B", "A"], ["B", "A", "B"]]
    word = "AB"
    print(object.isWordExist(mat, word))
