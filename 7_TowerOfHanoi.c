#include <stdio.h>
int TOH(int n, char A, char C, char B)
{
    // if(n==1)TOH(n,A,C,B);
    if (n > 0)
    {
        TOH(n - 1, A, B, C);
        printf("Disk %c To %c \n", A, B);
        TOH(n - 1, B, C, A);
    }
}
int main()
{
    int n = 3;
    TOH(n, 'A', 'B', 'C');
    return 0;
}