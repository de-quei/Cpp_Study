// C
#include <stdio.h>
#include <string.h>

// C++
#include <iostream>
#include <string>

using namespace std;

struct Person {
	int height;
	int weight;
};
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

	Student(int _number, string _name, string _tel, string _department, string _address) 
		// 멤버변수 초기화. const / 참조형 멤버변수 사용 가능
		: number(_number), name(_name), tel(_tel), department(_department), address(_address)
	{
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
	//매개변수가 없는 생성자
	//Student student;
	Student student1 = Student();
	//student.print();

	// 정적할당
	//Student student2 = Student(1234, "오모리모토키", "010-1212-3434", "MRS.GREENAPPLE", "일본");
	//student2.print();

	//동적할당은 포인터로 접근한다.
	Student* student3 = new Student(1234, "오모리모토키", "010-1212-3434", "MRS.GREENAPPLE", "도쿄");
	student3->print();

	struct Person p;
	p.height = 163;
	p.weight = 50;

	struct Person* ptr = &p;

	// 둘 다 같은 결과
	cout << "키       : " << ptr->height << "cm" << endl;
	cout << "몸 무 게 : " << (*ptr).weight << "kg" << endl;

	return 0;
}