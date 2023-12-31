﻿#include <iostream>

class smart_array {
    int size{};
    int logical_index{};
    int* arr{};
public:
    smart_array(int size) {
        arr = new int[size];
        this->size = size;
    }

    ~smart_array() {
        delete[] arr;
    }

    smart_array(const smart_array&) = delete;

    smart_array& operator=(const smart_array&) = delete;

    void add_element(int elem) {
        if (logical_index == size) {
            throw std::exception("Выход за пределы массива!");
        }
        else {
            arr[logical_index] = elem;
            logical_index++;
        }
    }

    int get_element(int index) {
        if (index < 0 || index > logical_index) {
            throw std::exception("Индекс выходит за пределы массива!");
        }
        else {
            return arr[index];
        }
    }
};
int main()
{
    setlocale(LC_ALL, "Russian");
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(0) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}