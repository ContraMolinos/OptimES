/*
 * 
 * (c) Fratoria B.V.
 * 
 * Rivium 2e straat 22-24
 * 2909LG Capelle aan den IJssel
 * The Netherlands
 */

#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include "DeltaStop.h"
#include "Chromosome.h"

using OptimES::Chromosome;
using OptimES::DeltaStop;

struct chromosomePop2
{
    chromosomePop2():popSize(5), chromosomeSize(10), templateChromosome(chromosomeSize)
    {
        for(int i=0;i<chromosomeSize;++i)
        {
            templateChromosome[i]=i*2.3;
        }
        templateChromosome.setFitness(0);
        population.resize(popSize,templateChromosome);
        for(int i=0;i<popSize;++i)
        {
            population[i].setFitness(10*i);
        }
    }
    ~chromosomePop2()
    {}
    
    size_t chromosomeSize;
    size_t popSize;
    std::vector<Chromosome> population;
    Chromosome templateChromosome;
};

BOOST_FIXTURE_TEST_SUITE(deltaStopSuite1, chromosomePop2)
BOOST_AUTO_TEST_CASE(normalStoppingConditionTest)
{
    DeltaStop ds(0.01);
    BOOST_CHECK_EQUAL(ds.stopCondition(population),false);
    population[0].setFitness(12); //Worse result.
    BOOST_CHECK_EQUAL(ds.stopCondition(population),false);
    population[0].setFitness(3); //Better result, large improvement.
    BOOST_CHECK_EQUAL(ds.stopCondition(population),false);
    population[0].setFitness(2.9999); //Better result, small improvement.
    for(uint i=0;i<100;++i) //100 is a hardcoded value in deltaStopTest.
        BOOST_CHECK_EQUAL(ds.stopCondition(population),false);
    BOOST_CHECK_EQUAL(ds.stopCondition(population),true);
    
}

BOOST_AUTO_TEST_CASE(exceptionTest)
{
    BOOST_CHECK_THROW(DeltaStop ds(-0.3),std::invalid_argument);
    BOOST_CHECK_THROW(DeltaStop ds2(0.0),std::invalid_argument);
}
        
BOOST_AUTO_TEST_SUITE_END();