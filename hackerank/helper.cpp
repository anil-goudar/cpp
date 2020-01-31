#include "helper.h"

vector<int> readVectorOfInt() {
	string ip;
	vector<int> v;
	getline(cin, ip);
	std::istringstream iss(ip);
	int temp;
	while (iss >> temp) {
		v.push_back(temp);
	}
	return v;
}

void variableSize() {
	int n_a;
	int n_q;
	cin >> n_a >> n_q;
	vector<vector<int>> arr;
	cin.ignore(32767, '\n');
	for (int i = 0; i < n_a; i++) {
		vector<int> sub_arr = readVectorOfInt();
		//cout << sub_arr.size() << " first is: " << sub_arr[0] << endl;
		arr.push_back(sub_arr);
		//cin.ignore(32767, '\n');
	}
	for (int i = 0; i < n_q; i++) {
		int k, j;
		cin >> k >> j;
		cout << arr[k][j+1] << endl;
	}
}