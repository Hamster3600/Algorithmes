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
    std::cout << "Sqare root = " << method_Newton_Rapson(25, 0.0000001);
    return 0;
}