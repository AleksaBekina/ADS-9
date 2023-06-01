// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template <class T>
class BST {
 private:
  struct BTNode {
    T value;
    int count;
    struct BTNode* left;
    struct BTNode* right;
    explicit BTNode(T data) : value(data), count(1) {
      left = nullptr;
      right = nullptr;
    }
  };
  BTNode* root;
  BTNode* addBST(BTNode*, T);

 public:
  BST();
  void add(T);
  int depth(void)
#endif  // INCLUDE_BST_H_
