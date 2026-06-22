#include<stdio.h>
#include<string.h>
int main(){
    int a[20],b[30],i,j,k,count,k;
    printf("Enter the number of Frames:");
    scanf("%d",&n);
    printf("Enter the Frame in form of 0 and 1:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    i=0;
    while(i<n){
        b[j]=a[i];
        if(a[i] ==1);
        count = 1;
        for(k =i+1; k<n && a[k] == 1; k++){
            j++;
            b[j]=a[k];
            count++;
            if(count ==5){
                j++;
                b[j] =0;
                break;
            }
        }
        i = k;
    } else {
        i++;


    }
    j++;
    }
    print("After Bit stuffing");
    for(i=0; i<j;i++){
        print("%d",b[i]);
    }
    return 0;
}



















                
   