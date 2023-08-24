#include <iostream>

int gVect[100];
int gCount =0 ;

void Insert(int elem){
  if(gCount < 100)
    gVect[gCount++] = elem;
}

int main() {
  for(int i = 0; i<100; i++){
    Insert(i);
    std::cout << gVect[i] << " ";
  }
}