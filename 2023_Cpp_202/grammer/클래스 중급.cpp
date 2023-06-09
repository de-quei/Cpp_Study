﻿#include <iostream>
#include <string.h>
using namespace std;

class MString {	//class는 기본이 private
public:
	MString(const char* str) {	//생성자
		unsigned int l = strlen(str);	//문자열의 길이
		//동적할당!
		c_str_ = new char[l + 1];		// '\0' 널문자가 들어갈 공간 +1
		strcpy(c_str_, str);			// 문자열 복사
		size_ = l;
		cout << "MString 생성자 호출 완료" << endl;
	}
	unsigned int size(void) { return size_; }
	char* c_str(void) { return c_str_; }

	//복사생성자(별도의 정의가 없으면 컴파일러가 알아서 만들어 줌)
	//TODO : 소멸자 호출 시 에러발생
	MString(const MString& rhs)
		: c_str_(rhs.c_str_), size_(rhs.size_)
	{
		cout << "복사생성자 호출" << endl;
	}

	//소멸자(destructor)
	~MString() {
		//소멸자로 생성자에서 동적할당한 메모리 해제
		delete[] c_str_;
		cout << "MString 소멸자 호출 완료" << endl;
	}

private:
	unsigned int size_;	//문자열의 길이
	char* c_str_;	//문자열의 시작 주소
	//cpp은 const를 선언해주면 그 변수를 사용할 때 마다 const를 붙여줘야 한다.
};
int main(){

	//일반생성자 호출
	MString str = MString("I will be back");
	
	//복사생성자 호출
	MString str2 = str;

	return 0;
}