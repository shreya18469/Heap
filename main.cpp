#include <iostream>
#include <cstring>
#include <fstream>
#include <math.h>

using namespace std;

void insert(int* arr, int &curr);
void madd(int* arr, int curr);
void display(int index, int* arr, int depth, int size);
void print(int* arr);
void remove(int* table, int size);
void check(int* arr, int curr);
void rcheck(int *arr, int curr);
int left(int curr);
int right(int curr);
int parent(int curr);

  
void insert(int* arr, int &curr){

}

void madd(int* arr, int &curr){
  
}
void display(int index, int* arr, int depth, int size){

}

void print(int* arr){

}
void check(int* arr, int curr){
  
}
void remove(int* arr, int size){

}
void rcheck(int* arr, int curr){

}

int left(int curr){
  return curr * 2;
}
int right(int curr){
  return curr * 2 + 1;
}
int parent(int curr){
  return (int) floor((curr+1)/2) -1;
}

int main(){


  return 0;
}
