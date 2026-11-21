#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
#include <list>
#include <cctype>

/*
9. Define an Order class with (customer) name, address, data, and
vector<Purchase> members. Purchase is a class with a (product) name, unit_price,
and count members. Define a mechanism for reading and writing Orders to and
from a file. Define a mechanism for printing Orders. Create a file of at least
ten Orders, read it into a vector<Order>, sort it by name (of customer), and
write it back out to a file.
Create another file of at least ten Orders of which about a third are the same
as in the first file, read it into a write it back out to a file. Merge the two
files into a third using std::merge().
*/

/*
10. Compute the total value of the orders in the two files from the previous 
exercise. The value of an individual Purchase is (of course) its unit_price*count.
*/

std::string trim(const std::string& s) {
    std::size_t start = 0;
    while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start]))) ++start;
    std::size_t end = s.size();
    while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1]))) --end;
    return s.substr(start, end - start);
}

class Purchase {
public:
    Purchase() : pName(), unit_price(), count() {}
    Purchase(const std::string& n, double up, int c)
        : pName(n), unit_price(up), count(c) {}

    bool is_empty() const { return pName.empty(); }

    double getPrice() const {
        return unit_price;
    }

    int getCount() const {
        return count;
    }

    friend std::istream& operator>>(std::istream& ist, Purchase& p) {
        char ch;
        if (!(ist >> ch)) return ist;

        if (ch != '{') throw std::runtime_error("Expected '{' for Purchase.");

        std::string content;
        if (!std::getline(ist, content, '}')) {
            throw std::runtime_error("Missing '}' for Purchase.");
        }

        content = trim(content);

        if (content.empty()) {
            p = Purchase();
            return ist;
        }

        std::istringstream ss(content);
        std::string raw_name;

        if (!std::getline(ss, raw_name, '|')) {
            throw std::runtime_error("Missing '|' in Purchase.");
        }

        p.pName = trim(raw_name);

        if (!(ss >> p.unit_price >> p.count) || p.pName.empty()) {
            throw std::runtime_error("Bad Purchase values.");
        }

        return ist;
    }

    friend std::ostream& operator<<(std::ostream& ost, const Purchase& p) {
        ost << "{ " << p.pName << " | " << p.unit_price << " " << p.count <<
            " }";

        return ost;
    }

private:
    std::string pName;
    double unit_price;
    int count;
};

class Order {
public:
    Order() : custName(), address(), data(), purchases() {}
    Order(const std::string& cn, const std::string& ad, const std::string& d)
        : custName(cn), address(ad), data(d), purchases() {}

    const std::string& getName() const {
        return custName;
    }

    const std::string& getAddress() const {
        return address;
    }

    const std::vector<Purchase>& getPurchases() const {
        return purchases;
    }

    friend std::istream& operator>>(std::istream& ist, Order& o) {
        o = Order();

        std::string header_line;
        while (std::getline(ist, header_line) && trim(header_line).empty()) {}
        if (!ist) return ist;

        std::istringstream header_ss(header_line);
        std::string name, addr, extra;

        if (!std::getline(header_ss, name, '|') ||
            !std::getline(header_ss, addr, '|') ||
            !std::getline(header_ss, extra)) {
            throw std::runtime_error("Bad Order header format.");
        }

        o.custName = trim(name);
        o.address = trim(addr);
        o.data = trim(extra);

        std::string purchases_line;
        if (!std::getline(ist, purchases_line)) {
            throw std::runtime_error("Missing purchases line for Order.");
        }

        std::istringstream purchases_ss(purchases_line);
        Purchase purTemp;
        while (purchases_ss >> purTemp) {
            if (!purTemp.is_empty()) {
                o.purchases.push_back(purTemp);
            }
        }

        return ist;
    }

    friend std::ostream& operator<<(std::ostream& ost, const Order& o) {
        ost << o.custName << " | " << o.address << " | " << o.data <<
            "\n";

        for (size_t i = 0; i < o.purchases.size(); i++) {
            ost << o.purchases[i] << " ";
        }

        ost << "\n";

        return ost;
    }

private:
    std::string custName;
    std::string address;
    std::string data; //additional data
    std::vector<Purchase> purchases;
};

struct orderByName {
    bool operator()(const Order& a, const Order& b) const {
        return a.getName() < b.getName();
    }
};

struct orderByAddress {
    bool operator()(const Order& a, const Order& b) const {
        return a.getAddress() < b.getAddress();
    }
};

struct sumPurchases {
    double operator()(double accum, const Purchase& p) const {
        return accum + (p.getCount() * p.getPrice());
    }
};

struct sumOrders {
    double operator()(double accum, const Order& o) const {
        return accum + std::accumulate(o.getPurchases().begin(), 
                                        o.getPurchases().end(),
                                        0.0,
                                        sumPurchases());
    }
};

int main() {

    try {
        std::ifstream ist("input21_9.txt");
        if (!ist) throw std::runtime_error("Can't open input file");

        std::vector<Order> vec;
        for (Order ord; ist >> ord;) {
            vec.push_back(ord);
        }

        std::sort(vec.begin(), vec.end(), orderByName());

        std::ofstream ost("output21_9.txt");
        if (!ost) throw std::runtime_error("Can't open output file");

        for (size_t i = 0; i < vec.size(); i++) {
            ost << vec[i];
        }

        std::cout << "File (from vector) successfully created!\n";

        std::ifstream ist2("input21_9_1.txt");
        if (!ist2) throw std::runtime_error("Can't open input file");

        std::list<Order> lst;

        for (Order ord; ist2 >> ord;) {
            lst.push_back(ord);
        }

        lst.sort(orderByAddress());

        std::ofstream ost2("output21_9_1.txt");
        if (!ost2) throw std::runtime_error("Can't open output file");

        for (std::list<Order>::const_iterator p = lst.begin();
            p != lst.end(); ++p) {
            ost2 << *p;
        }

        std::cout << "File (from list) successfully created!\n";

        //sorting again via names, to merge both structures
        lst.sort(orderByName());

        std::vector<Order> merged;

        std::merge(vec.begin(), vec.end(),
            lst.begin(), lst.end(),
            std::back_inserter(merged),
            orderByName());

        std::ofstream ost3("output21_9_2.txt");
        if (!ost3) throw std::runtime_error("Can't open output file.");

        for (size_t i = 0; i < merged.size(); i++) {
            ost3 << merged[i];
        }

        std::cout << "Merged File successfully created!\n";

        double accumOrdersVec = std::accumulate(vec.begin(),
                                                vec.end(),
                                                0.0,
                                                sumOrders());

        double accumOrdersLst = std::accumulate(lst.begin(),
                                                lst.end(),
                                                0.0,
                                                sumOrders());
        
        std::cout << "\nThe total value of the orders (vector) is: " <<
            accumOrdersVec << "\n";
        std::cout << "The total value of the orders (list) is: " <<
            accumOrdersLst << "\n";

        std::cout << "\nThe total value of both files is: " <<
            accumOrdersLst + accumOrdersVec << "\n";
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}