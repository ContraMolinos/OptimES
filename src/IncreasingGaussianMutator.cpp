/*
 * 
 * (c) Fratoria B.V.
 * 
 * Rivium 2e straat 22-24
 * 2909LG Capelle aan den IJssel
 * The Netherlands
 */

/* 
 * File:   IncreasingGaussianMutator.cpp
 * Author: Fratoria B.V. <j.salguero@fratoria.nl>
 * 
 * Created on August 9, 2018, 11:28 AM
 */

#include "IncreasingGaussianMutator.h"

namespace OptimES
{
    IncreasingGaussianMutator::IncreasingGaussianMutator(double _speed, uint _popSize):speed(_speed), diff(0), counter(1),populationSize(_popSize),applyLimits(nullptr)
    {}

    IncreasingGaussianMutator::IncreasingGaussianMutator(const IncreasingGaussianMutator& orig):speed(orig.speed), diff(orig.diff),counter(orig.counter), populationSize(orig.populationSize), applyLimits(orig.applyLimits)
    {}

    IncreasingGaussianMutator::~IncreasingGaussianMutator()
    {}
    void IncreasingGaussianMutator::mutate(Chromosome& _c, double _sigma, double _mutationProb)
    {
        if(counter>populationSize)
        {
            diff+=speed;
            counter=1;
        }
        double sigma=_sigma*(1+diff);
        ++counter;
        GaussianMutator::mutate(_c,sigma,_mutationProb);
        //for(uint i=0;i<_c->getSize();++i)
        //    (*_c)[i]=std::abs((*_c)[i]);
        if(applyLimits)
            applyLimits(_c);
    }
void IncreasingGaussianMutator::setLimitsFunction(void(*_limiter)(Chromosome&))
{
    applyLimits=_limiter;
}

}