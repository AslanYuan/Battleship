#include "Ai.h"

Ai::Ai(std::string difficulty) {
};

//Arranges ships at the start of the game only
void Ai::arrangeShip() {
	carrier.yStart = 1;
	carrier.xStart = 1;

	battleship.yStart = 1;
	battleship.xStart = 1;

	cruiser.yStart = 1;
	cruiser.xStart = 1;

	submarine.yStart = 1;
	submarine.yStart = 1;

	destroyer.yStart = 1;
	destroyer.yStart = 1;
};

int* Ai::easyAttack(int board[10][10]) {

	int attack[2];

	for (int i = 0; i < 10; i++) {
		for (int j = 10; j < 10; j++)
			if (!board[i + rand() % 10][j + rand() % 10]) {
				attack[0] = i;
				attack[1] = j;
				return attack;
			}
	}
	return nullptr;
};

int* Ai::normalAttack(int board[10][10]) {

	int attack[2];

	if (!target) {
		return easyAttack(board);
	}
	else if (target) {
		for (int i = -1; i = 1; i += 2) {
			for (int j = -1; i = 1; i += 2) {
				if (board[i + target[0]][j + target[1]]) {
					continue;
				}
				else {
					attack[0] = i;
					attack[1] = j;
					return attack;
				}
			}
		}
	}
}

int* Ai::hardAttack(int board[10][10]) {
	//TODO
}

int Ai::getX() {
};

void Ai::fitAircraftcarrier(int board[10][10])
{	
	int count = 0;
	for (int i = 0; i < 10; i++) {		//ready all the possible space for Carrier first(still working)
		for (int j = 0; j < 10; j++) {
			if (i < 10 && j < 6) {
				if (board[i][j] == board[i][j + 4]) { count++; }
			}

			if (i < 6 && j < 10) {
				if (board[i][j] == board[i + 4][j]) { count++; }
			}
		}
	}
}
void Ai:: fitBattleship(int board[10][10])
{
	int count = 0;
	for (int i = 0; i < 10; i++) {			//ready all the possible space for Battleship first(still working)
		for (int j = 0; j < 10; j++) {
			if (i < 10 && j < 7) {
				if (board[i][j] == board[i][j + 3]) { count++; }
			}

			if (i < 7 && j < 10) {
				if (board[i][j] == board[i + 3][j]) { count++; }
			}
		}
	}
}
void Ai::fitSubmarine(int board[10][10])
{	
	int count = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i < 10 && j < 8) {
				if (board[i][j] == board[i][j + 2]) { count++; }
			}

			if (i < 8 && j < 10) {
				if (board[i][j] == board[i + 2][j]) { count++; }
			}
		}
	}
}
void Ai::fitCruiser(int board[10][10])
{	
	int count = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i < 10 && j < 8) {
				if (board[i][j] == board[i][j + 2]) { count++; }
			}

			if (i < 8 && j < 10) {
				if (board[i][j] == board[i + 2][j]) { count++; }
			}
		}
	}
}

void Ai::fitDestroyer(int board[10][10])
{	
	int count = 0;
	for (int i = 0; i < 10; i++) {		
		for (int j = 0; j < 10; j++) {
			if (i < 10 && j < 9) {
				if (board[i][j] == board[i][j + 1]) { count++; }
			}

			if (i < 9 && j < 10) {
				if (board[i][j] == board[i + 1][j]) { count++; }
			}
		}
	}
}
