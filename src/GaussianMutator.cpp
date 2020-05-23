/*
 * 
 * (c) Fratoria B.V.
 * 
 * Rivium 2e straat 22-24
 * 2909LG Capelle aan den IJssel
 * The Netherlands
 */

/* 
 * File:   GaussianMutator.cpp
 * Author: Fratoria B.V. <j.salguero@fratoria.nl>
 * 
 * Created on August 9, 2018, 9:48 AM
 */

#include "GaussianMutator.h"

namespace OptimES
{
    GaussianMutator::GaussianMutator()
    {
        rEngine.seed(std::clock());
    }

    GaussianMutator::GaussianMutator(const GaussianMutator& orig):rEngine(orig.rEngine)
    {
    }

    GaussianMutator::~GaussianMutator()
    {
    }
    void GaussianMutator::mutate(Chromosome& _c, double _sigma, double _mutationProb)
    {
        //Uniform distribution between 0 and 1.
        std::uniform_real_distribution<> trigger(0,1);
        //Normal distribution.
        std::normal_distribution<> mutSize(0.0, std::abs(_sigma));
        size_t nGenes=_c.getSize();
        for(size_t i=0;i<nGenes;++i)
        {
            double n=trigger(rEngine);
            if(n>_mutationProb)
                continue;
            //_c[i]*=(1+mutSize(rEngine));
            _c[i]+=mutSize(rEngine);
        }
    }


}