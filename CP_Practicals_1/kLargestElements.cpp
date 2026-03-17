#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cout << "Enter the number of elements (N): ";
    cin >> n;
    cout << "Enter K (number of largest elements to find): ";
    cin >> k;
    
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Validate K
    if (k > n || k <= 0) {
        cout << "Invalid K! K should be between 1 and " << n << endl;
        return 1;
    }
    
    // Create a max heap (priority_queue by default is a max heap)
    priority_queue<int> maxHeap;
    
    // Insert all elements into the max heap
    for (int i = 0; i < n; i++) {
        maxHeap.push(arr[i]);
    }
    
    // Extract and print K largest elements
    cout << "Output: ";
    for (int i = 0; i < k; i++) {
        cout << maxHeap.top();
        maxHeap.pop();
        if (i < k - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}
