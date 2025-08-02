/* 
Explanation of the algorithm:
1. The program finds the leader (majority element) in an array using the tournament method.
2. The function `findLeaderTournament`:
   - Iteratively reduces the array size by comparing pairs of elements.
   - Retains elements that are equal and discards others.
   - Returns the potential leader after all rounds.
3. The function `isLeader`:
   - Checks if the candidate leader appears more than half the time in the array.
4. The main function:
   - Reads the array from the user.
   - Calls `findLeaderTournament` to find the candidate leader.
   - Calls `isLeader` to verify if the candidate is the actual leader.
   - Outputs the result.
*/

#include <iostream>
#include <string>
using namespace std;

int findLeaderTournament(int arr[], int n) {
    int current[1000];
    int size = n;
    for (int i = 0; i < n; i++) current[i] = arr[i];

    while (size > 1) {
        int nextRound[1000];
        int nextSize = 0;
        for (int i = 0; i + 1 < size; i += 2) {
            if (current[i] == current[i + 1]) {
                nextRound[nextSize++] = current[i];
            }
        }
        if (size % 2 == 1) {
            nextRound[nextSize++] = current[size - 1];
        }
        for (int i = 0; i < nextSize; i++) current[i] = nextRound[i];
        size = nextSize;
    }

    if (size == 0) return -1;
    return current[0];
}

bool isLeader(int arr[], int n, int candidate) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate) count++;
    }
    return count > n / 2;
}

int main() {
    string line;
    getline(cin, line);

    int arr[1000];
    int n = 0;
    string num = "";
    for (size_t i = 0; i <= line.size(); i++) {
        if (i == line.size() || line[i] == ' ') {
            if (num != "") {
                arr[n++] = stoi(num);
                num = "";
            }
        } else {
            num += line[i];
        }
    }

    int candidate = findLeaderTournament(arr, n);
    if (candidate == -1) {
        cout << "No leader found" << endl;
    } else if (isLeader(arr, n, candidate)) {
        cout << "Leader: " << candidate << endl;
    } else {
        cout << "No leader found" << endl;
    }

    return 0;
}
