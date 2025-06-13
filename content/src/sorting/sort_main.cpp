/*
 * Author: uli
 * License: MIT
 * Description:
 * Time: 2025-06-13 16:18:08 +0800
 */

#include <iostream>
#include <random>

#include "sorting/sorting.h"

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 100);
    std::vector<int> a(20);
    std::ranges::generate(a, [&]() { return dist(gen); });
    std::cout << "original array: \n";
    for (const int i: a) {
        std::cout << i << ' ';
    }
    std::vector<int> b = a;
    std::cout << std::endl;
    shell_sort(b);
    std::cout << "shell sorted array: \n";
    for (const int i: b) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    shell_sort(b, [](const int x, const int y) { return x > y; });
    std::cout << "shell sorted array(large to small): \n";
    for (const int i: b) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    b = a;
    insert_sort(b);
    std::cout << "insert sorted array: \n";
    for (const int i: b) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    b = a;
    binary_insert_sort(b);
    std::cout << "binary insert sorted array: \n";
    for (const int i: b) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    b = a;
    select_sort(b);
    std::cout << "select sorted array: \n";
    for (const int i: b) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    b = a;
    bubble_sort(b);
    std::cout << "bubble sorted array: \n";
    for (const int i: b) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    b = a;
    quick_sort(b);
    std::cout << "quick sorted array: \n";
    for (const int i: b) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    b = a;
    heap_sort(b);
    std::cout << "heap sorted array: \n";
    for (const int i: b) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    b = a;
    merge_sort(b);
    std::cout << "merge sorted array: \n";
    for (const int i: b) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}
