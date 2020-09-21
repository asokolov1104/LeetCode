//
#include <iostream>
#include <string>
#include <stack>
#include <deque>
using namespace std;
//
int isBalanced(string& s);
string isBalancedv2(string& s);
struct TretData
{
	int iRetCode;
	size_t strLen;
	string substr;
};
TretData isBalancedv3(string& s);
//
auto main() -> int {

	// Test data: "" -> 0
	string test00{ };
	// Test data: "()" -> 0
	string test01{"()[]"};
	// Test data: "()" -> 0
	string test02{ "([])" };
	// Test data: "()" -> 0
	string test03{ "[()]" };
	// Test data: "()" -> 0
	string test04{ "[]()" };

	// Test data: "(" -> 1
	string test05{ "(" };
	// Test data: "[" -> 1
	string test06{ "[" };
	// Test data: ")" -> 2
	string test07{ ")" };
	// Test data: "]" -> 3
	string test08{ "]" };

	// Test data: ")" -> 2
	string test09{ "[)]" };
	// Test data: "(])" -> 3
	string test10{ "(])" };

	// Test data: "(abc)" -> 0
	string test11{ "(abc)" };

	// Test data: "ab(cd)" -> 0
	string test12{ "ab(cd)" };

	// Test data: "})]({" -> ({})
	string test30{ "})]({" };
	// Test data: "}](){" -> (){}
	string test31{ "}](){" };
	// Test data: "sh(dh)}" -> sh(dh)
	string test32{ "sh(dh)}a" };
	// Test data: "]h({hdb}b)[" -> infinite
	string test33{ "]h({hdb}b)[" };


	//
	/*cout << "Test 00 result = " << isBalanced(test00) << endl;
	cout << "Test 01 result = " << isBalanced(test01) << endl;
	cout << "Test 02 result = " << isBalanced(test02) << endl;
	cout << "Test 03 result = " << isBalanced(test03) << endl;
	cout << "Test 04 result = " << isBalanced(test04) << endl;

	cout << "Test 05 result = " << isBalanced(test05) << endl;
	cout << "Test 06 result = " << isBalanced(test06) << endl;
	cout << "Test 07 result = " << isBalanced(test07) << endl;
	cout << "Test 08 result = " << isBalanced(test08) << endl;

	cout << "Test 09 result = " << isBalanced(test09) << endl;
	cout << "Test 10 result = " << isBalanced(test10) << endl;

	cout << "Test 11 result = " << isBalanced(test11) << endl;
	cout << "Test 12 result = " << isBalanced(test12) << endl;*/


	cout << "Test 30 result = " << isBalancedv2(test30) << endl;
	cout << "Test 31 result = " << isBalancedv2(test31) << endl;
	cout << "Test 32 result = " << isBalancedv2(test32) << endl;
	cout << "Test 33 result = " << isBalancedv2(test33) << endl;

	cout << endl;

	cout << "Test 30 result = " << isBalancedv3(test30).iRetCode << "  " << isBalancedv3(test30).substr << endl;
	cout << "Test 31 result = " << isBalancedv3(test31).iRetCode << "  " << isBalancedv3(test31).substr << endl;
	cout << "Test 32 result = " << isBalancedv3(test32).iRetCode << "  " << isBalancedv3(test32).substr << endl;
	cout << "Test 33 result = " << isBalancedv3(test33).iRetCode << "  " << isBalancedv3(test33).substr << endl;

	cout << endl;

	for (size_t idx = 0; idx < test30.size(); idx++)
	{
		cout << "Test30 : " << test30 << " :result = " << isBalancedv3(test30).iRetCode << "  Len = " << isBalancedv3(test30).strLen << "  " << isBalancedv3(test30).substr << endl;
		test30.push_back(test30[0]);
		test30.erase(0, 1);
	}

	cout << endl;

	for (size_t idx = 0; idx < test31.size(); idx++)
	{
		cout << "Test31 : " << test31 << " :result = " << isBalancedv3(test31).iRetCode << "  Len = " << isBalancedv3(test31).strLen << "  " << isBalancedv3(test31).substr << endl;
		test31.push_back(test31[0]);
		test31.erase(0, 1);
	}

	cout << endl;

	for (size_t idx = 0; idx < test32.size(); idx++)
	{
		cout << "Test32 : " << test32 << " :result = " << isBalancedv3(test32).iRetCode << "  Len = " << isBalancedv3(test32).strLen << "  " << isBalancedv3(test32).substr << endl;
		test32.push_back(test32[0]);
		test32.erase(0, 1);
	}

	cout << endl;

	for (size_t idx = 0; idx < test33.size(); idx++)
	{
		cout << "test33 : " << test33 << " :result = " << isBalancedv3(test33).iRetCode << "  Len = " << isBalancedv3(test33).strLen << "  " << isBalancedv3(test33).substr << endl;
		test33.push_back(test33[0]);
		test33.erase(0, 1);
	}

	cout << endl;

	return 0;
}

