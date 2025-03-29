//학생 정보를 구조체로 입력받고, 국, 영, 수, 평균 중 하나를 선택하여 내림차순으로 정렬하여 출력하는 프로그램

#include <iostream>
#include <cstdlib> //qsort 함수 사용을 위해 불러옴 
#include <cstring> //strcmp 함수 사용을 위해 불러옴 
#define SIZE 3
char choice[30]; //국, 영, 수, 평균 선택지 저장 

//학생 정보 구조체(국어, 영어, 수학, 평균) 
struct student {
	char name[30];
	int korean, english, math, avg;
};

//qsort 함수 사용을 위한 compare 함수 생성 
int compare(const void* a, const void* b);

int main() {
	//포인터로 구조체 배열 S 생성 (크기: 3) 
	struct student* S = new struct student[SIZE];

	//학생 정보 입력받기 
	std::cout << "학생 3명의 이름, 국어, 영어, 수학 점수를 입력해주세요" << std::endl;
	for (int i = 0; i < 3; i++) {
		std::cin >> S[i].name >> S[i].korean >> S[i].english >> S[i].math; //이름, 국, 영, 수 
		S[i].avg = (S[i].korean + S[i].english + S[i].math) / 3; //평균 
	}

	//국, 영, 수, 평균 선택지 입력 후 정렬 
	std::cout << "국어, 영어, 수학, 평균 중 하나를 선택하세요: ";
	std::cin >> choice;
	qsort(S, SIZE, sizeof(struct student), compare);

	//점수가 높은 순으로 이름 출력 
	std::cout << "점수가 가장 높은 순서로 이름을 출력합니다." << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << S[i].name << " ";

	//메모리 할당 해제 
	delete[] S;
	return 0;
}

int compare(const void* a, const void* b) {
	//struct student형식으로 변환하여 x, y로 받기 
	struct student x = *(struct student*)a;
	struct student y = *(struct student*)b;

	//내림차순 정렬이므로 y에서 x를 빼준다.
	if (strcmp(choice, "국어") == 0) return y.korean - x.korean;
	else if (strcmp(choice, "영어") == 0) return y.english - x.english;
	else if (strcmp(choice, "수학") == 0) return y.math - x.math;
	else return y.avg - x.avg;
}

/*
이 코드를 작성할때 처음에는 qsort를 사용하려 했으나 compare 함수 작성법이 기억나지 않아서
수업 시간 때는 버블 정렬 코드를 직접 짜서 성적을 오름차순으로 정렬 후 이름을 역순으로 출력하였다.
하지만 집에와서 보니 코드가 너무 길어지고 가독성이 떨어져서 퀵정렬 함수를 사용하였다.
std::cin으로 문자열을 입력받는 부분도 scanf로만 해봐서 헷갈렸으나 금방 적응하였다.
*/