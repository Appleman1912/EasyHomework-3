using namespace std;
#include <iostream>
#include <bitset>

int main() {
	int n;
	do
	{
		cin >> n;
	} while (n <= 0 || n >= 32);

	unsigned int mask = 1;
	unsigned int ToCompare = 1;
	for (int i = 0; i < n - 1; i++) {
		mask = (mask << 1);
	}
	for (int i = 0; i < n - 2; i++) {
		ToCompare = (ToCompare << 1);
	}
	int number;
	cin >> number;
	for (int i = 1; i < n; i++) {
		int oldValue = number;
		cin >> number;
		if (oldValue <= number) {
			mask = mask | ToCompare;
		}
		ToCompare = (ToCompare >> 1);
	}
	//bitset<8> bset(mask);
	//cout << bset << endl;

	int counterOfOnes = 0;
	unsigned int MaskToCount = 1;
	for (int i = 0; i < n - 1; i++) {
		MaskToCount = (MaskToCount << 1);
	}
	for (int i = 0; i < n; i++) {
		if ((mask & MaskToCount) != 0) {
			++counterOfOnes;

		}
		MaskToCount = (MaskToCount >> 1);
	}
	int posOfOne = counterOfOnes / 2;
	int index = 0;
	unsigned int maskToFindOne = 1;
	for (int i = 0; i < n - 1; i++) {
		maskToFindOne = (maskToFindOne << 1);
	}
	int countLeft = 0;
	int countRight = 0;
	if (counterOfOnes % 2 == 0) {
		int counter = 1;
		for (int i = 0; i < n; i++) {
			if ((mask & maskToFindOne) != 0) {
				maskToFindOne = (maskToFindOne >> 1);
				if (index == posOfOne) {
					break;
				}
				++index;
			}
		}
		unsigned int ZerosCounter = 0;

		cout << "Index : " << index << endl;
		
		for (int i = 0; i < n; i++) {
			if (i == index) {
				continue;
			}
			if (i < index) {
				if ((mask & 1)) {
					continue;
				}
				else {
					countLeft++;
				}
			}
			else if(i>index)
			{
				if ((mask & 1)) {
					continue;
				}
				else {
					countRight++;
				}
			}
			mask = mask >> 1;
		}
		
	
	
	}
	cout << countLeft << " " << countRight << endl;


	return 0;
}