# Algorithmes

This repository contains implementations of various algorithms written in C++. Each algorithm is stored in its own file and is accompanied by an explanation of how it works.

## List of Algorithms

### Sorting Algorithms
- **Bubble Sort** (`boubleSort.cpp`): Sorts an array by repeatedly swapping adjacent elements if they are in the wrong order.
- **Quick Sort** (`quickSort.cpp`): A divide-and-conquer algorithm that sorts an array using partitioning.
- **Merge Sort** (`mergeSort.cpp`): A divide-and-conquer algorithm that merges sorted subarrays.
- **Insertion Sort** (`insertionSort.cpp`): Sorts an array by inserting elements into their correct position.
- **Selection Sort** (`selectionSort.cpp`): Sorts an array by repeatedly selecting the smallest element from the unsorted portion.
- **Counting Sort** (`countingSort.cpp`): Sorts an array by counting occurrences of each element.

### Searching Algorithms
- **Binary Search** (`binarySearch.cpp`): Searches for an element in a sorted array using a divide-and-conquer approach.
- **Linear Search with Sentinel** (`linearSearchSentinel.cpp`): Linear search using a sentinel to simplify termination checks.

### Mathematical Algorithms
- **Euclidean Algorithm** (`euklides.cpp`): Calculates the GCD and LCM of two numbers.
- **Fast Exponentiation** (`fastExponentiation.cpp`): Computes powers efficiently using divide-and-conquer.
- **Prime Factorization** (`primeFactorization.cpp`): Finds the prime factors of a number.
- **Sieve of Eratosthenes** (`eratosthenesSieve.cpp`): Finds all prime numbers up to a given limit.
- **Fibonacci Sequence** (`Fibonacci.cpp`): Generates the Fibonacci sequence up to a specified number of terms.
- **Perfect Number Check** (`isPerfect.cpp`): Checks if a number is a perfect number.
- **Prime Number Check** (`isPrime.cpp`): Checks if a number is a prime number.

### Graph Algorithms
- **Kruskal's Algorithm** (`Kruskal.cpp`): Finds the Minimum Spanning Tree (MST) of a graph.

### String Algorithms
- **Palindrome Checking** (`palindromeChecking.cpp`): Checks if a string is a palindrome.
- **Pattern Searching** (`patternSearching.cpp`): Finds occurrences of a pattern in a text.
- **Anagram Generation** (`anagramGeneration.cpp`): Generates all possible anagrams of a string.

### Cipher Algorithms
- **Caesar Cipher** (`cezar.cpp`): Implements the Caesar cipher for encryption and decryption.
- **Vernam Cipher** (`vernam.cpp`): Implements the Vernam cipher for encryption and decryption.
- **Columnar Transposition Cipher** (`columnCipher.cpp`): Implements the columnar transposition cipher.

### Miscellaneous Algorithms
- **Gray Code Conversion** (`gray.cpp`): Converts binary numbers to Gray code.
- **Leader Tournament** (`LeaderTournament.cpp`): Finds the leader (majority element) in an array using the tournament method.
- **Triangle Inequality Check** (`triangleInequality.cpp`): Checks if three side lengths can form a triangle.
- **Reverse Polish Notation (RPN)** (`RPN.cpp`): Evaluates mathematical expressions written in RPN.
- **Power Set Generation** (`powerSet.cpp`): Generates all subsets of a given set.
- **Combination Generation** (`creatingCombinations.cpp`): Generates all combinations of a given set.
- **Permutation Counting** (`permutationCounting.cpp`): Generates all permutations of a given set and counts them.
- **Most Frequent Element** (`mostFrequent.cpp`): Finds the most frequent element in an array.
- **Number System Conversion** (`Convertion.cpp`): Converts numbers between decimal, binary, octal, and hexadecimal.

## How to Run

1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd Algorithmes

2. To compile a C++ file, use the following command:
    ```bash
    g++ filename.cpp -o output
    ```
    Replace `filename.cpp` with the name of the algorithm file you want to compile, and `output` with the desired name for the executable.
