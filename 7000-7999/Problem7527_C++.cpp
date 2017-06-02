#include <stdio.h>


int n,courses,y1,m1,d1,y2,m2,d2;char name[31];
int main(){

scanf("%d\n",&n);
  while(n--)
  {
scanf("%s %d/%d/%d %d/%d/%d %d",name,&y1,&m1,&d1,&y2,&m2,&d2,&courses);
if(y1>=2010){
    printf("%s eligible\n",name);
}
else if(y2>=1991){
    printf("%s eligible\n",name);
}
    else{
if(courses<41) {printf("%s coach petitions\n",name);}
else {

    printf("%s ineligible\n",name);
}

    }

}

}
