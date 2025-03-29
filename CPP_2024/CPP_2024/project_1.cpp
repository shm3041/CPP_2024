//이름, 주소, 암호를 입력받아 출력하는 프로그램

#include <iostream>
#include <cstring> // strcmp 함수를 사용하기 위해 불러옴
using namespace std;

int main() {
	char name[20];
	cout << "이름을 입력하세요: ";
	cin >> name;
	cout << "이름은 " << name << "입니다." << endl;

	cin.ignore(); //cin.getline 사용을 위해 버퍼를 비워줌

	char home_address[100];
	cout << "주소를 입력하세요: ";
	cin.getline(home_address, 100, '\n'); //주소 사이에는 띄어쓰기가 있으므로 getline 사용
	cout << "주소는 " << home_address << "입니다." << endl;


	char pw1[50];
	char pw2[50];
	//암호가 올바르게 입력되지 않으면 다시 입력하도록 while 사용
	while (1) {
		cout << "새 암호를 입력하세요: ";
		cin >> pw1;
		cout << "암호를 한번 더 입력하세요: ";
		cin >> pw2;

		//pw1과 pw2를 비교 후 값이 일치하면 반복문을 빠져나오도록 함
		if (strcmp(pw1, pw2) == 0) {
			cout << "암호가 올바르게 입력되었습니다." << endl;
			break;
		}
		else
			cout << "암호가 일치하지 않습니다." << endl;
	}

	return 0;
}

/*
처음 cin.getline을 사용하여 코드를 짜고 실행하였을 때 주소를 입력하지 않아도 
다음 단계(암호 입력)로 넘어가서 당황하였으나 구글링을 하여 개행 문자를 버퍼에서 비워주면 된다는 것을 알게되어
cin.ignore()을 사용하여 문제를 해결하였다.
*/