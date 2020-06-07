//16521129_PhamKimThanh

#include <iostream>
#include <string>
using namespace std;

int input(int M) {
	cout << "Input number of tests: " << endl;
	cin >> M;
	return M;
}

//Nhap chuoi cac la bai
void inputCards(char* &cards, int N) {
	for (int i = 0; i < N*4; i++) {
		cin >> cards[i];
	}
}

//Chia doi bai cho Adam va Eva
void inputAdamEva(char* &cardsAdam, char* &cardsEva, char* cardsTemp, int N) {
	for (int i = 0; i < N * 2; i++) {
		cardsAdam[i] = cardsTemp[i];
	}
	int j = 0;
	for (int i = N * 4 - 1; i > N * 2; i--) {
		cardsEva[j] = cardsTemp[i - 1];
		cardsEva[j + 1] = cardsTemp[i];
		j = j + 2;
		i--;
	}
}

struct Card {
	int ID;
	int Prio = 0;
	int Check = 0;
};

Card convertCards(char* cards, int N, Card* &cardsR) {
	int j = 0;
	int m = 0;
	for (int i = 0; i < N; i++) {
		switch (cards[i]) {
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': 
			cardsR[j].ID = (int)cards[i] - 48;
			j++;
			break;
		case 'T':
			cardsR[j].ID = 10;
			j++;
			break;
		case 'J':
			cardsR[j].ID = 11;
			j++;
			break;
		case 'Q':
			cardsR[j].ID = 12;
			j++;
			break;
		case 'K':
			cardsR[j].ID = 13;
			j++;
			break;
		case 'A':
			cardsR[j].ID = 14;
			j++;
			break;
		}
		switch (cards[i + 1]) {
		case 'C':
			cardsR[m].Prio = 3;
			m++;
			break;
		case 'B':
			cardsR[m].Prio = 2;
			m++;
			break;
		case 'R':
			cardsR[m].Prio = 1;
			m++;
			break;
		case 'N':
			cardsR[m].Prio = 0;
			m++;
			break;
		}
		i++;

	}
	return *cardsR;
}

//Kiem tra diem va sap xep
int Point(Card* A, Card* B, int N) {
	int count = 0;
	for (int i = 0; i < N; i++) {
		int max = 0;
		int IDTemp = 0;
		for (int j = 0; j < N; j++) {
			if (A[j].Check == 0) {
				if (A[j].ID > max && A[j].ID < B[i].ID) {
					max = A[j].ID;
					IDTemp = j;
				}
				else if (A[j].ID > max && A[j].ID == B[i].ID) {
					if (B[i].Prio > A[i].Prio) {
						max = A[j].ID;
						IDTemp = j;
					}
				}
			}
		}
		if (max != 0) {
			A[IDTemp].Check = 1;
		}
	}
	for (int i = 0; i < N; i++) {
		if (A[i].Check == 1)
		{
			count++;
		}
	}
	return count;
}

void outputChar(char* cards, int N) {
	for (int i = 0; i < N; i++) {
		cout << cards[i];
	}
}

void outputID(Card* cards, int N) {
	for (int i = 0; i < N; i++) {
		cout << cards[i].ID;
	}
}

void outputPrio(Card* cards, int N) {
	for (int i = 0; i < N; i++) {
		cout << cards[i].Prio;
	}
}

int main() {
	int BT = 0;
	cout << "Nhap so lan can thuc hien: " << endl;
	cin >> BT;
	int* resultFinal = new int[BT];
	int temp = 0;
	for (int i = 0; i < BT; i++) {
		int N = 0;
		cout << "Input number of cards: " << endl;
		cin >> N;

		char* CardsTemp = new char[N * 4];
		inputCards(CardsTemp, N);

		char* CardsAdam = new char[N * 2];
		char* CardsEva = new char[N * 2];
		inputAdamEva(CardsAdam, CardsEva, CardsTemp, N);

		Card* cardsAdam = new Card[N];
		convertCards(CardsAdam, N * 4, cardsAdam);

		Card* cardsEva = new Card[N];
		convertCards(CardsEva, N * 4, cardsEva);

		int result = Point(cardsAdam, cardsEva, N);
		resultFinal[temp] = result;
		temp++;
		//cout << "Eva's Point is: " << result << endl;
		/*outputChar(CardsAdam, N * 2);
		cout << endl;
		outputChar(CardsEva, N * 2);
		cout << endl;
		outputPrio(cardsAdam, N);
		cout << endl;
		outputPrio(cardsEva, N);*/
	}
	for (int i = 0; i < BT; i++) {
		cout << resultFinal[i] << endl;
	}
	return 0;
}