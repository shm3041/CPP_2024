#include <iostream>

class CTest {
public:
	CTest() { std::cout << "CTest()" << std::endl; }
	void Testfunc() { std::cout << "CTest::TestFunc()" << std::endl; }
};

class CTestEx : public CTest {
public:
	CTestEx() { std::cout << "CTestEx()" << std::endl; }
	void Testfunc() { std::cout << "CTestEx::TestFunc()" << std::endl; }
};

int main() {
	CTestEx a;
	CTest& b = a;
	a.Testfunc();
	b.Testfunc();

	return 0;
}

//���α׷� ���� ����: CTestEx Ŭ������ a ��ü ����
//CTestEx�� CTest�� ��ӹް� �������� CTest�� �⺻ ������ ȣ��
//CTestŬ������ a��ü�� ����
//a��ü�� Testfunc�Լ� -> CTestEX::TestFunc()���
//b��ü�� Testfunc�Լ� -> CTestŬ�����̹Ƿ� CTest::TestFunc() ���
//�̰��� ���������̶� �ϸ� virtual Ű���带 ����Ͽ� override�� ���� �������̶� �Ѵ�.
