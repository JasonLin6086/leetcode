/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
using IT = vector<NestedInteger>::const_iterator;
class NestedIterator {
private:
    stack<pair<IT,IT>> depth;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Initialize your data structure here.
        depth.emplace(nestedList.begin(),nestedList.end());
    }

    // @return {int} the next element in the iteration
    int next() {
        // Write your code here
        return (depth.top().first++)->getInteger();
    }

    // @return {boolean} true if the iteration has more element or false
    bool hasNext() {
        // Write your code here
        while (!depth.empty()) {
            auto& cur = depth.top();
            if (cur.first == cur.second) {
                depth.pop();
            } else if (cur.first->isInteger()) {
                return true;
            } else {
                auto& nestedList = cur.first->getList();
                cur.first++;
                depth.emplace(nestedList.begin(), nestedList.end());
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) v.push_back(i.next());
 */
