class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		//	result
		int result{ 0 };
		//	Table with special calculated value
		vector<vector<char>> table(matrix);
		//	Convert table with char codes to (0,1) values
		for (auto& row : table) {
			for (auto& el : row) {
				el -= '0';
			}
		}
		//	Building table with value:
		//		if M(i,j) = 0, then T(i,j) = 0,
		//		if M(i,j) = 1, then T(i,j) = min( T(i-1,j-1), T(i-1,j), T(i, j-1) ) + M(i,j)
		for (size_t row = 1; row < table.size(); row++) {
			for (size_t col = 1; col < table[row].size(); col++) {
				if (matrix[row][col] == '0') {
					table[row][col] = 0;
				}
				else {
					table[row][col] = min(min(table[row - 1][col - 1], table[row - 1][col]), table[row][col - 1]) + 1;
				}
			}
		}
		//	Finding maximum value in table
		for (auto& row : table) {
			result = max(result, (int)*(max_element(row.begin(), row.end())));
		}

		return result * result;
	}
};