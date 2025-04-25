#include<bits/stdc++.h>
using namespace std;

// First occurrence or previous smaller element
int findFirstOccurrenceOrPrevSmaller(vector<int>& v, int target) {
    if (v.empty()) return -1;
    
    int l = -1;                  // Just before first valid index
    int r = v.size() - 1;        // Last valid index
    
    // Maintain invariants: v[l] < target and v[r] >= target
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (v[m] >= target) r = m;   // Found candidate for first occurrence
        else l = m;                  // Too small
    }
    
    // If r contains the target, return first occurrence
    if (r >= 0 && r < v.size() && v[r] == target) return r;
    
    // Target not found, return previous smaller element (l)
    if (l >= 0 && l < v.size()) return l;
    
    return -1;  // No smaller element exists
}

// Last occurrence or next greater element
int findLastOccurrenceOrNextGreater(vector<int>& v, int target) {
    if (v.empty()) return -1;
    
    int l = 0;                   // First valid index
    int r = v.size();            // Just after last valid index
    
    // Maintain invariants: v[l] <= target and v[r] > target
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (v[m] <= target) l = m;   // Found candidate for last occurrence
        else r = m;                  // Too large
    }
    
    // If this is the target, return its index
    if (v[l] == target) return l;
    
    // Target not found, return next greater element (r)
    if (r < v.size()) return r;
    
    return -1;  // No greater element exists
}

int main() {
    vector<int> v{2, 3, 4, 6, 8, 8, 8, 9, 10};
    int target = 5;
    
    cout<<findFirstOccurrenceOrPrevSmaller(v,target)<<endl;
    cout<<findLastOccurrenceOrNextGreater(v,target)<<endl;
    return 0;
}


// I'm writing binary search in this way: if you want to find the lowest x
//  satisfying f(x)
// :

// int l=lowest_possible_value-1,r=highest_possible_value,m;
// while(r-l>1)
// {
//     m=l+(r-l)/2;if(f(m))r=m;else l=m;
// }
// return r;
// and vice versa if you want to find the highest x
//  satisfying g(x)
// :

// int l=lowest_possible_value,r=highest_possible_value+1,m;
// while(r-l>1)
// {
//     m=l+(r-l)/2;if(g(m))l=m;else r=m;
// }
// return l;