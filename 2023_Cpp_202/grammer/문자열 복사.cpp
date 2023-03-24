#include <iostream>
#include <string>	// std::string 클래스

int main(void) {

	std::string str1;
	std::string str2 = "Jiwoo";

	//str1에 str2할당
	str1 = str2;

	std::cout << str1 << std::endl;

	return 0;
}