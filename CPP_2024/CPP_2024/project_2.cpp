//로또 번호 6개를 입력받고 사용자에게 로또 번호 6개를 입력받아 당첨 여부를 확인하는 프로그램

#include <iostream>

int main() {
    int lotto_arr[6] = { 0, };
    int error_counter = 0;

    //중복되는 값, 1~45가 아닌 값을 입력하였다면 계속 반복되도록 while 사용
    while (1) {
        //로또 번호 6개 입력받기.
        std::cout << "로또 번호 6개를 입력하세요: ";
        for (int i = 0; i < 6; i++)
            std::cin >> lotto_arr[i];

        //입력받는 값 중 중복되는 값이 있거나 1~45가 아닌 값이 있다면 에러 카운터 증가
        for (int i = 0; i < 6; i++) {
            for (int k = i + 1; k < 6; k++) {
                if (lotto_arr[i] == lotto_arr[k] || lotto_arr[k] < 1 || lotto_arr[k] > 45)
                    error_counter++;
            }
        }
        //에러 카운터가 0이라면 탈출하고 아니라면 에러 메시지 출력 후 카운터를 초기화하고 처음으로 이동.
        if (error_counter == 0) break;
        else {
            std::cout << "중복되는 값이 있거나 1~45가 아닌 값을 입력하셨습니다." << std::endl;
            error_counter = 0;
        }
    }

    //로또 번호 출력
    std::cout << "로또 번호가 성공적으로 지정되었습니다." << std::endl << "금일 로또 번호는 ";
    for (int i = 0; i < 6; i++)
        std::cout << lotto_arr[i] << " ";
    std::cout << "입니다." << std::endl;


    int u_lotto_arr[6] = { 0, };
    int u_fail = 0;
    //사용자 로또 번호 입력
    std::cout << "사용자 로또 번호를 입력하세요: ";
    for (int i = 0; i < 6; i++)
        std::cin >> u_lotto_arr[i];

    //당첨 여부 확인
    for (int i = 0; i < 6; i++)
        if (lotto_arr[i] != u_lotto_arr[i]) u_fail++;

    if (u_fail == 0) std::cout << "축하드립니다! 당첨되셨습니다!" << std::endl;
    else std::cout << "당첨되지 않았습니다." << std::endl;


    return 0;
}

/*
처음에는 입력과 배열을 따로 두어서 입력되는 값이 1 ~ 45일 때, 
중복되는 값이 없을 때 배열에 넣으려 했으나 코드가 복잡해지고 가독성이 안좋아져서 
6개의 숫자를 모두 입력받고 그 값을 검증하는 방식으로 코드를 짰다.
*/