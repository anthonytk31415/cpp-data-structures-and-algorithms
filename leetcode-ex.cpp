#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMovesToSeat1(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int res = 0;
        for (size_t i = 0; i < seats.size(); i++) {
            res += abs(seats[i] - students[i]);
        }
        return res; 
    }

    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        vector<int> countSeats(101, 0); 
        vector<int> countStudents(101, 0); 

        // Count the frequency of each seat and student position
        for (int i = 0; i < seats.size(); ++i) {
            countSeats[seats[i]] += 1;
            countStudents[students[i]] += 1; 
        }

        int res = 0;
        int i = 0, j = 0;
        while (i < countSeats.size() && j < countStudents.size()) {
            while (i < countSeats.size() && countSeats[i] == 0) {
                i++;
            } 
            while (j < countStudents.size() && countStudents[j] == 0) {
                j++; 
            }
            if (i < countSeats.size() && j < countStudents.size() && countSeats[i] > 0 && countStudents[j] > 0) {
                cout << "i: " << i << ", j: " << j << endl;
                res += abs(i - j);
                countSeats[i] -= 1; 
                countStudents[j] -= 1;
            }
        }
        return res; 
    }
};
int main (){
    cout << "Hello world" << endl;
    Solution s = Solution(); 
    vector<int> seats = {3,1,5}; 
    vector<int> students = {2,7,4}; 
    int x {9};
    int res = s.minMovesToSeat(seats, students); 
    cout << res << endl;
    return res; 
}