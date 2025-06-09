/*
 * Author: uli
 * License: MIT
 * Description:
 * Time: 2025-06-09 22:58:26 +0800
 */

#ifndef KMP_H
#define KMP_H
#include <vector>

/**
 * O(n^2) 暴力字符串匹配，对应 KMP 写法
 * @param s 文本串
 * @param p 模式串
 * @return 所有匹配位置
 */
inline std::vector<int> match_string_bf(const std::string &s, const std::string &p) {
    std::vector<int> matched;
    for (int i = 0, j = 0; i + p.size() <= s.size(); i++, j = 0) {
        while (j < p.size() && s[i + j] == p[j]) j++;
        if (j == p.size()) matched.push_back(i + j - 1);
    }
    return matched;
}

/**
 * O(n) 字符串匹配
 * @param s 文本串
 * @param p 模式串
 * @return 所有匹配位置
 */
inline std::vector<int> match_string_kmp(const std::string &s, const std::string &p) {
    std::vector<int> next(p.size());
    for (int i = 1, j = 0; i < p.size(); i++) {
        while (j && p[i] != p[j]) j = next[j - 1];
        if (p[i] == p[j]) j++;
        next[i] = j;
    }
    std::vector<int> matched;
    for (int i = 0, j = 0; i < s.size(); i++) {
        while (j && s[i] != p[j]) j = next[j - 1];
        if (s[i] == p[j]) j++;
        if (j == p.size()) matched.push_back(i);
    }
    return matched;
}

#endif //KMP_H
