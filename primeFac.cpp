#include <iostream>
#include <stack>
using namespace std;

int main() {
    int inputNumber;
    cout << "Enter a number: ";
    cin >> inputNumber;
    
    if (inputNumber < 2) {
        cout << "No prime factors for numbers less than 2." << endl;
        return 0;
    }

    stack<int> primeStack;
    
    // Find prime factors and push them onto the stack
    for (int divisor = 2; divisor <= inputNumber; divisor++) {
        while (inputNumber % divisor == 0) {
            primeStack.push(divisor);  // Push each factor into the stack
            inputNumber /= divisor;
        }
    }

    // To store factors in descending order with their powers
    stack<pair<int, int>> factorCounts;
    if (!primeStack.empty()) {
        int currentFactor = primeStack.top();
        int count = 0;

        // Process factors from top to bottom, counting occurrences of each
        while (!primeStack.empty()) {
            int nextFactor = primeStack.top();
            primeStack.pop();

            if (nextFactor == currentFactor) {
                count++;
            } else {
                factorCounts.push({currentFactor, count});
                currentFactor = nextFactor;
                count = 1;
            }
        }
        factorCounts.push({currentFactor, count});
    }

    // Display the result in descending order
    cout << "Prime factorization in descending order: ";
    bool isFirst = true;
    while (!factorCounts.empty()) {
        auto factorPair = factorCounts.top();
        factorCounts.pop();

        if (!isFirst) cout << "*";
        cout << factorPair.first;
        if (factorPair.second > 1) cout << "^" << factorPair.second;
        isFirst = false;
    }
    cout << endl;

    return 0;
}
