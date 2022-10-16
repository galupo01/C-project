#include <iostream>

using namespace std;

void HeapSort(int n, int m, int *p, int *q, int *s){
    for ( int i =0, j= 0, k = 0; k < n; k++ ){
        if (i < m){
            if (p[i] < q[j])
                s[k] = p[i++];
            else 
                s[k] = q[j++];
        }
        else 
            s[k] = q[j++];
    }
}


int main (){
    
    int a[] = {0,3,4,7};
    int b[] = {1,2,5,6,8,9};
    int c[10];

    HeapSort(10, 4, a, b, c);

    for (int k = 0; k < 10; k ++)
        cout << "Position " << k << ": " << c[k] << endl;
}
