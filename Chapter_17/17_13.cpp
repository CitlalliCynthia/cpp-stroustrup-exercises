#include <iostream>
#include <string>

/*
11. Complete the “list of gods” example from §17.10.1 and run it.

12. Why did we define two versions of find()?

13. Modify the Link class from §17.10.1 to hold a value of a struct God. struct God should have members of type string: name, mythology, vehicle, and weapon. For example, God{"Zeus", "Greek", "", "lightning"} and God{"Odin", "Norse", "Eight-legged flying horse called Sleipner", "Spear called Gungnir"}. Write a print_all() function that lists gods with their attributes one per line. Add a member function add_ordered() that places its new element in its correct lexicographical position. Using the Links with the values of type God, make a list of gods from three mythologies; then move the elements (gods) from that list to three lexicographically ordered lists — one for each mythology.
*/

struct God {
    std::string name;
    std::string mythology;
    std::string vehicle;
    std::string weapon;

    God(const std::string& n, const std::string& m, const std::string& v, const std::string& w) : name(n), mythology(m), vehicle(v), weapon(w) {}

    friend bool operator==(const God& a, const God& b) {
        return (a.name == b.name &&
            a.mythology == b.mythology &&
            a.vehicle == b.vehicle &&
            a.weapon == b.weapon);
    }

    friend bool operator!=(const God& a, const God& b) {
        return !(a == b);
    }

    friend std::ostream& operator<<(std::ostream& ost, const God& god) {
        ost << "(Name: " << god.name << " Mythology: " << god.mythology <<
            " Vehicle: " << god.vehicle << " Weapon: " << god.weapon << ")";
        return ost;
    }
};

class Link {
public:
    God value;
    Link(const God& v, Link* p = NULL, Link* s = NULL)
        : value{ v }, prev{ p }, succ{ s } {
    }
    Link* insert(Link* n); // insert n before this object
    Link* add(Link* n); // insert n after this object
    Link* add_ordered(Link* n); //adds it in correct lexicographical position
    Link* erase(); // remove this object from list
    Link* find(const God& s); // find s in list
    const Link* find(const God& s) const; // find s in const list (see §18.5.1)
    Link* advance(int n); // move n positions in list
    Link* getBeginning(); //get the first element
    const Link* getBeginning() const;
    Link* next() const { return succ; }
    Link* previous() const { return prev; }
private:
    Link* prev;
    Link* succ;
};

Link* Link::insert(Link* n) // insert n before this object; return n
{
    if (n == NULL) return this;
    n->succ = this; // this object comes after n
    if (prev) prev->succ = n;
    n->prev = prev; // this object’s predecessor becomes n’s predecessor
    prev = n; // n becomes this object’s predecessor
    return n;
}

Link* Link::add(Link* n) // insert n after this object; return n
{
    if (n == NULL) return this;
    n->prev = this; // p comes before n
    if (succ) succ->prev = n;
    n->succ = succ; // p’s successor becomes n’s successor
    succ = n; // n becomes p’s successor
    return n;
}
Link* Link::erase() // remove *p from list; return p’s successor
{
    if (succ) succ->prev = prev;
    if (prev) prev->succ = succ;
    return succ;
}
Link* Link::find(const God& s) // find s in list;
// return null for “not found”
{
    Link* p = getBeginning();
    while (p) {
        if (p->value == s) return p;
        p = p->succ;
    }
    return NULL;
}

const Link* Link::find(const God& s) const // find s in const list
{
    const Link* p = getBeginning(); // Must be 'const Link*' because 'this' is constant
    while (p) {
        if (p->value == s) return p;
        p = p->next(); // We use next()
    }
    return NULL;
}

Link* Link::advance(int n) // move n positions in list
// return null for “not found”
// positive n moves forward, negative backward
{
    Link* p = this;
    if (p == NULL) return NULL;
    if (0 < n) {
        while (n--) {
            if (p->succ == NULL) return NULL;
            p = p->succ;
        }
    }
    else if (n < 0) {
        while (n++) {
            if (p->prev == NULL) return NULL;
            p = p->prev;
        }
    }
    return p;
}

Link* Link::getBeginning() {
    Link* p = this;
    while (p->prev) {
        p = p->prev;
    }
    return p;
}

const Link* Link::getBeginning() const {
    const Link* p = this;
    while (p->prev) {
        p = p->prev;
    }
    return p;
}

void print_all(Link* p)
{
    if (p == NULL) return;

    p = p->getBeginning();
    
    std::cout << "{ ";
    while (p) {
        std::cout << p->value;

        if (p->next() != NULL) {
            std::cout << ",\n";
        }

        p = p->next();
    }
    std::cout << " }";
}

int main() {

    Link* norse_gods = new Link((God("Thor", "Norse", "Chariot", "Mjolnir")));
    norse_gods = norse_gods->insert(new Link(God("Odin", "Norse", "Sleipner", "Gungnir")));
    norse_gods = norse_gods->insert(new Link(God("Zeus", "Greek", "Pegasus", "Lightning")));
    norse_gods = norse_gods->insert(new Link(God("Freia", "Norse", "Pegasus", "Lightning")));
    Link* greek_gods = new Link(God("Hera", "Greek", "whatever", "whatever"));
    greek_gods = greek_gods->insert(new Link(God("Athena", "Greek", "whatever", "whatever")));
    greek_gods = greek_gods->insert(new Link(God("Mars", "Greek", "whatever", "whatever")));
    greek_gods = greek_gods->insert(new Link(God("Poseidon", "Greek", "whatever", "whatever")));

    Link* p = greek_gods->find(God("Mars", "Greek", "whatever", "whatever"));
    if (p) p->value = God("Ares", "Greek", "whatever", "whatever");

    Link* p2 = norse_gods->find(God("Zeus", "Greek", "Pegasus", "Lightning"));
    if (p2) {
        if (p2 == norse_gods) norse_gods = p2->next();
        p2->erase();
        greek_gods = greek_gods->insert(p2);
    }

    print_all(norse_gods);
    std::cout << "\n";
    print_all(greek_gods);
    std::cout << "\n";

    return 0;
}