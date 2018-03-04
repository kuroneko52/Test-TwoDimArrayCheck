// Sroot.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class arrayCheck {
	int xSize;
	int ySize;
	int *p;
public:
	arrayCheck(int x, int y);
	~arrayCheck() { delete[] p; }
	int &put(int x, int y);
	int get(int x, int y);
};

arrayCheck::arrayCheck(int x, int y) {
	p = new int[x*y];
	xSize = x;
	ySize = y;
}

int &arrayCheck::put(int x, int y) {
	if (x < 0 || y < 0 || x >= xSize || y >= ySize) {
		cout << "境界エラー\n";
		exit(1);
	}

	return p[x*xSize + y];
}

int arrayCheck::get(int x, int y) {
	if (x < 0 || y < 0 || x >= xSize || y >= ySize) {
		cout << "境界エラー\n";
		exit(1);
	}

	return p[x*xSize + y];
}

int main()
{
	arrayCheck a(2, 3);

	/*a.put(0, 1) = 25;
	a.put(1, 2) = 3685;

	cout << a.get(0, 1) << " " << a.get(1, 2) << "\n";*/

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			a.put(i, j) = i + j;
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << a.get(i, j) << "\n";
		}
	}

	//Error Check Test
	a.put(2, 3);

	return 0;
}