#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {

  char *p = "My name is ";
  char *name= "Yohan";

  printf("%p%s\n", p, name);

  name = "James";
  return 0;
}
/*
  - strings as pointers
  - structs instead of classes, end in semicolon
  - o->x and o->y
  - exercises: pg 42, 47

  - recursion on pointers *a
  - exercises: pg 49, 50
*/
