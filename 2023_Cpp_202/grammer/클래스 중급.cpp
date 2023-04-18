#include <iostream>
#include <string>
using namespace std;

class MString {	//class는 기본이 private
public:
	unsigned int size(void) { return size_; }
	const char* c_str(void) { return c_str_; }
	MString(const char* str) {	//생성자
		c_str_ = str;
		size_ = strlen(str);//문자열 길이 strlen함수
	}
private:
	unsigned int size_;	//문자열의 길이
	const char* c_str_;	//문자열의 시작 주소
};
int main(){

	MString* str = new MString("I will be back");
	cout << str->c_str() << endl;
	delete str;

	return 0;
}