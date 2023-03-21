#include <iostream>

using namespace std;

void Plus2(int& num) {
	num += 2;
}
int main(void) {

	int a = 3;

	Plus2(a);

	cout << a << endl;

	return 0;
}