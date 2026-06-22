#include <iostream>
#include<ctime>
#include<cstdlib>
#include<conio.h>
using namespace std;
void finalResult(short arr[]);
void result(short arr[],int x,short choice, short comChoice);
void check(short choice,short comChoice,short arr[]);
short computerChoice();
void gameplay(short rounds);
void startGame();

int main(){

	srand((unsigned)time(NULL));
	startGame();

	return 0;
}

void finalResult(short arr[]) {
	system("cls");
	cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t+++++Final Result+++++" << endl;
	if (arr[0] > arr[1]) {
		cout << "\t\t\t\t\t\tplayer: " << arr[0] << endl;
		cout << "\t\t\t\t\t\tcomputer: " << arr[1] << endl;
		cout << "\n\n\n\t\t\t\t\t\tPlayer wins" << endl;
		system("color 20");
	}
	else if(arr[0] == arr[1]){
		cout << "\t\t\t\t\t\tPlayer: " << arr[0] << endl;
		cout << "\t\t\t\t\t\tcomputer: " << arr[1] << endl;
		cout << "\n\n\n\t\t\t\t\t\tDraw" << endl;
		system("color 60");
	}
	else {
		cout << "\t\t\t\t\t\tPlayer: " << arr[0] << endl;
		cout << "\t\t\t\t\t\tcomputer: " << arr[1] << endl;
		cout << "\n\n\n\t\t\t\t\t\tComputer wins" << endl;
		system("color 40");
		cout << "\a";
	}
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
void result(short arr[],int x, short choice,short comChoice) {
	system("cls");
	cout << "++++++++++++++++Round[" << x+1 << "]++++++++++++++++++++++" << endl;
	if (choice == 1 && comChoice == 1) {
		cout << "Player Choice is Rock" << endl;
		cout << "Computer Choice is Rock" << endl;
		cout<<"Result is draw" << endl;
	}
	else if (choice == 2 && comChoice == 2) {
			cout << "Player Choice is Paper" << endl;
			cout << "Computer Choice is Paper" << endl;
			cout << "Result is draw" << endl;
	}
	else if (choice == 3 && comChoice == 3) {
		cout << "Player Choice is Scssiors" << endl;
		cout << "Computer Choice is Scssiors" << endl;
		cout << "Result is draw" << endl;
	}
	else if (choice == 1 && comChoice == 2) {
		cout << "Player Choice is Rock" << endl;
		cout << "Computer Choice is Paper" << endl;
		cout << "Computer wins" << endl;
	}
	else if (choice == 1 && comChoice == 3) {
		cout << "Player Choice is Rock" << endl;
		cout << "Computer Choice is Scissors" << endl;
		cout << "Player wins" << endl;
	}
	else if (choice == 2 && comChoice == 3) {
		cout << "Player Choice is Paper" << endl;
		cout << "Computer Choice is Scissors" << endl;
		cout << "Computer wins" << endl;
	}
	else if (choice == 2 && comChoice == 1) {
		cout << "Player Choice is Paper" << endl;
		cout << "Computer Choice is Rock" << endl;
		cout << "Player wins" << endl;
	}
	else if (choice == 3 && comChoice == 1) {
		cout << "Player Choice is Scissors" << endl;
		cout << "Computer Choice is Rock" << endl;
		cout << "Computer wins" << endl;
	}
	else if (choice == 3 && comChoice == 2) {
		cout << "Player Choice is Scissors" << endl;
		cout << "Computer Choice is Paper" << endl;
		cout << "Player wins" << endl;
	}

	cout << "Player: " << arr[0] << endl;
	cout << "computer: " << arr[1] << endl;
	cout << "\n\nPress any key to continue ";
	_getch();
}
void check(short choice, short comChoice,short arr[]) {
	if (choice == comChoice) {
		system("color 60");
		arr[0]++;
		arr[1]++;
	}
	else if (choice == 1 && comChoice == 3) {
		arr[0]++;
		system("color 20");
	}
	else if (choice == 2 && comChoice == 1) {
		arr[0]++;
		system("color 20");
	}
	else if (choice == 3 && comChoice == 2) {
		arr[0]++;
		system("color 20");
	}
	else {
		arr[1]++;
		system("color 40");
		cout << "\a";
	}
	
}
short computerChoice() {
	return 1 + rand() % 3;
}
void gameplay(short rounds) {
	short choice=0,comChoice=0;
	short arr[2] = { 0 };
	for (int i = 0; i < rounds; i++) {
		system("cls");
		system("color F0");
		cout << "\nRound[" << i+1 << "] begins: \n";
		cout << "Your choice: [1]:Rock  [2]:Paper  [3]:Scissors :...? ";
	    cin >> choice;
		comChoice = computerChoice();
		check(choice, comChoice, arr);
		if (i == rounds - 1) {
			result(arr, i, choice, comChoice);
			finalResult(arr);
		}
		else
		result(arr, i, choice, comChoice);
	}
}
void startGame() {
	short rounds;
	cout << "\t\t\t\t\t++WELCOME in Rock Paper scissors Game++" << "\n\n\nplease Enter number of rounds do you want: ";
	cin >> rounds;
	gameplay(rounds);
}