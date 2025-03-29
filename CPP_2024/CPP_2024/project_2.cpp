//�ζ� ��ȣ 6���� �Է¹ް� ����ڿ��� �ζ� ��ȣ 6���� �Է¹޾� ��÷ ���θ� Ȯ���ϴ� ���α׷�

#include <iostream>

int main() {
    int lotto_arr[6] = { 0, };
    int error_counter = 0;

    //�ߺ��Ǵ� ��, 1~45�� �ƴ� ���� �Է��Ͽ��ٸ� ��� �ݺ��ǵ��� while ���
    while (1) {
        //�ζ� ��ȣ 6�� �Է¹ޱ�.
        std::cout << "�ζ� ��ȣ 6���� �Է��ϼ���: ";
        for (int i = 0; i < 6; i++)
            std::cin >> lotto_arr[i];

        //�Է¹޴� �� �� �ߺ��Ǵ� ���� �ְų� 1~45�� �ƴ� ���� �ִٸ� ���� ī���� ����
        for (int i = 0; i < 6; i++) {
            for (int k = i + 1; k < 6; k++) {
                if (lotto_arr[i] == lotto_arr[k] || lotto_arr[k] < 1 || lotto_arr[k] > 45)
                    error_counter++;
            }
        }
        //���� ī���Ͱ� 0�̶�� Ż���ϰ� �ƴ϶�� ���� �޽��� ��� �� ī���͸� �ʱ�ȭ�ϰ� ó������ �̵�.
        if (error_counter == 0) break;
        else {
            std::cout << "�ߺ��Ǵ� ���� �ְų� 1~45�� �ƴ� ���� �Է��ϼ̽��ϴ�." << std::endl;
            error_counter = 0;
        }
    }

    //�ζ� ��ȣ ���
    std::cout << "�ζ� ��ȣ�� ���������� �����Ǿ����ϴ�." << std::endl << "���� �ζ� ��ȣ�� ";
    for (int i = 0; i < 6; i++)
        std::cout << lotto_arr[i] << " ";
    std::cout << "�Դϴ�." << std::endl;


    int u_lotto_arr[6] = { 0, };
    int u_fail = 0;
    //����� �ζ� ��ȣ �Է�
    std::cout << "����� �ζ� ��ȣ�� �Է��ϼ���: ";
    for (int i = 0; i < 6; i++)
        std::cin >> u_lotto_arr[i];

    //��÷ ���� Ȯ��
    for (int i = 0; i < 6; i++)
        if (lotto_arr[i] != u_lotto_arr[i]) u_fail++;

    if (u_fail == 0) std::cout << "���ϵ帳�ϴ�! ��÷�Ǽ̽��ϴ�!" << std::endl;
    else std::cout << "��÷���� �ʾҽ��ϴ�." << std::endl;


    return 0;
}

/*
ó������ �Է°� �迭�� ���� �ξ �ԷµǴ� ���� 1 ~ 45�� ��, 
�ߺ��Ǵ� ���� ���� �� �迭�� ������ ������ �ڵ尡 ���������� �������� ���������� 
6���� ���ڸ� ��� �Է¹ް� �� ���� �����ϴ� ������� �ڵ带 ®��.
*/