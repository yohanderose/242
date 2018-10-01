#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mylib.h"
#include "bst.h"

struct bstnode {
  char *key;
  bst left;
  bst right;
};

bst bst_new() {
  /* bst b = emalloc(sizeof *b); */
  /* b->key = NULL; */
  /* b->left = NULL; */
  /* b->right = NULL; */
  /* return b; */
  return NULL;
}

bst bst_free(bst b) {
  if (b == NULL) {
    return b;
  }  
  bst_free(b->left);
  bst_free(b->right);

  free(b->key);
  free(b);
  return NULL;
}

bst bst_insert(bst b, char *str) {  
  if (b == NULL) {
    bst b = emalloc(sizeof *b);
    b->left = NULL;
    b->right = NULL;
    b->key = emalloc((strlen(str)+1) * sizeof(char));
    strcpy(b->key, str);
    return b;
  }
  if (strcmp(str, b->key) <= 0) {
    b->left = bst_insert(b->left, str);
  } else {
    b->right = bst_insert(b->right, str);
  }
  return b;
}

bst bst_inorder(bst b, void f(char *str)) {
  if (b == NULL) {
    return b;
  }
  bst_inorder(b->left, f);
  f(b->key);
  bst_inorder(b->right, f);
  return NULL;
}

bst bst_preorder(bst b, void f(char *str)) {
  if (b == NULL) {
    return b;
  }
  f(b->key);
  bst_preorder(b->left, f);
  bst_preorder(b->right, f);
  
  return NULL;
}

int bst_search(bst b, char *str) {
  if (b == NULL) {
    return 0;
  }
  if (strcmp(b->key, str) == 0) {
    return 1;
  }
  return bst_search(b->left, str) + bst_search(b->right, str);
}

				 

