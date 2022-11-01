class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> answer(n, -1);
        for(int b = 0; b < n; ++b) {
            int j = b;
            for(int i = 0; i < m; ++i) {
                if((j == 0 && grid[i][j] == -1) || (j == (n - 1) && grid[i][j] == 1)) break;
                if(grid[i][j] == 1) {
                    if(grid[i][j + 1] == 1) {
                        j++;
                        if(i == m - 1) answer[b] = j;
                        else continue;
                    }
                    else break;
                }
                if(grid[i][j] == -1) {
                    if(grid[i][j - 1] == -1) {
                        j--;
                        if(i == m - 1) answer[b] = j;
                        else continue;
                    }
                    else break;
                }
            }
        }
        return answer;
    
    }
};