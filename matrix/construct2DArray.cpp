#include <iostream>
#include <vector> 

using namespace std; 

vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    vector<vector<int>> res; 
    if (original.size() != n*m) 
        return res;
    int k = 0;
    for (int i = 0; i < m; i++){
        vector<int> row; 
        for (int j = 0; j < n; j++){
            row.push_back(original[k]);
            k ++;
        }
        res.push_back(row); 
    }
    return res; 
};


int main() {


    return 0;
}