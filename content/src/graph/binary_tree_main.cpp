/*
 * Author: uli
 * License: MIT
 * Description:
 * Time: 2025-06-10 23:15:37 +0800
 */

#include "graph/binary_tree.h"

int main() {
    std::vector<std::string> tree = {"A", "B", "C", "D", "E"};
    const BinaryTreeNode *root = nullptr;
    root = build_by_level(tree);
    if (!root) return -1;
    std::vector<std::string> pre, in, post, level;
    root->preOrder(pre);
    root->inOrder(in);
    root->postOrder(post);
    root->levelOrder(level);

    std::cout << "preOrder: ";
    for (const auto &s: pre) {
        std::cout << s << ' ';
    }
    std::cout << std::endl;

    std::cout << "inOrder: ";
    for (const auto &s: in) {
        std::cout << s << ' ';
    }
    std::cout << std::endl;

    std::cout << "postOrder: ";
    for (const auto &s: post) {
        std::cout << s << ' ';
    }
    std::cout << std::endl;

    std::cout << "levelOrder: ";
    for (const auto &s: level) {
        std::cout << s << ' ';
    }
    std::cout << std::endl;

    pre.clear();
    in.clear();
    post.clear();

    root->preOrder_no_recursive(pre);
    root->inOrder_no_recursive(in);
    root->postOrder_no_recursive(post);

    std::cout << "preOrder with no recursive: ";
    for (const auto &s: pre) {
        std::cout << s << ' ';
    }
    std::cout << std::endl;

    std::cout << "inOrder with no recursive: ";
    for (const auto &s: in) {
        std::cout << s << ' ';
    }
    std::cout << std::endl;

    std::cout << "postOrder with no recursive: ";
    for (const auto &s: post) {
        std::cout << s << ' ';
    }
    std::cout << std::endl;


}
