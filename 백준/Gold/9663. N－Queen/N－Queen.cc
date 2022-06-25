#include <iostream>

using namespace std;

int n;
int dap;

bool isusedY[20];
bool isused1[50]; // x + y
bool isused2[50]; // x - y + n

void func(int k) {
	if (k == n) {
		dap++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (isused1[i + k] || isused2[k - i + n] || isusedY[i]) continue;
			
		isused1[k+i] = true;
		isused2[k - i + n] = true;
		isusedY[i] = true;
		func(++k);
		k--;
		isused1[k+i] = false;
		isused2[k - i + n] = false;
		isusedY[i] = false;
	}
}

int main() {
	cin >> n;
	func(0);
	cout << dap;
	return 0;
}