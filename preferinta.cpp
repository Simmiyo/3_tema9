#include "preferinta.h"
using namespace std;

//preferinte generale
preferinta :: preferinta(string g,int d)
{
    gen_p = g;
    dur_p = d;
}

preferinta :: preferinta(const preferinta &p)
{
    gen_p = p.gen_p;
    dur_p = p.dur_p;
}

preferinta preferinta :: operator=(const preferinta &p)
{
    gen_p = p.gen_p;
    dur_p = p.dur_p;
    return *this;
}

istream & operator>>(istream &in,preferinta &p)
{
    in >> p.gen_p;
    in >> p.dur_p;
    return in;
}

ostream & operator<<(ostream &out,const preferinta &p)
{
    if(p.gen_p != "NaN")
        out << " Sa fie " << p.gen_p << ".";
    if(p.dur_p > 0)
        out << " Sa dureze minim " << p.dur_p << " minute.";
    return out;
}

bool preferinta :: check_gen(const string s) const
{
    return (s == gen_p);
}

bool preferinta :: check_dur_min(int i) const
{
    return (i >= dur_p);
}

void preferinta :: set_gen(const string s)
{
    gen_p = s;
}

void preferinta :: set_dur(int i)
{
    dur_p = i;
}

//preferinte circ

pref_circ :: pref_circ(string g ,int d) : preferinta(g,d)
{
    anim_p = "NaN";
    gen_p = "comedie";
}

pref_circ :: pref_circ(const pref_circ &c) : preferinta(c)
{
    anim_p = c.anim_p;
}

pref_circ pref_circ :: operator=(const pref_circ &c)
{
    preferinta :: operator=(c);
    anim_p = c.anim_p;
    return *this;
}

istream & operator>>(istream &in,pref_circ &c)
{
    in >> static_cast<preferinta&>(c);
    in >> c.anim_p;
    c.gen_p = "comedie";
    return in;
}

ostream & operator<<(ostream &out,pref_circ &c)
{
    out << static_cast<preferinta&>(c);
    out << " Sa prezinte " << c.anim_p << ".";
    return out;
}

bool pref_circ :: check_anim(const string a) const
{
    return (a == anim_p);
}

void pref_circ :: set_anim(const string a)
{
    anim_p = a;
}

void pref_circ :: set_gen(const string g)
{
    gen_p = "comedie";
}


//preferinte opera

pref_opera :: pref_opera(string g,int d) : preferinta(g,d)
{
    voce_p = "NaN";
}

pref_opera :: pref_opera(const pref_opera &o) : preferinta(o)
{
    voce_p = o.voce_p;
}

pref_opera pref_opera :: operator=(const pref_opera &o)
{
    preferinta :: operator=(o);
    voce_p = o.voce_p;
    return *this;
}

istream & operator>>(istream &in,pref_opera &o)
{
    in >> static_cast<preferinta&>(o);
    in >> o.voce_p;
    return in;
}

ostream & operator<<(ostream &out,pref_opera &o)
{
    out << static_cast<preferinta&>(o);
    out << " Sa aiba drept solist principal un " << o.voce_p << ".";
    return out;
}

bool pref_opera :: check_voce(const string v) const
{
    return (v == voce_p);
}

void pref_opera :: set_voce(const string v)
{
    voce_p = v;
}


//preferinta teatru

pref_teatru :: pref_teatru(string g ,int d) : preferinta(g,d)
{
    interact_p = 0;
}

pref_teatru :: pref_teatru(const pref_teatru &t) : preferinta(t)
{
    interact_p = t.interact_p;
}

pref_teatru pref_teatru :: operator=(const pref_teatru &t)
{
    preferinta :: operator=(t);
    interact_p = t.interact_p;
    return *this;
}

istream & operator>>(istream &in,pref_teatru &t)
{
    in >> static_cast<preferinta&>(t);
    in >> t.interact_p;
    return in;
}

ostream & operator<<(ostream &out,pref_teatru &t)
{
    out << static_cast<preferinta&>(t);
    if(t.interact_p)
        out << " Sa fie intaractiv.";
    else out << " Sa nu fie interactiv.";
    return out;
}

bool pref_teatru :: check_interact(bool i) const
{
    return (i == interact_p);
}

void pref_teatru :: set_interact(bool i)
{
    interact_p = i;
}
