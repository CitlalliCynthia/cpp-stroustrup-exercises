#include <iostream>
#include <string>
#include <vector>

/*
13. Write a Tracer class where its constructor prints a string and its destructor prints a string. 
Give the strings as constructor arguments. Use it to see where RAII management objects will do their 
job (i.e., experiment with Tracers as local objects, member objects, global objects, objects allocated
by new, etc.). Then add a copy constructor and a copy assignment so that you can use Tracer objects to
see when copying is done.
*/

struct Tracer {

	Tracer(const std::string& s) : output(s) {
		std::cout << "Hey! Constructor called!\n";
		std::cout << "-- " << output << " --\n\n";
	}
	
	Tracer(const Tracer& t) : output(t.output) {
		std::cout << "Hey! Copy Constructor called!\n";
		std::cout << "-- " << output << " --\n\n";
	}

	Tracer& operator=(const Tracer& t) {
		std::cout << "Hey! Copy Assignment called!\n";
		std::cout << "-- Old value: " << output << ", New value: " << t.output << "--\n\n";
		output = t.output;
		return *this;
	}

	~Tracer() {
		std::cout << "Hey! Destructor called!\n";
		std::cout << "-- " << output << " --\n\n";
	}
	
private:
	std::string output;
};

Tracer t("Global variable");

int main() {

	{
		Tracer t1("Inside a block");
	}
	
	Tracer* p = new Tracer("Dinamic memory");

	Tracer a("Objet A");
	Tracer b_assign("Objet B");
	b_assign = a;

	struct box {
		Tracer t;

		box() : t(Tracer("Inside a struct")) {}
	};

	box b;
	
	std::vector<Tracer> vec;
	vec.push_back(Tracer("Inside a vector"));

	delete p;

	return 0;
}