


#include <stdio.h>
#include <algorithm>

int n;
int a,b,c;
int m;
int main(){

scanf("%d",&n);
a=n-(n/100)*100;
c=(n-n%10)/10;
b=(n/100)*10 +n%10;
m=c;
if((b<=c)&&(b/10>=1)) m=b;
if((a<b)&&(a/10>=1)) m=a;

printf("%d",m);

}
