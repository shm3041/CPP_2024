//vector을 이용하여 1-100까지의 난수 중 10의 배수가 아닌 수를 저장,
//이를 오름차순으로 정렬하여 출력, 평균을 출력하는 프로그램

#include <iostream>
#include <time.h> //난수 생성을 위해 include
#include <vector> //vector함수 사용을 위해 include
#include <algorithm> //sort함수 사용을 위해 include

int main() {
	srand(time(NULL)); //난수 생성을 위한 선언
	std::vector<int> v; //int자료가 들어갈 수 있는 벡터 v 생성

	//만약 random(난수)이 10의 배수라면 반복문을 탈출, 아니라면 v에 삽입
	while (1) {
		int random = rand() % 100 + 1; //난수 저장
		if (random % 10) v.push_back(random); //만약 10의 배수가 아니라면 생성된 난수를 v에 삽입
		else break; //10의 배수가 나오면 반복문 탈출
	}

	//vector의 첫 번째 원소부터 마지막 원소까지 모든 값을 더해서 result에 넣기
	double result = 0; //평균값 저장할 변수
	std::vector<int>::iterator it; //iterator변수 선언
	for (it = v.begin(); it != v.end(); it++) {
		result += *it;
	}
	result = result / v.size(); //result 값 나누기 벡터의 원소 개수

	sort(v.begin(), v.end()); //오름차순으로 정렬

	for (it = v.begin(); it != v.end(); it++) std::cout << *it << ' '; //모든 원소 출력
	std::cout << std::endl << result << std::endl; //평균 출력

	return 0;
}

/*
난수 생성 시 rand() % 99 + 1을 하면 1 부터 99 + 1의 값이 생성되는 줄 알았는데 
이번에 조교님이 그렇게 하면 1부터 99까지만 생성된다고 알려주셔서 잘못된 지식을 고칠 수 있었습니다. 
STL에 있는 vector를 사용할 수 있게 된다면 DFS, BFS를 배울 때 편하다고 알고 있었는데 
이번 기회를 통해 vector의 사용법을 알게 되어서 이에 관한 고민을 해결할 수 있었습니다. 
이번 수업을 통해 STL 사용법을 알게되어 유익하였습니다.
*/