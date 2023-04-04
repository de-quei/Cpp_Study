// C
#include <stdio.h>
#include <string.h>

// C++
#include <iostream>
#include <string>

using namespace std;

// 여러가지 data들을 하나의 의미있는 구조체로 묶어서 관리
// 구조체, 클래스는 일반적으로 단어의 첫 글자를 대문자로 합시다
// class는 default가 private (struct는 default가 public)
class Student {

public:
	// 생성자 (Constructor) : 객체를 생성할 때 호출되는 함수
	// 생성자를 정의하지 않으면 default로 매개변수가 없는 생성자가 정의된다.
	Student() {
		number = 2208;
		name = "김현지";
		tel = "010-2952-3435";
		department = "뉴미디어소프트웨어과";
		address = "제주특별자치도 제주시 노형동 월산북길 77, 노형휴팰리스 2302호";
	}
	void print(void) {
		//자료형 : Student (class 생략가능)
		cout << "학    번 : " <<  number << endl;
		cout << "이    름 : " <<  name << endl;
		cout << "전화번호 : " <<  tel << endl;
		cout << "학    과 : " <<  department << endl;
		cout << "주    소 : " <<  address << endl;
	}

private:
	// 성능때문에 학번은 문자열로 하지 않음.
	// 일반적으로 문자열은 정수형 데이터보다 많은 메모리 공간을 요구하며
	// 정수는 비교연산을 한번에 할 수 있으나, 문자열은 글자 수 만큼 반복하여 비교해야함.
	int number;			//학번
	string name;		//이름
	string tel;			//전화번호
	string department;	//학과
	string address;		//주소

};
int main(void)
{
	Student student;

	student.print();

	return 0;
}