//Pham Kim Thanh - 16521129
//Please change the value of file "BOX.INP" to run the code properly

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	string input;

	int number1 = 0; 
	int number2 = 0;

	string temp1;
	string temp2;

	int pos = 0;

	int n = 0;

	int *number = new int[12];

	ifstream readFile("BOX.INP");

	for (int i = 0; i < 6; i++) {
		getline(readFile, input);
		while ((pos = input.find(" ")) > 0)
		{
			temp1 = input.substr(0, pos);
			input.erase(0, pos + 1);
		}
		temp2 = input.substr(0);
		number[n] = stoi(temp1);
		number[n + 1] = stoi(temp2);
		n += 2;
	}

	readFile.close();

	ofstream writeFile("BOX.OUT");

	for (int i = 0; i < 12; i++) {
		int count = 0;
		for (int j = 0; j < 12; j++) {
			if (number[i] == number[j]) {
				count++;
			}
		}
		if (count < 4)
		{
			writeFile << "NO";
			return 0;
		}
	}
	writeFile << "YES";
	return 0;
}