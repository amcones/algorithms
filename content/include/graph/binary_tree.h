/*
 * Author: uli
 * License: MIT
 * Description: 二叉树定义与遍历
 * Time: 2025-06-10 01:10:06 +0800
 */

#ifndef TREE_H
#define TREE_H
#include <iostream>

struct BinaryTreeNode {
    int data;
    BinaryTreeNode *lChild, *rChild;

    void preOrder(BinaryTreeNode *root) {
        if (!root) return;
        // std::cout<<root->data<<std::endl;
        preOrder(root->lChild);
        preOrder(root->rChild);
    }

    void inOrder(BinaryTreeNode *root) {
        if (!root) return;
        inOrder(root->lChild);
        // std::cout<<root->data<<std::endl;
        inOrder(root->rChild);
    }

    void postOrder(BinaryTreeNode *root) {
        if (!root) return;
        postOrder(root->lChild);
        postOrder(root->rChild);
        // std::cout<<root->data<<std::endl;
    }

    void levelOrder(BinaryTreeNode *root) {
        if (!root) return;
        std::queue<BinaryTreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            const auto node = q.front();
            q.pop();
            if (node->lChild)q.push(node->lChild);
            if (node->rChild)q.push(node->rChild);
        }
    }

    //TODO: 非递归遍历
};
#endif //TREE_H
