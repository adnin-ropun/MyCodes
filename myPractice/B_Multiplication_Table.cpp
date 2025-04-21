#include<bits/stdc++.h>
using namespace std;

// More efficient implementation for counting values
int countLessEqual(int x, int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        count += min(x / i, n);
    }
    return count;
}

int main() {
    int n; cin >> n;
    int l = 1, r = n*n;
    int Index = (n*n + 1)/2; // Proper median position
    int ans = -1;
    
    while(l <= r) {
        int m = l + (r - l)/2;
        int count = countLessEqual(m, n);
        
        if(count >= Index) {
            ans = m; // Store the potential answer
            r = m - 1; // Continue searching in the lower half
        } else {
            l = m + 1;
        }
    }
    
    if(ans == -1) {
        cout << l << endl; // This would happen if binary search somehow fails
    } else {
        cout << ans << endl;
    }
    
    return 0;
}