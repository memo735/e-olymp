#include <stdio.h>
#include <math.h>
long long n,flag;
int main(){
scanf("%lld",&n);

for(int i=2;i<=pow(n,0.5);i++){
if(n%i==0){
    flag=1;break;
}

}

if(flag==1){
printf("No");


}
else printf("Yes");


}
