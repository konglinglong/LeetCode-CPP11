//88. 合并两个有序数组
//
//	给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
//
//
//
//说明:
//
//初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
//你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
//
//
//
//示例:
//
//输入:
//nums1 = [1,2,3,0,0,0], m = 3
//nums2 = [2,5,6],       n = 3
//
//输出: [1,2,2,3,5,6]

#include <vector>
#include <algorithm>
#include "../unitTest/doctest.h"

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int last=m+n-1;
		while(n){
			if(m==0||nums1[m-1]<=nums2[n-1]){
				nums1[last--]=nums2[--n];
			}else{
				nums1[last--]=nums1[--m];
			}
		}
	}
};

TEST_CASE ("merge2")
{
	Solution solution;
	vector<int> vec_in1 = {1,2,3,0,0,0};
	vector<int> vec_in2 = {2,5,6};
	vector<int> vec_out = {1,2,2,3,5,6};
	solution.merge(vec_in1, 3, vec_in2, 3);
	CHECK(vec_in1 == vec_out);
}