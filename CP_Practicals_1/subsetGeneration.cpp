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
    
    cout << "\nAll possible subsets:" << endl;
    
    // Iterate through all possible bitmasks from 0 to 2^n - 1
    for (int mask = 0; mask < totalSubsets; mask++) {
        cout << "{";
        
        bool first = true;
        
        // Check each bit position
        for (int i = 0; i < n; i++) {
            // If the i-th bit is set in mask, include arr[i]
            if (mask & (1 << i)) {
                if (!first) {
                    cout << " ";
                }
                cout << arr[i];
                first = false;
            }
        }
        
        cout << "}" << endl;
    }
    
    return 0;
}
