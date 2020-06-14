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
	int temp1 = 0;
	int temp2 = 0;
	for (int i = 0; i < (n / 2); i++) {
		for (int m = 0; m < n; m++) {
			//Sau khi su dung min salary thuc hien gan lai gia tri min cho cac pilot chua check
			if (l[m].check == 0) {
				min1 = l[m].assit;
				temp1 = m;
				break;
			}
		}

		//So sanh luong lai phu thap nhat: neu co gia tri thap hon check no khong thi check cai cu
		for (int j = 0; j < n; j++) {
			if (l[j].assit < min1 && l[j].check == 0) {
				min1 = l[j].assit;
				temp1 = j;
			}
		}
		l[temp1].check = 1;

		for (int m = 0; m < n; m++) {
			//Sau khi su dung min salary thuc hien gan lai gia tri min cho cac pilot chua check
			if (l[m].check == 0) {
				min2 = l[m].main;
				temp2 = m;
				break;
			}
		}

		//So sanh luong lai phu thap nhat: neu co gia tri thap hon check no khong thi check cai cu
		for (int j = 0; j < n; j++) {
			if (l[j].main < min2 && l[j].check == 0) {
				min2 = l[j].main;
				temp2 = j;
			}
		}
		l[temp2].check = 1;
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