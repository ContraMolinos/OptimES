/*
 * 
 * (c) Fratoria B.V.
 * 
 * Rivium 2e straat 22-24
 * 2909LG Capelle aan den IJssel
 * The Netherlands
 */

#ifndef MUTATEFRACTIONGAUSS_H
#define MUTATEFRACTIONGAUSS_H
#include <cmath>
#include <random>
#include <iostream>
#include <ctime>
#include "auxFunctions.h"
#include "Chromosome.h"

/*! \brief Class that will take a set of Chromosome objects and mutate a fraction of the less fitted ones.
 * 
 * This class will take a set of Chromosome objects, select the less fitted ones and apply a number of mutations to randomly chosen genes. The amount of mutation is given by a zero-centered Gaussian distribution.
 */
class MutateFractionGauss {
public:
    /*! \brief Constructor.
     * \param _fraction	Fraction of the chromosomes to be mutated.
     * \param _sigma	Standard deviation of the Gaussian distribution that will determine the magnitude of the mutation.
     * \param _nMutations   Number of mutations that are to be applied to each chromosome. Two or more mutations can be applied to the same gene, so the actual number of mutations is any number between 1 and _nMutations.
     */
    MutateFractionGauss(double _fraction=0.5, double _sigma=1.0, uint _nMutations=1);
    MutateFractionGauss(const MutateFractionGauss& orig);
    virtual ~MutateFractionGauss();
    /*! \brief Method to modify (evolve) a population of chromosomes.
     * \param _population   Pointer to array of chromosomes.
     * \param _popSize	    Total number of chromosomes.
     * 
     * This method leaves untouched the chromosomes with the lowest fitness values and mutates the rest.
     */
    uint evolve(Chromosome** _population, uint _popSize);
private:
    double fraction;
    double sigma;
    uint nMutations;
    std::default_random_engine rEngine;
    
    void mutateChromosome(Chromosome* _chr);
};

#endif /* MUTATEFRACTIONGAUSS_H */

