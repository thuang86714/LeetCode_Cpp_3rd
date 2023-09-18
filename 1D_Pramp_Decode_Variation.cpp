#include <iostream>
#include <string>
#include <vector>
using namespace std;

int decodeVariations(const string& S)
{
	// your code goes here
  //dp
  int size = S.size();
  vector<int> dp(size+1);
  //base case
  dp[size] = 1;
  for(int i = size-1; i >= 0; i--){
    if(S[i] == '0'){
      dp[i] = 0;
    }else if(S[i] == '1'){
      dp[i] = dp[i + 1] + dp[i + 2];
    }else if(S[i] == '2'){
      dp[i] = dp[i + 1];
      if(i != size -1 && S[i + 1] < '7'){
        dp[i] += dp[i + 2];
      }
    }else{
      dp[i] = dp[i + 1];
    }
  }
  return dp[0];
}

int main() 
{
	return 0;
}
