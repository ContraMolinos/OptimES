/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ElitistEvolution.h
 * Author: F.J Salguero <j.salguero@fratoria.com>
 *
 * Created on 15 de mayo de 2018, 11:45
 */

#ifndef ELITISTRECOMBINATION_H
#define ELITISTRECOMBINATION_H

#include <random>
#include <ctime>
#include "OptimAuxFunctions.h"
#include "Chromosome.h"

namespace OptimES
{
    template<typename MutationEngine>
    class ElitistRecombination {
    public:
	ElitistRecombination(float _fractionElite, float _mutationProb, float _mutationSize, MutationEngine& _mutEng):
		survivingFraction(_fractionElite), 
		mutationProbability(_mutationProb),
		mutationSigma(_mutationSize),
		mutator(_mutEng)
	{
	    if(survivingFraction>1||survivingFraction<0||mutationProbability<0||mutationProbability>1||mutationSigma<0)
		throw std::invalid_argument("Invalid argument for elitist evolution.");
	    rEngine.seed(std::clock());
	}
		
	ElitistRecombination(const ElitistRecombination& orig):
		survivingFraction(orig.survivingFraction),
		mutationProbability(orig.mutationProbability),
		mutationSigma(orig.mutationSigma), 
		rEngine(orig.rEngine),
		mutator(orig.mutator)
	{}

	virtual ~ElitistRecombination()
	{}

	virtual uint evolve(vector<Chromosome> &_population)
	{
        size_t popSize=_population.size();
	    //Number of individuals that survive.
	    uint survivalPop=std::round(survivingFraction*popSize);
	    if(survivalPop<1)
            survivalPop=1;
	    quickSort(_population, 0, popSize);
        double normalization=0;
        //Probability of one of the parents to be chosen will be given by:
        //P=(1+Fm-Fi)/sum_i(1+Fm-Fi)
        //Where Fm is the fitting of the best non surviving individual and Fi the
        //fitting of each individual. Adding 1 will ensure that there is no
        //chance of dividing by 0.
        double Fm=_population[survivalPop].getFitness();
        std::vector<double> probability;
        probability.reserve(survivalPop);
        static unsigned long counter=0;
        double mean=0;
        for(size_t i=0;i<survivalPop;++i)
        {
            probability.push_back(1+Fm-_population[i].getFitness());
            normalization+=probability.back();
        }
        for(const Chromosome& c:_population)
            mean+=c.getFitness();
        normalization=1.0/normalization;
        std::cout<<counter++<<" "<<_population[0].getFitness()<<" "<<mean<<std::endl;
        
        std::uniform_int_distribution<> chooseMate(0,survivalPop-1);
        size_t childIdx=survivalPop;
        for(size_t i=0;i<survivalPop;++i)
        {
            size_t nChildren=std::max(1.0,std::round((popSize-survivalPop)*probability[i]*normalization));
            for(size_t j=0;j<nChildren;++j)
            {
                if(childIdx>=popSize)   //Rounding errors may result in an extra child.
                    break;
                size_t mate=chooseMate(rEngine);
                _population[childIdx]=recombine(_population[i],_population[mate]);
                _population[childIdx].setFitness(std::numeric_limits<double>::infinity());
                mutator.mutate(_population[childIdx++],mutationSigma,mutationProbability);
            }
        }
	    return popSize;
	}
	
    private:
	Chromosome recombine(const Chromosome& _p1, const Chromosome& _p2)
	{
	    size_t nGenes=_p1.getSize();
	    //Generator of random 0's and 1's.
	    std::uniform_int_distribution<> chooseParent(0,1);
        Chromosome child(nGenes);
	    double genes[nGenes];

	    for(size_t i=0;i<nGenes;++i)
            genes[i]=chooseParent(rEngine)?_p1.getGenes()[i]:_p2.getGenes()[i];

	    child.setGene(genes);
	    return child;
	}

	MutationEngine mutator;
	float survivingFraction;
	float mutationProbability;
	float mutationSigma;
	std::default_random_engine rEngine;
    };
}
#endif /* ELITISTEVOLUTION_H */

