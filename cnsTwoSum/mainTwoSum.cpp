//
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;
//
void printResult(vector<int> result) {
	for (auto& v : result) {
		cout << v << ' ';
	}
	cout << endl;
}
//	Solve problem via hash-map
vector<int> twoSum(vector<int>& nums, int target);
//
auto main() -> int
{
	if (false)
	{
		//	given array of integers
		vector<int> givenArray{ 2, 7, 11, 15 };
		cout << "Given array: ";
		for (auto& x : givenArray)
			cout << x << " ";
		cout << endl;

		//	specific target
		int target = 22;
		cout << "target: " << target << endl;

		//	two indices
		int idx1{ 0 }, idx2{ 0 };

		//	problem solution class
		class Solution {
		public:
			vector<int> twoSum(vector<int>& nums, int target) {
				vector<int> res;
				//	size() - Returns the number of elements in the vector
				//	operator[] - Returns a reference to the vector element at a specified position
				for (size_t j = 0; j < (nums.size() - 1); j++)
					for (size_t i = (j + 1); i < nums.size(); i++)
						if ((nums[j] + nums[i]) == target)
						{
							res.push_back(j);
							res.push_back(i);
							return res;
						};
				return res;
			}
		} task;

		vector<int> result = task.twoSum(givenArray, target);

		if (!result.empty())
		{
			idx1 = result[0];
			idx2 = result[1];
		}

		//	print solution
		cout << "nums[" << idx1 << "] + nums[" << idx2 << "] = ";
		cout << givenArray[idx1] << " + " << givenArray[idx2] << " = " << givenArray[idx1] + givenArray[idx2];
		cout << endl;

	}

	//	Testing hash-map approach
	{
		// Test data: [3, 3], target = 6 -> [0,1]
		vector<int> test01{ 3, 3 };
		int target01 = 6;

		// Test data: [3, 2, 4], target = 6 -> [1,2]
		vector<int> test02{ 3, 2, 4 };
		int target02 = 6;

		// Test data: [2, 7, 11, 15], target = 9 -> [0,1]
		vector<int> test03{ 2, 7, 11, 15 };
		int target03 = 9;

		//
		printResult(twoSum(test01, target01));
		printResult(twoSum(test02, target02));
		printResult(twoSum(test03, target03));
	}

	return 0;
}
//
vector<int> twoSum(vector<int>& nums, int target)
{
	typedef unordered_map<int, int> myHashMap;
	myHashMap hashMap;	//	declare hash-map variable
	myHashMap::iterator iter;
	int delta{ 0 };	//	delta value between target and cur value
	for (int i = 0; i < (int)nums.size(); i++) {
		delta = target - nums[i];
		iter = hashMap.find(delta);
		if ( iter != hashMap.cend() ) {
			return vector<int>({ iter->second, i });
		}
		hashMap[nums[i]] = i;
	}
	return vector<int>{};
}