var isValidSudoku = function(board) {

    const rows = Array.from({ length: 9 }, () => new Set());
    const cols = Array.from({ length: 9 }, () => new Set());
    const boxes = Array.from({ length: 9 }, () => new Set());

    for (let r = 0; r < 9; r++) {
        for (let c = 0; c < 9; c++) {

            if (board[r][c] === '.') {
                continue;
            }

            let num = board[r][c];
            let box = Math.floor(r / 3) * 3 + Math.floor(c / 3);

            if (rows[r].has(num) ||
                cols[c].has(num) ||
                boxes[box].has(num)) {
                return false;
            }

            rows[r].add(num);
            cols[c].add(num);
            boxes[box].add(num);
        }
    }

    return true;
};