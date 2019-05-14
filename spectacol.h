#ifndef SPECTACOL_H_INCLUDED
#define SPECTACOL_H_INCLUDED
#include <string>
#include <numeric>
#include <vector>
#include "preferinta.h"
#include "exigenta.h"
#include "fragmentare.h"
#pragma once

class spectacol
{
    protected:
        std :: string tip;
        std :: string nume;
        unsigned int durata;
        std :: string gen;
        unsigned int luna;
        std :: vector <int> zi_prezentare;
        std :: vector <int> nr_locuri;
    public:
        spectacol(std :: string s = "NaN",int d = 0,std :: string g = "NaN",unsigned int l = 0);
        virtual ~spectacol()=0;
        spectacol(const spectacol &);
        virtual void citire(std :: istream &);
        virtual void scriere(std :: ostream &) const;
        spectacol & operator=(const spectacol &);
        bool operator==(const spectacol &);
        bool operator==(const preferinta &);
        void adaugare_reprezentatie(int,int);
        void eliminare_reprezentatie(int);
        template<class X>
        friend bool egal(const X &,const X &);
        template <class Q>
        friend void verif_exig(std :: vector<Q>,exigente &,int);
};

class opera : public spectacol
{
    std :: string nume_solist;
    std :: string tip_solist;
    unsigned short int nr_acte;
    std :: vector <int> durata_act;
    unsigned int pauza;
    public:
        opera(std :: string s = "NaN",int d = 0,std :: string g = "NaN",unsigned int l = 0);
        ~opera();
        opera(const opera &);
        void citire(std :: istream &);
        void scriere(std :: ostream &) const;
        opera operator=(const opera &);
        bool operator==(const opera &);
        bool operator==(const pref_opera &);
        bool operator==(const preferinta &);
        void calcul_durata();
        friend std :: istream & operator>>(std :: istream &,opera &);
        friend std :: ostream & operator<<(std :: ostream &,const opera &);
        template<class X>
        friend bool egal(const X &,const X &);
};

class teatru : public spectacol
{
    bool interact;
    unsigned int durata_interact;
    public:
        teatru(std :: string s = "NaN",int d = 0,std :: string g = "NaN",unsigned int l = 0);
        teatru(const teatru &);
        void citire(std :: istream &);
        void scriere(std :: ostream &) const;
        teatru operator=(const teatru &);
        bool operator==(const teatru &);
        bool operator==(const pref_teatru &);
        bool operator==(const preferinta &);
        void calcul_durata(int,int);
        friend std :: istream & operator>>(std :: istream &,teatru &);
        friend std :: ostream & operator<<(std :: ostream &,const teatru &);
        template<class X>
        friend bool egal(const X &,const X &);
};


class circ : public spectacol
{
    unsigned int nr_prestatii;
    std :: vector <std :: string> animale;
    bool adecvat;
    bool exista_animale;
    bool pericol;
    public:
        circ(std :: string s = "NaN",int d = 0,std :: string g = "comedie",unsigned int l = 0);
        ~circ();
        circ(const circ &);
        void citire(std :: istream &);
        void scriere(std :: ostream &) const;
        circ operator=(const circ &);
        bool operator==(const circ &);
        bool operator==(const pref_circ &);
        bool operator==(const preferinta &);
        void set_pericol();
        friend std :: istream & operator>>(std :: istream &,circ &);
        friend std :: ostream & operator<<(std :: ostream &,const circ &);
        template<class X>
        friend bool egal(const X &,const X&);
        template <class Q>
        friend void verif_exig(std :: vector<Q>,exigente &,int);
};

#endif // SPECTACOL_H_INCLUDED
