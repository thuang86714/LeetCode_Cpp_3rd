#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //stack LIFO
        //credit to riemeltm
        //TC O(n), SC O(n)
        stack<int> st;//store the index of elements
        
        int n = temperatures.size();
        vector<int> result(n, 0);
        for(int i = n - 1; i >= 0;i--){
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]){
                st.pop();
            }

            if(!st.empty())result[i] = st.top()-i;

            st.push(i);
        }
        return result;



    }
};