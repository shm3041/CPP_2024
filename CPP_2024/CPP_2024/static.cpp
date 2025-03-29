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
���� ���� ������ �Լ��� ����Ǹ� ������� static���� ������ ������ ���α׷��� ����� �� �������.
���� Count()�� ����Ǿ cnt�� ���� 1�̸�, ���� Count()�� ���� �� �� cnt�� 2�� �ȴ�.
������ �� static���� ������ ������ �����ϱ� ���ؼ��� ������ �Լ����� �ؾ��ϸ�, 
main�̳� �ٸ� �Լ������� �� ���� ������ �� ����.
*/