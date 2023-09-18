#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        //1 <= num <= 3999
        vector<string> thou = {"", "M", "MM", "MMM"};
        vector<string> hund = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> ones = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return thou[num/1000] + hund[num%1000/100] + tens[num%100/10] + ones[num%10];
    }
};