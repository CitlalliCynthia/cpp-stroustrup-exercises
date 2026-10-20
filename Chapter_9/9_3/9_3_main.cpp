#include "9_3.h"

int main() {

	pairs::Name_pairs Obj1 = pairs::Name_pairs();

	Obj1.read_names();

	pairs::Name_pairs Obj2 = Obj1;

	//Obj1.print("Pairs introduced:");
	std::cout << "\nPairs introduced (Obj1):\n" << Obj1;

	Obj1.sortNameAndAge();

	pairs::Name_pairs Obj3 = Obj1;

	//Obj1.print("Pairs sorted:");
	std::cout << "\nPairs introduced (Obj1):\n" << Obj1;

	if (Obj1 == Obj2) { //Not gonna be
		std::cout << "Obj1 and Obj2 are both are equal!";
	}
	else if (Obj1 != Obj2) { //Gonna be
		std::cout << "Obj1 and Obj2 are not equal!\n";
		}

	if(Obj1 == Obj3) std::cout << "Obj1 and Obj3 are equal!\n"; //Gonna be

	return 0;
}