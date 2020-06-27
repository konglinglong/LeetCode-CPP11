//93. 复原IP地址
//
//	给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
//
//有效的 IP 地址正好由四个整数（每个整数位于 0 到 255 之间组成），整数之间用 '.' 分隔。
//
//
//
//示例:
//
//输入: "25525511135"
//输出: ["255.255.11.135", "255.255.111.35"]

#include <vector>
#include <string>
#include <algorithm>
#include "../unitTest/doctest.h"

using namespace std;

class Solution
{
public:
	vector<string> restoreIpAddresses(string s)
	{
		vector<string> res;
		string tmp = "";
		backtrack(s, res, tmp, 0);
		return res;
	}
	void backtrack(string s, vector<string> &res,
				   string tmp, int n)
	{
		if (s.size() > 3 * (4 - n)) return;
		if (n == 4 && s.size() == 0) {
			tmp.pop_back(); //去掉最后的'.'
			res.push_back(tmp);
		}
		for (int i = 1; i <= 3; i++) {
			if (s.size() < i) break;
			int val = stoi(s.substr(0, i));
			if (i != to_string(val).size()) break;
			if (val > 255) break;

			tmp += s.substr(0, i) + '.';
			backtrack(s.substr(i), res, tmp, n + 1);
			tmp = tmp.substr(0, tmp.size() - i - 1);
		}
	}
};

TEST_CASE ("restoreIpAddresses")
{
	Solution solution;
	vector<string> vec_out = {"255.255.11.135", "255.255.111.35"};
	CHECK(solution.restoreIpAddresses("25525511135") == vec_out);
}
