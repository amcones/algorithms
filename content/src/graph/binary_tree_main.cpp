/*
 * Author: uli
 * License: MIT
 * Description:
 * Time: 2025-06-10 23:15:37 +0800
 */

#include "graph/binary_tree.h"

int main() {
    const std::vector<std::string> levelData = {"A", "B", "C", "D", "E"};
    const BinaryTree<std::string> *tree = new BinaryTree(BinaryTree<std::string>::build_by_level(levelData));

    auto visit = [](const BinaryTreeNode<std::string> *node) {
        std::cout << node->data << ' ';
    };

    std::cout << "preOrder: ";
    tree->preOrder(tree->root, visit);
    std::cout << std::endl;
    std::cout << "preOrder with no recursive: ";
    tree->preOrder_no_recursive(visit);
    std::cout << std::endl;

    std::cout << "inOrder: ";
    tree->inOrder(tree->root, visit);
    std::cout << std::endl;
    std::cout << "inOrder with no recursive: ";
    tree->inOrder_no_recursive(visit);
    std::cout << std::endl;

    std::cout << "postOrder: ";
    tree->postOrder(tree->root, visit);
    std::cout << std::endl;
    std::cout << "postOrder with no recursive: ";
    tree->postOrder_no_recursive(visit);
    std::cout << std::endl;

    std::cout << "levelOrder: ";
    tree->levelOrder(visit);
    std::cout << std::endl;

    delete(tree);
}
