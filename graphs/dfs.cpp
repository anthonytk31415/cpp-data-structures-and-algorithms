#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void printAdjList(unordered_map<int, vector<int>> &graph){
    for (auto& pair : graph){
        cout << "key: " << pair.first << "; values: "; 
        for (auto& value : pair.second){
            cout << value << ", "; 
        }
        cout << endl; 
    }
    return; 
}

void printVector(vector<int> &graph){
    for (auto& num : graph){
        cout << "nums: " << num << ", "; 
    }
    cout << endl; 
    return; 
}

unordered_map<int, vector<int>> buildAdjList(vector<vector<int>> &edges){
    unordered_map<int, vector<int>> graph = {}; 
    for (vector<int> &pair : edges){
        graph[pair[0]].push_back(pair[1]); 
    }
    return graph; 
}

void dfs(int &node, unordered_map<int, vector<int>> &graph, vector<int> &res, unordered_map<int, int> &visited, bool &cycles) {
    visited[node] = 1; 
    for (int &child : graph[node] ){
        if (visited.find(child) == visited.end()){
            dfs(child, graph, res, visited, cycles);
        } else if (visited[child] == 1){
            cycles = true; 
        }
    }
    visited[node] = 2; 
    res.push_back(node);
}

vector<int> topoSort(vector<vector<int>> &edges, int n){
    bool cycles = false; 
    vector<int> res = {};
    unordered_map<int, vector<int>> graph = buildAdjList(edges);
    printAdjList(graph);
    unordered_map<int, int> visited = {}; // key, value = 0, 1, 2;

    for (int i = 0; i < n; i ++){
        if (visited.find(i) == visited.end()){
            dfs(i, graph, res, visited, cycles); 
            if (cycles){
                cout << "cycle detected at " << i << endl; 
                return vector<int> {}; 
            }
        }
    }
    return res; 
}



// trying some fun stuff 
int fn(){
    // vector<int> v = {}; 
    unordered_map<int, vector<int>> graph  = {}; 

    // making a vector of arrays of length 2
    vector<array<int, 2>> edges = {};
    array<int, 2>  arr = {3,4};
    edges.push_back({1,2});
    edges.push_back(arr); 


    vector<int> nums = {}; 
    nums.push_back(1);


    return 0; 
}


int main() {
    int x = fn();
    cout << x << endl;
    vector<vector<int>> edges1 = {{0,1}, {1,2}, {6,7}, {5, 8}, {2,3}, {3,4}, {5,6} };
    vector<int> path = topoSort(edges1, 9); 
    cout << "the path  : " << endl; 
    printVector(path); 
    return 0;
}