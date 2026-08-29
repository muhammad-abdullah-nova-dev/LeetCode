var spiralOrder = function(matrix) {
    
    if (matrix.length === 0) return [];

    let ans = [];

    let rows = matrix.length;
    let cols = matrix[0].length;

    let top = 0;
    let bottom = rows - 1;
    let left = 0;
    let right = cols - 1;

    while (top <= bottom && left <= right) {

        // Left → Right
        for (let i = left; i <= right; i++) {
            ans.push(matrix[top][i]);
        }
        top++;

        // Top → Bottom
        for (let i = top; i <= bottom; i++) {
            ans.push(matrix[i][right]);
        }
        right--;

        // Right → Left
        if (top <= bottom) {
            for (let i = right; i >= left; i--) {
                ans.push(matrix[bottom][i]);
            }
            bottom--;
        }

        // Bottom → Top
        if (left <= right) {
            for (let i = bottom; i >= top; i--) {
                ans.push(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
};