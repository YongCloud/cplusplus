/*
 * print binary coefficient (Pascal's Triangle).
 * reference to
 * runoob.com/cplusplus/cpp-examples-pyramid-pattern.html
 *
 * author xingjian
 * since 2019/12/28
 */
#include <iostream>
using namespace std;

#define SPACE "  "

int main()
{
	int rows, coef = 0;
	cout << "Enter number of rows: ";
	cin >> rows;

	for(int i = 0; i < rows; i++) {
		for(int space = 1; space <= rows-i; space++) {
			cout << SPACE;
		}

		for(int j = 0; j <= i; j++) {
			if (j == 0) {
				coef = 1;
			} else {
				coef = coef*(i-j+1)/j;
			}
			cout << coef << SPACE << " ";
		}
		cout << endl;
	}

	return 0;
}
