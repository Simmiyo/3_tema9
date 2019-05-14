#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <numeric>
#include <algorithm>
#include "program.h"

using namespace std;

int main()
{
    ifstream f;
    ofstream g;
    f.open("spectacole.in");
    g.open("recomandari.out");
    program &p = program :: getinstance();
    f >> p;
    teatru t("Hamlet",0,"NaN",5);
    cout << p;
    spectator cristi;
    f>>cristi;
    cout<<cristi;
    p.recomandari(cristi,g);
    f.close();
    g.close();
    return 0;
}
