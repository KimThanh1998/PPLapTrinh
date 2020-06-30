#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string input;
int pos = 0;
int posStk = 0;
int cnt = 0;
int j = 0;

//Tao 1 mang gom 10 phan tu string, moi phan tu gom 1 mang 3 chu string
string** stack = new string * [10];

void check() {
	for (int i = 0; i < 10 - 2; i++) {
		if (*(stack[i]) == "(" && *(stack[i + 1]) == "E" && *(stack[i + 2]) == ")")
		{
			cout << "Change F --> ( E )" << endl;
			*(stack[i]) = "F";
			*(stack[i + 1]) = "\0";
			*(stack[i + 2]) = "\0";
			cnt -= 2;
		}
	}

	for (int i = 0; i < 10; i++) {
		if (*(stack[i]) == "id")
		{
			cout << "Change F --> id" << endl;
			*(stack[i]) = "F";
		}
	}

	for (int i = 0; i < 10; i++) {
		if (*(stack[i]) == "T" && *(stack[i + 1]) == "*" && *(stack[i + 2]) == "F")
		{
			cout << "Change T --> T * F" << endl;
			*(stack[i]) = "T";
			*(stack[i + 1]) = "\0";
			*(stack[i + 2]) = "\0";
			cnt -= 2;
		}
	}


	for (int i = 0; i < 10; i++) {
		if (*(stack[i]) == "F")
		{
			cout << "Change T --> F" << endl;
			*(stack[i]) = "T";
		}
	}

	for (int i = 0; i < 10; i++) {
		if (*(stack[i]) == "E" && *(stack[i + 1]) == "+" && *(stack[i + 2]) == "T")
		{
			cout << "Change E --> E + T" << endl;
			*(stack[i]) = "E";
			*(stack[i + 1]) = "\0";
			*(stack[i + 2]) = "\0";
			cnt -= 2;
		}
	}

	for (int i = 0; i < 10; i++) {
		if (*(stack[i]) == "T" && *(stack[i + 1]) != "*") {
			if (*(stack[i]) == "T" && input.substr(0, 1) != "*")
			{
				cout << "Change E --> T" << endl;
				*(stack[i]) = "E";
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		if (*(stack[i]) == "E" && input.empty() && *(stack[i + 1]) != "+") {
			if (*(stack[i]) == "E" && input.empty() && input.substr(0, 1) != "+")
			{
				cout << "Change P --> E" << endl;
				*(stack[i]) = "P";
			}
		}
	}
}

int main() {
	//Tao bien doc file
	ifstream readFile("Input.txt");

	//Doc 1 dong tu file
	getline(readFile, input);

	cout << "Input is: " << input << endl;

	//Tao 1 mang gom 10 phan tu string, moi phan tu gom 1 mang 3 chu string(tt)
	for (int i = 0; i < 10; i++) {
		stack[i] = new string[3];
	}


	for (cnt = 0; j < 10; j++, cnt++) {
		//Thuc hien tach chuoi
		if ((pos = input.find(" ")) > 0) {
			*(stack[cnt]) = input.substr(0, pos);
			input.erase(0, pos + 1);
		}
		else if ((pos = input.find(" ")) == string::npos){
			*(stack[cnt]) = input;
			input.erase();
		}
		check();
	}

	//Xuat chuoi de kiem tra
	for (int i = 0; i < 10; i++) {
		cout << "Chuoi da qua xu ly: " << *(stack[i]) << endl;
	}

	return 0;
}