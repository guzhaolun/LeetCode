#include <vector>
#include <algorithm>
using namespace std;

//Definition for an interval.
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
	
};

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
	{
		vector<Interval> res;
		if (intervals.empty())
			return res;
		//Interval temp = intervals[0];
		if (newInterval.end < intervals[0].start)
		{
			intervals.insert(intervals.begin(), newInterval);
			return intervals;
		}
		int i = 0;
		for (; i < intervals.size(); i++)
		{
			if (newInterval.end < intervals[i].start)
			{
				res.push_back(newInterval);
				break;
			}
			if (newInterval.start < intervals[i].end||newInterval.end<=intervals[i].end)
			{
				newInterval.start = min(newInterval.start, intervals[i].start);
				newInterval.end = max(newInterval.end, intervals[i].end);
				continue;
			}
			
			res.push_back(intervals[i]);
		}
		for (int j = i; j < intervals.size(); j++)
			res.push_back(intervals[j]);
		return res;
	}
};