/*
 * Author: uli
 * License: MIT
 * Description: 实现了几种最常用的排序，均为模版类，带有比较器
 * Time: 2025-06-13 16:08:48 +0800
 */

#ifndef SHELL_SORT_H
#define SHELL_SORT_H
#include <vector>

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
void select_sort(std::vector<T> &a, Compare comp = Compare{}) {
    const int n = a.size();
    for (int i = 0; i < n; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (comp(a[j], a[k])) {
                k = j;
            }
        }
        if (k != i) {
            std::swap(a[k], a[i]);
        }
    }
}

template<std::totally_ordered T, class Compare = std::less<T> >
void bubble_sort(std::vector<T> &a, Compare comp = Compare{}) {
    const int n = a.size();
    for (int i = 0; i < n; i++) {
        bool f = false;
        for (int j = i + 1; j < n; j++) {
            if (comp(a[j], a[i])) {
                std::swap(a[i], a[j]);
                f = true;
            }
        }
        if (!f)return;
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

template<std::totally_ordered T, class Compare = std::less<T> >
void heap_sort(std::vector<T> &a, Compare comp = Compare{}) {
    std::function<void(int, int)> heapify = [&](const int n, int root) {
        int largest = root, left = root * 2 + 1, right = root * 2 + 2;
        if (left < n && comp(a[largest], a[left])) {
            largest = left;
        }
        if (right < n && comp(a[largest], a[right])) {
            largest = right;
        }
        if (largest != root) {
            std::swap(a[largest], a[root]);
            heapify(n, largest);
        }
    };
    const int n = a.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(n, i);
    }
    for (int i = n - 1; i >= 0; --i) {
        std::swap(a[i], a[0]);
        heapify(i, 0);
    }
}

template<std::totally_ordered T, class Compare = std::less<T> >
void merge_sort(std::vector<T> &a, Compare comp = Compare{}) {
    const int n = a.size();
    std::function<void(int, int)> recursive = [&](int l, int r) {
        if (l >= r) return;
        std::vector<T> tmp(r - l + 1);
        const int mid = (l + r) >> 1;
        recursive(l, mid);
        recursive(mid + 1, r);

        int k = 0, i = l, j = mid + 1;
        while (i <= mid && j <= r)
            if (comp(a[i], a[j])) tmp[k++] = a[i++];
            else tmp[k++] = a[j++];

        while (i <= mid) tmp[k++] = a[i++];
        while (j <= r) tmp[k++] = a[j++];

        for (i = l, j = 0; i <= r; i++, j++) a[i] = tmp[j];
    };
    recursive(0, n - 1);
}

#endif //SHELL_SORT_H
