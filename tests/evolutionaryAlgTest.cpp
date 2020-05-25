/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <boost/test/unit_test.hpp>
#include <turtle/mock.hpp>

#include "EvolutionaryAlg.h"
#include "Chromosome.h"

MOCK_CLASS(mockCost)
{
    MOCK_METHOD(evaluate,1,double(OptimES::Chromosome&))
};

MOCK_CLASS(mockEvo)
{
    MOCK_METHOD(evolve,1,uint(std::vector<OptimES::Chromosome>&))
};

MOCK_CLASS(mockStop)
{
    MOCK_METHOD(stopCondition,1,bool(const std::vector<OptimES::Chromosome>&))
};

struct initEvolutionaryAlg
{
    initEvolutionaryAlg():runner(cost, evo, stop), popSize(3)
    {
        population=new OptimES::Chromosome*[popSize];
        for(size_t i=0;i<popSize;++i)
        {
            population[i]=new OptimES::Chromosome(4);
            population[i]->setFitness(i);
        }
    }
    
    ~initEvolutionaryAlg()
    {
        for(size_t i=0;i<popSize;++i)
            delete population[i];
        delete[] population;
    }
    
    mockCost cost;
    mockEvo evo;
    mockStop stop;
    OptimES::EvolutionaryAlg<mockCost, mockEvo, mockStop> runner;
    size_t popSize;
    OptimES::Chromosome** population;
};

BOOST_FIXTURE_TEST_SUITE(EvolutionaryAlgorithmTests, initEvolutionaryAlg)
        
BOOST_AUTO_TEST_CASE(getSolutionThrow)
{
    BOOST_CHECK_THROW(runner.getSolution(), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(getSolutionTest)
{
    runner.setPopulation(population,popSize);
    OptimES::Chromosome solution=runner.getSolution();
    BOOST_CHECK_EQUAL(solution.getFitness(),0);
}

BOOST_AUTO_TEST_CASE(runTest)
{
    const size_t nLoops=10;
    const double dummyVal=0.4;
    runner.setPopulation(population,popSize);
    mock::sequence seq;
    MOCK_EXPECT(stop.stopCondition).exactly(nLoops).in(seq).returns(false);
    MOCK_EXPECT(stop.stopCondition).exactly(1).in(seq).returns(true);
    MOCK_EXPECT(evo.evolve).exactly(nLoops).returns(popSize);
    MOCK_EXPECT(cost.evaluate).exactly(nLoops*popSize).returns(dummyVal);
    
    runner.run();
}
        
BOOST_AUTO_TEST_SUITE_END();