#ifndef PREFERINTA_H_INCLUDED
#define PREFERINTA_H_INCLUDED
#include <string>
#include <iostream>
#pragma once

class preferinta
{
    protected:
        std :: string gen_p;
        int dur_p;
    public:
        preferinta(std :: string g = "NaN",int d = 0);
        preferinta(const preferinta &);
        preferinta operator=(const preferinta &);
        friend std :: istream & operator>>(std :: istream &,preferinta &);
        friend std :: ostream & operator<<(std :: ostream &,const preferinta &);
        bool check_gen(const std :: string) const;
        bool check_dur_min( int) const;
        virtual void set_gen(const std :: string);
        void set_dur(int);
};

class pref_circ : public preferinta
{
    std :: string anim_p;
    public:
        pref_circ(std :: string g = "NaN",int d = 0);
        pref_circ(const pref_circ &);
        pref_circ operator=(const pref_circ &);
        friend std :: istream & operator>>(std :: istream &,pref_circ &);
        friend std :: ostream & operator<<(std :: ostream &,pref_circ &);
        bool check_anim(const std :: string) const;
        void set_anim(const std :: string);
        void set_gen(const std :: string);
};

class pref_opera : public preferinta
{
    std :: string voce_p;
    public:
        pref_opera(std :: string g = "NaN",int d = 0);
        pref_opera(const pref_opera &);
        pref_opera operator=(const pref_opera &);
        friend std :: istream & operator>>(std :: istream &,pref_opera &);
        friend std :: ostream & operator<<(std :: ostream &,pref_opera &);
        bool check_voce(const std :: string) const;
        void set_voce(const std :: string);
};

class pref_teatru : public preferinta
{
    bool interact_p;
    public:
        pref_teatru(std :: string g = "NaN",int d = 0);
        pref_teatru(const pref_teatru &);
        pref_teatru operator=(const pref_teatru &);
        friend std :: istream & operator>>(std :: istream &,pref_teatru &);
        friend std :: ostream & operator<<(std :: ostream &,pref_teatru &);
        bool check_interact(bool) const;
        void set_interact(bool);
};

#endif // PREFERINTA_H_INCLUDED
