//
#include <vector>
#include <iostream>
using namespace std;
//
auto main() -> int
{
	//	given array of integers
	vector<int> givenArray{ 2, 7, 11, 15 };
	cout << "Given array: ";
	for (auto &x : givenArray)
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

	return 0;
}