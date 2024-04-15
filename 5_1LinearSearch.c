#include <stdio.h>
#include <stdbool.h>
bool LinearSearch(int a[],int len,int se)
{
    for(int i=0;i<len;i++){
        if(a[i]==se)return true;
    }
    return false;
}
int main()
{   
    int searchElement;
    int a[]={1,2,3,4,5,6};
    int len=sizeof(a) / sizeof(a[0]);
    printf("Enter Search Element: ");
    scanf("%d",&searchElement);
    bool searchElementPresent=LinearSearch(a,len,searchElement);
    printf("isPresent: %d",searchElementPresent);
}