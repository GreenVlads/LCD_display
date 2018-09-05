#pragma once

#include <iostream>
#include <time.h>
#include <Windows.h>
#include <string>

#define N 3
#define M 60

class LCD {
private:

	char mass[N][M];

public:
	int number;

	LCD();
	~LCD();
	void output();
	void init();
	void destruct();

	operator int()
	{
		return number;
	}

	LCD & operator++()
	{
		char c = mass[1][1];
		for (int i = 1; i < N - 1; i++) {
			for (int j = 1; j < M - 1; j++) {
				if (j != M - 2) {
					mass[i][j] = mass[i][j + 1];
				}
				if ((j == M - 2) && (i != N - 1)) {
					mass[i][j] = mass[i + 1][1];
				}
			}
		}
		mass[N - 2][M - 2] = c;
		return *this;
	}
};


LCD::LCD()
{
	int i, j;
	srand(clock() % 1000000);
	number = rand();

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (i == 0 && j == 0) {
				mass[i][j] = (char)218;
			}
			else if (i == 0 && j == M - 1) {
				mass[i][j] = (char)191;
			}
			else if (i == N - 1 && j == 0) {
				mass[i][j] = (char)192;
			}
			else if (i == N - 1 && j == M - 1) {
				mass[i][j] = (char)217;
			}
			else if ((i == 0 && j != 0 && j != M - 1) || (i == N - 1 && j != 0 && j != M - 1)) {
				mass[i][j] = (char)196;
			}
			else if ((j == 0 && i != 0 && i != N - 1) || (j == M - 1 && i != 0 && i != N - 1)) {
				mass[i][j] = (char)179;
			}
			else mass[i][j] = (char)176;

		}
	}
}

LCD::~LCD()
{
}

void LCD::output()
{
	for (int i = 0; i < N; i++, std::cout << std::endl) {
		for (int j = 0; j < M; j++) {
			std::cout << mass[i][j];

		}
	}
}

void LCD::init()
{
	int pos = 0;
	std::string str;
	std::cout << "Enter: " << std::endl;
	std::cin >> str;
	for (int i = 1; i < N - 1; i++, std::cout << std::endl) {
		for (int j = 1; j < M - 1; j++) {
			if (str[pos] == 0)break;
			mass[i][j] = char(str[pos]);
			pos++;
		}
	}
}

void LCD::destruct() {
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (i == 0 && j == 0) {
				mass[i][j] = (char)218;
			}
			else if (i == 0 && j == M - 1) {
				mass[i][j] = (char)191;
			}
			else if (i == N - 1 && j == 0) {
				mass[i][j] = (char)192;
			}
			else if (i == N - 1 && j == M - 1) {
				mass[i][j] = (char)217;
			}
			else if ((i == 0 && j != 0 && j != M - 1) || (i == N - 1 && j != 0 && j != M - 1)) {
				mass[i][j] = (char)196;
			}
			else if ((j == 0 && i != 0 && i != N - 1) || (j == M - 1 && i != 0 && i != N - 1)) {
				mass[i][j] = (char)179;
			}
			else mass[i][j] = (char)176;

		}
	}
}
