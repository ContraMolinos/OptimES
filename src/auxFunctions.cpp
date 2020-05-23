/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "auxFunctions.h"


void quickSort(Chromosome** _population, uint _low, uint _high)
{
    if(_low<_high)
    {
        uint p=partition(_population, _low, _high);
        quickSort(_population, _low, p);
        quickSort(_population, p+1, _high);
    }
}

uint partition(Chromosome** _population, uint _low, uint _high)
{
    double pivot=_population[(_high-1)]->getFitness();
    
    uint j=_low;
    for(uint i=_low;i<_high-1;++i)
    {
        if(_population[i]->getFitness()<=pivot)
        {
            //Swap
            Chromosome* tmp=_population[i];
            _population[i]=_population[j];
            _population[j]=tmp;
            ++j;
        }
    }
    Chromosome* tmp=_population[j];
    _population[j]=_population[_high-1];
    _population[_high-1]=tmp;
    return j;
}
