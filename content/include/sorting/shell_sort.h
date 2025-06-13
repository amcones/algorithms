/*
 * Author: uli
 * License: MIT
 * Description:
 * Time: 2025-06-13 16:08:48 +0800
 */

#ifndef SHELL_SORT_H
#define SHELL_SORT_H
#include <vector>

template<std::totally_ordered T, class Compare = std::less<T> >
void shell_sort(std::vector<T> &a, Compare comp = Compare{}) {
    const int n = a.size();
    for (int dis = n / 2; dis; dis >>= 1) {
        for (int i = 0; i < n; i += dis) {
            const auto tmp = a[i];
            int j = i - dis;
            while (j >= 0 && comp(tmp, a[j])) {
                a[j + dis] = a[j];
                j -= dis;
            }
            a[j + dis] = tmp;
        }
    }
}

template<std::totally_ordered T, class Compare = std::less<T> >
void insert_sort(std::vector<T> &a, Compare comp = Compare{}) {
    const int n = a.size();
    for (int i = 0; i < n; i += 1) {
        const auto tmp = a[i];
        int j = i - 1;
        while (j >= 0 && comp(tmp, a[j])) {
            a[j + 1] = a[j];
            j -= 1;
        }
        a[j + 1] = tmp;
    }
}

template<std::totally_ordered T, class Compare = std::less<T> >
void binary_insert_sort(std::vector<T> &a, Compare comp = Compare{}) {
    const int n = a.size();
    for (int i = 0; i < n; i += 1) {
        const auto tmp = a[i];
        int l = 0, r = i - 1;
        while (l <= r) {
            int mid = (l + r + 1) >> 1;
            if (comp(a[mid], tmp)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        for (int j = i - 1; j >= l; --j) {
            a[j + 1] = a[j];
        }
        a[l] = tmp;
    }
}

template<std::totally_ordered T, class Compare = std::less<T> >
void quick_sort(std::vector<T> &a, Compare comp = Compare{}) {
    std::function<void(int, int)> recursive = [&](int l, int r) {
        if (l >= r) return;

        int i = l - 1, j = r + 1, x = a[(l + r) >> 1];
        while (i < j) {
            do i++; while (comp(a[i], x));
            do j--; while (comp(x, a[j]));
            if (i < j) std::swap(a[i], a[j]);
        }

        recursive(l, j);
        recursive(j + 1, r);
    };
    recursive(0, a.size() - 1);
}

#endif //SHELL_SORT_H
