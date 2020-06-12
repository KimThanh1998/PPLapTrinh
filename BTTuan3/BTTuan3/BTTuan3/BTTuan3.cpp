//Pham Kim Thanh - 16521129

#include <iostream>
#include <string>

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

	for (int i = 0; i < 6; i++) {
		getline(cin, input);
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

	for (int i = 0; i < 12; i++) {
		int count = 0;
		for (int j = 0; j < 12; j++) {
			if (number[i] == number[j]) {
				count++;
			}
		}
		if (count < 4)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}