#include <iostream>
#include <vector>

using namespace std;

int least_step(int*list, int*pFlag, int len, int index) {
	int steps = 0;
	if (list[index] + index >= len) {
		pFlag[index] = 1;
		return 1;
	}
	if (list[index] == 0) {
		pFlag[index] = -1;
		return -1;
	}
	int steps_below = -1;
	for (int k = list[index]; k > 0; k--) {
		if (pFlag[index + k] == -1)
			continue;
		else if (pFlag[index + k] == 0) {
			int tmp = least_step(list, pFlag, len, index + k);
			if (tmp == -1)
				continue;
			if (steps_below == -1) {
				steps_below = tmp;
			}
			else {
				steps_below = tmp < steps_below ? tmp : steps_below;
			}
		}
		else
		{
			if (steps_below == -1)
				steps_below = pFlag[index + k];
			else
				steps_below = pFlag[index + k]<steps_below? pFlag[index+k]: steps_below;
		}


	}
	if (steps_below == -1) {
		pFlag[index] = -1;
		return -1;
	}
	pFlag[index] = steps_below + 1;
	return steps_below + 1;

}

int main(int argc, char**argv) {

	int num1;
	cin >> num1;
	int*pList = new int[num1];
	for (int i = 0; i < num1; i++)
		cin >> pList[i];
	int*pFlag = new int[num1];
	for (int i = 0; i < num1; ++i)
		pFlag[i] = 0;

	cout << least_step(pList, pFlag, num1, 0) << endl;

	system("pause");
	return 0;
}
