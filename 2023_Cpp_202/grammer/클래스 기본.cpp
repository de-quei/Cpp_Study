// C
#include <stdio.h>
#include <string.h>

// C++
#include <iostream>
#include <string>

using namespace std;

struct pizza {
	string brand;
	string menu;
};
int main(void)
{

	struct pizza todaysPizza;
	todaysPizza.brand = "Pizza school";
	todaysPizza.menu = "Combination";

	cout << "Brand : " << todaysPizza.brand << endl;
	cout << "Brand : " << todaysPizza.menu << endl;

	return 0;
}