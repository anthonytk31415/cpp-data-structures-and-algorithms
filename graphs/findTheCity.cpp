// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance


// this is a n^3 algorithm. 
// Can implement with Floyd Warshall. How? 

#include <iostream>
#include <algorithm> 
#include <vector> 
#include <unordered_set> 

using namespace std; 

class Solution {

public: 
    int dfs(int &i, unordered_map<int, int> &visited, int totalCost, unordered_map<int, vector<vector<int>>> &graph){
        int res = 0;  
        for (auto &edge : graph[i]){
            if ((visited.find(edge[0]) == visited.end() || visited[edge[0]] < totalCost - edge[1]) && (totalCost - edge[1] >= 0) ){
                if (visited.find(edge[0]) == visited.end()){
                    res += 1; 
                }
                visited[edge[0]] = totalCost - edge[1];
                res += dfs(edge[0], visited, totalCost - edge[1], graph);
            }
        }
        return res; 
    }


public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<int> numCities = {}; 
        for (int i = 0; i < n; i++){
            numCities.push_back(INT_MAX);
        }

        unordered_map<int, vector<vector<int>>> graph = {};
        for (auto &edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }

        unordered_map<int, int> visited; 
        for (int i = 0; i < n; i++ ){
            visited = {}; 
            visited[i] = distanceThreshold;
            int curRes = dfs(i, visited, distanceThreshold, graph); 
            numCities[i] = curRes; 
        }
        int minCity = n-1; 
        int minVal = INT_MAX; 
        for (int i = 0; i < n; i ++){
            if (numCities[i] <= minVal){
                minCity = i; 
                minVal = numCities[i];
            }
        }
        return minCity; 
    }
};

int main() {
    Solution s = Solution(); 
    vector<vector<int>> edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    int x = s.findTheCity(4, edges, 4);

    // vector<vector<int>> edges =  {{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}};
    // int x = s.findTheCity(5, edges, 2);

    // vector<vector<int>> edges = {{0,1,10},{0,2,1},{2,3,1},{1,3,1},{1,4,1},{4,5,10}};
    // int x = s.findTheCity(6, edges, 20);

    cout << "res: " << x << endl;
    return 0; 
}