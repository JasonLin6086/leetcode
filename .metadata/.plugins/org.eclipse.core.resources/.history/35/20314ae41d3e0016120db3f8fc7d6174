/*
 * mergeintervals.cpp
 *
 *  Created on: Jun 29, 2016
 *      Author: jason
 */
#include <iostream>
#include <vector>
#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <deque>
//#include <stack>
//#include <unordered_map>
//#include <set>
//#include <string>
//#include <unordered_set>
//#include <climits>

using namespace std;

/**
 * Definition of Interval:
 */
class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

bool myfunction (Interval a, Interval b) { return a.start < b.start; }

class Solution {
public:


    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        int size = intervals.size();
        vector<Interval> result;
        if (size == 0) return result;
        if (size == 1) return intervals;
        int i;
        sort(intervals.begin(), intervals.end(), myfunction);
        result.push_back(intervals[0]);
        for (i=1; i<size; i++) {
            Interval &prev = result.back();
            if (intervals[i].start <= prev.end) {
                prev.end = max(intervals[i].end, prev.end);
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};

int main()
{
	Solution s;
	vector<Interval> intervals;
	intervals.push_back(Interval(1,3));
	intervals.push_back(Interval(2,6));
	intervals.push_back(Interval(8,10));
	intervals.push_back(Interval(15,18));
	vector<Interval> result = s.merge(intervals);
	for (unsigned int i=0; i<result.size(); i++) {
		cout<<result[i].start<<":"<<result[i].end<<endl;
	}
	return 0;
}



