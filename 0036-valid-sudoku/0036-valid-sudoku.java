class Solution {
    public boolean isValidSudoku(char[][] board) {

        boolean[][] rows = new boolean[9][10];
        boolean[][] cols = new boolean[9][10];
        boolean[][] boxes = new boolean[9][10];

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {

                if (board[r][c] == '.') {
                    continue;
                }

                int num = board[r][c] - '0';
                int box = (r / 3) * 3 + (c / 3);

                if (rows[r][num] || cols[c][num] || boxes[box][num]) {
                    return false;
                }

                rows[r][num] = true;
                cols[c][num] = true;
                boxes[box][num] = true;
            }
        }

        return true;
    }
}