//
TretData isBalancedv3(string& s) {
	stack<char> l_stack;
	string result, buffer;
	for (auto& sym : s) {
		switch (sym) {
		case '(':
		case '[':
		case '{': {
			if (l_stack.empty()) {
				//	flush buffer - copy founded characters and clear buffer
				result += buffer;
				buffer.clear();
			}
			buffer += sym;
			l_stack.push(sym);
		} break;
		case ')': {
			if (!l_stack.empty() && l_stack.top() == '(') {
				//	copy founded characters and clear buffer
				buffer += sym;
				l_stack.pop();
				if (l_stack.empty()) {
					//	flush buffer
					result += buffer;
					buffer.clear();
				}
			}
			else
				return TretData{2, result.size(), result};
		} break;
		case ']': {
			if (!l_stack.empty() && l_stack.top() == '[') {
				//	copy founded characters and clear buffer
				buffer += sym;
				l_stack.pop();
				if (l_stack.empty()) {
					//	flush buffer
					result += buffer;
					buffer.clear();
				}
			}
			else
				return TretData{ 3, result.size(), result };
		} break;
		case '}': {
			if (!l_stack.empty() && l_stack.top() == '{') {
				//	copy founded characters and clear buffer
				buffer += sym;
				l_stack.pop();
				if (l_stack.empty()) {
					//	flush buffer
					result += buffer;
					buffer.clear();
				}
			}
			else
				return TretData{ 4, result.size(), result };
		} break;
		default: {
			//	means character founded and copy it to buffer
			if (l_stack.empty()) {
				//	flush buffer - copy founded characters and clear buffer
				result += sym;
				//buffer.clear();
			}
			else
				buffer += sym;
		}
		}
	}

	if (l_stack.empty())
		return TretData{ 0, result.size(), result + " Infinite" };
	else
		return TretData{ 1, result.size(), result };
}

//
string isBalancedv2(string& s) {
	stack<char> l_stack;
	string result, buffer;
	char sym;
	bool barrier_set = false;
	int barrier_idx = s.size();
	int idx = 0;
	//for (auto& sym : s) {
	//for(size_t i = 0; i < s.size(); i++) {
	while( idx != barrier_idx ) {
		idx %= s.size();
		sym = s[idx];
		switch (sym) {
		case '(':
		case '[':
		case '{': {
			if (!barrier_set) {
				barrier_idx++;
				if (barrier_idx > (int)s.size())
					barrier_idx = (int)s.size();
				barrier_set = true;
			}
			if (l_stack.empty()) {
				//	flush buffer - copy founded characters and clear buffer
				result += buffer;
				buffer.clear();
			}
			else {
			}
			buffer += sym;
			l_stack.push(sym);
		} break;
		case ')':
		case ']':
		case '}': {
			if (l_stack.empty()) {
				//	means there's no open brackets found yet
				//	release buffer
				buffer.clear();
				//	Move barrier if not founded yet
				if (!barrier_set)
					barrier_idx = idx;
			}
			else {
				//	copy founded characters and clear buffer
				buffer += sym;
				l_stack.pop();
				//	if stack become empty after the pop
				if (l_stack.empty()) {
					//	flush buffer - copy founded characters and clear buffer
					result += buffer;
					buffer.clear();
				}
			}
		} break;
		default: {
			//	means character founded and copy it to buffer
			buffer += sym;
		}
		}
		idx++;
	}

	//if (l_stack.empty())
	//	return string("infinite");
	//else
		return result;
}
//
int isBalanced(string& s) {
	stack<char> l_stack;
	for (auto& sym : s) {
		switch (sym) {
		case '(':
		case '[':
			l_stack.push(sym); break;
		case ')': {
			if (!l_stack.empty() && l_stack.top() == '(')
				l_stack.pop();
			else
				return 2;
		} break;
		case ']': {
			if (!l_stack.empty() && l_stack.top() == '[')
				l_stack.pop();
			else
				return 3;
		} break;
		default:
			break;
		}
	}

		if (l_stack.empty())
			return 0;
		else
			return 1;
}
