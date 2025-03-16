#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "linklist.h"
#include "display.h"

int main(){
  struct node *first = NULL;
  struct node *second = NULL;
  insertsortnamemhs(&first, "Jajang Nurjaman", 80);
  insertsortnamemhs(&first, "Agus Australia", 90);
  insertsortnamemhs(&first, "Asep Sikasep", 100);
  insertsortnamemhs(&first, "Budi Siregar", 70);
  countmhs(first);
  separator("Mahasiswa (sorted by name)");
  printmhs(first);
  separator("Mahasiswa (sorted by grade)");
  sortgrademhs(first);
  return 0;
}
