#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <tuple>

using namespace std;

// https://leetcode.com/problems/equal-row-and-column-pairs/?envType=study-plan-v2&envId=leetcode-75
// 2352. Equal Row and Column Pairs


class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<long, int> rows = {}; 
        unordered_map<long, int> cols = {}; 
        int res = 0;
        for (int i = 0; i < grid.size(); i ++){
            long row = 0; 
            for (int j = 0; j < grid[i].size(); j ++){
                if (j > 0)
                    row *= 10; 
                row += grid[i][j]; 
            }
            rows[row] += 1; 
        }

        for (int j = 0; j < grid[0].size(); j ++){
            long col = 0; 
            for (int i = 0; i < grid.size(); i ++){
                if (i > 0)
                    col *= 10; 
                col += grid[i][j]; 
            }
            cols[col] += 1; 
        }

        for (auto pair : rows){
            int row = pair.first; 
            if (cols.find(row) != cols.end()){
                res += rows[row]*cols[row]; 
            }
        }
        return res;
    }
};
    
int main() {

    Solution sol = Solution();
    // vector<vector<int>> grid = {{3,2,1},{1,7,6},{2,7,7}};
    vector<vector<int>> grid = {{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};
    int res = sol.equalPairs(grid);
    cout << "res: " << res ;
    return 0;

}