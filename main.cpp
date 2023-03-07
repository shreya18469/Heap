/*
  Shreya Suresh
  3/5/23
  Heap- program that allows user to add, display, and remove stuff from a max heap
 */
#include <iostream>
#include <cstring>
#include <fstream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
//function prototypes
void madd(int* arr, int &curr);
void fadd(int* arr, int &curr);
void display(int index, int* arr, int depth, int size);
void remove(int* table, int size);
void check(int* arr, int curr);
void rcheck(int *arr, int curr);
int left(int curr);
int right(int curr);
int parent(int curr);

  
void fadd(int* arr, int &curr) { //add using the file
  cout << "How many numbers are you adding?" << endl;
  int numi;
  cin >> numi;
  for (int i = 0; i < numi; i++){
    fstream file("numbers.txt"); //import file
    char input[100];
    int count = 0;
    int num = (rand() % 50) + 1;
    int n;
    char temp[100];
    while(file.getline(input, 100, ' ')){
      if (count == num){
	strcpy(temp, input);
	count++;
      }
      count++;
    }
    n = atoi(temp);
    arr[curr] = n;
    check(arr, curr); 
    curr++;
  }
}

void madd(int* arr, int &curr){//add number manually
  cout << "What number do you want to add 1-100? " << endl;
  int input;
  cin >> input;
  arr[curr] = input;
  check(arr, curr);
  curr++;
}
void display(int index, int* arr, int depth, int size){ //display the heap like a tree
  if (right(index) <= size && right(index) != -1){ //print on right
    display(right(index), arr, depth +1, size);
  }
  for (int i = 0; i < depth; i++){
    cout << "\t";
  }
  cout << arr[index-1] << endl;
  if (left(index) <= size && left(index) != -1){ //print on left
    display(left(index), arr, depth +1, size);
  }
}

void check(int* arr, int curr){ //checking if a child is larger than current parent
  if (curr != 0 && arr[parent(curr)] < arr[curr]){
    //switch the parent and child
    int temp = arr[parent(curr)];
    arr[parent(curr)] = arr[curr];
    arr[curr] = temp;
    check(arr, parent(curr));
  }
  return;
}
void remove(int* arr, int size){ //remove the heap
  while(size != 0){
    cout << arr[0] << " ";
    arr[0] = arr[size-1];
    arr[size-1] = -1;
    rcheck(arr, 1);
    size = size - 1;
  }
}
void rcheck(int* arr, int curr){ //check if child is larger than parent and switch
  if (arr[right(curr)-1] >= arr[left(curr)-1] && arr[right(curr)-1] > arr[curr-1]){ //if the right is the greatest
  int temp = arr[curr-1];
  arr[curr-1] = arr[right(curr)-1];
  arr[right(curr)-1] = temp;
  rcheck(arr, right(curr));
  return;
}
  if (arr[left(curr)-1] > arr[right(curr)-1] && arr[left(curr)-1] > arr[curr-1]){ //if left if greatest
    int temp = arr[curr-1];
    arr[curr-1] = arr[left(curr)-1];
    arr[left(curr)-1] = temp;
    rcheck(arr, left(curr));
    return;
 }
}

int left(int curr){ //get left child
  return curr * 2;
}
int right(int curr){ //get right child
  return curr * 2 + 1;
}
int parent(int curr){ //get parent
  return (int) floor((curr+1)/2) -1;
}

int main(){
  srand(time(0));
  bool stillPlaying = true;
  int* arr = new int[100];
  int curr = 0;
  for (int i = 0; i < 100; i++){
    arr[i] = -1;
  }
  while(stillPlaying == true){
    cout << "Enter FADD(file add), MADD(manually add), DISPLAY, REMOVE, or QUIT" << endl;
    char input[10];
    cin >> input;
    if (strcmp(input, "MADD") == 0){
      madd(arr, curr);
    } else if (strcmp(input, "FADD") == 0){
      fadd(arr, curr);
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
