# CP-Data-Structures
Some data structures that I use in competitive programming

## Trees
 - [Segment Tree](https://github.com/David1425/CP-Data-Structures/blob/main/README.md#segment-tree---segment_treecpp)

### Segment Tree - [segment_tree.cpp](https://github.com/David1425/CP-Data-Structures/blob/main/Trees/segment_tree.cpp)

| Class Functions | Descriptions |
|-----------------|--------------|
| .setCalc(func) | sets what this segment tree does, defaults to min(a, b) for range minimum queries |
| .setBase(val) | sets what the base case is if outside of query range, defaults to 2e9 for range minimum queries |
| .build(vector) | initializes segment tree with a starting list of values |
| .update(index, value) | updates the element at index(starting at 0) to value |
| .query(left, right) | returns the answer to the query with range [left, right]|

