#include <iostream>
#include <string>

int main() {
	// ��Ʈ�� ����
	std::string str; // �� ���ڿ��� ���� ��Ʈ�� ��ü ����
	std::string address("����� ���ϱ� �Ｑ�� 389");
	std::string copyAddress(address); // address�� ���ڿ��� ������ ��Ʈ�� ��ü ����
	char text[] = { 'L', 'o', 'v', 'e', ' ', 'C', '+', '+', '\0' }; // C-��Ʈ��
	std::string title(text); // "Love C++" ���ڿ��� ���� ��Ʈ�� ��ü ����
	// ��Ʈ�� ���
	std::cout << str << std::endl; // �� ��Ʈ��. �ƹ� ���� ��µ��� ����
	std::cout << address << std::endl;
	std::cout << copyAddress << std::endl;
	std::cout << title << std::endl;
}