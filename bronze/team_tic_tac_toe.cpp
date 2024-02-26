#include <iostream>
#include <set>

using namespace std;

set<set<char>> S[4];

void test(char a, char b, char c) {
   set<char> s;
   s.insert(a);
   s.insert(b);
   s.insert(c);
   S[s.size()].insert(s);
}
//if cow C has 1 sigle win it cant get one more

int main() {
   freopen("tttt.in","r",stdin);
   freopen("tttt.out","w",stdout);
   char a, b, c, d, e, f, g, h, i;
   cin >> a >> b >> c >> d >> e
       >> f >> g >> h >> i;
   // a b c
   // d e f
   // g h i
   test(a,b,c);
   test(d,e,f);
   test(g,h,i);
   test(a,d,g);
   test(b,e,h);
   test(c,f,i);
   test(a,e,i);
   test(g,e,c);
   cout << S[1].size() << endl << S[2].size() << endl;
}

