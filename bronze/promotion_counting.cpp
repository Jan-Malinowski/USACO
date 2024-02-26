#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream in("promote.in");
    ofstream out("promote.out");
    int bs, be, ss, se, gs, ge, ps, pe;
    int pgs=0, gss=0, bss=0;
    in >> bs >>  be >> ss >> se >> gs >> ge >> ps >> pe;
    pgs=pe-ps;
    gss=pe-ps+ge-gs;
    bss=pe-ps+ge-gs+se-ss;

    out << bss <<"\n"<<gss<<"\n"<<pgs;

    return 0;
}