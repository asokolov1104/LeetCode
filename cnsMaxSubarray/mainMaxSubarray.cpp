//
#include <iostream>
#include <vector>
#include <algorithm>
//
using namespace std;
//
int maxSubArray(vector<int>& nums);
//
auto main() -> int {

	vector<int> test{ -2,1,-3,4,-1,2,1,-5,4 };
	cout << "Max sum: " << maxSubArray(test) << endl;

	vector<int> test02{ -2 };
	cout << "Max sum: " << maxSubArray(test02) << endl;

	return 0;
}
//	Divede and Conquer method
//	[Head| max(Tail)] -> max(Tail) if Head < 0
//	[Head| max(Tail)] -> Head + max(Tail) if Head >= 0
int maxSubArray(vector<int>& nums)
{
	//if (nums.size() == 1) {
	//	return nums[0];
	//}
	//else {
		int maxSum{ INT_MIN };
		int localMax{ INT_MIN };
		int accum{ 0 };
		for (auto& v : nums) {
			accum += v;
			localMax = max(localMax, accum);
			if (accum < 0) {
				accum = 0;
				maxSum = max(maxSum, localMax);
			}
		}
		maxSum = max(maxSum, localMax);

		//for (size_t idx = 0; idx < n_len; ++idx) {
		//	accum += nums[idx];
		//	localMax = max(localMax, accum);
		//	if (accum < 0) {
		//		accum = 0;
		//	}
		//	//else {
		//	//	localMax = max(localMax, accum);
		//	//}
		//	maxSum = max(maxSum, localMax);
		//}
		return maxSum;
	//}
}

////	Brute force method
////int maxSubArray(vector<int>& nums) {
////
////	if (nums.size() == 0) {
////		return 0;
////	}
////
////	int maxSum{ INT_MIN };
////	int idxBegin{ -1 };
////	int idxEnd{ -1 };
////	//	For each element in array
////	//	we calclulate sum of each subarray (starting with len 1 till end)
////	for (size_t idx1 = 0; idx1 < nums.size(); ++idx1) {
////		int sum{ 0 };
////		for (size_t idx2 = idx1; idx2 < nums.size(); ++idx2) {
////			sum += nums[idx2];
////			if (maxSum < sum) {
////				maxSum = sum;
////				idxBegin = idx1;
////				idxEnd = idx2;
////			}
////			//maxSum = max(maxSum, sum);
////		}
////	}
////	//
////	printf("Begin:%2d, End:%2d\n", idxBegin, idxEnd);
////	printf("v = [");
////	for (int idx = idxBegin; idx <= idxEnd; ++idx) {
////		printf(" %d,", nums[idx]);
////	}
////	printf("]\n");
////
////	return maxSum;
////}
//