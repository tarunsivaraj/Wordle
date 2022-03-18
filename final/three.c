#include "final.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int helper(int value, BinaryTree *tree, int depth_counter) {
  if(tree == NULL) {
    return -1;
  }
  if(tree->val == value) {
    return depth_counter;
  }
//  depth_counter++;
//  printf("%d", depth_counter);

  int left = helper(value, tree->left, depth_counter + 1);

  if(left != -1) {
    return left;
  }
  
  int right = helper(value, tree->right, depth_counter + 1);

  if(right != -1) {
    return right;
  }

  
  if (left == -1 && right == -1) {
    return -1;
  }
  return -1;
}

int depth_of_value(int value, BinaryTree *tree) {
  // Your code here!
  // Remember -- return 0 if the value is found at the root node, and -1 if the
  // value is not found in the tree at all.
  // You don't have to handle trees where the same value occurs more than once,
  // but if it does happen, you ought to return the shallowest depth of that
  // value.
  // Also remember that this is just a binary tree, not a binary *search* tree.
  int depth_counter = 0;
  return helper(value, tree, depth_counter);

}
