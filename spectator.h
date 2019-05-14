#ifndef SPECTATOR_H_INCLUDED
#define SPECTATOR_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include "preferinta.h"
#include "exigenta.h"
#pragma once

class program;

class spectator
{
    std :: string nume;
    int varsta;
    std :: vector <preferinta> preferinte;
    std :: vector <pref_circ> preferinte_c;
    std :: vector <pref_opera> preferinte_o;
    std :: vector <pref_teatru> preferinte_t;
    exigente exigenta;
    public:
        spectator(std :: string n = "NaN",int v = 0);
        ~spectator();
        spectator(const spectator &);
        spectator operator=(const spectator &);
        friend std :: istream & operator>>(std :: istream &,spectator &);
        friend std :: ostream & operator<<(std :: ostream &,const spectator &);
        friend program;
};

#endif // SPECTATOR_H_INCLUDED
