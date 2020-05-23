/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   deltaStop.cpp
 * Author: F.J Salguero <j.salguero@fratoria.com>
 * 
 * Created on 16 de abril de 2018, 20:05
 */

#include "DeltaStop.h"

namespace OptimES
{
    DeltaStop::DeltaStop(double _delta):delta(_delta), notCalledYet(true), nWithoutImprovement(0)
    {
        if(delta<=0)
            throw std::invalid_argument("Non-positive delta in stopping condition.");
    }

    DeltaStop::DeltaStop(const DeltaStop& orig):delta(orig.delta), lastVal(orig.lastVal), 
    notCalledYet(orig.notCalledYet), nWithoutImprovement(orig.nWithoutImprovement)
    {
    }

    DeltaStop::~DeltaStop()
    {
    }

    bool DeltaStop::stopCondition(const std::vector<Chromosome> &_population)
    {
        if(_population.size()==0)
            throw std::invalid_argument("Can't evaluate a population of zero size.");
        double cost=evaluateFitness(_population);
        double d=lastVal-cost;
        lastVal=cost;
        if(d<0 || d>delta)
        {
            //return false;
            nWithoutImprovement=0;
        }else
        {
            ++nWithoutImprovement;
        }
        if(nWithoutImprovement>stoppingLimit)
            return true;
        else
            return false;

    }

    double DeltaStop::evaluateFitness(const std::vector<Chromosome> &_population) const
    {
        double minFit=_population[0].getFitness();
        double fit;
        for(Chromosome c:_population)
        {
            fit=c.getFitness();
            if(fit<minFit)
                minFit=fit;
        }
        return minFit;            
    }
}