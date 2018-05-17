/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ElitistEvolution.cpp
 * Author: F.J Salguero <contramolinosdeviento@gmail.com>
 * 
 * Created on 15 de mayo de 2018, 11:45
 */

#include "ElitistEvolution.h"
#include <iostream>

ElitistEvolution::ElitistEvolution(float _fractionElite, float _mutationProb, float _mutationSize):survivingFraction(_fractionElite), mutationProbability(_mutationProb),mutationSigma(_mutationSize)
{
    if(survivingFraction>1||survivingFraction<0||mutationProbability<0||mutationProbability>1||mutationSigma<0)
        throw std::invalid_argument("Invalid argument for elitist evolution.");
    rEngine.seed(std::clock());
}

ElitistEvolution::ElitistEvolution(const ElitistEvolution& orig):survivingFraction(orig.survivingFraction),mutationProbability(orig.mutationProbability),mutationSigma(orig.mutationSigma), rEngine(orig.rEngine)
{
}

ElitistEvolution::~ElitistEvolution()
{
}

uint ElitistEvolution::evolve(Chromosome** _population, uint _popSize)
{
    uint survivalPop=std::ceil(survivingFraction*_popSize);
    quickSort(_population, 0, _popSize);
    for(uint i=0;i<_popSize-survivalPop;++i)
    {
        uint parent1=i%survivalPop;
        uint parent2=(i+1)%survivalPop;
        uint child=survivalPop+i;
        if(child>=_popSize)   //To avoid buffer overflow.
            break;
        delete _population[child];
        _population[child]=recombine(_population[parent1],_population[parent2]);
        mutateChromosome(_population[child]);
    }
    return _popSize;
}

Chromosome* ElitistEvolution::recombine(Chromosome* _p1, Chromosome* _p2)
{
    size_t nGenes=_p1->getSize();
    //std::cout<<nGenes<<std::endl;
    std::uniform_int_distribution<> chooseParent(0,1);
    Chromosome* child=new Chromosome(nGenes);
    double genes[nGenes];
    for(size_t i=0;i<nGenes;++i)
    {
        //std::cout<<"before="<<genes[i]<<std::endl;
        //std::cout<<_p1->getGenes()[i]<<" "<<_p2->getGenes()[i]<<std::endl;
        genes[i]=chooseParent(rEngine)?_p1->getGenes()[i]:_p2->getGenes()[i];
        //std::cout<<"after="<<genes[i]<<std::endl;
    }
    child->setGene(genes);
    return child;
}

void ElitistEvolution::mutateChromosome(Chromosome* _c)
{
    std::uniform_real_distribution<> trigger(0,1);
    std::normal_distribution<> mutSize(0.0, mutationSigma);
    size_t nGenes=_c->getSize();
    for(size_t i=0;i<nGenes;++i)
    {
        //std::cout<<i<<std::endl;
        double n=trigger(rEngine);
        //std::cout<<"  "<<n<<std::endl;
        if(n>mutationProbability)
            continue;
        //std::cout<<"before="<<(*_c)[i]<<std::endl;
        (*_c)[i]*=(1+mutSize(rEngine));
        //std::cout<<"after="<<(*_c)[i]<<std::endl;
    }
}
