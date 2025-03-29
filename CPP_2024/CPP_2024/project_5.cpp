//10-20사이의 정수를 입력받고 값이 
//짝수일 경우 짝수를 출력, 홀수는 X로 출력
//홀수일 경우 홀수를 출력, 짝수는 X로 출력하는 프로그램

#include <iostream>
using namespace std;

int main() {
	int* arr;
	int size;

	//배열 사이즈 입력
	cout << "정수를 입력하세요: ";
	while (1) {
		cin >> size;
		if (10 <= size && size <= 20) break;
		else cout << "10 ~ 20사이의 정수를 입력하세요: ";
	}

	//배열 사이즈 설정
	arr = new int[size];

	//짝수일 경우 실행
	if (size % 2 == 0) {
		for (int i = 0; i < size; i++)
			//짝수일 경우 i를 배열에 삽입, 홀수일 경우 4444를 배열에 삽입
			i % 2 == 0 ? arr[i] = i : arr[i] = 4444;
	}
	//홀수일 경우 실행
	else {
		for (int i = 0; i < size; i++)
			//홀수일 경우 i를 배열에 삽입, 짝수일 경우 4444를 배열에 삽입
			i % 2 != 0 ? arr[i] = i : arr[i] = 4444;
	}

	//배열에 있는 값이 4444일 경우 X라 출력
	for (int i = 0; i < size; i++)
		arr[i] != 4444 ? cout << arr[i] << " " : cout << "X ";

	//제일 뒤에 값 출력
	cout << size;

	delete[] arr;
	return 0;
}

/*
처음에는 배열을 int형이 아닌 char로 선언하여 배열안에 X와 수를 모두 넣으려 했으나
char로 선언한 배열에 수를 넣는 방법을 몰라서 배열을 int형으로 만들었으며 X대신
4444를 넣어 출력 시 4444라면 X가 출력되도록 하였다.

X대신 4444를 넣는 부분도 4444대신 0이 들어가도록 하였는데 입력값이 짝수일 경우 
0까지 X로 출력되어 4444가 들어가도록 바꾸었다.
*/