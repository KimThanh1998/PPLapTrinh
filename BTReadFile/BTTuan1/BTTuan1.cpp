#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <string.h>
#include <fcntl.h> //_O_WTEXT
#include <io.h>    //_setmode()

using namespace std;

//void Check(wstring Array[], wstring check, wstring Array2[], int m) {
//	for (int j = 0; j < 7749; j++) {
//		if (check.compare(Array[j]) == 0) {
//			wcout << "Done\t" << check << " " << j << endl;
//			Array2[m] = check;
//		}
//	}
//}

int binarySearch(wstring names[], int size, wstring value)
{
	int first = 0,             // First array element
		last = size - 1,       // Last array element
		middle,                // Mid point of search
		position = -1;         // Position of search value
	bool found = false;        // Flag

	/*wcout << value << L"\n";*/
	while (!found && first <= last)
	{
		middle = (first + last) / 2;     // Calculate mid point
		/*wcout << names[middle] << L"\t";*/
		if (value.compare(names[middle]) == 0)      // If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (value.compare(names[middle]) < 0)  // If value is in lower half
			last = middle - 1;
		else 
			first = middle + 1;           // If value is in upper half
	}
	return position;
}

//int binarySearchSo(int arr[], int l, int r, int x)
//{
//	if (r >= l) {
//		int mid = l + (r - l) / 2;
//		if (arr[mid] = x)
//			return mid;
//		if (arr[mid] > x)
//			return binarySearchSo(arr, l, mid - 1, x);
//		return binarySearchSo(arr, mid + 1, r, x);
//	}
//	return -1;
//}

int similar(wstring check, wstring array2[], int n) {
	for (int j = 0; j < n; j++) {
		if (check.compare(array2[j]) == 0) {
			return 0;
		}
	}
	return 1;
}

void sort(wstring array[], int n) {
	int i, j;
	wstring key;
	for (i = 0; i < n; i++) 
	{
		key = array[i];
		j = i - 1;
		while (j >= 0 && (array[j] > key)) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
	}
}

//void sortSO(int array[], int n) {
//	int i, j;
//	int key;
//	for (i = 0; i < n; i++)
//	{
//		key = array[i];
//		j = i - 1;
//		while (j >= 0 && array[j] > key) {
//			array[j + 1] = array[j];
//			j--;
//		}
//		array[j + 1] = key;
//	}
//}


int wmain() {
	//_setmode(_fileno(stdout), _O_U16TEXT); //needed for output
	_setmode(_fileno(stdin), _O_U16TEXT); //needed for input
	SetConsoleOutputCP(CP_UTF8);												//Page VN
	wifstream Read(u8"syllables.txt");											//Read File
	wstring Array[7749];														//Create Array
	int Alength = sizeof(Array) / sizeof(Array[0]);
	int x = 0;
	if (Read.is_open()) {														//Check
		while (!Read.eof()) {
			for (int i = 0; i < Alength; i++) {
				getline(Read, Array[i]);
				x++;
			}
		}
	}
	
	sort(Array, 7749);
	/*for (int i = 0; i < 7749; i++) {
		wcout << L"\t" << Array[i];
	}
	wcout << endl;*/
	//-------------------------------------------------------

	wifstream Read1(u8"test.txt");											//Read File
	wstring Array1[100];													//Create Array
	int A1length = sizeof(Array1) / sizeof(Array1[0]);
	if (Read1.is_open()) {													//Check
		while (!Read1.eof()) {
			for (int i = 0; i < A1length; i++) {
				getline(Read1, Array1[i]);
			}
		}
		Read1.close();
	}
	sort(Array1, A1length);
	/*for (int i = 0; i < A1length; i++) {
		wcout << L"\t" << Array1[i];
	}
	wcout << endl;*/
	//----------------------------------------------
	wstring Array2[100];
	int m = 0;
	int A2length = sizeof(Array2) / sizeof(Array2[0]);
	//----------------------------------------------
	for (int i = 0; i < A1length; i++) {
		wstring check = Array1[i];
		//wcout << L"\n" << check;
		if (similar(check, Array2, A2length) == 1) {
			int pos = binarySearch(Array, 7745, check);
			cout << pos << endl;
			if (pos != -1) 
			{ 
				Array2[m] = check; 
				m++; 
			};
		}
	}
	//----------------------------------------------
	for (int m = 0; m < A2length; m++) {
		wcout << L"\n" << Array2[m];
	}
}