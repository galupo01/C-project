#include <iostream>
#include <iomanip>

const int MAXTAM = 10;

using namespace std;

typedef struct Queue_1{
  int data[MAXTAM];
  int rear;
}Queue_1;


void initializer_queue(Queue_1 *p){
  for (int i = 0; i < MAXTAM; i ++)
    p->data[i] = 0;
  p->rear = 0;
}


bool full_queue(Queue_1 *p){
  if (p->rear == MAXTAM)
    return true;
  else
    return false;
}


bool empty_queue(Queue_1 *p){
  if (p->rear == 0)
    return true;
  else
    return false;
}

void insert_queue(Queue_1 *p, int x){
  if (full_queue(p))
    cout << "Error! The queue is full.";
  else{
      p->data[p->rear] = x;
      p->rear++;
  }
}


int remove_queue(Queue_1 *p){
  if (empty_queue(p))
    return 0;
  else{
    int x = p->data[0];
    for (int i = 0; i < p->rear; i ++)
      p->data[i] = p->data[i+1];
    p->rear--;
    return x;
  }
}


int main (){
  int option = 0, number = 0;
  Queue_1 q1;
  char quit;
  
  initializer_queue(&q1); 
  system("clear");
  do{
      cout << setw(35) << "Abstract Queue!" << endl << endl;
      cout << setw(13) << " ";
      for (int i = 0; i < MAXTAM; i ++)
        cout << q1.data[i] << "| ";
      cout << endl << endl << "Choose an option: "<< endl << "[1] insert" << endl << "[2] remove" << endl << "[3] quit" << endl << endl;
      cin >> option;
      switch (option){
        case 1:
          cout << endl << "Type a number: "<< endl << endl;
          cin >> number;
          insert_queue(&q1, number);
          system("clear");
        break;
        case 2:
          remove_queue(&q1);
          system("clear");
        break;
        default:
          if (option != 3){
            cout << "Invalid option. Press Q to choose again" << endl;
            cin >> quit;
            system("clear");
          } 
      }
    }while(option != 3);
  
  return 0;
}
