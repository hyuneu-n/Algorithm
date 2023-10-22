#include <iostream>
using namespace std;

int CoinChange(int W);

int main() {
	int change;

	cout << "거스름돈을 입력하세요 >> ";
	cin >> change;

	int result = CoinChange(change);
	cout << result << endl;
}

int CoinChange(int W) {
	int change = 0;
	int n500 = 0;
	int n100 = 0;
	int n50 = 0;
	int n10 = 0;
	int n1 = 0;

	while (change >= 500)
		change -= 500;
	n500++;

	while (change >= 100)
		change -= 100;
	n100++;

	while (change >= 50)
		change -= 50;
	n50++;

	while (change >= 10)
		change -= 10;
	n10++;

	while (change >= 1)
		change -= 1;
	n1++;

	return (n500 + n100 + n50 + n10 + n1);
}