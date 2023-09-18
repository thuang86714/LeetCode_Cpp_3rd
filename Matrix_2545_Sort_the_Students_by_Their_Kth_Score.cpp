#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        // m = score.size();
        //int n = score[0].size();
        sort(score.begin(), score.end(), [&](auto const &a, auto const & b){
            return a[k] > b[k];
        });
        return score;
    }
};