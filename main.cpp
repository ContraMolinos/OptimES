/*
 * 
 * (c) Fratoria B.V.
 * 
 * Rivium 2e straat 22-24
 * 2909LG Capelle aan den IJssel
 * The Netherlands
 */

#include <iostream>
#include "Chromosome.h"
#include "DeltaStop.h"
#include "EvolutionaryAlg.h"
#include "testProblem.h"
#include "MutateFractionGauss.h"
#include "NIterStop.h"
#include "ElitistEvolution.h"

using namespace std;
/*
 * 
 */
int main(int argc, char** argv)
{
    const uint chrSize=5;
    const uint popSize=7;
    
    testProblem problem;
    Chromosome chr(chrSize);
    Chromosome* pop[popSize];
    double gene[chrSize]={-4.3,2.5,-0.2,64.02, 4.0};
    chr.setGene(gene);
    problem.evaluate(chr);
    for(uint i=0;i<popSize;++i)
        pop[i]=new Chromosome(chr);
    MutateFractionGauss mfg(6.0/7.0,1,2);
    ElitistEvolution elEvo(0.2,0.5,2);
    DeltaStop ds(1e-25);
    NIterStop is(1e6);
    
    EvolutionaryAlg<testProblem,ElitistEvolution,NIterStop> eAlg(problem, elEvo, is);
    eAlg.setPopulation(pop, popSize);
    eAlg.run();
    
    for(uint i=0;i<chrSize;++i)
        cout<<chr[i]<<" ";
    cout<<"->"<<chr.getFitness()<<endl;
    
    for(uint i=0;i<popSize;++i)
    {
        for(uint j=0;j<chrSize;++j)
        {
            cout<<pop[i]->getGenes()[j]<<" ";
        }
        cout<<"->"<<pop[i]->getFitness()<<endl;
    }
    
    /*
    for(uint i=0;i<popSize;++i)
        delete pop[i];
    */
    return 0;
}

