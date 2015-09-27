#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
using namespace std;
int main()
{
   int N, ans=-1;
   bool fail=false, found=false;
   long tick;
   short len;
   string ticket;
   cin >> N >> ticket;
   stringstream ss(ticket);
   ss >>tick;
   len=(short)ticket.length();
   ticket="";
   for(long i=tick+1; i<tick+N; ++i, fail=false) {
	   ss.str(""); ss.clear(); ss << i; ticket = ss.str();
       if(len<(short)ticket.length()){ fail=true; break; }
       ++ans;
       for(int j=2; j<=sqrt(i); ++j) {
           if(!(i%j)) fail=true;
       }
       if(!fail) { found=true; break; }
   }
   cout << (fail||!found ? -1: ans)<<endl;
   return 0;
}
