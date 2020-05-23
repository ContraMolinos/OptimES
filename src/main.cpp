/*
 * 
 * (c) Fratoria B.V.
 * 
 * Rivium 2e straat 22-24
 * 2909LG Capelle aan den IJssel
 * The Netherlands
 */

#include <iostream>
#include <chrono>
#include "Chromosome.h"
#include "DeltaStop.h"
#include "EvolutionaryAlg.h"
#include "testProblem.h"
#include "MutateFractionGauss.h"
#include "NIterStop.h"
#include "ElitistRecombination.h"
#include "GaussianMutator.h"

using namespace std;
using namespace OptimES;
/*
 * 
 */
int main(int argc, char** argv)
{
    const uint chrSize=5;
    const uint popSize=150;
    
    testProblem problem(chrSize);
    //Chromosome chr(chrSize);
    Chromosome* pop[popSize];
    //double gene[chrSize]={-4.3,2.5};//,-0.2,64.02, 4.0};
    //chr.setGene(gene);
    //problem.evaluate(chr);
    std::default_random_engine rEngine;
    std::uniform_real_distribution<double> geneVal(-200,200);
    for(uint i=0;i<popSize;++i)
    {
        double gene[chrSize];
        for(size_t j=0;j<chrSize;++j)
            gene[j]=geneVal(rEngine);
        pop[i]=new Chromosome(gene,chrSize);
        problem.evaluate(*pop[i]);
    }
    MutateFractionGauss mfg(6.0/7.0,1,2);
    GaussianMutator mut;
    ElitistRecombination<GaussianMutator> elEvo(0.2,0.3,0.5,mut);
    DeltaStop ds(1e-25);
    NIterStop is(5e6);
    
    EvolutionaryAlg<testProblem,ElitistRecombination<GaussianMutator>,NIterStop> eAlg(problem, elEvo, is);
    eAlg.setPopulation(pop, popSize);
    std::chrono::high_resolution_clock::time_point before=std::chrono::high_resolution_clock::now();
    eAlg.run();
    std::chrono::high_resolution_clock::time_point after=std::chrono::high_resolution_clock::now();
    std::cout<<"Calculation time="<<std::chrono::duration_cast<std::chrono::microseconds>(after-before).count()<<" us"<<std::endl;

    
    vector<Chromosome> endPop=eAlg.getPopulation();
    Chromosome solution=eAlg.getSolution();
        
    cout<<"Solution:"<<endl;
    for(uint i=0;i<solution.getSize();++i)
        cout<<solution[i]<<" ";
    cout<<"->"<<solution.getFitness()<<endl;
    
    cout<<"============"<<endl;
    for(uint i=0;i<popSize;++i)
    {
        for(uint j=0;j<chrSize;++j)
        {
            cout<<endPop[i].getGenes()[j]<<" ";
        }
        cout<<"->"<<endPop[i].getFitness()<<endl;
    }
    
    /*
    */
    return 0;
}

