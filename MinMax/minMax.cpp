#include <iostream>

int main() {
    const int MAX_SIZE = 1000;
    int array[MAX_SIZE];
    int size;

    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    if (size <= 0 || size > MAX_SIZE) {
        std::cout << "Invalid array size!" << std::endl;
        return 1;
    }

    std::cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; i++) {
        std::cin >> array[i];
    }

    // INITIALIZE min and max to first element
    int minimum = array[0];
    int maximum = array[0];

    // FIND MIN and MAX
    for (int i = 1; i < size; i++) {
        if (array[i] < minimum) {
            minimum = array[i];
        }
        if (array[i] > maximum) {
            maximum = array[i];
        }
    }

    std::cout << "\nMinimum value: " << minimum << std::endl;
    std::cout << "Maximum value: " << maximum << std::endl;

    // FIND SECOND MAXIMUM
    int secondMaximum = array[0];
    bool found = false;

    for (int i = 0; i < size; i++) {
        if (array[i] != maximum) {
            if (!found || array[i] > secondMaximum) {
                secondMaximum = array[i];
                found = true;
            }
        }
    }

    if (found) {
        std::cout << "Second maximum: " << secondMaximum << std::endl;
    } else {
        std::cout << "No second maximum found (all elements are equal)." << std::endl;
    }

    return 0;
}
