#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

/*
3. Write a template class Pair that can hold a pair of values of any type. Use this to implement a simple symbol
table like the one we used in the calculator (§7.8).
*/

template<typename T, typename U>
struct Pair {
	T first;
	U second;

	Pair(T f, U s) : first(f), second(s) {}
};

//Symbol table
class Symbol_table {
private:
    std::vector<Pair<std::string, double> > var_table;

public:
    //Checks if a variable already exists
    bool is_declared(const std::string& name) const {
        for (size_t i = 0; i < var_table.size(); ++i) {
            if (var_table[i].first == name) return true;
        }
        return false;
    }

    //Gets the value of an existent variable
    double get(const std::string& name) const {
        for (size_t i = 0; i < var_table.size(); ++i) {
            if (var_table[i].first == name) return var_table[i].second;
        }
        throw std::runtime_error("get: variable not defined -> " + name);
    }

    //Changes the value of an existent variable
    void set(const std::string& name, double val) {
        for (size_t i = 0; i < var_table.size(); ++i) {
            if (var_table[i].first == name) {
                var_table[i].second = val;
                return;
            }
        }
        throw std::runtime_error("set: variable not defined -> " + name);
    }

    //Adds a new variable to the table
    double declare(const std::string& name, double val) {
        if (is_declared(name)) {
            throw std::runtime_error("declare: variable declared twice -> " + name);
        }
        var_table.push_back(Pair<std::string, double>(name, val));
        return val;
    }
};

int main() {
    try {
        Symbol_table st;

        st.declare("pi", 3.14159);
        st.declare("x", 10.0);

        std::cout << "pi = " << st.get("pi") << "\n";
        std::cout << "x = " << st.get("x") << "\n";

        st.set("x", 25.5);
        std::cout << "New value of x = " << st.get("x") << "\n";

        std::cout << st.get("z") << "\n";
    }
    catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    return 0;
}