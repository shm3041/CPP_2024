//배열 크기 및 요소를 입력받고 요소를 반대로 출력 및 요소의 합을 출력하는 프로그램

#include <iostream>

//배열에 있는 값을 거꾸로 출력한다.
int reverse(int arr[], int num) {
	std::cout << "배열을 반대로 출력" << std::endl;
	for (int i = num - 1; i >= 0; i--) {
		std::cout << arr[i] << " ";
	}

	return 0;
}

//배열에 있는 값을 모두 더하고 이를 메인 함수로 리턴한다.
int sum(int arr[], int num) {
	int sum = 0;

	for (int i = 0; i < num; i++) {
		sum += arr[i];
	}

	return sum;
}

int main() {
	int num = 0;
	int* arr;

	//사용자에게 배열의 크기를 입력받고, 1이상 10이하로 입력하였다면 반복문을 탈출
	while (1) {
		std::cout << "배열의 크기를 정해주세요: ";
		std::cin >> num;
		if (1 <= num && num <= 10) break;
		else std::cout << "1이상 10 이하로 설정하여 주세요." << std::endl;
	}

	//사용자에게 입력받은 크기만큼 메모리에 공간 할당
	arr = new int[num];
	std::cout << "정수를 입력하세요: ";

	//배열에 들어갈 수 입력받기
	for (int i = 0; i < num; i++) {
		std::cin >> arr[i];
	}

	//reverse함수 호출
	reverse(arr, num);

	//배열에 있는 값을 모두 더하는 함수(sum)를 호출하고 리턴받은 값을 출력한다.
	std::cout << std::endl << "모든 정수의 합: " << sum(arr, num) << std::endl;

	//arr배열의 메모리 할당 해제
	delete[] arr;
	return 0;

}
