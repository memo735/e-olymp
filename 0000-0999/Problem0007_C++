#include <iostream>
#include <string>

using namespace std;

const string Rom[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I", ""};
const int Ar[]={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1, 0};

string Roman(int arab)
{
   string roman;
   int i=0;
   while(arab>0) {
       while(Ar[i]<=arab) { roman+=Rom[i]; arab-=Ar[i]; }
       ++i;
   }
   return roman;
}
int Arab(string roman)
{
   int arab=0, i=0;
   while(roman!="") {
       while(Rom[i]==roman.substr(0, Rom[i].length())) {
           roman.replace(0, Rom[i].length(), "");
           arab+=Ar[i];
       }
       ++i;
   }
   return arab;
}

int main()
{
   string first, second;
   char c;
   while((c=getchar())!='+') first.push_back(c);
   while((c=getchar())!='\n') second.push_back(c);
   cout << Roman(Arab(first) + Arab(second))<<endl;
   return 0;
}
