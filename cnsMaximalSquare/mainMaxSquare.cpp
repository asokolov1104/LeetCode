//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//
int maximalSquare(vector<vector<char>>& matrix);
void print2Dmatrix(vector<vector<char>>& matrix);
//
auto main() -> int
{
	// Test data: [] -> 0
	vector<vector<char>> test01{ };
	// Test data: [0] -> 0
	vector<vector<char>> test02{ {'0'} };
	// Test data: [1] -> 1
	vector<vector<char>> test03{ {'1'} };
	// Test data: [0 0 0] -> 0
	vector<vector<char>> test04{ {'0', '0', '0'} };
	// Test data: [0 1 0] -> 1
	vector<vector<char>> test05{ {'0', '1', '0'} };
	// Test data: [0 0]
	//            [0 0] -> 0
	vector<vector<char>> test06{ {'0','0'},{'0','0'} };
	// Test data: [0 0]
	//            [0 1] -> 1
	vector<vector<char>> test07{ {'0','0'},{'0','1'} };
	// Test data: [1 1]
	//            [0 1] -> 1
	vector<vector<char>> test08{ {'1','1'},{'0','1'} };
	// Test data: [1 1]
	//            [1 1] -> 4
	vector<vector<char>> test09{ {'1','1'},{'1','1'} };
	// Test data: [0 1 1]
	//            [0 1 1] -> 4
	vector<vector<char>> test10{ {'0','1','1'},{'0','1','1'} };
	// Test data: [1 0 1 0 0]
	//            [1 0 1 1 1]
	//            [1 1 1 1 1]
	//            [1 0 0 1 0] -> 4
	vector<vector<char>> test11{ {'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'} };
	//
	cout << "Test 01 result = " << maximalSquare(test01) << endl;
	cout << "Test 02 result = " << maximalSquare(test02) << endl;
	cout << "Test 03 result = " << maximalSquare(test03) << endl;
	cout << "Test 04 result = " << maximalSquare(test04) << endl;
	cout << "Test 05 result = " << maximalSquare(test05) << endl;
	cout << "Test 06 result = " << maximalSquare(test06) << endl;
	cout << "Test 07 result = " << maximalSquare(test07) << endl;
	cout << "Test 08 result = " << maximalSquare(test08) << endl;
	cout << "Test 09 result = " << maximalSquare(test09) << endl;
	cout << "Test 10 result = " << maximalSquare(test10) << endl;
	cout << "Test 11 result = " << maximalSquare(test11) << endl;

	//
	return 0;
}

int maximalSquare(vector<vector<char>>& matrix)
{
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
	//	Printing table
	print2Dmatrix(table);
	//	Finding maximum value in table
	for (auto& row : table) {
		result = max(result, (int)*(max_element(row.begin(), row.end())));
	}
	
	return result * result;
}

void print2Dmatrix(vector<vector<char>>& matrix)
{
	if (matrix.empty()) {
		cout << "empty" << endl;
	}
	else {
		for (auto& row : matrix) {
			for (auto& el : row) {
				cout << (int)el << ' ';
			}
			cout << endl;
		}
	}
}