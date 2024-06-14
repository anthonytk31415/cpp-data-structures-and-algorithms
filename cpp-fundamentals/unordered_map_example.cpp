#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <format>
using namespace std;



int main() 
{
    unordered_map <string, int> myMap;
    myMap["a"] = 1; 
    myMap["b"] = 2;             // insertion
    myMap.insert({"c", 3});
    // myMap.find returns an iterator pointing at the value if key is found
    // or to the one at end if it is not
    string key = "b";
    myMap.erase(key);           // deletion
    auto it = myMap.find(key);  // test for membershp; if key not in map, gives a pointer to the end
    if (it == myMap.end())      // use the myMap.end
    cout << format("this key is not found in myMap: {}", key) << endl;
    size_t mapSize = myMap.size(); // size of map
    cout << "size of map: " << mapSize << endl;        

    // iterate over pairs of the map
    for (auto& pair : myMap){
        myMap[pair.first] = pair.second + 1; 
        cout << format("key: {}; value: {}", pair.first, pair.second);
    }
    return 0; 

}