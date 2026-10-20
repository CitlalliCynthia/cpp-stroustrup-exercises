#include "9_2.h"

int main() {

	pairs::Name_pairs Obj1 = pairs::Name_pairs();

	Obj1.read_names();

	Obj1.print("Pairs introduced:");

	Obj1.sortNameAndAge();

	Obj1.print("Pairs sorted:");

	return 0;
}