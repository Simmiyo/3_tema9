#include "spectacol.h"
using namespace std;

spectacol :: spectacol(string s,int d,string g,unsigned int l)
{
    nume = s;
    durata = d;
    gen = g;
    luna = l;
}


spectacol :: ~spectacol()
{
    zi_prezentare.erase(zi_prezentare.begin(),zi_prezentare.end());
    nr_locuri.erase(nr_locuri.begin(),nr_locuri.end());
}

spectacol :: spectacol(const spectacol &s)
{
    tip = s.tip;
    nume = s.nume;
    durata = s.durata;
    gen = s.gen;
    luna = s.luna;
    zi_prezentare = s.zi_prezentare;
    nr_locuri = s.nr_locuri;
}

spectacol & spectacol :: operator=(const spectacol &s)
{
    tip = s.tip;
    nume = s.nume;
    durata = s.durata;
    gen = s.gen;
    luna = s.luna;
    zi_prezentare = s.zi_prezentare;
    nr_locuri = s.nr_locuri;
    return *this;
}

bool spectacol :: operator==(const spectacol &s)
{
    if(tip != s.tip)
        return 0;
    if(nume == s.nume)
        if(durata == s.durata)
            if(luna == s.luna)
                if(gen == s.gen)
                    if(nr_locuri == s.nr_locuri)
                        if(zi_prezentare == s.zi_prezentare)
                                return 1;
    return 0;
}

bool spectacol :: operator==(const preferinta &p)
{
    if(!p.check_gen("NaN"))
        if(!p.check_gen(gen))
            return 0;
    if(p.check_dur_min(0))
        if(!p.check_dur_min(durata))
            return 0;
    return 1;
}

void spectacol :: citire(istream &in)
{
    getline(in,nume);
    if(nume[nume.length()-1] == '\r')
        nume.erase(nume.begin()+nume.length()-1);
    in >> durata;
    in >> gen;
    in >> luna;
    int n,x;
    in >> n;
    zi_prezentare.erase(zi_prezentare.begin(),zi_prezentare.end());
    nr_locuri.erase(nr_locuri.begin(),nr_locuri.end());
    for(int i=0;i<n;i++)
    {
        in >> x;
        zi_prezentare.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        in >> x;
        nr_locuri.push_back(x);
    }
}

void spectacol :: scriere(ostream &out) const
{
    out << "Nume spectacol: " << nume << endl;
    out << "Durata spectacol: " << durata << endl;
    out << "Gen spectacol: " << gen << endl;
    out << "Luna: " << luna << endl;
    out << "Zile prezentari: ";
    for(int i=0;i<zi_prezentare.size();i++)
       out << zi_prezentare[i] <<" ";
    out << endl << "Nr locuri : ";
    for(int i=0;i<nr_locuri.size();i++)
         out << nr_locuri[i] << " ";
}

void spectacol :: adaugare_reprezentatie(int zi,int loc)
{
    zi_prezentare.push_back(zi);
    nr_locuri.push_back(loc);
}

void spectacol :: eliminare_reprezentatie(int zi)
{
    for(int i=0;i<zi_prezentare.size();i++)
        if(zi == zi_prezentare[i])
        {
            zi_prezentare.erase(zi_prezentare.begin() + i);
            nr_locuri.erase(nr_locuri.begin() + i);
        }
}


opera :: opera(string s, int d, string g, unsigned int l) : spectacol(s,d,g,l)
{
    tip = "opera";
    nume_solist = "NaN";
    tip_solist = "NaN";
    nr_acte = 0;
    pauza = 0;
}

opera :: ~opera()
{
    durata_act.erase(durata_act.begin(),durata_act.end());
}

opera :: opera(const opera &o) : spectacol(o)
{
    tip = o.tip;
    nume_solist = o.nume_solist;
    tip_solist = o.tip_solist;
    nr_acte = o.nr_acte;
    durata_act = o.durata_act;
    pauza = o.pauza;
}

