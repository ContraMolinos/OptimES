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
#include "Chromosome.h"
#include "testProblem.h"

/*! \brief Template class for optimization.
 */
template<typename ProblemType, typename EvolutionPolicy, typename StoppingPolicy>
class EvolutionaryAlg {
public:
    EvolutionaryAlg(ProblemType& _problem, EvolutionPolicy& _evoType, StoppingPolicy& _stoppingCriteria): costFunc(_problem), evolution(_evoType), stopCriteria(_stoppingCriteria), popSize(0), population(nullptr)
    {};
    
    void setCostFunction(ProblemType* _func)
    {
        costFunc=_func;
    }
    
    void setPopulation(Chromosome** _c, uint _popSize)
    {
        for(int i=0;i<popSize;++i)
            delete population[i];
        delete population;
        popSize=_popSize;
        population=new Chromosome*[popSize];
	std::memcpy(population,_c,popSize*sizeof(Chromosome*));
    }
    
    void run()
    {
        while(!stopCriteria.stopCondition(population, popSize))
        {
            popSize=evolution.evolve(population, popSize);
            for(uint i=0;i<popSize;++i)
            costFunc.evaluate(*(population[i]));
        }
    }
    
    virtual ~EvolutionaryAlg()
    {   
        for(int i=0;i<popSize;++i)
            delete population[i];
        delete population;
    };
    
private:
    ProblemType costFunc;
    EvolutionPolicy evolution;
    Chromosome** population;
    StoppingPolicy stopCriteria;
    uint popSize;
    
};

#endif /* EVOLUTIONARYALG_H */

