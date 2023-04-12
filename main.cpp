#include <memory>
#include "Stack.h"

using namespace std;

template <class T>
T inputStream(istream& is = cin) {
	T tmp;
	is >> tmp;
	return tmp;
}

void printMenu() {
	cout << "*******************************************\n";
	cout << "* 1. 삽입    2. 삭제    3. 출력   4. 종료 *\n";
	cout << "*******************************************\n";
	cout << "\n원하시는 메뉴를 골라주세요: ";
}

using Container = LinkedList<int>;

int main(){
	unique_ptr<Container> container;
	bool exit = false;


	cout << "자료구조 선택(1: Stack, Other: Linked List): ";

	if(inputStream<int>() == 1)
		container = make_unique<Stack<int>>();
	else
		container = make_unique<LinkedList<int>>();
	
	int tmp;
	while(!exit) {
		printMenu();

		switch(inputStream<int>()) { 
		case 1:
			cout << "원하시는 값을 입력해주세요: ";
			cin >> tmp;
			container->insert(tmp);
			cout << tmp << "가 삽입되었습니다.\n";
			break;				
		case 2:
			if(container->erase(tmp))
				cout << tmp << "가 삭제되었습니다.\n";
			else 
				cout << "비어있습니다. 삭제 실패\n";
			break;
		case 3:
			cout << "크기: " << container->size() << '\n';
			container->print();
			break;
		case 4:
			exit = true;
			break;
		default:
			cout<<"잘못 입력하셨습니다."<<endl;
		}		
	};
		
	return 0;
}

