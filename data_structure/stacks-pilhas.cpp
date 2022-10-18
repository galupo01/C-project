#include <iostream>
#include <iomanip>
#define MAXTAM 10

using namespace std;

void stackf(int *p){
  for (int i = 0; i < MAXTAM; i ++)
    p[i] = 0;
}

bool empty(int *top){
  if (*top == -1)
    return true;
  else
    return false;
}

bool full(int *top){
  if (*top == MAXTAM)
    return true;
  else
    return false;
}

bool push(int *top, int *p, int x){
  if (full(top))
    return false;
  else{
    p[*top+1] = x;
    (*top)++;
    return true;
  }
}

int pop(int *top, int *p){
  if (empty(top))
    return 0;
  else{
    int aux = p[(*top)];
    p[(*top)--] = 0;
    return aux;
  }
}


int main(){
  int stack[MAXTAM];
  int top = -1, option = 0, num;
  char Q;
  int x;
  stackf(stack);

  do{
    cout << endl << endl << setw(31) << "---" << endl;
    for (int i = MAXTAM-1; i >= 0; i --)
      cout << setw(30) << stack[i] << endl;
    cout << setw(31) << "---";
    cout << endl << endl << "[1]Push\n[2]Pop\n[3]Quit"<<endl<< endl;
    cin >> option;
    switch(option){
      case 1:
        cout << "Type a number: "<< endl;
        cin >> num;
        push(&top, stack, num);
        system("clear");
      break;
      case 2:
        x = pop(&top, stack);
        cout << "Number removed : " << x;
        system("clear");
      break;
      default:
        if (option != 3){
        cout << "Invalid option! Press Q to choose again." << endl;
        cin >> Q;
        system("clear");
        }
      
      }
  }while(option!=3);

  return 0;
