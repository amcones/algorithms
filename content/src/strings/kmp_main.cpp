/*
 * Author: uli
 * License: MIT
 * Description:
 * Time: 2025-06-09 21:16:01 +0800
 */

#include "strings/kmp.h"
#include <iostream>

int main() {
    const std::string s = "abcdabcxabcabcd";
    const std::string p = "abcd";
    const std::vector<int> matched_kmp = match_string_kmp(s, p);
    const std::vector<int> matched_bf = match_string_bf(s, p);
    std::cout << "kmp result: ";
    for (const int m: matched_kmp) {
        std::cout << m << ' ';
    }
    std::cout << std::endl;
    std::cout << "bf result: ";
    for (const int m: matched_bf) {
        std::cout << m << ' ';
    }
}
