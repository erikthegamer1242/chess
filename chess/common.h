#include <iostream>
#include <cctype>
#include <string>

int char_to_int(char input) {
	input = toupper(input);
	int output = 0;
	switch (input) {
	case 'A': {
		output = 0;
		break;
	}
	case 'B': {
		output = 1;
		break;
	}
	case 'C': {
		output = 2;
		break;
	}
	case 'D': {
		output = 3;
		break;
	}
	case 'E': {
		output = 4;
		break;
	}
	case 'F': {
		output = 5;
		break;
	}
	case 'G': {
		output = 6;
		break;
	}
	case 'H': {
		output = 7;
		break;
	}
	}
	return output;
}

void crtanje_ploce(char board[][8], char bijeli_jede[][8], char crni_jede[][8], int &ilegalno, int &debug) {
    char polje[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	int i, j, k;
    for(int i = 0; i<2; i++) {
        cout << " ";
        for(int j=0;j<8;j++) {
			//Polje iznad ploce, sto je bijeli pojeo (crne figure)
            if(debug == 0) {
                if (bijeli_jede[i][j] == 'p') {
                    cout << "  ♙ ";
                } else if (bijeli_jede[i][j] == 'r') {
                    cout << "  ♖ ";
                } else if (bijeli_jede[i][j] == 'h') {
                    cout << "  ♘ ";
                } else if (bijeli_jede[i][j] == 'c') {
                    cout << "  ♗ ";
                } else if (bijeli_jede[i][j] == 'k') {
                    cout << "  ♔ ";
                } else if (bijeli_jede[i][j] == 'q') {
                    cout << "  ♕ ";
                }
            }
            else cout << "   " << bijeli_jede[i][j];
        }   
        cout <<endl;
    }
    cout << endl;
	cout << " ";
    if(debug == 1) {
        for (i = 0; i < 8; i++) cout << "   " << i; 
    }
    else for (i = 0; i < 8; i++)		cout << "   " <<polje[i];
	cout << endl;
	for (k = 0; k < 8; k++) {
		cout << "  ";
		for (i = 0; i < 33; i++) {
			cout << "-";
		}
		cout << endl;
		cout << (k + 1 - debug) << " ";
		for (j = 0; j < 8; j++) {
		//Ploca
			// Da lepo zgledi
			if(debug == 0) {
				//Crne figure unicode
				if (board[k][j] == 'p') {
					cout << "| ♙ ";
				} else if (board[k][j] == 'r') {
					cout << "| ♖ ";
				} else if (board[k][j] == 'h') {
					cout << "| ♘ ";
				} else if (board[k][j] == 'c') {
					cout << "| ♗ ";
				} else if (board[k][j] == 'k') {
					cout << "| ♔ ";
				} else if (board[k][j] == 'q') {
					cout << "| ♕ ";
				}
				// Bijele figure unicode frontend
				else if (board[k][j] == 'P') {
					cout << "| ♟︎ ";
				} else if (board[k][j] == 'R') {
					cout << "| ♜ ";
				} else if (board[k][j] == 'H') {
					cout << "| ♞ ";
				} else if (board[k][j] == 'C') {
					cout << "| ♝ ";
				} else if (board[k][j] == 'K') {
					cout << "| ♚ ";
				} else if (board[k][j] == 'Q') {
					cout << "| ♛ ";
				} else 
					cout << "| " << board[k][j] << " ";
				}
			//Kada je debug == 1
			else
				cout << "| " << board[k][j] << " ";
		}
		cout << "| \n";
	}
	cout << "  ";
	for (i = 0; i < 33; i++) {
		cout << "-";
	}
	cout << endl;
    for(int i = 0; i<2; i++) {
        cout << " ";
        for(int j=0;j<8;j++) {
		//Polje ispod ploce, sto je crni pojeo (bijele figure)
        if(debug == 0) {
            if (crni_jede[i][j] == 'P') {
                cout << "  ♟︎ ";
            } else if (crni_jede[i][j] == 'R') {
                cout << "  ♜ ";
            } else if (crni_jede[i][j] == 'H') {
                cout <<"  ♞ ";
            } else if (crni_jede[i][j] == 'C') {
                cout << "  ♝ ";
            } else if (crni_jede[i][j] == 'K') {
                cout << "  ♚ ";
            } else if (crni_jede[i][j] == 'Q') {
                cout << "  ♛ ";
            }
        }
        else cout << "   " << crni_jede[i][j];   
        } 
        cout << endl;
    }
}

void logika_za_crtanje(int row_to, int row_from, char column_to, char column_from, char board[][8])

{
	int column_to_int = 0, column_from_int = 0;
	column_to_int = char_to_int(column_to);
	column_from_int = char_to_int(column_from);
	char temp_ploca;
	temp_ploca = board[row_from][column_from_int];
	board[row_from][column_from_int] = board[row_to][column_to_int];
	board[row_to][column_to_int] = temp_ploca;
	int n = getchar();
}