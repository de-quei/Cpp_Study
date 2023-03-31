// C
#include <stdio.h>
#include <string.h>

// C++
#include <iostream>
#include <string>

using namespace std;

// 여러가지 data들을 하나의 의미있는 구조체로 묶어서 관리
// 구조체, 클래스는 일반적으로 단어의 첫 글자를 대문자로 합시다
struct Student {
	// 성능때문에 학번은 문자열로 하지 않음.
	//일반적으로 문자열은 정수형 데이터보다 많은 메모리 공간을 요귷며
	//정수는 비교연산을 한번에 할 수 있으나, 문자열은 글자 수 만큼 반복하여 비교해야함.
	int number;			//학번
	string name;		//이름
	string tel;			//전화번호
	string department;	//학과
	string address;		//주소
};
int main(void)
{
	Student student;
	student.number = 2208;
	student.name = "김현지";
	student.tel = "010-2952-3435";
	student.department = "뉴미디어소프트웨어과";
	student.address = "제주특별자치도 제주시 노형동 월산북길 77, 노형휴팰리스 2302호";

	//자료형 : struct Student (C++에서는 Student만 써도 가능)
	cout << "학    번 : " << student.number << endl;
	cout << "이    름 : " << student.name << endl;
	cout << "전화번호 : " << student.tel << endl;
	cout << "학    과 : " << student.department << endl;
	cout << "주    소 : " << student.address << endl;

	return 0;
}