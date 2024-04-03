/*게임공학과 2019180013 두혁찬*/

#include <iostream>
#include <cstring>


int toNum(const char* word) {
	if (strcmp(word, "가위") == 0)
		return -1;
	else if (strcmp(word, "바위") == 0)
		return 0;
	else if (strcmp(word, "보") == 0)
		return 1;
	else
		std::cout << "잘못 입력하셨습니다." << std::endl;
		return 2; // 유효하지 않은 입력
}
void RSP(int P1, int P2) {

	if (P1 == P2) {
		std::cout << "비겼습니다." << std::endl;
	}
	else{
		if (P1 == -1) {
			if(P2 == 0) std::cout << "사용자2가 이겼습니다." << std::endl;
			else std::cout << "사용자1이 이겼습니다." << std::endl;
		}
		else if (P1 == 0) {
			if (P2 == -1) std::cout << "사용자1이 이겼습니다." << std::endl;
			else std::cout << "사용자2가 이겼습니다." << std::endl;
		}
		else if (P1 == 1) {
			if (P2 == -1) std::cout << "사용자2가 이겼습니다." << std::endl;
			else std::cout << "사용자1이 이겼습니다." << std::endl;
		}		
	}
}
int main() {
	char p1[10];
	char p2[10];
	int P1, P2;

	std::cout << "가위 바위 보 게임을 합니다.가위, 바위, 보 중에서 입력하세요." << std::endl;

	std::cout << "사용자1>> ";
	std::cin >> p1;
	P1 = toNum(p1);
	if (P1 == 2) return 1;

	std::cout << "사용자2>> ";
	std::cin >> p2;
	P2 = toNum(p2);
	if (P2 == 2) return 1;

	RSP(P1, P2);
}