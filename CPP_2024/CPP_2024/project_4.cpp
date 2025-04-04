//배열의 요소 5개를 입력받고, 배열의 요소를 반대로 바꾸어 저장하고 출력하는 프로그램

#include <iostream>

//reverse 함수에 arr배열의 포인터를 받음
void reverse(int* arr) {

	//배열안에 있는 값 반대로 바꾸기
	int temp; //배열에 있는 정수 임시 저장할 변수
	// 배열 중앙을 기준으로 양쪽의 값을 바꿀 것이니 배열 크기 /2한 만큼 반복문 실행
	for (int i = 0; i < 5 / 2; i++)
	{
		temp = arr[i]; // i번째의 원소를 temp에 저장
		arr[i] = arr[5 - i - 1]; //중앙을 기준으로 대칭되게 오른쪽 값을 왼쪽에 저장
		arr[5 - i - 1] = temp; //temp에 저장해놨던 값을 배열에 저장
	}

}

int main() {
	int arr[5];
	//arr배열에 들어갈 값 입력받기
	std::cout << "정수 5개를 입력하세요: ";
	for (int i = 0; i < 5; i++) {
		std::cin >> arr[i];
	}

	//reverse 함수 호출
	reverse(arr);

	//배열의 요소 출력
	for (int i = 0; i < 5; i++)
		std::cout << arr[i] << " ";

	return 0;
}

/*
배열의 포인터를 매개변수로 가져오는 것은 잘했으나 배열의 원소를 거꾸로 저장하는 것이 어려웠다.
처음에는 배열을 하나 더 만들어서 그곳에 값을 임시저장하고 다시 원래 배열로 값을 거꾸로 넣으려 했으나 
너무 비효율적이어서 현재의 방식으로 바꿨다.
*/