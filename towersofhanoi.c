#include<stdio.h>

void towerOfHanoi(int n, char from, char to, char aux) 
{ 
    if (n == 1) 
    { 
        printf("\n Move disk 1 from rod %c to rod %c", from, to); 
        return; 
    } 
    towerOfHanoi(n-1, from, aux, to); 
    printf("\n Move disk %d from rod %c to rod %c", n, from, to); 
    towerOfHanoi(n-1, aux, to, from); 
} 
  
int main() 
{ 
    int n = 4;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0; 
}

/*
OUTPUT:
 Move disk 1 from rod A to rod B
 Move disk 2 from rod A to rod C
 Move disk 1 from rod B to rod C
 Move disk 3 from rod A to rod B
 Move disk 1 from rod C to rod A
 Move disk 2 from rod C to rod B
 Move disk 1 from rod A to rod B
 Move disk 4 from rod A to rod C
 Move disk 1 from rod B to rod C
 Move disk 2 from rod B to rod A
 Move disk 1 from rod C to rod A
 Move disk 3 from rod B to rod C
 Move disk 1 from rod A to rod B
 Move disk 2 from rod A to rod C
 Move disk 1 from rod B to rod C
*/
