/*
 * 
 * (c) Fratoria B.V.
 * 
 * Rivium 2e straat 22-24
 * 2909LG Capelle aan den IJssel
 * The Netherlands
 */

#ifndef EVOLUTIONARYALG_H
#define EVOLUTIONARYALG_H
#include <stdexcept>
#include <cstring>
#include <limits>
#include <vector>
#include "Chromosome.h"
#include "testProblem.h"

#include <iostream>

namespace OptimES
{
    using std::vector;
    /*! \brief Template class for optimization.
     * \param ProblemType Class modeling the cost function to minimize. It is required that it has a public method named evaluate that takes a pointer to a Chromosome object. It can have any return type.
     * \param EvolutionPolicy Class type that models the way the population of chromosomes is modified in each iteration. It must contain a public method named evolve that takes as parameters a pointer to a pointer to Chromosome (population) and an unsigned int (size of the population). It must return the new population size.
     * \param StoppingPolicy Class type that evaluates a population of Chromosomes and determines whether the criteria to finish the optimization are met. It must contain a method named stopCondition that takes a pointer to pointer to Chromosomes (population) and an unsigned int (population size). Return type must be a bool or a type convertible to bool.
     */
    template<typename ProblemType, typename EvolutionPolicy, typename StoppingPolicy>
    class EvolutionaryAlg {
    public:
	EvolutionaryAlg(ProblemType& _problem, EvolutionPolicy& _evoType, StoppingPolicy& _stoppingCriteria): mCostFunc(_problem), mEvolutionAlgo(_evoType), mStoppingCriteria(_stoppingCriteria), mPopSize(0)
	{};

	void setCostFunction(ProblemType _func)
	{
	    mCostFunc=_func;
	}

	void setPopulation(Chromosome** _c, uint _popSize)
	{
	    mPopulation.clear();
	    mPopSize=_popSize;
        mPopulation.reserve(mPopSize);
        for(size_t i=0;i<_popSize;++i)
            mPopulation.push_back(*_c[i]);
	}

	void run()
	{
	    while(!mStoppingCriteria.stopCondition(mPopulation))
	    {
            mPopSize=mEvolutionAlgo.evolve(mPopulation);
            for(uint i=0;i<mPopSize;++i)
                mCostFunc.evaluate(mPopulation[i]);
	    }
	}

	virtual ~EvolutionaryAlg()
	{};

	vector<Chromosome> getPopulation()
	{
	    return mPopulation;
	}

	Chromosome getSolution()
	{
        if(mPopSize==0)
            throw std::runtime_error("No population available.");
	    double score=std::numeric_limits<double>::max();
	    double fitness;
	    uint solIdx=mPopSize-1;
	    for(uint i=0;i<mPopSize;++i)
	    {
            fitness=mPopulation[i].getFitness();
            if(fitness<score)
            {
                score=fitness;
                solIdx=i;
            }
	    }

	    return mPopulation[solIdx];
	}

    private:
	ProblemType mCostFunc;
	EvolutionPolicy mEvolutionAlgo;
	vector<Chromosome> mPopulation;
	StoppingPolicy mStoppingCriteria;
	uint mPopSize;

    };
}

#endif /* EVOLUTIONARYALG_H */

