#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "my_string.h"

#define STR_EQUAL(a, b) (strcmp(a, b) == 0)

int main(int argc, char **argv) {
  srand(time(NULL));

  if (argc < 2) {
    printf("Usage: %s <function> <arguments>\n", argv[0]);
    exit(1);
  } else if (STR_EQUAL(argv[1], "strlen")) {
    if (argc != 3) {
      printf("Usage: %s strlen <string>\n", argv[0]);
      exit(1);
    }
    char* s1 = argv[2];
    printf("%s\n", s1);
    printf("%d\n", strlen(s1) == my_strlen(s1));
  } else if (STR_EQUAL(argv[1], "strcmp")) {
    if (argc != 4) {
      printf("Usage: %s strcmp <string1> <string2>\n", argv[0]);
      exit(1);
    }
    char* s1 = argv[2];
    char* s2 = argv[3];

    int my = my_strcmp(s1, s2);
    int df = strcmp(s1, s2);
    int eq = (my == 0 && df == 0) ||  (my != 0 && df != 0);

    printf("%d\n", eq);
  } else if (STR_EQUAL(argv[1], "strncmp")) {
    if (argc != 5) {
      printf("Usage: %s strncmp <string1> <string2> <number>\n", argv[0]);
      exit(1);
    }
    char* s1 = argv[2];
    char* s2 = argv[3];
    int n = atoi(argv[4]);

    int my = my_strncmp(s1, s2, n);
    int df = strncmp(s1, s2, n);
    int eq = (my == 0 && df == 0) ||  (my != 0 && df != 0);

    printf("%d\n", eq);
  } else if (STR_EQUAL(argv[1], "strcpy")) {
    if (argc != 3) {
      printf("Usage: %s strcpy <string>\n", argv[0]);
      exit(1);
    }
    char* s1 = argv[2];
    char* s2 = malloc(strlen(s1) + 1);
    char* s3 = malloc(strlen(s1) + 1);

    my_strcpy(s2, s1);
    strcpy(s3, s1);

    printf("%d\n", STR_EQUAL(s2, s3));

    free(s2);
    free(s3);
  } else if (STR_EQUAL(argv[1], "strncpy")) {
    if (argc != 4) {
      printf("Usage: %s strncpy <string> <number>\n", argv[0]);
      exit(1);
    }
    char* s1 = argv[2];
    int n = atoi(argv[3]);
    char* s2 = malloc(strlen(s1) + 1);
    char* s3 = malloc(strlen(s1) + 1);

    my_strncpy(s2, s1, n);
    strncpy(s3, s1, n);

    printf("%d\n", STR_EQUAL(s2, s3));

    free(s2);
    free(s3);
  } else if (STR_EQUAL(argv[1], "strchr")) {
    if (argc != 4) {
      printf("Usage: %s strchr <string> <character>\n", argv[0]);
      exit(1);
    }
    char* s1 = argv[2];
    char* s2 = argv[3];

    printf("%d\n",
        my_strchr(s1, (char) *s2) == strchr(s1, (char) *s2) ? 1 : 0);
  } else if (STR_EQUAL(argv[1], "strrchr")) {
    if (argc != 4) {
      printf("Usage: %s strrchr <string> <character>\n", argv[0]);
      exit(1);
    }
    char* s1 = argv[2];
    char* s2 = argv[3];

    printf("%d\n",
        my_strrchr(s1, (char) *s2) == strrchr(s1, (char) *s2) ? 1 : 0);
  } else if (STR_EQUAL(argv[1], "strcat")) {
    if (argc != 4) {
      printf("Usage: %s strcat <string> <string>\n", argv[0]);
      exit(1);
    }
    char* s1 = argv[2];
    char* s2 = argv[3];

    char* r1 = malloc(strlen(s1) + strlen(s2) + 1);
    char* r2 = malloc(strlen(s1) + strlen(s2) + 1);

    strcpy(r1, s1);
    strcpy(r2, s1);

    my_strcat(r1, s2);
    strcat(r2, s2);

    printf("%d\n", STR_EQUAL(r1, r2));

    free(r1);
    free(r2);
  } else if (STR_EQUAL(argv[1], "strncat")) {
    if (argc != 5) {
      printf("Usage: %s strncat <string> <string> <number>\n", argv[0]);
      exit(1);
    }
    char* s1 = argv[2];
    char* s2 = argv[3];
    int n = atoi(argv[4]);

    char* r1 = malloc(strlen(s1) + strlen(s2) + 1);
    char* r2 = malloc(strlen(s1) + strlen(s2) + 1);

    strcpy(r1, s1);
    strcpy(r2, s1);

    my_strncat(r1, s2, n);
    strncat(r2, s2, n);

    printf("%d\n", STR_EQUAL(r1, r2));

    free(r1);
    free(r2);
  } else if (STR_EQUAL(argv[1], "memmove")) {
    if (argc != 2) {
      printf("Usage: %s memmove\n", argv[0]);
      exit(1);
    }
    int len = 200;

    char* a = malloc(len);
    char* b = malloc(len);
    for (int i = 0 ; i < len ; i++) {
      a[i] = rand() % 255;
      b[i] = a[i];
    }

    int n = 100;
    int offset = (rand() % 30) + 20;

    memmove(a + offset, a, n);
    my_memmove(b + offset, b, n);

    int eq = memcmp(a, b, len);

    printf("%d\n", eq == 0 ? 1 : 0);

    free(a);
    free(b);
  } else if (STR_EQUAL(argv[1], "strstr")) {
    if (argc != 4) {
      printf("Usage: %s strstr <string> <string>\n", argv[0]);
      exit(1);
    }
    char* s1 = argv[2];
    char* s2 = argv[3];

    printf("%d\n", strstr(s1, s2) == my_strstr(s1, s2));
  } else if (STR_EQUAL(argv[1], "memset")) {
    if (argc != 2) {
      printf("Usage: %s memset\n", argv[0]);
      exit(1);
    }
    int len = (rand() % 200) + 20;

    char* a = malloc(len);
    char* b = malloc(len);

    char byte = rand() % 255;

    memset(a, byte, len);
    my_memset(b, byte, len);

    int eq = memcmp(a, b, len);

    printf("%d\n", eq == 0);

    free(a);
    free(b);
  } else if (STR_EQUAL(argv[1], "strcspn")) {
    if (argc != 4) {
      printf("Usage: %s strcspn <string> <string>\n", argv[0]);
      exit(1);
    }
    char* s1 = argv[2];
    char* s2 = argv[3];

    printf("%d\n", strcspn(s1, s2) == my_strcspn(s1, s2));
  } else {
    printf("Unknown function: %s\n", argv[0]);
  }

  return 0;
}
