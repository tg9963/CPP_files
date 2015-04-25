#include <hash_map>
#include <iostream>
using namespace std;
//using namespace stdext;
 
int main(void)
{
// container and iterators
hash_map <int, int> hm1;
hash_map <int, int> :: iterator hm1_Iter;
hash_map <int, int> :: const_iterator hm1_cIter;
typedef pair <int, int> Int_Pair;
 
// pushing/inserting data
hm1.insert(Int_Pair(3, 7));
hm1.insert(Int_Pair(9, 5));
hm1.insert(Int_Pair(2, 4));
hm1_cIter = hm1.begin();
 
// print the elements
cout<<"The first element of hm1 hash map is "<<hm1_cIter->first<<endl;
hm1_Iter = hm1.begin();
hm1.erase(hm1_Iter);
// the following 2 lines would err because the iterator is const
// hm1_cIter = hm1.begin();
// hm1.erase(hm1_cIter);
hm1_cIter = hm1.begin();
cout<<"After erase() operation, the first element of hm1 hash map is now "<<hm1_cIter->first<<endl;
return 0;
}
