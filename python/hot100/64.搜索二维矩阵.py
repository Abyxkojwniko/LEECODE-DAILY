class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])
        left, right = -1, m * n
        while left + 1 < right:
            mid = left + (right - left) // 2
            x = matrix[mid//n][mid%n]
            if x == target:
                return True
            elif x > target:
                right = mid
            else:
                left = mid
        return False