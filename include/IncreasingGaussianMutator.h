/*
 * 
 * (c) Fratoria B.V.
 * 
 * Rivium 2e straat 22-24
 * 2909LG Capelle aan den IJssel
 * The Netherlands
 */

/* 
 * File:   IncreasingGaussianMutator.h
 * Author: Fratoria B.V. <j.salguero@fratoria.nl>
 *
 * Created on August 9, 2018, 11:28 AM
 */

#ifndef INCREASINGGAUSSIANMUTATOR_H
#define INCREASINGGAUSSIANMUTATOR_H
#include "GaussianMutator.h"

namespace OptimES
{
    class IncreasingGaussianMutator:public GaussianMutator {
    public:
	IncreasingGaussianMutator(double _speed, uint _popSize=1);
	IncreasingGaussianMutator(const IncreasingGaussianMutator& orig);
	virtual ~IncreasingGaussianMutator();
	virtual void mutate(Chromosome& _c, double _sigma, double _mutationProb) override;
    void setLimitsFunction(void (*_limiter)(Chromosome&));

    private:
	double speed;
	double diff;
	uint counter;
	uint populationSize;
    void (*applyLimits)(Chromosome&);
    };
}

#endif /* INCREASINGGAUSSIANMUTATOR_H */

