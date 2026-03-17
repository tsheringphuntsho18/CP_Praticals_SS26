#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

vector<double> runningMedian(vector<int>& a) {
    vector<double> result;
    
    // Max heap for lower half (stores smaller elements)
    priority_queue<int> maxHeap;
    
    // Min heap for upper half (stores larger elements)
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int num : a) {
        // Add to appropriate heap
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        
        // Balance the heaps
        // Ensure maxHeap has at most one more element than minHeap
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        
        // Ensure minHeap doesn't have more elements than maxHeap
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        
        // Calculate median
        double median;
        if (maxHeap.size() == minHeap.size()) {
            // Even number of elements
            median = (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            // Odd number of elements
            median = maxHeap.top();
        }
        
        result.push_back(median);
    }
    
    return result;
}

int main() {
    int n;
    cout << "Enter the number of integers: ";
    cin >> n;
    
    vector<int> a(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<double> medians = runningMedian(a);
    
    cout << "\nRunning Medians:" << endl;
    cout << fixed << setprecision(1);
    for (double median : medians) {
        cout << median << endl;
    }
    
    return 0;
}
