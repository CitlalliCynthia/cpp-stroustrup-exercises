#include <iostream>
#include <string>
#include <stdexcept>

/*
10. Implement a simple unique_ptr supporting only a constructor, destructor, –>, *, and release(). In 
particular, don’t try to implement an assignment or a copy constructor.
*/

template<typename T>
class unique_ptr {
private:
    T* ptr;

    //to prohibit their use
    unique_ptr(const unique_ptr&);
    unique_ptr& operator=(const unique_ptr&);

public:
    explicit unique_ptr(T* p = NULL) {//to prohibit implicit convertions
        ptr = p;
    }

    ~unique_ptr() {
        std::cout << "\n" << ptr << " destructor was called\n";
        delete ptr;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    T* release() {
        T* temp = ptr;
        ptr = NULL;
        return temp;
    }
};

void test_exception() {
    unique_ptr<std::string> p(new std::string("Hello World!"));
    std::cout << "Inside the function: " << *p << " (Size: " << p->size() << ")\n";

    throw std::runtime_error("Simulated error!");
    //To simulate an error, so the destructor is called
}

int main() {
    unique_ptr<std::string> u1(new std::string("Hello World 2!"));
    std::cout << "Content (*u1): " << *u1 << "\n";
    std::cout << "Size (u1->size()): " << u1->size() << "\n";

    //Copy prohibition test (error)
    //unique_ptr<std::string> u2 = u1;

    std::string* crude_pointer = u1.release();
    std::cout << "After 'release': " << *crude_pointer << "\n";
    delete crude_pointer;

    try {
        test_exception();
    }
    catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    return 0;
}