/* 
Explanation of the algorithm:
1. The program calculates the square root of a number using the Newton-Raphson method.
2. The function `method_Newton_Rapson`:
   - Takes a number and an epsilon value (precision) as input.
   - Starts with an initial guess for the square root.
   - Iteratively refines the guess using the formula: `next_guess = current_guess - (function / derivativeFunction)`.
   - Stops when the difference between the guess squared and the number is within the epsilon range.
3. The main function:
   - Calls `method_Newton_Rapson` with a test number and precision.
   - Prints the calculated square root.
*/

#include <iostream>

double method_Newton_Rapson(int number, double epsilon){
    if(number < 0){
        std::cout << "Cannot calculate square root of a negative number (in real numbers)" << std::endl;
        return -1;
    }   else if(number == 0){
        return 0;
    }

    double current_guess = (double)number / 2;

    while(true){
        double function = current_guess * current_guess - number;

        if(function >= -epsilon && function < 0){
            return current_guess;
        }   else if(function <= epsilon && function > 0){
            return current_guess;
        }
        
        double derivativeFunction = 2 * current_guess;

        if(derivativeFunction == 0){
            std::cout << "Devision by zero. Try different initial guess";
        }

        double next_guess = current_guess - (function / derivativeFunction);

        current_guess = next_guess;
    }
}

int main(){
    std::cout << "Sqare root = " << method_Newton_Rapson(2, 0.0000001) << std::endl;
    return 0;
}