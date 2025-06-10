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
    std::string data;
    BinaryTreeNode *left, *right;

    explicit BinaryTreeNode(std::string data): data(std::move(data)), left(nullptr), right(nullptr) {
    }

    void preOrder(std::vector<std::string> &pre) const {
        pre.push_back(data);
        if (left) left->preOrder(pre);
        if (right) right->preOrder(pre);
    }

    void inOrder(std::vector<std::string> &in) const {
        if (left) left->inOrder(in);
        in.push_back(data);
        if (right) right->inOrder(in);
    }

    void postOrder(std::vector<std::string> &post) const {
        if (left) left->postOrder(post);
        if (right) right->postOrder(post);
        post.push_back(data);
    }

    void levelOrder(std::vector<std::string> &level) const {
        std::queue<const BinaryTreeNode *> q;
        q.push(this);
        while (!q.empty()) {
            const auto node = q.front();
            q.pop();
            level.push_back(node->data);
            if (node->left)q.push(node->left);
            if (node->right)q.push(node->right);
        }
    }

    void preOrder_no_recursive(std::vector<std::string> &pre) const {
        std::stack<const BinaryTreeNode *> stk;
        stk.push(this);
        while (!stk.empty()) {
            const auto node = stk.top();
            stk.pop();
            pre.push_back(node->data);
            if (node->right) stk.push(node->right);
            if (node->left) stk.push(node->left);
        }
    }

    void inOrder_no_recursive(std::vector<std::string> &in) const {
        std::stack<const BinaryTreeNode *> stk;
        auto cur = this;

        while (!stk.empty() || cur) {
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            if (!stk.empty()) {
                cur = stk.top();
                in.push_back(cur->data);
                stk.pop();
                cur = cur->right;
            }
        }
    }

    void postOrder_no_recursive(std::vector<std::string> &post) const {
        std::stack<const BinaryTreeNode *> s1, s2;
        s1.push(this);

        while (!s1.empty()) {
            auto node = s1.top();
            s1.pop();
            s2.push(node);

            if (node->left) s1.push(node->left);
            if (node->right) s1.push(node->right);
        }

        while (!s2.empty()) {
            post.push_back(s2.top()->data);
            s2.pop();
        }
    }
};

inline BinaryTreeNode *build_by_level(const std::vector<std::string> &levelOrder) {
    if (levelOrder.empty()) return nullptr;

    auto *root = new BinaryTreeNode(levelOrder[0]);
    std::queue<BinaryTreeNode *> q;
    q.push(root);

    for (int i = 1; i < levelOrder.size() && !q.empty(); i++) {
        BinaryTreeNode *curr = q.front();
        q.pop();

        if (!levelOrder[i].empty()) {
            curr->left = new BinaryTreeNode(levelOrder[i]);
            q.push(curr->left);
        }
        i++;

        if (i < levelOrder.size() && !levelOrder[i].empty()) {
            curr->right = new BinaryTreeNode(levelOrder[i]);
            q.push(curr->right);
        }
    }

    return root;
}
#endif //TREE_H
