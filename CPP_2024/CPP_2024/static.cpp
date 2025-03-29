#include <iostream>

static int cnt = 0;

void Count() {
	static int cnt;
	cnt++;
	printf("%d\n", cnt);
}

int main() {
	Count();
	printf("%d\n", cnt);
	Count();
	printf("%d\n", cnt);

	return 0;
}
/*
본래 지역 변수는 함수가 종료되면 사라지나 static으로 선언한 변수는 프로그램이 종료될 때 사라진다.
따라서 Count()가 종료되어도 cnt의 값은 1이며, 다음 Count()가 실행 될 때 cnt는 2가 된다.
하지만 이 static으로 선언한 변수에 접근하기 위해서는 동일한 함수에서 해야하며, 
main이나 다른 함수에서는 이 값에 접근할 수 없다.
*/