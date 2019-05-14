#ifndef EXIGENTA_H_INCLUDED
#define EXIGENTA_H_INCLUDED
#include <string>
#include <iostream>
#include <vector>
#include "fragmentare.h"
#pragma once

class exigente
{
    std :: vector <std :: string> combinatie_e;
    int dur_e;
    bool pericol_e;
    int nr_spect;
    public:
        exigente(int d = 0,bool p = 0,int n = 0);
        ~exigente();
        exigente(const exigente &);
        exigente operator=(const exigente &);
        friend std :: istream & operator>>(std :: istream &,exigente &);
        friend std :: ostream & operator<<(std :: ostream &,const exigente &);
        bool check_dur_max(int);
        bool check_pericol(bool);
        bool check_audienta(int);
        bool check_comb(std :: string);
        void set_dur(int);
        void set_pericol(bool);
        void set_audienta(int);
        void set_comb(std :: vector <std :: string>);
        template <class Q>
        friend void verif_exig(std :: vector<Q>,exigente &,int);
};

#endif // EXIGENTA_H_INCLUDED
