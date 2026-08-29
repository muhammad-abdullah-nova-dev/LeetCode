public class Solution {
    public IList<int> SpiralOrder(int[][] matrix) {
        
        if (matrix.Length == 0)
            return new List<int>();

        List<int> ans = new List<int>();

        int rows = matrix.Length;
        int cols = matrix[0].Length;

        int top = 0;
        int bottom = rows - 1;
        int left = 0;
        int right = cols - 1;

        while (top <= bottom && left <= right) {

            // Left → Right
            for (int i = left; i <= right; i++) {
                ans.Add(matrix[top][i]);
            }
            top++;

            // Top → Bottom
            for (int i = top; i <= bottom; i++) {
                ans.Add(matrix[i][right]);
            }
            right--;

            // Right → Left
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.Add(matrix[bottom][i]);
                }
                bottom--;
            }

            // Bottom → Top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.Add(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
}