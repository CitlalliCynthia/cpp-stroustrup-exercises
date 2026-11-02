#include <iostream>
#include <string>

/*
11. Complete the “list of gods” example from §17.10.1 and run it.

12. Why did we define two versions of find()?
*/

class Link {
public:
    std::string value;
    Link(const std::string& v, Link* p = NULL, Link* s = NULL)
        : value{ v }, prev{ p }, succ{ s } {
    }
    Link* insert(Link* n); // insert n before this object
    Link* add(Link* n); // insert n after this object
    Link* erase(); // remove this object from list
    Link* find(const std::string& s); // find s in list
    const Link* find(const std::string& s) const; // find s in const list (see §18.5.1)
    Link* advance(int n) const; // move n positions in list
    Link* next() const { return succ; }
    Link* previous() const { return prev; }
private:
    Link* prev;
    Link* succ;
};

Link* Link::insert(Link* n) // insert n before this object; return n
{
    if (n == NULL) return this;
    if (this == NULL) return n;
    n->succ = this; // this object comes after n
    if (prev) prev->succ = n;
    n->prev = prev; // this object’s predecessor becomes n’s predecessor
    prev = n; // n becomes this object’s predecessor
    return n;
}

Link* Link::add(Link* n) // insert n after this object; return n
{
    if (n == NULL) return this;
    if (this == NULL) return n;
    n->prev = this; // p comes before n
    if (succ) succ->prev = n;
    n->succ = succ; // p’s successor becomes n’s successor
    succ = n; // n becomes p’s successor
    return n;
}
Link* Link::erase() // remove *p from list; return p’s successor
{
    if (this == NULL) return NULL;
    if (succ) succ->prev = prev;
    if (prev) prev->succ = succ;
    return succ;
}
Link* Link::find(const std::string& s) // find s in list;
// return null for “not found”
{
    Link* p = this;
    while (p) {
        if (p->value == s) return p;
        p = p->succ;
    }
    return NULL;
}

const Link* Link::find(const std::string& s) const // find s in const list
{
    const Link* p = this; // Must be 'const Link*' because 'this' is constant
    while (p) {
        if (p->value == s) return p;
        p = p->next(); // We use next()
    }
    return NULL;
}

Link* Link::advance(int n) const // move n positions in list
// return null for “not found”
// positive n moves forward, negative backward
{
    Link* p = (Link*)this;
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

void print_all(Link* p)
{
    std::cout << "{ ";
    while (p) {
        std::cout << p->value;

        if (p->next() != NULL) {
            std::cout << ", ";
        }

        p = p->next();
    }
    std::cout << " }";
}

int main() {

    Link* norse_gods = new Link{ "Thor" };
    norse_gods = norse_gods->insert(new Link{ "Odin" });
    norse_gods = norse_gods->insert(new Link{ "Zeus" });
    norse_gods = norse_gods->insert(new Link{ "Freia" });
    Link* greek_gods = new Link{ "Hera" };
    greek_gods = greek_gods->insert(new Link{ "Athena" });
    greek_gods = greek_gods->insert(new Link{ "Mars" });
    greek_gods = greek_gods->insert(new Link{ "Poseidon" });

    Link* p = greek_gods->find("Mars");
    if (p) p->value = "Ares";

    Link* p2 = norse_gods->find("Zeus");
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
