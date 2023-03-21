#include <iostream>

using namespace std;

int main(void) {

	int a = 30;
	int* pa = &a;

	// a = 100;
	*pa = 100;

	cout << "a의 값은 " << a << endl;

	return 0;
}