#include "exigenta.h"
using namespace std;


exigente :: exigente(int d,bool p,int n)
{
    dur_e = d;
    pericol_e = p;
    nr_spect = n;
}

exigente :: ~exigente()
{
    combinatie_e.erase(combinatie_e.begin(),combinatie_e.end());
}

exigente :: exigente(const exigente &e)
{
    combinatie_e = e.combinatie_e;
    dur_e = e.dur_e;
    pericol_e = e.pericol_e;
    nr_spect = e.nr_spect;
}

exigente exigente :: operator=(const exigente &e)
{
    combinatie_e = e.combinatie_e;
    dur_e = e.dur_e;
    pericol_e = e.pericol_e;
    nr_spect = e.nr_spect;
    return *this;
}

istream & operator>>(istream &in,exigente &e)
{
    string comb;
    getline(in,comb);
    e.combinatie_e = fragmentare(comb,", ");
    in >> e.dur_e;
    in >> e.pericol_e;
    in >> e.nr_spect;
    return in;
}

ostream & operator<<(ostream &out,const exigente &e)
{
    int i;
    if(e.combinatie_e.size())
    {
        out << "- Sa nu se regaseasca printre combinatiile: ";
        for(i=0;i<e.combinatie_e.size()-1;i++)
            out << e.combinatie_e[i] << ", ";
        out << e.combinatie_e[i];
        out << endl;
    }
    if(e.dur_e > 0)
        out << "- Sa dureze maxim " << e.dur_e << " minute." << endl;
    if(e.pericol_e == 1)
        out << "- Daca e circ, sa nu fie expuse animale periculoase." << endl;
    if(e.nr_spect > 0)
        out << "- Sa nu fie prezenti in sala mai mult de " << e.nr_spect << " spectatori.";
}

inline bool exigente :: check_dur_max(int d)
{
    return (d == dur_e);
}

inline bool exigente :: check_pericol(bool p)
{
    return (p == pericol_e);
}

inline bool exigente :: check_audienta(int a)
{
    return (a == nr_spect);
}

bool exigente :: check_comb(string c)
{
    for(int i=0;i<combinatie_e.size();i++)
        if(c == combinatie_e[i])
            return 1;
    return 0;
}

inline void exigente :: set_dur(int d)
{
    dur_e = d;
}

inline void exigente :: set_pericol(bool p)
{
    pericol_e = p;
}

inline void exigente :: set_audienta(int a)
{
    nr_spect = a;
}

inline void exigente :: set_comb(vector <string> c)
{
    combinatie_e = c;
}
