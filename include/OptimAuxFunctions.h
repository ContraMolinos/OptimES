/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   auxFunctions.h
 * Author: F.J Salguero <j.salguero@fratoria.com>
 *
 * Created on 15 de mayo de 2018, 13:01
 */

#ifndef OPTIMAUXFUNCTIONS_H
#define OPTIMAUXFUNCTIONS_H

#include<sys/types.h>
#include "Chromosome.h"
#include <vector>
#include <algorithm>

namespace OptimES
{
    using std::vector;
    
    inline uint partition(vector<Chromosome> &_population, uint _low, uint _high)
    {
        double pivot=_population[(_high-1)].getFitness();

        uint j=_low;
        for(uint i=_low;i<_high-1;++i)
        {
            if(_population[i].getFitness()<=pivot)
            {
                std::iter_swap(_population.begin()+i, _population.begin()+j);
                ++j;
            }
        }
        std::iter_swap(_population.begin()+j, _population.begin()+_high-1);
        return j;
    }
    
    inline void quickSort(vector<Chromosome> &_population, uint _low, uint _high)
    {
        if(_low<_high)
        {
            uint p=partition(_population, _low, _high);
            quickSort(_population, _low, p);
            quickSort(_population, p+1, _high);
        }
    }
    
}

#endif /* AUXFUNCTIONS_H */

