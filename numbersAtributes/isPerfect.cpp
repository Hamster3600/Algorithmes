/* 
Explanation of the algorithm:
1. The program checks whether a given number is a perfect number.
2. The main function:
   - Defines a test number.
   - Iterates through all integers less than the number to find its divisors.
   - Calculates the sum of the divisors.
   - Compares the sum with the original number to determine if it is perfect.
   - Outputs the result.
*/

#include <iostream>
using namespace std;

int main ()
{
    int n = 28, sum = 0;
    
    for(int i = 1; i < n; i++){
        if(n % i == 0)
            sum = sum + i;
    }
    
    if(sum == n)
        cout << n << " is a perfect number";
    else
        cout << n << " is not a perfect number";
    

}