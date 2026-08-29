class Solution:
    def spiralOrder(self, matrix):
        
        if not matrix:
            return []

        ans = []

        rows = len(matrix)
        cols = len(matrix[0])

        top = 0
        bottom = rows - 1
        left = 0
        right = cols - 1

        while top <= bottom and left <= right:

            # Left → Right
            for i in range(left, right + 1):
                ans.append(matrix[top][i])
            top += 1

            # Top → Bottom
            for i in range(top, bottom + 1):
                ans.append(matrix[i][right])
            right -= 1

            # Right → Left
            if top <= bottom:
                for i in range(right, left - 1, -1):
                    ans.append(matrix[bottom][i])
                bottom -= 1

            # Bottom → Top
            if left <= right:
                for i in range(bottom, top - 1, -1):
                    ans.append(matrix[i][left])
                left += 1

        return ans