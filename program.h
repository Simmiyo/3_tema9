#ifndef PROGRAM_H_INCLUDED
#define PROGRAM_H_INCLUDED
#include <vector>
#include <string>
#include <algorithm>
#include "spectator.h"
#include "preferinta.h"
#include "spectacol.h"
#pragma once

class program
{
    std :: vector <circ> spect_c;
    std :: vector <opera> spect_o;
    std :: vector <teatru> spect_t;
    program() {};
    program(const program &) {};
    program operator=(const program &) {};
    public:
        static program & getinstance()
        {
            static program instance;
            return instance;
        }
        template <class X>
        void adaugare_spect(X){std :: cout << "Tip spectacol inexistent!";}
        void eliminare_spect(const std :: string,int,const std :: string);
        friend std :: istream & operator>>(std :: istream &,program &);
        friend std :: ostream & operator<<(std :: ostream &,const program &);
        template <class Y>
        friend void elim(Y,std :: vector<Y>);
        void recomandari(spectator &,std :: ostream &);
        template <class Z,class W>
        friend void verif_pref(std :: vector<Z> &,std :: vector<Z>,std :: vector<W>);
        template <class Q>
        friend void verif_exig(std :: vector<Q>,exigente &,int);
};

template<class X>
bool egal(const X &a, const X &b)
{
    return(a.nume == b.nume && a.luna == b.luna);
}

template <class Z,class W>
void verif_pref(std :: vector<Z> &rec,std :: vector<Z> sp,std :: vector<W> pr)
{
    for(int i=0;i<pr.size();i++)
        for(int j=0;j<sp.size();j++)
            if(sp[j] == pr[i])
                rec.push_back(sp[j]);
}

template <class Q>
void verif_exig(std :: vector<Q> sp,exigente &ex,int age)
{
    for(int i=0;i<sp.size();i++)
        for(int j=0;j<ex.combinatie_e.size();j++)
            if(sp[i].tip + "-" + sp[i].gen == ex.combinatie_e[j])
                {
                    sp.erase(sp.begin() + i);
                    break;
                }
    for(int i=0;i<sp.size();i++)
        if(sp[i].durata > ex.dur_e)
            sp.erase(sp.begin() + i);
    for(int i=0;i<sp.size();i++)
    {
        for(int j=0;j<sp[i].nr_locuri.size();j++)
            if(sp[i].nr_locuri[j] > ex.nr_spect)
                sp[i].eliminare_reprezentatie(j);
        if(!sp[i].zi_prezentare.size())
            sp.erase(sp.begin() + i);
    }
}

template <>
inline void verif_exig(std :: vector<circ> sp,exigente &ex,int age)
{
    for(int i=0;i<sp.size();i++)
        for(int j=0;j<ex.combinatie_e.size();j++)
            if(sp[i].tip + "-" + sp[i].gen == ex.combinatie_e[j])
                {
                    sp.erase(sp.begin() + i);
                    break;
                }
    for(int i=0;i<sp.size();i++)
        if(sp[i].durata > ex.dur_e)
            sp.erase(sp.begin() + i);
    for(int i=0;i<sp.size();i++)
    {
        for(int j=0;j<sp[i].nr_locuri.size();j++)
            if(sp[i].nr_locuri[j] > ex.nr_spect)
                sp[i].eliminare_reprezentatie(j);
        if(!sp[i].zi_prezentare.size())
            sp.erase(sp.begin() + i);
    }
    for(int i=0;i<sp.size();i++)
        if((sp[i].pericol == 1 && ex.pericol_e == 1) || (age < 18 && !sp[i].adecvat))
            sp.erase(sp.begin() + i);
}

template <class X>
void elim(X x,std :: vector<X> v)
{
    typename std :: vector <X> :: iterator it;
    std :: vector <X> v0;
    v0.push_back(x);
    it = find_first_of(v.begin(),v.end(),v0.begin(),v0.end(),egal<X>);
    if(it != v.end())
        v.erase(it);
}

template <>
inline void program :: adaugare_spect(circ c)
{
    spect_c.push_back(c);
}

template <>
inline void program :: adaugare_spect(opera o)
{
    spect_o.push_back(o);
}

template <>
inline void program :: adaugare_spect(teatru t)
{
    spect_t.push_back(t);
}

#endif // PROGRAM_H_INCLUDED
