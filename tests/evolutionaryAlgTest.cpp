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

//\TODO:
//run calls evolve and evaluate
//getPopulation
//