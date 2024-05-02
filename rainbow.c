#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

struct option long_options[] = {
  {"normal",no_argument, 0, 'n'},
  {"big-normal", no_argument, 0, 'B'},
  {"bright", no_argument, 0, 'b'},
  {"big-bright", no_argument, 0, 'o'},
  {0, 0, 0, 0}
};

void show_normal() {
  for (int a=30;a<=37;a++) {
    for (int b=40;b<=47;b++) {
      printf("\e[%d;%dmCOLORS\e[0m", a, b);
    }
    printf("\n");
  }
}

void show_big_normal() {
  for (int a=0;a<=8;a++) {
    for (int b=30;b<=37;b++) {
      for (int c=40;c<=47;c++) {
        printf("\e[%d;%d;%dm\\e[%d;%d;%dm\e[0m", a, b, c, a, b, c);
      }
      printf("\n");
    }
  }
}

void show_bright() {
 for (int a=90;a<=97;a++) {
   for (int b=100;b<=107;b++) {
     printf("\e[%d;%dmCOLORS\e[0m", a, b);
   }
   printf("\n");
 }
}

void show_big_bright() {
  for (int a=0;a<=8;a++) {
    for (int b=90;b<=97;b++) {
      for (int c=100;c<=107;c++) {
        printf("\e[%d;%d;%dm\\e[%d;%d;%dm\e[0m", a, b, c, a, b, c);
      }
      printf("\n");
    }
  }
}

int main(int argc, char* argv[]) {
  int opt;
  while ((opt = getopt_long(argc, argv, "nbBo", long_options, 0)) != -1) {
    switch (opt) {
    case 'n':
      show_normal();
      break;
    case 'b':
      show_bright();
      break;
    case 'B':
      show_big_normal();
      break;
    case 'o':
      show_big_bright();
      break;
    default:
      abort();
    }
  }

  if (argc == 1) {
    printf("Usage: rainbow [-n | --normal] [-b | --bright]\n");
    printf("               [-B | --big-normal] [-o | --big-bright]\n");
  }
  
  for(;optind < argc;optind++)
    printf("extra arguments: %s\n", argv[optind]);
  
  return 0;
}
