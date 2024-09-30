class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0};
        int column[9][9] = {0};
        int box[3][9][9] = {0};
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.')
                    continue;
                int num = board[r][c] - '1';
                if (row[r][num] || column[num][c] || box[r / 3][c / 3][num]) {
                    return false;
                }
                row[r][num]++;
                column[num][c]++;
                box[r / 3][c / 3][num]++;
            }
        }
        return true;
    }
};