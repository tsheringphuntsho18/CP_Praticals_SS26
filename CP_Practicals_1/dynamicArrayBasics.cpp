#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;

    // Step 1: Read the number of elements
    cout << "Enter the number of elements: ";
    cin >> N;

    // Step 2: Create a dynamic container (vector)
    vector<int> numbers(N);

    // Step 3: Read N integers
    cout << "Enter " << N << " integers:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    // Initialize max, min, and sum
    int max = numbers[0];
    int min = numbers[0];
    int sum = 0;

    // Step 4: Find maximum, minimum, and sum
    for (int i = 0; i < N; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }

        if (numbers[i] < min) {
            min = numbers[i];
        }

        sum += numbers[i];
    }

    // Step 5: Print results
    cout << "Maximum element: " << max << endl;
    cout << "Minimum element: " << min << endl;
    cout << "Sum of elements: " << sum << endl;

    return 0;
}