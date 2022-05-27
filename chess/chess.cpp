#include "common.h"
#include "figure.h"
#include <cmath>
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

#if defined(_WIN32)
#define CLEAR system("cls");
#elif defined(__linux__)
#define CLEAR system("clear");
#endif

#define FILENAME "chess.bin"

int igra_radi = 1;
int debug = 0;
int clear_screen = 1;
int ilegalno = 0;
char bijeli_jede[2][8] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};
char crni_jede[2][8] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					             {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};
char board[8][8] = {{'R', 'H', 'C', 'Q', 'K', 'C', 'H', 'R'},
					{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
					{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
					{'r', 'h', 'c', 'q', 'k', 'c', 'h', 'r'}};



int main() {
	fstream file;
	cout << "Do you want to load last game [y/N] ?";
	char choice;
	cin >> choice;
	if(toupper(choice) == 'Y') {
		cout << "Loading game!";
			file.open(FILENAME, ios::binary | ios::in);
			if(file.fail()) {
				cout << "Greska pri otvaranju " << FILENAME << ". Provjerie jeste li kreirali datoteku i je li ona pravilno napisana!\n";
				return 0;
    		}
			file.read((char*)&bijeli_jede, sizeof(bijeli_jede));
            file.read((char*)&crni_jede, sizeof(crni_jede));
            file.read((char*)&board, sizeof(board));
			file.close();
	}
	int row_from = 0, row_to = 0;
	char column_from, column_to;
	do {
		if (clear_screen == 1)
			CLEAR;
		crtanje_ploce(board, bijeli_jede, crni_jede, debug);
		if (ilegalno == 1) {
			printf("\nilegalno!!!");
			ilegalno = 0;
		}
		cout <<"\nFrom position(Example:b1, if: f9 save game): ";
		cin >> column_from;
		cin >> row_from;
		if(toupper(column_from)== 'F' && row_from == 9) {
			cout << "Saving game!";
			file.open(FILENAME, ios::binary | ios::out);
			file.write((char*)&bijeli_jede, sizeof(bijeli_jede));
            file.write((char*)&crni_jede, sizeof(crni_jede));
            file.write((char*)&board, sizeof(board));
			file.close();
			return 0;
		}
		cout << "\nTo position(Example:c3): ";
		cin >> column_to;
		cin >> row_to;
		if (debug == 0) {
			row_from -= 1;
			row_to -= 1;
		}
		if (board[row_from][(char_to_int(column_from))] == 'p' || board[row_from][(char_to_int(column_from))] == 'P') pijuni(row_to, row_from, column_to, column_from, board, bijeli_jede, crni_jede, ilegalno);
		else if (board[row_from][char_to_int(column_from)] == 'r' || board[row_from][char_to_int(column_from)] == 'R') kula(row_to, row_from, column_to, column_from, board, bijeli_jede, crni_jede, ilegalno); 
		else if (board[row_from][char_to_int(column_from)] == 'h' || board[row_from][char_to_int(column_from)] == 'H') konj(row_to, row_from, column_to, column_from, board, bijeli_jede, crni_jede, ilegalno);
		else if (board[row_from][char_to_int(column_from)] == 'c' || board[row_from][char_to_int(column_from)] == 'C') lovac(row_to, row_from, column_to, column_from, board, bijeli_jede, crni_jede, ilegalno);
		else if (board[row_from][char_to_int(column_from)] == 'k' || board[row_from][char_to_int(column_from)] == 'K') kralj(row_to, row_from, column_to, column_from, board, bijeli_jede, crni_jede, ilegalno);
		else if (board[row_from][char_to_int(column_from)] == 'q' || board[row_from][char_to_int(column_from)] == 'Q') kraljica(row_to, row_from, column_to, column_from, board, bijeli_jede, crni_jede, ilegalno);
	} while (igra_radi == 1);
}