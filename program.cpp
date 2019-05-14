#include "program.h"
using namespace std;

void program :: eliminare_spect(const string n,int l,const string tip)
{
    if(tip == "circ")
    {
        circ c(n,0,"NaN",l);
        elim<circ>(c,spect_c);
    }
    else if(tip == "opera")
         {
            opera o(n,0,"NaN",l);
            elim<opera>(o,spect_o);
         }
    else if(tip == "teatru")
         {
            teatru t(n,0,"NaN",l);
            elim<teatru>(t,spect_t);
         }
}

void program :: recomandari(spectator &ins,ostream &out)
{
    vector <circ> recom_c;
    vector <opera> recom_o;
    vector <teatru> recom_t;
    if(ins.preferinte_c.size())
        verif_pref(recom_c,spect_c,ins.preferinte_c);
    else verif_pref(recom_c,spect_c,ins.preferinte);
    if(ins.preferinte_o.size())
        verif_pref(recom_o,spect_o,ins.preferinte_o);
    else verif_pref(recom_o,spect_o,ins.preferinte);
    if(ins.preferinte_t.size())
        verif_pref(recom_t,spect_t,ins.preferinte_t);
    else verif_pref(recom_t,spect_t,ins.preferinte);
    verif_exig(spect_c,ins.exigenta,ins.varsta);
    verif_exig(spect_o,ins.exigenta,ins.varsta);
    verif_exig(spect_t,ins.exigenta,ins.varsta);
    int i;
    out << "Recomandari pentru domnul/doamna " << ins.nume << "." << endl << endl;
    out << "Recomandari circ:" << endl;
    for(i=0;i<recom_c.size();i++)
        out << recom_c[i] << endl;
    out << endl << "Recomandari opera:" << endl;
    for(i=0;i<recom_o.size();i++)
        out << recom_o[i] << endl;
    out << endl << "Recomandari teatru:" << endl;
    for(i=0;i<recom_t.size();i++)
        out << recom_t[i] << endl;
}

istream & operator>>(istream &in,program &p)
{
    int i, nr_s;
    string tip;
    in >> nr_s;
    circ c;
    opera o;
    teatru t;
    for(i=0;i<nr_s;i++)
    {
        in >> tip;
        in.ignore(1,'\n');
        if(tip == "circ")
            {
                in >> c;
                p.spect_c.push_back(c);
            }
        else if(tip == "opera")
                {
                    in >> o;
                    p.spect_o.push_back(o);
                }
             else if(tip == "teatru")
                     {
                         in >> t;
                         p.spect_t.push_back(t);
                     }
    }
    return in;
}

ostream & operator<<(ostream &out,const program &p)
{
    int i;
    out << "Spectacole de circ:" << endl;
    for(i=0;i<p.spect_c.size();i++)
        out << p.spect_c[i] << endl;
    out << "Spectacole de opera:" << endl;
    for(i=0;i<p.spect_o.size();i++)
        out << p.spect_o[i] << endl;
    out << "Spectacole de teatru:" << endl;
    for(i=0;i<p.spect_t.size();i++)
        out << p.spect_t[i] << endl;
    return out;
}

