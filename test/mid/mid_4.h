class Dept {
	int size;
	int* scores;

public:
	Dept(int size) {
		this->size = size;
		scores = new int[size];
	}
	Dept(const Dept& Dept);
	~Dept();
	int getSize() { return size	; }
	void read();
	bool isOver60(int index);
};

inline Dept::Dept(const Dept& Dept){
	this->size = Dept.size;
	this->scores = Dept.scores;
}

inline Dept::~Dept()
{
}

void Dept::read() {

	std::cout << this->size<<"개 점수 입력 >> ";
	for (int i = 0; i < 10; i++) {
		std::cin >> this->scores[i];
	}
}

inline bool Dept::isOver60(int index)
{
	if (this->scores[index] > 60)return true;
	return false;
}
