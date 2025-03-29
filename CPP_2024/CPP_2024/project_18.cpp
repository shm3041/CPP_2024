//직업별 공격력을 랜덤으로 생성하여 출력하는 프로그램

#include <iostream>
#include <ctime> //난수 생성을 위해

class Character {
protected: //상속을 위하여 protected 선언
	std::string type; //종류
	int attack; //공격력
public:
	Character() {} //기본 생성자
	Character(std::string type, int attack) : type(type), attack(attack) {} //type, attack 변수 초기화
	virtual void print() { //각 직업에서 본인의 정보를 출력해줘야 되니까 virtual 사용
		std::cout << "종류: " << type << " / " << "공격력: " << attack << std::endl;
	}
};

class Warrior : public Character { //type, attack 변수 사용을 위해 상속
private:
	int specialSkill; //특수기
public:
	//Character에서 상속받은 type, attack과 specialSkill변수를 초기화
	Warrior(std::string type, int attack, int specialSkill)
		: Character(type, attack), specialSkill(specialSkill) {
	}
	void print() override { //Warrior의 print함수를 사용한다고 명시
		std::cout << "종류: " << type << " / " << "공격력: " <<
			attack << " / " << "특수기 : " << specialSkill << std::endl;
	}
};

class Thief : public Character { //type, attack 변수 사용을 위해 상속
private:
	int specialSkill; //특수기
public:
	//Character에서 상속받은 type, attack과 specialSkill변수를 초기화
	Thief(std::string type, int attack, int specialSkill)
		: Character(type, attack), specialSkill(specialSkill) {
	}
	void print() override { //Warrior의 print함수를 사용한다고 명시
		std::cout << "종류: " << type << " / " << "공격력: " <<
			attack << " / " << "특수기 : " << specialSkill << std::endl;
	}
};

class Wizard : public Character { //type, attack 변수 사용을 위해 상속
private:
	int specialSkill; //특수기
public:
	//Character에서 상속받은 type, attack과 specialSkill변수를 초기화
	Wizard(std::string type, int attack, int specialSkill)
		: Character(type, attack), specialSkill(specialSkill) {
	}
	void print() override { //Warrior의 print함수를 사용한다고 명시
		std::cout << "종류: " << type << " / " << "공격력: " <<
			attack << " / " << "특수기 : " << specialSkill << std::endl;
	}
};

int main() {
	srand(time(NULL)); //랜덤 함수를 생성하기 위해 사용
	Character* C[10]; //Character 포인터형 배열 생성 (직업 객체 관리)
	//Character로 만든 이유는 모든 직업이 Character을 상속받았기 때문
	for (int i = 0; i < 10; i++) {
		int random = rand() % 8 + 1; //최소 1 최대 9 난수 생성
		int r_damage = rand(); //난수 생성
		if (1 <= random && random <= 3) //random이 1 이상, 3 이하라면 Wizard 객체 생성
			C[i] = new Wizard("마법사", r_damage, r_damage * 1);
		else if (4 <= random && random <= 6) //random이 4 이상, 6 이하라면 Thief 객체 생성
			C[i] = new Thief("도적", r_damage, r_damage * 2);
		else //그 외(7 이상 9이하라면 Warrior 객체 생성
			C[i] = new Warrior("전사", r_damage, r_damage * 3);
	}

	for (int i = 0; i < 10; i++) { C[i]->print(); } //직업별 정보 출력
	for (int i = 0; i < 10; i++) { delete C[i]; } //동적 메모리 할당 해제

	return 0;
}
