/*
 * Author: uli
 * License: MIT
 * Description: 二叉树定义与遍历
 * 使用了模版类，允许改变数据类型和访问器
 * 但由于构建方式不完善，目前数据类型仅支持 string
 * Time: 2025-06-10 01:10:06 +0800
 */

#ifndef TREE_H
#define TREE_H
#include <iostream>

template<typename T>
struct BinaryTreeNode {
    T data;
    BinaryTreeNode *left, *right;

    explicit BinaryTreeNode(T data): data(std::move(data)), left(nullptr), right(nullptr) {
    }
};

template<typename T>
struct BinaryTree {
    BinaryTreeNode<T> *root;

    explicit BinaryTree(BinaryTreeNode<T> *root): root(root) {
    }

    ~BinaryTree() {
        auto remove = [](const BinaryTreeNode<T> *node) {
            delete node;
        };
        postOrder(root, remove); // 确保根最后被删除
    }

    template<typename VST>
    void preOrder(BinaryTreeNode<T> *node, VST &visit) const {
        visit(node);
        if (node->left) preOrder(node->left, visit);
        if (node->right) preOrder(node->right, visit);
    }

    template<typename VST>
    void inOrder(BinaryTreeNode<T> *node, VST &visit) const {
        if (node->left) inOrder(node->left, visit);
        visit(node);
        if (node->right) inOrder(node->right, visit);
    }


    template<typename VST>
    void postOrder(BinaryTreeNode<T> *node, VST &visit) const {
        if (node->left) postOrder(node->left, visit);
        if (node->right) postOrder(node->right, visit);
        visit(node);
    }

    template<typename VST>
    void levelOrder(VST &visit) const {
        std::queue<const BinaryTreeNode<T> *> q;
        q.push(root);
        while (!q.empty()) {
            const auto node = q.front();
            q.pop();
            visit(node);
            if (node->left)q.push(node->left);
            if (node->right)q.push(node->right);
        }
    }

    template<typename VST>
    void preOrder_no_recursive(VST &visit) const {
        std::stack<const BinaryTreeNode<T> *> stk;
        stk.push(root);
        while (!stk.empty()) {
            const auto node = stk.top();
            stk.pop();
            visit(node);
            if (node->right) stk.push(node->right);
            if (node->left) stk.push(node->left);
        }
    }

    template<typename VST>
    void inOrder_no_recursive(VST &visit) const {
        std::stack<BinaryTreeNode<T> *> stk;
        auto cur = root;

        while (!stk.empty() || cur) {
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            if (!stk.empty()) {
                cur = stk.top();
                visit(cur);
                stk.pop();
                cur = cur->right;
            }
        }
    }

    template<typename VST>
    void postOrder_no_recursive(VST &visit) const {
        std::stack<const BinaryTreeNode<T> *> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            auto node = s1.top();
            s1.pop();
            s2.push(node);

            if (node->left) s1.push(node->left);
            if (node->right) s1.push(node->right);
        }

        while (!s2.empty()) {
            visit(s2.top());
            s2.pop();
        }
    }

    static BinaryTreeNode<T>* build_by_level(const std::vector<T> &levelOrder) {
        if (levelOrder.empty()) return nullptr;

        auto *root = new BinaryTreeNode<T>(levelOrder[0]);
        std::queue<BinaryTreeNode<T> *> q;
        q.push(root);

        for (int i = 1; i < levelOrder.size() && !q.empty(); i++) {
            auto *curr = q.front();
            q.pop();

            if (!levelOrder[i].empty()) {
                curr->left = new BinaryTreeNode<T>(levelOrder[i]);
                q.push(curr->left);
            }
            i++;

            if (i < levelOrder.size() && !levelOrder[i].empty()) {
                curr->right = new BinaryTreeNode<T>(levelOrder[i]);
                q.push(curr->right);
            }
        }
        return root;
    }
};


#endif //TREE_H
