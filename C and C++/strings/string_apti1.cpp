# include <string.h>
# include <iostream>
using namespace std;
main() {
   string s("abc");
   string t;
   char & c(s[1]);

   t = s;	// Data typically shared between s and t.
   c = 'z';
   cout<<s<<endl;     // How many strings does this modify?
   if (t[1] == 'z') {
        printf("wrong\n");
   } else {
        printf("right\n");
   }
}

/*

Here only s will be modified and not t.

*/
