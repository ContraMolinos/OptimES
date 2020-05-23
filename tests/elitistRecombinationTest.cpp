/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include<vector>
#include "Chromosome.h"
#include "ElitistRecombination.h"

using OptimES::Chromosome;
using OptimES::ElitistRecombination;
namespace bdata = boost::unit_test::data;

//No mutation.
class dummyMutator
{
public:
    virtual void mutate(Chromosome& _c, double _sigma, double _mutationProb){};
};

struct elitistFixt
{
    elitistFixt()
    {
        for(size_t i=0;i<10;++i)
        {
            double val[10]={i,i,i,i,i,i,i,i,i,i};
            Chromosome cr(val,10);
            cr.setFitness(20.394-i);
            population.push_back(cr);
        }
    }
    dummyMutator mutator;
    size_t chromosomeSize=5;
    std::vector<Chromosome> population;
};

BOOST_FIXTURE_TEST_SUITE(ElitistRecombinationTest, elitistFixt)
BOOST_AUTO_TEST_CASE(ConstructorExceptions)
{
    BOOST_CHECK_THROW(ElitistRecombination<dummyMutator>(1.2,0.3,3.2,mutator),std::invalid_argument);
    BOOST_CHECK_THROW(ElitistRecombination<dummyMutator>(-0.2,0.3,3.2,mutator),std::invalid_argument);
    BOOST_CHECK_THROW(ElitistRecombination<dummyMutator>(0.3,2.1,3.2,mutator),std::invalid_argument);
    BOOST_CHECK_THROW(ElitistRecombination<dummyMutator>(0.3,-0.3,3.2,mutator),std::invalid_argument);
    BOOST_CHECK_THROW(ElitistRecombination<dummyMutator>(0.3,0.3,-3.2,mutator),std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(NoSurvivorTest)
{
    ElitistRecombination<dummyMutator> evolver(0.0,0.1,3.2,mutator);
    //The last Chromosome of the vector is the one with the lowest fitting, so 
    //it should survive.
    double expectedSurvivorFitness=population.back().getFitness();
    evolver.evolve(population);
    BOOST_CHECK_EQUAL(population[0].getFitness(), expectedSurvivorFitness);
}

BOOST_AUTO_TEST_CASE(AllSurvivorTest)
{
    ElitistRecombination<dummyMutator> evolver(1.0,0.1,3.2,mutator);
    //The last Chromosome of the vector is the one with the lowest fitting, so 
    //it should survive.
    double expectedSurvivorFitness[population.size()];
    for(size_t i=0;i<population.size();++i)
        expectedSurvivorFitness[i]=population[population.size()-1-i].getFitness();
    evolver.evolve(population);
    unsigned int matches=0;
    for(size_t i=0;i<population.size();++i)
        matches+=int(expectedSurvivorFitness[i]==population[i].getFitness());
    BOOST_CHECK_EQUAL(matches, population.size());
}

//Test that the number of survivors is as expected for a range of survival probabilities.
//The previous two test could be included here but, since they are extreme cases,
//I better put them in a separate test.
BOOST_DATA_TEST_CASE(survivorTest, bdata::xrange<float>(0.0,1.0,0.05f))
{
    ElitistRecombination<dummyMutator> evolver(sample,0.1,3.2,mutator);
    uint expectedSurvivors=std::max(std::round(sample*population.size()),1.0f);
    double initialFitness[population.size()];
    for(size_t i=0;i<population.size();++i)
        initialFitness[i]=population[population.size()-1-i].getFitness();
    evolver.evolve(population);
    unsigned int matches=0;
    for(size_t i=0;i<population.size();++i)
    {
        matches+=int(initialFitness[i]==population[i].getFitness());
    }
    BOOST_TEST(expectedSurvivors==matches);
}

BOOST_AUTO_TEST_SUITE_END();