#include "fragmentare.h"
using namespace std;


std :: vector <std :: string> fragmentare(std :: string lista,std :: string delim)
{
    std :: vector <std :: string> fragmente;
    int poz = 0;
    std :: string token;
    while ((poz = lista.find(delim)) != std :: string::npos)
    {
        token = lista.substr(0,poz);
        fragmente.push_back(token);
        lista.erase(0,poz + delim.length());
    }
    lista.erase(lista.length());
    fragmente.push_back(lista);
    return fragmente;
}
