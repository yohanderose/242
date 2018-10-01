#include <stdio.h>
#include <string.h>
#include "htable.h"
#include "mylib.h"
struct htablerec {
  int capacity;
  int num_keys;
  char **keys;
};

static unsigned int htable_word_to_int(char *word) {
  unsigned int result = 0;
  while (*word != '\0') {
    result = (*word++ + 31 * result);
  }
  return result;
}

static unsigned int htable_hash(htable h, unsigned int i_key) {
  return i_key % h->capacity;
}

htable htable_new(int capacity) {
  int i;
  htable h = emalloc(sizeof *h);
  h->capacity = capacity;
  h->num_keys = 0;
  h->keys = emalloc((sizeof h->keys[0]) * h->capacity);
  for (i=0; i<h->capacity; i++) {
    h->keys[i] = emalloc((sizeof h->keys[0]) * 80);
    strcpy(h->keys[i],""); /*Remember to allocate and init*/
  }
  return h;
}
void htable_free(htable h) {
  int i;
  for (i=0; i<h->capacity; i++) {
    free(h->keys[i]);
  }
  free(h->keys);
  free(h);
}
int htable_insert(htable h, char *key) {
  int insert = -1;
  if (h->num_keys < h->capacity) {
    insert = htable_word_to_int(key);
    insert = htable_hash(h, insert);
    /*Check if hashed insert is free, otherwise find empty. */
    if (strcmp(h->keys[insert],"") == 0) {
      strcpy(h->keys[insert], key);
      h->num_keys++;
    } else {
      for (insert=0; insert<h->capacity; insert++) {
	if (strcmp(h->keys[insert],"") == 0) {
	  strcpy(h->keys[insert], key);
	  h->num_keys++;
	}
      }
    }

  }
  return insert;
}
void htable_print(htable h, FILE *stream) {
  int i;
  for (i = 0; i < h->capacity; i++) {
    fprintf(stream, "%2d %s\n", i, h->keys[i] == NULL ? "" : h->keys[i]);
  }
}
