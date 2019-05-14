#include "spectator.h"
using namespace std;

spectator :: spectator(string n,int v)
{
    nume = n;
    varsta = v;
}

spectator :: ~spectator()
{
    preferinte_c.erase(preferinte_c.begin(),preferinte_c.end());
    preferinte_t.erase(preferinte_t.begin(),preferinte_t.end());
    preferinte_o.erase(preferinte_o.begin(),preferinte_o.end());
    preferinte.erase(preferinte.begin(),preferinte.end());
}

spectator :: spectator(const spectator &s)
{
    nume = s.nume;
    varsta = s.varsta;
    preferinte_c = s.preferinte_c;
    preferinte_o = s.preferinte_o;
    preferinte_t = s.preferinte_t;
    exigenta = s.exigenta;
}

spectator spectator :: operator=(const spectator &s)
{
    nume = s.nume;
    varsta = s.varsta;
    preferinte_c = s.preferinte_c;
    preferinte_o = s.preferinte_o;
    preferinte_t = s.preferinte_t;
    exigenta = s.exigenta;
    return *this;
}

istream & operator>>(istream &in,spectator &s)
{
    string tip;
    preferinta p;
    pref_circ c;
    pref_opera o;
    pref_teatru t;
    int nr_preferinte;
    getline(in,s.nume);
    in >> s.varsta;
    in >> nr_preferinte;
    int i;
    for(i=0;i<nr_preferinte;i++)
    {
        in >> tip;
        if(tip == "circ")
        {
            in >> c;
            s.preferinte_c.push_back(c);
        }
        else if(tip == "opera")
             {
                in >> o;
                s.preferinte_o.push_back(o);
             }
        else if(tip == "teatru")
             {
                in >> t;
                s.preferinte_t.push_back(t);
             }
        else if(tip == "NaN")
             {
                in >> p;
                s.preferinte.push_back(p);
             }
        else
            cout << "Eroare tip spectacol preferat.";
    }
    if(i > 0)
        in.ignore(1,'\n');
    in >> s.exigenta;
    return in;
}

ostream & operator<<(ostream &out,const spectator &s)
{
    int i;
    out << "Nume spectator: " << s.nume << endl;
    out << "Varsta spectator: " << s.varsta << endl;
    out << "Preferinte circ: " << endl;
    for(i=0;i<s.preferinte_c.size();i++)
        out << "-" << s.preferinte_c[i] << endl;
    out << "Preferinte opera: " << endl;
    for(i=0;i<s.preferinte_o.size();i++)
        out << "-" << s.preferinte_o[i] << endl;
    out << "Preferinte teatru: " << endl;
    for(i=0;i<s.preferinte_t.size();i++)
        out << "-" << s.preferinte_t[i] << endl;
    out << "Preferinte generale spectacol: " << endl;
    for(i=0;i<s.preferinte.size();i++)
        out << "-" << s.preferinte[i] << endl;
    out << "Exigente: " << endl;
    out << s.exigenta;
}