void opera :: citire(istream &in)
{
    this->spectacol::citire(in);
    int n,x;
    in.ignore(1,'\n');
    getline(in,nume_solist);
    if(nume[nume_solist.length()-1] == '\r')
        nume_solist.erase(nume_solist.begin()+nume_solist.length()-1);
    in >> tip_solist;
    while (tip_solist != "tenor" && tip_solist != "bariton" && tip_solist != "bass")
    {
        cout << "Introduceti un tip valid de solist: ";
        cin >> tip_solist;
    }
    in >> nr_acte;
    while(nr_acte > 7 || nr_acte < 1)
    {
        cout << "Introduceti un nr valid de acte: ";
        cin >> nr_acte;
    }
    durata_act.erase(durata_act.begin(),durata_act.end());
    for(int i=0;i<nr_acte;i++)
    {
        in >> x;
        durata_act.push_back(x);
    }
    in >> pauza;
    in.ignore(1,'\n');
    calcul_durata();
}

void opera :: scriere(ostream &out) const
{
    this -> spectacol :: scriere(out);
    out << endl << "Nume solist: " << nume_solist << endl;
    out << "Tip solist: " << tip_solist << endl;
    out << "Nr acte: " << nr_acte << endl;
    out << "Durata act: ";
    for(int i=0;i<nr_acte;i++)
        out << durata_act[i] << " ";
    out << endl << "Durata pauza: " << pauza << endl;
    out << endl;
}

opera opera :: operator=(const opera &o)
{
    spectacol :: operator=(o);
    tip = o.tip;
    nume_solist = o.nume_solist;
    tip_solist = o.tip_solist;
    nr_acte = o.nr_acte;
    durata_act = o.durata_act;
    pauza = o.pauza;
    return *this;
}

bool opera :: operator==(const opera &o)
{
    if(!this->spectacol::operator==(o))
        return 0;
    if (tip_solist == o.tip_solist && nume_solist == o.nume_solist)
        if(nr_acte == o.nr_acte && durata_act == o.durata_act)
            if(pauza == o.pauza)
                return 1;
    return 0;
}

bool opera :: operator==(const pref_opera &op)
{
    if(!this->spectacol::operator==(op))
        return 0;
    if(!op.check_voce("NaN"))
        return op.check_voce(tip_solist);
    return 1;
}

bool opera :: operator==(const preferinta &op)
{
    return this->spectacol::operator==(op);
}

void opera :: calcul_durata()
{
    accumulate(durata_act.begin(),durata_act.end(),durata);
    durata += pauza * (durata_act.size() - 1);
}

istream & operator>>(istream &in,opera &op)
{
    op.citire(in);
    return in;
}

ostream & operator<<(ostream &out,const opera &op)
{
    op.scriere(out);
    return out;
}

teatru :: teatru(string s, int d, string g, unsigned int l) : spectacol(s,d,g,l)
{
    tip = "teatru";
    interact = 0;
    durata_interact = 0;
}

teatru :: teatru(const teatru &t) : spectacol(t)
{
    tip = t.tip;
    interact = t.interact;
    durata_interact = t.durata_interact;
}

void teatru :: citire(istream &in)
{
    this -> spectacol :: citire(in);
    in >> interact;
    in.ignore(1,'\n');
}

void teatru :: scriere(ostream &out) const
{
    this -> spectacol :: scriere(out);
    if(!interact)
        out << endl << "Teatrul nu este interactiv." << endl;
    else {
            out << endl << "Teatrul este interactiv." << endl;
            out << "Durata interactiunii este de " << durata_interact << " minute." << endl;
         }
    out << endl;
}

teatru teatru :: operator=(const teatru &t)
{
    spectacol :: operator=(t);
    tip = t.tip;
    interact = t.interact;
    durata_interact = t.durata_interact;
    return *this;
}

bool teatru :: operator==(const teatru &t)
{
    if(!this->spectacol::operator==(t))
        return 0;
    if(interact != t.interact)
        return 0;
    return (durata_interact == t.durata_interact);
}

