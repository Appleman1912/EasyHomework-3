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
	int counterOfOnes = 1;
	for (int i = 1; i < n; i++) {
		int oldValue = number;
		cin >> number;
		if (oldValue <= number) {
			mask = mask | ToCompare;
			++counterOfOnes;
		}
		ToCompare = (ToCompare >> 1);
	}
	//bitset<8> bset(mask);
	//cout << bset << endl;

	/*
	
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

	*/

	int posOfOne = counterOfOnes / 2;
	
	unsigned int maskToFindOne = 1;
	for (int i = 0; i < n - 1; i++) {
		maskToFindOne = (maskToFindOne << 1);
	}

	int index = 0,counter=0;
	cout << "Counter of ones: " << counterOfOnes << endl;
	if (counterOfOnes % 2 == 0) {
		//++index;
		//++counter;
		for (int i = 0; i < n; i++) {
			if ((mask & maskToFindOne) != 0) {
				if (counter == posOfOne-1) {
					break;
				}

				++counter;
			}
			maskToFindOne = (maskToFindOne >> 1);
			++index;

		}
	}
	else {
		//++index;
		for (int i = 0; i < n; i++) {
			if ((mask & maskToFindOne) != 0) {
				if (counter == posOfOne) {
					break;
				}
				++index;
				++counter;
			}
			maskToFindOne = (maskToFindOne >> 1);
		}
	}
	cout << "Index: " << index << endl;
	//if (counterOfOnes % 2 == 0) {
		//++index;
	//}
	maskToFindOne = 1;
	for (int i = 0; i < n-1; i++) {
		maskToFindOne = (maskToFindOne << 1);
	}
	bitset<6> ns(maskToFindOne);
	cout << ns<<endl;
	bitset<6> nss(mask);
	cout << nss << endl;
	unsigned int copy = mask;
	cout << "Index: " << index << endl;
	int countLeft = 0, countRight = 0;
	for (int i = 0; i < n; i++) {
		if (i == index) {
			maskToFindOne = (maskToFindOne >> 1);
			continue;
		}
		else if (i < index) {
			//cout<<"Restuly: " << (copy ^ maskToFindOne) << endl;
			bool bit = (copy & maskToFindOne);
			if (bit!=1) {
				++countLeft;
			}


		}
		else {

			bool bit = (copy & maskToFindOne);
			if (bit != 1) {
				++countRight;
			}

		}

		maskToFindOne = (maskToFindOne >> 1);
	}

	cout << "CountLeft: " << countLeft << "  CountRight: " << countRight << endl;
	if (countLeft < countRight) {
		cout << "Right Side" << endl;
	}
	else if (countLeft == countRight) {
		cout << "Equal Side" << endl;
	}
	else {
		cout << "Left Side" << endl;
	}
	//not wrong writing next idea
	/*
	
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
	
	*/

	cout << countLeft << " " << countRight << endl;


	return 0;
}