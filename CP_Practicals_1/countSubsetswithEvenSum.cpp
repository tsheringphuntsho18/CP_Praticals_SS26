#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements (N): ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Total number of subsets = 2^n
    int totalSubsets = (1 << n);
    int evenSumCount = 0;
    
    // Iterate through all possible bitmasks from 0 to 2^n - 1
    for (int mask = 0; mask < totalSubsets; mask++) {
        int sum = 0;
        
        // Check each bit position and calculate sum of subset
        for (int i = 0; i < n; i++) {
            // If the i-th bit is set in mask, include arr[i] in sum
            if (mask & (1 << i)) {
                sum += arr[i];
            }
        }
        
        // Check if sum is even
        if (sum % 2 == 0) {
            evenSumCount++;
        }
    }
    
    cout << "Number of subsets with even sum: " << evenSumCount << endl;
    
    return 0;
}
