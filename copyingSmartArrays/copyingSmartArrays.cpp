#include <iostream>
#include <stdexcept>

class smart_array {

private:
    int* data;
    int size;
    int capacity;

public:
    smart_array(int s);

    smart_array& operator=(const smart_array& other);

    smart_array(const smart_array& other);

    void add_element(int element);

    int get_element(int index);

    ~smart_array();
    
};

int main() {

    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);

    smart_array new_array(2);
    //new_array = new_array;
        new_array.add_element(44);
        new_array.add_element(34);

        arr = new_array;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}

smart_array::smart_array(int s) : size(0), capacity(s) {
    data = new int[capacity];
}
smart_array& smart_array::operator=(const smart_array& other) {
    if (this != &other) {
        delete[] data;
        data = new int[other.capacity];
        size = other.size;
        capacity = other.capacity;
    }
    return *this;
}

smart_array::smart_array(const smart_array& other) {
        data = new int[other.capacity];
        size = other.size;
        capacity = other.capacity;
  
}
void smart_array::add_element(int element) {
    if (size == capacity) {
        throw std::out_of_range("Array is full");
    }
    data[size++] = element;
}
int smart_array::get_element(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}
smart_array::~smart_array() {
    delete[] data;
    
}
