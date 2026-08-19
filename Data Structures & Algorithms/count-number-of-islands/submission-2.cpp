#include <queue>
using namespace std;

class Solution {
public:
    void DFS(vector<vector<char>>& grid, int row, int col, int numRows, int numCols){
        if(grid[row][col] == '0'){
            return;
        }

        grid[row][col] = '0';

        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};

        for(int i = 0; i < 4; i++){
            int newRow = row + dr[i];
                int newCol = col + dc[i];

                if(newRow >= 0 && newRow < numRows &&
                   newCol >= 0 && newCol < numCols){
                        if(grid[newRow][newCol] == '1'){
                            DFS(grid, newRow, newCol, numRows, numCols);
                        }
                   }
        }

    }

    void BFS(vector<vector<char>>& grid, int row, int col){
        int numRows = grid.size();
        int numCols = grid[0].size();
        
        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};

        queue<std::pair<int,int>> q;
        q.push({row,col});
        grid[row][col] = '0';

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int newRow = r + dr[i];
                int newCol = c + dc[i];

                if(newRow >= 0 && newRow < numRows &&
                   newCol >= 0 && newCol < numCols)
                {
                    if(grid[newRow][newCol] == '1'){
                        grid[newRow][newCol] = '0';
                        q.push({newRow, newCol});
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;

        int numRows = grid.size();
        int numCols = grid[0].size();

        for(int r = 0; r < numRows; r++){
            for (int c = 0; c < numCols; c++){
                if(grid[r][c] == '1'){
                    DFS(grid, r,c, numRows, numCols);
                    islands++;
                }
            }
        }


        return islands;
    }
};
