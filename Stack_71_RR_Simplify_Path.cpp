#include <stack>
#include <string>
using namespace std;


class Solution {
public:
    string simplifyPath(string path) {
        string res = "";
        //LIFO
        stack<string> st;
        for(int i = 0; i < path.size(); i++){
            if(path[i] == '/')continue;

            string temp;
            while(i < path.size() && path[i] != '/'){
                temp += path[i];
                i++;
            }

            if(temp == "."){
                continue;
            }else if(temp == ".."){
                if(!st.empty())st.pop();
            }else{
                st.push(temp);
            }
        }

        while(!st.empty()){
            res = "/" + st.top() + res;
            st.pop();
        }
        if(res.size() == 0){
            return "/";
        }else return res;
    }
};