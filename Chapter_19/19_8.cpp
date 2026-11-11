#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <new>

/*
8. Implement an allocator (§19.3.7) using the basic allocation functions malloc() and free()
(§B.11.4). Get vector as defined by the end of §19.4 to work for a few simple test cases. Hint: Look 
up “placement new” and “explicit call of destructor” in a complete C++ reference.
*/

template<typename T> class allocator {
public:
	// . . .
	T* allocate(int n); // allocate space for n objects of type T
	void deallocate(T* p, int n); // deallocate n objects of type T starting at p
	void construct(T* p, const T& v); // construct a T with the value v in p
	void destroy(T* p); // destroy the T in p
};

template<typename T>
T* allocator<T>::allocate(int n) {
	if (n <= 0) return NULL;
	void* p = std::malloc(n * sizeof(T));
	if (p == NULL) throw std::bad_alloc();
	return static_cast<T*>(p);
}

template<typename T>
void allocator<T>::deallocate(T* p, int n) {
	std::free(p);
}

template<typename T>
void allocator<T>::construct(T* p, const T& v) {
	new(p) T(v);
}

template<typename T>
void allocator<T>::destroy(T* p) {
	p->~T();
}

//Vector

// an almost real vector of doubles:
template<typename T, typename A = allocator<T> > class vector {
	A alloc; // read “for all types T” (just like in math)
	int sz; // the size
	T* elem; // a pointer to the elements
	int space; // size + free space
public:
	vector() : sz(0), elem(NULL), space(0) { }
	explicit vector(int s, T def = T()) :sz(s), elem(alloc.allocate(s)), space(s)
	{
		for (int i = 0; i < sz; ++i) alloc.construct(&elem[i], def); // elements are initialized
	}
	vector(const vector&); // copy constructor
	vector& operator=(const vector&); // copy assignment
	//vector(vector<T, A>&&); // move constructor
	//vector& operator=(vector<T, A>&&); // move assignment
	~vector() {
		for (int i = 0; i < sz; ++i) alloc.destroy(&elem[i]);
		alloc.deallocate(elem, space);
	} // destructor
	T& at(int n); // checked access
	const T& at(int n) const; // checked access
	T& operator[](int n) { return elem[n]; } // access: return reference
	const T& operator[](int n) const { return elem[n]; }
	int size() const { return sz; } // the current size
	int capacity() const { return space; }
	void resize(int newsize, T val = T()); // growth
	void push_back(const T& d);
	void reserve(int newalloc);
};

template<typename T, typename A>
vector<T, A>::vector(const vector& arg)
// allocate elements, then initialize them by copying
	:sz(arg.sz), elem(alloc.allocate(arg.sz)), space(arg.sz)
{
	for (int i = 0; i < sz; ++i) alloc.construct(&elem[i], arg.elem[i]);
}

template<typename T, typename A > T& vector<T, A>::at(int n)
{
	if (n < 0 || sz <= n) throw std::out_of_range("out of range");
	return elem[n];
}

template<typename T, typename A > const T& vector<T, A>::at(int n) const
{
	if (n < 0 || sz <= n) throw std::out_of_range("out of range");
	return elem[n];
}

template<typename T, typename A>
void vector<T, A>::reserve(int newalloc)
{
	if (newalloc <= space) return; // never decrease allocation
	T* p = alloc.allocate(newalloc); // allocate new space
	for (int i = 0; i < sz; ++i) alloc.construct(&p[i], elem[i]); // copy
	for (int i = 0; i < sz; ++i) alloc.destroy(&elem[i]); // destroy
	alloc.deallocate(elem, space); // deallocate old space
	elem = p;
	space = newalloc;
}

template<typename T, typename A>
void vector<T, A>::resize(int newsize, T val)
{
	reserve(newsize);
	for (int i = sz; i < newsize; ++i) alloc.construct(&elem[i], val); // construct
	for (int i = newsize; i < sz; ++i) alloc.destroy(&elem[i]); // destroy
	sz = newsize;
}

template<typename T, typename A>
void vector<T, A>::push_back(const T& val)
{
	if (space == 0) reserve(8); // start with space for 8 elements
	else if (sz == space) reserve(2 * space); // get more space
	alloc.construct(&elem[sz], val); // add val at end
	++sz; // increase the size
}

template<typename T, typename A>
vector<T, A>& vector<T, A>::operator=(const vector& a)
{
	if (this == &a) return *this; // self-assignment, no work needed
	if (a.sz <= space) { // enough space, no need for new allocation
		for (int i = 0; i < a.sz; ++i) elem[i] = a.elem[i]; // copy elements
		for (int i = a.sz; i < sz; ++i) alloc.destroy(&elem[i]); // destroy leftover elements
		sz = a.sz;
		return *this;
	}
	T* p = alloc.allocate(a.sz); // allocate new space
	for (int i = 0; i < a.sz; ++i) alloc.construct(&p[i], a.elem[i]); // copy elements
	for (int i = 0; i < sz; ++i) alloc.destroy(&elem[i]); // destroy old elements
	alloc.deallocate(elem, space); // deallocate old space
	space = sz = a.sz; // set new size
	elem = p; // set new elements
	return *this; // return a self-reference
}

/*
vector::vector(vector&& a)
:sz{a.sz}, elem{a.elem} // copy a’s elem and sz
{
a.sz = 0; // make a the empty vector
a.elem = nullptr;
}
vector& vector::operator=(vector&& a) // move a to this vector
{
delete[] elem; // deallocate old space
elem = a.elem; // copy a’s elem and sz
sz = a.sz;
a.elem = nullptr; // make a the empty vector
a.sz = 0;
return *this; // return a self-reference (see §17.10)
}
*/

int main() {

	try {
		std::cout << "--- TEST WITH INT ---\n";
		vector<int> v_int;
		for (int i = 0; i < 10; ++i) {
			v_int.push_back(i * 10);
		}
		std::cout << "Size: " << v_int.size() << ", Capacity: " << v_int.capacity() << "\n";
		std::cout << "Elements: ";
		for (int i = 0; i < v_int.size(); ++i) {
			std::cout << v_int[i] << " ";
		}
		std::cout << "\n\n";

		std::cout << "--- TEST WITH STD::STRING ---\n";
		vector<std::string> v_str;
		v_str.push_back("Thor");
		v_str.push_back("Odin");
		v_str.push_back("Loki");

		v_str.resize(5, "Valkyrie");
		std::cout << "After resize(5): ";
		for (int i = 0; i < v_str.size(); ++i) {
			std::cout << v_str[i] << " ";
		}
		std::cout << "\n";

		v_str.resize(2);
		std::cout << "After resize(2): ";
		for (int i = 0; i < v_str.size(); ++i) {
			std::cout << v_str[i] << " ";
		}
		std::cout << "\n\n";

		std::cout << "--- ASINGMENT AND COPY ---\n";
		vector<std::string> v_copy(v_str);
		vector<std::string> v_asig;
		v_asig = v_copy;
		v_asig[0] = "Freya";

		std::cout << "Original[0]: " << v_str[0] << ", Modified copy[0]: " << v_asig[0] << "\n\n";

		std::cout << "--- RANGE EXCEPTION ---\n";
		std::cout << "Attempting to access index 10...\n";
		std::cout << v_int.at(10) << "\n"; //must throw index out of range
	}
	catch (const std::out_of_range& e) {
		std::cout << "Error: " << e.what() << "\n";
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << "\n";
	}

	return 0;
}