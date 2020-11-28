//
#include <vector>
using namespace std;
//
class Solution {
public:
	virtual int maxTurbulenceSize(vector<int>& A) = 0;
};
//
class Solution1 : public Solution {
public:
	int maxTurbulenceSize(vector<int>& A)
	{
		return 0;
	}
};

//
auto main() -> int {
	return 0;
}