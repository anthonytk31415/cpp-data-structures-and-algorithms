// kmp
#include <iostream> 
#include <vector> 
#include <string> 

using namespace std; 

vector<int> compute_lps(string & pat) {
    vector<int> lps(pat.size(), 0); 
    int length = 0, i = 1; 
    while (i < pat.size()){
        if (pat[i] == pat[length]){
            length += 1;
            lps[i] = length;       
            i += 1;        
        }
        else {
            if (length > 0){
                length = lps[length - 1]; 
            }
            else {
                i += 1; 
            }
        }
    }
    return lps;
}

vector<int> kmp(string & text, string & pat){
    vector<int> lps = compute_lps(pat); 
    vector<int> res; 
    int i = 0, j = 0; 
    while (i < text.size()){
        if (text[i] == pat[j]){
            i += 1; 
            j += 1; 
            if (j == pat.size()){
                res.push_back(i - j); 
                j = lps[j - 1]; 
            }
        }
        else {
            if (j > 0){
                j = lps[j - 1]; 
            }
            else {
                i += 1; 
            }
        }
    }
    return res; 
}

void printVector(vector<int> vect){
    cout << "{"; 
    for (int x : vect){
        cout << x << ", "; 
    }
    cout << "}" << endl;
}



int main(){
    string text = "xxxabababxxxababab";
    string pat = "abab"; 
    vector<int> res = kmp(text, pat); 
    printVector(res); 
    return 0; 
}

