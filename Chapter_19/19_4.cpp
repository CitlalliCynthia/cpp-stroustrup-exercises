#include <iostream>
#include <string>

/*
4. Modify class Link from §17.9.3 to be a template with the type of value as the template argument. Then redo
exercise 13 from Chapter 17 with Link<God>.
*/

struct God {
    std::string name;
    std::string mythology;
    std::string vehicle;
    std::string weapon;

    God(const std::string& n, const std::string& m, const std::string& v, const std::string& w) : name(n), mythology(m), vehicle(v), weapon(w) {}

    friend bool operator>(const God& a, const God& b) {
        return a.name > b.name;
    }

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

template<typename T>
class Link {
public:
    T value;
    Link(const T& v, Link* p = NULL, Link* s = NULL)
        : value( v ), prev( p ), succ( s ) {
    }
    Link* insert(Link* n); // insert n before this object
    Link* add(Link* n); // insert n after this object
    Link* add_ordered(Link* n); //adds it in correct lexicographical position
    Link* erase(); // remove this object from list
    Link* find(const T& s); // find s in list
    const Link* find(const T& s) const; // find s in const list (see §18.5.1)
    Link* advance(int n); // move n positions in list
    Link* getBeginning(); //get the first element
    const Link* getBeginning() const;
    Link* next() const { return succ; }
    Link* previous() const { return prev; }
private:
    Link* prev;
    Link* succ;
};

template<typename T>
Link<T>* Link<T>::insert(Link<T>* n) // insert n before this object; return n
{
    if (n == NULL) return this;
    n->succ = this; // this object comes after n
    if (prev) prev->succ = n;
    n->prev = prev; // this object’s predecessor becomes n’s predecessor
    prev = n; // n becomes this object’s predecessor
    return n;
}

template<typename T>
Link<T>* Link<T>::add(Link<T>* n) // insert n after this object; return n
{
    if (n == NULL) return this;
    n->prev = this; // p comes before n
    if (succ) succ->prev = n;
    n->succ = succ; // p’s successor becomes n’s successor
    succ = n; // n becomes p’s successor
    return n;
}

template<typename T>
Link<T>* Link<T>::erase() // remove *p from list; return p’s successor
{
    if (succ) succ->prev = prev;
    if (prev) prev->succ = succ;
    return succ;
}

template<typename T>
Link<T>* Link<T>::find(const T& s) // find s in list;
// return null for “not found”
{
    Link<T>* p = getBeginning();
    while (p) {
        if (p->value == s) return p;
        p = p->succ;
    }
    return NULL;
}

template<typename T>
const Link<T>* Link<T>::find(const T& s) const // find s in const list
{
    const Link<T>* p = getBeginning(); // Must be 'const Link*' because 'this' is constant
    while (p) {
        if (p->value == s) return p;
        p = p->next(); // We use next()
    }
    return NULL;
}

template<typename T>
Link<T>* Link<T>::advance(int n) // move n positions in list
// return null for “not found”
// positive n moves forward, negative backward
{
    Link<T>* p = this;
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

template<typename T>
Link<T>* Link<T>::add_ordered(Link<T>* n) {

    if (n == NULL) return n;

    Link<T>* p = getBeginning();

    while (p) {
        if (p->value > n->value) {
            p->insert(n);
            break;
        }
        if (p->succ == NULL) {
            p->add(n);
            break;
        }
        p = p->succ;
    }

    return n->getBeginning();
}

template<typename T>
Link<T>* Link<T>::getBeginning() {
    Link<T>* p = this;

    while (p->prev) {
        p = p->prev;
    }
    return p;
}

template<typename T>
const Link<T>* Link<T>::getBeginning() const {
    const Link<T>* p = this;
    while (p->prev) {
        p = p->prev;
    }
    return p;
}

template<typename T>
void print_all(Link<T>* p)
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

template<typename T>
void destroy_list(Link<T>* p) {
    if (p == NULL) return;

    p = p->getBeginning();

    while (p) {
        Link<T>* next_node = p->next();
        delete p;
        p = next_node;
    }
}

int main() {

    Link<God>* mixed_gods = new Link<God>(God("Thor", "Norse", "Chariot", "Mjolnir"));
    mixed_gods = mixed_gods->insert(new Link<God>(God("Ra", "Egyptian", "Solar Barque", "Sun Disk")));
    mixed_gods = mixed_gods->insert(new Link<God>(God("Zeus", "Greek", "Pegasus", "Lightning")));
    mixed_gods = mixed_gods->insert(new Link<God>(God("Odin", "Norse", "Sleipner", "Gungnir")));
    mixed_gods = mixed_gods->insert(new Link<God>(God("Hera", "Greek", "Chariot", "Peacock")));
    mixed_gods = mixed_gods->insert(new Link<God>(God("Anubis", "Egyptian", "None", "Staff")));

    std::cout << "--- ORIGINAL MIXED LIST ---\n";
    print_all(mixed_gods);
    std::cout << "\n\n";


    Link<God>* norse_list = NULL;
    Link<God>* greek_list = NULL;
    Link<God>* egyptian_list = NULL;

    Link<God>* current = mixed_gods->getBeginning();
    while (current) {
        Link<God>* new_node = new Link<God>(current->value);

        if (current->value.mythology == "Norse") {
            if (norse_list == NULL) norse_list = new_node;
            else norse_list = norse_list->add_ordered(new_node);
        }
        else if (current->value.mythology == "Greek") {
            if (greek_list == NULL) greek_list = new_node;
            else greek_list = greek_list->add_ordered(new_node);
        }
        else if (current->value.mythology == "Egyptian") {
            if (egyptian_list == NULL) egyptian_list = new_node;
            else egyptian_list = egyptian_list->add_ordered(new_node);
        }

        current = current->next();
    }

    std::cout << "--- NORDIC (ORDERED) ---\n";
    print_all(norse_list);
    std::cout << "\n\n";

    std::cout << "--- GREEK (ORDERED) ---\n";
    print_all(greek_list);
    std::cout << "\n\n";

    std::cout << "--- EGYPTIAN (ORDERED) ---\n";
    print_all(egyptian_list);
    std::cout << "\n\n";

    destroy_list(mixed_gods);
    destroy_list(norse_list);
    destroy_list(greek_list);
    destroy_list(egyptian_list);

    std::cout << "--- INT ---\n";
    Link<int>* intL = new Link<int>(111);
    intL = intL->add_ordered(new Link<int>(888));
    intL = intL->add_ordered(new Link<int>(999));
    print_all(intL);

    return 0;
}