bool teatru :: operator==(const pref_teatru &tp)
{
    if(!this->spectacol::operator==(tp))
        return 0;
    return tp.check_interact(interact);
}

bool teatru :: operator==(const preferinta &tp)
{
    return this->spectacol::operator==(tp);
}


void teatru :: calcul_durata(int nr_copii,int nr_adulti)
{
    durata_interact = nr_adulti + 2 * nr_copii;
}

istream & operator>>(istream &in,teatru &t)
{
    t.citire(in);
    return in;
}

ostream & operator<<(ostream &out,const teatru &t)
{
    t.scriere(out);
    return out;
}

circ :: circ(string s,int d ,string g ,unsigned int l) : spectacol(s,d,g,l)
{
    tip = "circ";
    nr_prestatii = 1;
    adecvat = 1;
    exista_animale = 0;
    pericol = 0;
    gen = "comedie";
}

circ :: ~circ()
{
    animale.erase(animale.begin(),animale.end());
}

circ :: circ(const circ &c) : spectacol(c)
{
    tip = c.tip;
    nr_prestatii = c.nr_prestatii;
    adecvat = c.adecvat;
    exista_animale = c.exista_animale;
    pericol = c.pericol;
    animale = c.animale;
    gen = c.gen;
}

void circ :: citire(istream &in)
{
    this -> spectacol :: citire(in);
    in >> nr_prestatii;
    in >> adecvat;
    in >> exista_animale;
    if(exista_animale)
    {
        string lista_anim;
        string delim = ", ";
        in.ignore(1,'\n');
        getline(in,lista_anim);
        animale = fragmentare(lista_anim,delim);
        this -> set_pericol();
    }
    else in.ignore(1,'\n');
}

void circ :: scriere(ostream &out) const
{
    this -> spectacol :: scriere(out);
    out << endl << "Nr prestatii: " << nr_prestatii << endl;
    if(adecvat)
        out << "Circ adecvat pt copii." << endl;
    else out << "Circ nerecomandat copiilor." <<endl;
    if(!exista_animale)
        out << "Circ fara animale." << endl;
    else
    {
        out << "Lista animale: ";
        for(int i=0;i<animale.size()-1;i++)
        {
            out << animale[i] << ", ";
        }
        out << animale[animale.size()-1] << endl;
    }
    if(!pericol)
        out << "Circul nu prezinta animale periculoase." << endl;
    else out << "Circul prezinta animale periculoase." << endl;
    out << endl;
}

circ circ :: operator=(const circ &c)
{
    spectacol :: operator=(c);
    tip = c.tip;
    nr_prestatii = c.nr_prestatii;
    adecvat = c.adecvat;
    exista_animale = c.exista_animale;
    pericol = c.pericol;
    gen = c.gen;
    return *this;
}

bool circ :: operator==(const circ &c)
{
    if(!this->spectacol::operator==(c))
        return 0;
    if(adecvat == c.adecvat)
        if(exista_animale == c.exista_animale)
            if(pericol == c.pericol)
                if(animale == c.animale)
                    return 1;
    return 0;
}

bool circ :: operator==(const pref_circ &cp)
{
    if(!this->spectacol::operator==(cp))
        return 0;
    if(!cp.check_anim("NaN"))
    {
        int i;
        for(i=0;i<animale.size();i++)
        {
            if(cp.check_anim(animale[i]))
                return 1;
        }
        return 0;
    }
    return 1;
}

bool circ :: operator==(const preferinta &cp)
{
    return this->spectacol::operator==(cp);
}

void circ :: set_pericol()
{
    string anim_per = " leu urs tigru sarpe gorila lei ursi tigri serpi gorile ";
    string anim;
    for(int i=0;i<animale.size();i++)
    {
        anim = " " + animale[i] + " ";
        if(anim_per.find(anim) != string::npos)
        {
            pericol = 1;
            break;
        }
    }
}

istream & operator>>(istream &in,circ &c)
{
    c.citire(in);
    return in;
}

ostream & operator<<(ostream &out,const circ &c)
{
    c.scriere(out);
    return out;
}
