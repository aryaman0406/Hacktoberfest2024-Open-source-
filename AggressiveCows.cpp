#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if it's possible to place cows with at least 'minDist' distance
bool canPlaceCows(vector<int>& stalls, int n, int cows, int minDist) {
    int count = 1; // Place the first cow in the first stall
    int lastPosition = stalls[0]; // Track the position of the last placed cow

    for (int i = 1; i < n; i++) {
        // Place next cow if the distance between this stall and the last placed cow is at least 'minDist'
        if (stalls[i] - lastPosition >= minDist) {
            count++;
            lastPosition = stalls[i];
            if (count == cows) {
                return true;
            }
        }
    }
    return false;
}

// Function to find the largest minimum distance using binary search
int largestMinDistance(vector<int>& stalls, int n, int cows) {
    sort(stalls.begin(), stalls.end()); // Sort the stall positions

    int low = 1; // Minimum possible distance (smallest value)
    int high = stalls[n - 1] - stalls[0]; // Maximum possible distance

    int result = 0; // To store the result

    // Binary search for the largest minimum distance
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, n, cows, mid)) {
            result = mid; // Store the mid as a valid result
            low = mid + 1; // Try to find a larger distance
        } else {
            high = mid - 1; // Try to find a smaller distance
        }
    }
    return result;
}

int main() {
    // Input: Number of stalls and number of cows
    int n = 5; // Number of stalls
    int cows = 3; // Number of cows
    vector<int> stalls = {1, 2, 8, 4, 9}; // Stall positions

    cout << "Largest minimum distance: " << largestMinDistance(stalls, n, cows) << endl;
    
    return 0;
}
