/*
 * 
 * (c) Fratoria B.V.
 * 
 * Rivium 2e straat 22-24
 * 2909LG Capelle aan den IJssel
 * The Netherlands
 */

/* 
 * File:   GaussianMutator.h
 * Author: Fratoria B.V. <j.salguero@fratoria.nl>
 *
 * Created on August 9, 2018, 9:48 AM
 */

#ifndef GAUSSIANMUTATOR_H
#define GAUSSIANMUTATOR_H

#include "Chromosome.h"
#include <random>
#include <ctime>

namespace OptimES
{
    /*! \brief Class to mutate a Chromosome object.
     * 
     * Each gene of the Chromosome object will be mutated with a given probability.
     * The mutation consists in multiplying its value by a random number drawn from
     * a Gaussian distribution with 0 mean and given sigma.
     */
    class GaussianMutator {
    public:
	GaussianMutator();
	GaussianMutator(const GaussianMutator& orig);
	virtual ~GaussianMutator();
	
	virtual void mutate(Chromosome& _c, double _sigma, double _mutationProb);

    private:
	
	std::default_random_engine rEngine;
    };
}
#endif /* GAUSSIANMUTATOR_H */

