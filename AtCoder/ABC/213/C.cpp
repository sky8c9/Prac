#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void compress_coord(vector<int>& nums) {
	map<int, int> mapping;
	for(int num : nums) {
		mapping[num] = 0;
	}

	int index = 1;
	for(auto& [key,val] : mapping) {
		val = index++;
	}

	for(int& num : nums) {
		num = mapping[num];
	}
}

void task() {
	int h,w,n;
	cin >> h >> w >> n;
	vector<int> hcoord(n);
	vector<int> wcoord(n);

	for(int i = 0; i < n; i++) {
		int a,b;
		cin >> a >> b;

		hcoord[i] = a;
		wcoord[i] = b;
	}

	compress_coord(hcoord);
	compress_coord(wcoord);
	for(int i = 0; i < n; i++) {
		cout << hcoord[i] << " " << wcoord[i] << endl;
	}
}

int main() {
	task();
	return 0;
}