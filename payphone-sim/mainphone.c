#include <stdio.h>
#include "payphone.h"
#include "lib-linklist/linkedlist.h"

int main(){
  linkedlist ** bukukontak = NULL;  //Single Linkedlist
  linkedlist ** antrian = NULL;     //Queue
  linkedlist ** dialer = NULL;      //Stack
  int noantri = 0;

  menu(noantri, antrian, bukukontak);

  return 0;
}
