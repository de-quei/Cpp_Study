#include <iostream>

using namespace std;

int main(){

	//int 3개의 공간에 동적할당 한 후 ptr1이 가리킨다.
	int* ptr1 = new int[3];
	ptr1[0] = 0, ptr1[1] = 10, ptr1[2] = 20;

	//별도의 공간을 동적할당 한 후, ptr1이 가리키는 내용물을 복사한다.(깊은 복사, deep copy)
	int* ptr2 = new int[3];
	for (int i = 0; i < 3; i++) {
		ptr2[i] = ptr1[i];
	}

	//깊은 복사를 하면 원본데이터가 유지될 수 있다.
	ptr2[1] = 100;
	for (int i = 0; i < 3; i++) {
		cout << ptr1[i] << ", " << ptr2[i] << endl;
	}

	//늦게 사용한 것을 먼저 해제하는 것이 좋다!
	delete[] ptr2;
	//이미 해제된 공간을 또 해제하려고 하니 에러가 발생
	delete[] ptr1;

	return 0;
}