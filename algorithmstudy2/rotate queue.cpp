#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <queue>
using namespace std;

int main() {

	//test git new branch
	int test = 0;
	int n, m;
	int result = 0;
	cin >> n >> m;
	deque<int> first;
	deque<int> second;
	queue<int> index;
	for (int i = 1; i <= n; i++) {
		first.push_back(i);
		second.push_back(i);
	}

	for (int i = 1; i <= m; i++) {
		int temp;
		cin >> temp;
		index.push(temp);
	}

	for (int k = 1; k <= m; k++) {
		int tempindex;
		tempindex = index.front();
		index.pop();

		int fcount = 0;
		int scount = 0;
		if (tempindex == first.front()) {
			first.pop_front();
			second.pop_front();
			n--;
			continue;
		}

		for (int i = 1; i <= n; i++) {
			if (tempindex != first.front()) {
				first.push_back(first.front());
				first.pop_front();
				fcount++;
			}
			else {
				first.pop_front();
				break;
			}
		}

		for (int i = 1; i <= n; i++) {
			if (tempindex != second.front()) {
				second.push_front(second.back());
				second.pop_back();
				scount++;
			}
			else {
				second.pop_front();
				break;
			}
		}
		n--;
		if (fcount < scount) { 
			result += fcount; second.clear();
			second = first;
		}
		else {
			result += scount;
			first.clear();
			first = second;
		}
	}
	
	cout << result << '\n';
	return 0;
}