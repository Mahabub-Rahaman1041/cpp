#include<stdio.h>
int main(){
    int n;
    printf("enter the number of element in an array:");
    scanf("%d",&n);
    int arr[n];
    printf("enter%d elements:\n",n);
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int sum =0;
    for(int i=0;i<n;i++)
    {
        sum +=arr[i];
    }
    float average=(float)sum/n;
    printf("sum:%d\n",sum);
    printf("average:%2f\n",average);
    return 0;
    }