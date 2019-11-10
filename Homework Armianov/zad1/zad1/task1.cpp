using namespace std;
#include <iostream>


int main() {
	int hemmingNumber = 1;
	int number;
	cin >> number;
	int counter = 1;
	cout << hemmingNumber<<" ";
	while (counter < number) {
		if (hemmingNumber % 2 == 0 || hemmingNumber % 3 == 0 || hemmingNumber % 5 == 0) {
			++counter;
			cout << hemmingNumber << " ";
		}
		++hemmingNumber;
	}
	return 0;
}