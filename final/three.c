#include "final.h"

#include <stdio.h>

int depth_of_value(int value, BinaryTree *tree) {
  // Remember -- return 0 if the value is found at the root node, and -1 if the
  // value is not found in the tree at all.
  // You don't have to handle trees where the same value occurs more than once,
  // but if it does happen, you ought to return the shallowest depth of that
  // value.
  // Also remember that this is just a binary tree, not a binary *search* tree.
  int distance = -1;
  if (tree == NULL) {
    return -1;
  }  
  if ((tree->val == value) || (distance = depth_of_value(value, tree->left)) >= 0 || (distance = depth_of_value(value, tree->right)) >= 0) {
    return distance + 1;
  }
  return distance;
}
