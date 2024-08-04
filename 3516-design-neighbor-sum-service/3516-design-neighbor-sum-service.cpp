class neighborSum {
public:
    vector<vector<int>> grid;
    int n;

    neighborSum(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();
    }

    int adjacentSum(int value) {
        int rIndex = -1;
        int cIndex = -1;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            auto it = find(grid[i].begin(), grid[i].end(), value);
            if (it != grid[i].end()) {
                rIndex = i;
                cIndex = distance(grid[i].begin(), it);
                break;
            }
        }

        if (rIndex - 1 >= 0) {
            sum += grid[rIndex - 1][cIndex]; // Top
        }
        if (rIndex + 1 < n) {
            sum += grid[rIndex + 1][cIndex]; // Bottom
        }
        if (cIndex - 1 >= 0) {
            sum += grid[rIndex][cIndex - 1]; // Left
        }
        if (cIndex + 1 < n) {
            sum += grid[rIndex][cIndex + 1]; // Right
        }

        return sum;
    }

    int diagonalSum(int value) {
        int rIndex = -1;
        int cIndex = -1;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            auto it = find(grid[i].begin(), grid[i].end(), value);
            if (it != grid[i].end()) {
                rIndex = i;
                cIndex = distance(grid[i].begin(), it);
                break;
            }
        }

        if (rIndex - 1 >= 0 && cIndex - 1 >= 0) {
            sum += grid[rIndex - 1][cIndex - 1]; // Top-Left
        }
        if (rIndex - 1 >= 0 && cIndex + 1 < n) {
            sum += grid[rIndex - 1][cIndex + 1]; // Top-Right
        }
        if (rIndex + 1 < n && cIndex - 1 >= 0) {
            sum += grid[rIndex + 1][cIndex - 1]; // Bottom-Left
        }
        if (rIndex + 1 < n && cIndex + 1 < n) {
            sum += grid[rIndex + 1][cIndex + 1]; // Bottom-Right
        }

        return sum;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */