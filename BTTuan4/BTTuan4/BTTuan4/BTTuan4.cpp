#include <iostream>

using namespace std;

struct pilot {
	int ID = 0;
	int main = 0;
	int assit = 0;
	int check = 0;
};

void outputList(pilot* l, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Main salary of pilot number " << i << " is: " << l[i].main << endl;
		cout << "Assit salary of pilot number " << i << " is: " << l[i].assit << endl;
	}
}

int operate(pilot* l, int n) {
	int min1 = 0;
	int min2 = 0;
	int result = 0;
	for (int i = 0; i < (n / 2); i++) {
		for (int m = 0; m < n; m++) {
			if (l[m].check != 1) {
				min1 = l[i].assit;
				min2 = l[i].main;
			}
		}
		for (int j = 0; j < n; j++) {
			if (l[j].assit < min1 && l[j].check == 0) {
				min1 = l[i].assit;
				l[j].check = 1;
			}
			if (l[j].main < min2 && l[j].check == 0) {
				min2 = l[i].main;
				l[j].check = 1;
			}
		}
		result += min1 + min2;
	}
	return result;
}

int main() {
	int number = 0;
	cout << "Input number of pilots: " << endl;
	cin >> number;

	pilot* list = new pilot[number];

	for (int i = 0; i < number; i++) {
		cout << "Input main salary: " << endl;
		cin >> list[i].main;
		cout << "Input assit salary: " << endl;
		cin >> list[i].assit;
		list->ID = i;
	}

	int result = operate(list, number);
	
	cout << "The minimun salary must be paid is: " << result;
	//outputList(list, number);

	return 0;
}