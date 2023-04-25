#include <iostream>
#include <string.h>
using namespace std;

class MString {	//class는 기본이 private
public:
	MString(const char* str) {	//생성자
		unsigned int l = strlen(str); //문자열의 길이
		//동적할당!
		c_str_ = new char[l + 1];	// '\0' 널문자가 들어갈 공간 +1
		strcpy(c_str_, str);		// 문자열 복사
		size_ = l;
	}
	unsigned int size(void) { return size_; }
	char* c_str(void) { return c_str_; }

	//소멸자(destructor)
	~MString() {
		//소멸자로 생성자에서 동적할당한 메모리 해제
		delete[] c_str_;
	}

private:
	unsigned int size_;	//문자열의 길이
	char* c_str_;	//문자열의 시작 주소
	//cpp은 const를 선언해주면 그 변수를 사용할 때 마다 const를 붙여줘야 한다.
};
int main(){

	//생성자가 호출되면서 "I will be back" 만큼의(문자열) 동적할당이 이루어짐.
	MString* str = new MString("I will be back");
	cout << str->c_str() << endl;

	//객체 str만 삭제, 동적할당으로 생성된 문자열은 그대로 남아있음(메모리 누수)
	// TODO : 소멸자(destructor)를 이용하여 동적할당된 메모리도 해제하자.
	delete str;

	return 0;
}