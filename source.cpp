#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <time.h>
#include "LCD.h"


using namespace std;


int main()
{
	LCD display;

	display.init();

	while (true) {
		++display;
		display.output();
		Sleep(100);
	}
	
	int(LCD::*pnumber) = &LCD::number;
	cout << display.number << endl << display.*pnumber << endl;
	cout << (int)display << endl;

	_getch();
	return 0;
}
