/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ElitistEvolution.h
 * Author: F.J Salguero <contramolinosdeviento@gmail.com>
 *
 * Created on 15 de mayo de 2018, 11:45
 */

#ifndef ELITISTEVOLUTION_H
#define ELITISTEVOLUTION_H

#include <sys/types.h>
#include <random>
#include <stdexcept>
#include <ctime>
#include "Chromosome.h"
#include "auxFunctions.h"

class ElitistEvolution {
public:
    ElitistEvolution(float _fractionElite, float _mutationProb, float _mutationSize);
    ElitistEvolution(const ElitistEvolution& orig);
    virtual ~ElitistEvolution();
    
    uint evolve(Chromosome** _population, uint _popSize);
private:
    Chromosome* recombine(Chromosome* _p1, Chromosome* _p2);
    void mutateChromosome(Chromosome* _c);
    
    float survivingFraction;
    float mutationProbability;
    float mutationSigma;
    std::default_random_engine rEngine;
};

#endif /* ELITISTEVOLUTION_H */

