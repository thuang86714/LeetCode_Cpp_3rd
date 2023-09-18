#include <iostream>
#include <cmath>
using namespace std;

double root(double x, unsigned int n) 
{
  //guessing and checking 
  //Leetcode Sqrt(), not pow()
  //edge case
  if(x == 0)return 0;
  
  double l = 0, r;
  if(x > 1){
    r = x;
  }else{
    r = 1;
  }
  double mid = (l + r)/2;
  
  while(mid - l >= 0.001){
    if(pow(mid, n) > x){
      r = mid;
    }else if(pow(mid, n) < x){
      l = mid;
    }else{
      break;
    }
    mid = (l + r)/2;
  }
  return mid;
}
//Hint : you need to check the abs of your new guess - guess should be less than or equals to. 0.001
int main() {
  return 0;
}

/*
Pseudocode:

function root(x, n):
    if (x == 0):
        return 0

    lowerBound = 0
    upperBound = max(1, x)
    approxRoot = (upperBound + lowerBound) / 2

    while (approxRoot - lowerBound >= 0.001):
        if (power(approxRoot, n) > x):
            upperBound = approxRoot
        else if (power(approxRoot, n) < x):
            lowerBound = approxRoot
        else
            break

        approxRoot = (upperBound + lowerBound) / 2

    return approxRoot
    
    
    
#include <iostream>
#include <cmath> // Include the cmath header for pow function

double root(double x, int n) {
    if (x < 0 || n <= 0) {
        // Invalid input, return an error value (you can also throw an exception here)
        return -1.0;
    }

    double guess = 1.0; // Initial guess (can be any positive number)
    double epsilon = 0.001; // Error tolerance

    while (true) {
        double nextGuess = ((n - 1) * guess + x / std::pow(guess, n - 1)) / n;
        if (std::abs(nextGuess - guess) < epsilon) {
            return nextGuess; // Found an approximate root
        }
        guess = nextGuess;
    }
}

*/
//Newton Raphson