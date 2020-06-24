//56. 合并区间
//
//	给出一个区间的集合，请合并所有重叠的区间。
//
//示例 1:
//
//输入: [[1,3],[2,6],[8,10],[15,18]]
//输出: [[1,6],[8,10],[15,18]]
//解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
//
//示例 2:
//
//输入: [[1,4],[4,5]]
//输出: [[1,5]]
//解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。


#include <vector>
#include <algorithm>
#include "../unitTest/doctest.h"

using namespace std;

class Solution
{
public:
	vector<vector<int>> merge(vector<vector<int>> &intervals)
	{
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

TEST_CASE ("merge")
{
	Solution solution;
	vector<vector<int>> vec_in = {{2, 6}, {1, 3}, {8, 10}, {15, 18}};
	vector<vector<int>> vec_out = {{1, 6}, {8, 10}, {15, 18}};
	CHECK(solution.merge(vec_in) == vec_out);
}

