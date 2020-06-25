//57. 插入区间
//
//	给出一个无重叠的 ，按照区间起始端点排序的区间列表。
//
//在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
//
//示例 1:
//
//输入: intervals = [[1,3],[6,9]], newInterval = [2,5]
//输出: [[1,5],[6,9]]
//
//示例 2:
//
//输入: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
//输出: [[1,2],[3,10],[12,16]]
//解释: 这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。

#include <vector>
#include <algorithm>
#include "../unitTest/doctest.h"

using namespace std;

class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

		intervals.push_back(newInterval);
		sort(intervals.begin(), intervals.end());

		vector<vector<int>> result;
		for (auto &i : intervals) {
			if (result.empty() || i[0] > result.back()[1]) {
				result.push_back(i);
			}
			else {
				result.back()[1] = max(i[1], result.back()[1]);
			}
		}
		return result;
	}
};

TEST_CASE ("insert")
{
	Solution solution;
	vector<vector<int>> vec_in1 = {{1,2},{3,5},{6,7},{8,10},{12,16}};
	vector<int> vec_in2 = {4,8};
	vector<vector<int>> vec_out = {{1,2},{3,10},{12,16}};
	CHECK(solution.insert(vec_in1, vec_in2) == vec_out);
}


