//67. 二进制求和
//
//	给你两个二进制字符串，返回它们的和（用二进制表示）。
//
//输入为 非空 字符串且只包含数字 1 和 0。
//
//
//
//示例 1:
//
//输入: a = "11", b = "1"
//输出: "100"
//
//示例 2:
//
//输入: a = "1010", b = "1011"
//输出: "10101"
//
//
//
//提示：
//
//每个字符串仅由字符 '0' 或 '1' 组成。
//1 <= a.length, b.length <= 10^4
//字符串如果不是 "0" ，就都不含前导零。
//


#include <vector>
#include <string>
#include "../unitTest/doctest.h"

using namespace std;

class Solution
{
public:
	string addBinary(string a, string b)
	{
		int la = a.size();
		int lb = b.size();
		if (la < lb) {
			swap(a, b);
			swap(la, lb);
		}
		if (la - lb > 0)
			b.insert(0, la - lb, '0');
		int pre = 0, cur = 0;
		string res;
		for (int i = la - 1; i >= 0; i--) {
			int ia = a[i] - '0';
			int ib = b[i] - '0';
			cur = ia ^ ib ^ pre;  // 二进制数相加结果与异或结果相同
			if (ia + ib + pre >= 2) pre = 1;
			else pre = 0;
			res.insert(0, 1, cur + '0');
		}
		if (pre)  // 最高位的进位单独处理
			res.insert(0, 1, pre + '0');
		return res;
	}
};

TEST_CASE ("addBinary")
{
	Solution solution;
	CHECK(solution.addBinary("1010", "1011") == "10101");
}


