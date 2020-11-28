//
#include <iostream>
#include <map>
template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K, V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
		: m_valBegin(val)
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign(K const& keyBegin, K const& keyEnd, V const& val) {
		// INSERT YOUR SOLUTION HERE
		if ((m_map.size() == 0) && (val == m_valBegin))
			return;
		if (keyBegin < keyEnd) {	//	interval not empty
			auto upp_it = m_map.upper_bound(keyEnd);	//	iterator to the first element greater than the given key
			auto low_it = m_map.lower_bound(keyBegin);	//	iterator to the first element not less than the given key
			if (upp_it == m_map.begin()) {
				m_map[keyEnd] = m_valBegin; 
				m_map[keyBegin] = val;
			}
			else {
				if (low_it == upp_it) {
					m_map[keyEnd] = (--upp_it)->second;
					m_map[keyBegin] = val;
				}
				else {
					m_map[keyEnd] = (--upp_it)->second;
					m_map[keyBegin] = val;
					if (upp_it->first < keyEnd)
						++upp_it;
					if (low_it->first > keyBegin) {
					}
					else
						++low_it;
					m_map.erase(low_it, upp_it);
				}
			}
			//	remove duplicates secondary values

			if (m_map.size() > 1) {
				auto prev = m_map.begin();
				auto it = prev;
				++it;
				while (it != m_map.end())
				{
					if (it->second == prev->second) {
						it = m_map.erase(it);
					}
					else {
						prev = it;
						++it;
					}
				}
			}
		}
	}

	// look-up of the value associated with key
	V const& operator[](K const& key) const {
		auto it = m_map.upper_bound(key);
		if (it == m_map.begin()) {
			return m_valBegin;
		}
		else {
			return (--it)->second;
		}
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.
//

auto main() -> int {

	//
	int idx[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };

	//
	if (false)
	{
		interval_map<int, char> task('C');

		task.assign(6, 9, 'D');
		task.assign(1, 3, 'A');
		task.assign(21, 24, 'F');
		task.assign(13, 17, 'X');
		task.assign(14, 16, 'W');
		task.assign(12, 18, 'O');

		for (auto& val : idx) {
			std::cout << "F(" << val << ")= " << task[val] << std::endl;
		}

	}

	//
	{
		interval_map<int, char> task('0');

		task.assign(11, 13, 'D');
			for (auto& val : idx) {
				std::cout << task[val] << ' ';
			}
			std::cout << std::endl;
		task.assign(15, 19, 'X');
			for (auto& val : idx) {
				std::cout << task[val] << ' ';
			}
			std::cout << std::endl;
		task.assign(12, 17, 'B');
			for (auto& val : idx) {
				std::cout << task[val] << ' ';
			}
			std::cout << std::endl;
		task.assign(20, 5, '1');
			for (auto& val : idx) {
				std::cout << task[val] << ' ';
			}
			std::cout << std::endl;

	}

	std::cout << std::endl;
	//
	{
		interval_map<int, char> task('0');

		task.assign(1, 4, 'A');
		for (auto& val : idx) {
			std::cout << task[val] << ' ';
		}
		std::cout << std::endl;
		task.assign(3, 6, 'B');
		for (auto& val : idx) {
			std::cout << task[val] << ' ';
		}
		std::cout << std::endl;
		task.assign(5, 8, 'C');
		for (auto& val : idx) {
			std::cout << task[val] << ' ';
		}
		std::cout << std::endl;
		task.assign(4, 8, 'E');
		for (auto& val : idx) {
			std::cout << task[val] << ' ';
		}
		std::cout << std::endl;

	}

	std::cout << std::endl;
	//
	{
		interval_map<int, char> task('0');

		task.assign(12, 15, 'A');
		for (auto& val : idx) {
			std::cout << task[val] << ' ';
		}
		std::cout << std::endl;
		task.assign(11, 14, 'B');
		for (auto& val : idx) {
			std::cout << task[val] << ' ';
		}
		std::cout << std::endl;
		task.assign(10, 13, 'C');
		for (auto& val : idx) {
			std::cout << task[val] << ' ';
		}
		std::cout << std::endl;
		task.assign(10, 13, 'E');
		for (auto& val : idx) {
			std::cout << task[val] << ' ';
		}
		std::cout << std::endl;

	}

	std::cout << std::endl;
	//
	{
		interval_map<int, char> task('0');

		task.assign(1, 3, '0');
		for (auto& val : idx) {
			std::cout << task[val] << ' ';
		}
		std::cout << std::endl;

		task.assign(3, 5, 'A');
		for (auto& val : idx) {
			std::cout << task[val] << ' ';
		}
		std::cout << std::endl;

		task.assign(5, 7, 'A');
		for (auto& val : idx) {
			std::cout << task[val] << ' ';
		}
		std::cout << std::endl;

	}

	if (false)
	{
		std::map<int, int> m_map;
		m_map[1] = 1;
		m_map[2] = 1;
		m_map[3] = 3;
		m_map[5] = 3;

		if (m_map.size() > 1) {
			auto prev = m_map.begin();
			auto it = prev;
			++it;
			while (it != m_map.end())
			{
				if (it->second == prev->second) {
					it = m_map.erase(it);
				}
				else {
					prev = it;
					++it;
				}
					
			}
		}
	}

	//
	return 0;
}