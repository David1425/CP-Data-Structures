# CP-Data-Structures
Some data structures that I use in competitive programming

## Trees
 - Segment Tree

### Segment Tree - [segment_tree.cpp](https://github.com/David1425/CP-Data-Structures/blob/main/Trees/segment_tree.cpp)
You can modify what the segment tree does inside the `calc()` function by using. You can also set a base case (for when searching range is outside the query range) inside the `base()` function. The default is set to range minimum queries (however if the constraints are big, you might want to use LONG_MAX instead of INT_MAX in the `base()` function). See table of functions below for changing `calc` and `base`.

| Class Functions | Descriptions |
|-----------------|--------------|
| .setCalc(func) | sets what this segment tree does, defaults to min(a, b) for range minimum queries |
| .setBase(func) | sets what is the base case if , defaults to INT_MAX for range minimum queries |
| .build(vector) | initializes segment tree with a starting list of values |
| .update(index, value) | updates the element at index(starting at 0) to value |
| .query(left, right) | returns the answer to the query with range [left, right]|

Usage:
```cpp
#include <bits/stdc++.h>

using namespace std;

// Copy everything from segment_tree.cpp(link above) to here
class segment_tree {
    ... // Leave everything in the class the same
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = arr.size();
    
    segment_tree RMQ(n); // create segment tree with n leaf nodes
    // As an example, I will change this segment tree to calculate range sum queries
    RMQ.setCalc([](int a, int b){ return a+b; });
    RMQ.setBase([](){ return 0; });
    
    RMQ.build(arr); // initializes the segment tree from the original vector
    
    // update value at index
    int ind = 3, val = 10;
    RMQ.update(ind, val);
    
    // query range
    int left = 0, right = 4;
    cout << RMQ.query(left, right) << endl;
    
    return 0;
}

```
