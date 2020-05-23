/*
 * 
 * (c) Fratoria B.V.
 * 
 * Rivium 2e straat 22-24
 * 2909LG Capelle aan den IJssel
 * The Netherlands
 */

#include <boost/test/unit_test.hpp>
#include "MutateFractionGauss.h"
#include "Chromosome.h"

using OptimES::Chromosome;
using OptimES::MutateFractionGauss;

struct chromosomePop
{
    chromosomePop():popSize(5), chromosomeSize(10), templateChromosome(chromosomeSize)
    {
        for(int i=0;i<chromosomeSize;++i)
        {
            templateChromosome[i]=i*2.3;
        }
        templateChromosome.setFitness(0);
        population.resize(popSize,templateChromosome);
        for(int i=0;i<popSize;++i)
        {
            population[i].setFitness(i);
        }
    }
    ~chromosomePop()
    {}
    
    size_t chromosomeSize;
    size_t popSize;
    std::vector<Chromosome> population;
    Chromosome templateChromosome;
};

BOOST_FIXTURE_TEST_SUITE(mutateFractionGaussSuite,chromosomePop)
BOOST_AUTO_TEST_CASE(nMutations)
{
    MutateFractionGauss mfg;
    mfg.evolve(population);
    //Check how many genes have been mutated;
    for(int i=0;i<popSize;++i)
    {
        int nDiff=0;
        for(int j=0;j<chromosomeSize;++j)
        {
            if(templateChromosome[j]!=population[i].getGenes()[j])
                ++nDiff;
        }
        if(population[i].getFitness()<2)
            BOOST_CHECK_EQUAL(nDiff,0);
        else
            BOOST_CHECK_EQUAL(nDiff,1);
    }
}

/*BOOST_AUTO_TEST_CASE(zeroSize)
{
    MutateFractionGauss mfg;
    BOOST_CHECK_NO_THROW(mfg.evolve(nullptr,0));
}*/

BOOST_AUTO_TEST_CASE(noMutations)
{
    MutateFractionGauss mfg(0,1,1);
    mfg.evolve(population);
    for(int i=0;i<popSize;++i)
    {
        int nDiff=0;
        for(int j=0;j<chromosomeSize;++j)
        {
            if(templateChromosome[j]!=population[i].getGenes()[j])
                ++nDiff;
        }
        BOOST_CHECK_EQUAL(nDiff,0);
    }
    
    MutateFractionGauss mfg2(1,1,0);
    mfg2.evolve(population);
    for(int i=0;i<popSize;++i)
    {
        int nDiff=0;
        for(int j=0;j<chromosomeSize;++j)
        {
            if(templateChromosome[j]!=population[i].getGenes()[j])
                ++nDiff;
        }
        BOOST_CHECK_EQUAL(nDiff,0);
    }
    
    MutateFractionGauss mfg3(1,0,1);
    mfg3.evolve(population);
    for(int i=0;i<popSize;++i)
    {
        int nDiff=0;
        for(int j=0;j<chromosomeSize;++j)
        {
            if(templateChromosome[j]!=population[i].getGenes()[j])
                ++nDiff;
        }
        BOOST_CHECK_EQUAL(nDiff,0);
    }
}
BOOST_AUTO_TEST_SUITE_END();