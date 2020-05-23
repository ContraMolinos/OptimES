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
	EvolutionaryAlg(ProblemType& _problem, EvolutionPolicy& _evoType, StoppingPolicy& _stoppingCriteria): costFunc(_problem), evolution(_evoType), stopCriteria(_stoppingCriteria), popSize(0)
	{};

	void setCostFunction(ProblemType _func)
	{
	    costFunc=_func;
	}

	void setPopulation(Chromosome** _c, uint _popSize)
	{
	    population.clear();
	    popSize=_popSize;
        population.reserve(popSize);
        for(size_t i=0;i<_popSize;++i)
            population.push_back(*_c[i]);
	}

	void run()
	{
	    while(!stopCriteria.stopCondition(population))
	    {
            popSize=evolution.evolve(population);
            for(uint i=0;i<popSize;++i)
                costFunc.evaluate(population[i]);
	    }
	}

	virtual ~EvolutionaryAlg()
	{};

	vector<Chromosome> getPopulation()
	{
	    return population;
	}

	Chromosome getSolution()
	{
	    double score=std::numeric_limits<double>::max();
	    double fitness;
	    uint solIdx=popSize;
	    for(uint i=0;i<popSize;++i)
	    {
            fitness=population[i].getFitness();
            if(fitness<score)
            {
                score=fitness;
                solIdx=i;
            }
	    }

	    return population[solIdx];
	}

    private:
	ProblemType costFunc;
	EvolutionPolicy evolution;
	vector<Chromosome> population;
	StoppingPolicy stopCriteria;
	uint popSize;

    };
}

#endif /* EVOLUTIONARYALG_H */

