#include <algorithm>
#include <string>
using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size()-1, n = b.size()-1;
        int carry = 0;
        string result;
        while(m >= 0 || n >= 0){
            int sum = carry;
            if(m >= 0)sum += a[m--] - '0';
            if(n >= 0)sum += b[n--] - '0';
            if(sum > 1){
                carry = 1;
            }else{
                carry = 0;
            }
            result += to_string(sum%2);


        }
        if(carry) result+= to_string(carry);
        reverse(result.begin(), result.end());
        return result;
    }
};