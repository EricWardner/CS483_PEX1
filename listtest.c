#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Example test program for CS 483 PEX 1
   USAFA/DFCS
   Maj Hancock
   david.hancock.2@us.af.mil

   This is not necessarily the same file that will be
   used to test PEX 1, but it should be pretty close */

int main(void) {
  node* list;
  list = NULL;
  char* zero = "zero";
  char* one = "one";
  char* two = "two";
  char* three = "three";

  list = list_insert_tail(list, one);
  list = list_insert_tail(list, two);
  list = list_insert_tail(list, three);
  printf("list_insert_tail and list_print test:\n");
  list_print(list);
  /* expected output:
  one
  two
  three
  */

  list = list_insert_head(list, zero);
  printf("\nlist_insert_head and list_print test:\n");
  list_print(list);
  /* expected output:
  zero
  one
  two
  three
  */

  list = list_remove(list, "one");
  printf("\nlist_remove test (middle):\n");
  list_print(list);
  /* expected output:
  zero
  two
  three
  */

  list = list_remove(list, "three");
  printf("\nlist_remove test (tail):\n");
  list_print(list);
  /* expected output:
  zero
  two
  */

  list = list_remove(list, "zero");
  printf("\nlist_remove test (head):\n");
  list_print(list);
  /* expected output:
  two
  */

  list = list_insert_head(list, zero);
  printf("\ninsert head test\n");
  list_print(list);
  list = list_insertn(list, one, 2);
  list = list_insertn(list, three, 4);
  printf("\nlist_insertn test:\n");
  list_print(list);
  /* expected output:
  zero
  one
  two
  three
  */

  printf("\nlist_get test:\n");
  int i;
  for(i = 1; i < 5; i++) {
    printf("%d: %s\n", i, list_get(list, i));
  }
  /* expected output:
  1: zero
  2: one
  3: two
  4: three
  */
  list_destroy(list);
}
