#include <iostream>
#include <cstring>
#include <fstream>
#include <math.h>

using namespace std;

void insert(int* arr, int &curr);
void fadd(int* arr, int curr);
void display(int index, int* arr, int depth, int size);
void print(int* arr);
void remove(int* table, int size);
void check(int* arr, int curr);
void rcheck(int *arr, int curr);
int left(int curr);
int right(int curr);
int parent(int curr);

  
void fadd(int* arr, int &curr){
  
}

void madd(int* arr, int &curr){
  cout << "What number do you want to add 1-100? " << endl;
  int input;
  cin >> input;
  arr[curr] = input;
  check(arr, curr);
  curr++;
}
void display(int index, int* arr, int depth, int size){
  if (right(index) <= size && right(index) != -1){
    display(right(index), arr, depth +1, size);
  }
  for (int i = 0; i < depth; i++){
    cout << "\t";
  }
  cout << arr[index-1] << endl;
  if (left(index) <= size && left(index) != -1){
    display(left(index), arr, depth +1, size);
  }
}

void print(int* arr){
  for (int i = 0; i < 100; i++){
    cout << arr[i] << endl;
  }
}
void check(int* arr, int curr){
  if (curr != 0 && arr[parent(curr)] < arr[curr]){
    int temp = arr[parent(curr)];
    arr[parent(curr)] = arr[curr];
    arr[curr] = temp;
    check(arr, parent(curr));
  }
  return;
}
void remove(int* arr, int size){
  
}
void rcheck(int* arr, int curr){
  if (arr[right(curr)-1] >= arr[left(curr)-1] && arr[right(curr)-1] > arr[curr-1]){
  int temp = arr[curr-1];
  arr[curr-1] = arr[right(curr)-1];
  arr[right(curr)-1] = temp;
  rcheck(arr, right(curr));
  return;
}
  if (arr[left(curr)-1] > arr[right(curr)-1] && arr[left(curr)-1] > arr[curr-1]){
    int temp = arr[curr-1];
    arr[curr-1] = arr[left(curr)-1];
    arr[left(curr)-1] = temp;
    rcheck(arr, left(curr));
    return;
 }
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

  bool stillPlaying = true;
  int* arr = new int[100];
  int curr = 0;
  for (int i = 0; i < 100; i++){
    arr[i] = -1;
  }
  while(stillPlaying == true){
    cout << "Enter FADD(file add), MADD(manually add), PRINT, DISPLAY, REMOVE, or QUIT" << endl;
    char input[10];
    cin >> input;
    if (strcmp(input, "MADD") == 0){
      madd(arr, curr);
    } else if (strcmp(input, "FADD") == 0){
      //fadd(arr, curr);
    } else if (strcmp(input, "PRINT") == 0){
      print(arr);
    } else if (strcmp(input, "DISPLAY") == 0){
      display(1, arr, 0, curr);
    } else if (strcmp(input, "REMOVE") == 0){
      remove(arr, curr);
      cout << endl;
      curr = 0;
      for (int i = 0; i < 100; i++){
	arr[i] = -1;
      }
    } else if (strcmp(input, "QUIT") == 0){
      stillPlaying = false;
    }
  }

  return 0;
}
