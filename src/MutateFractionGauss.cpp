/*
 * 
 * (c) Fratoria B.V.
 * 
 * Rivium 2e straat 22-24
 * 2909LG Capelle aan den IJssel
 * The Netherlands
 */

#include <stdexcept>
#include <random>
#include <cstring>
#include <vector>

#include "MutateFractionGauss.h"

namespace OptimES
{
    using std::vector;

    MutateFractionGauss::MutateFractionGauss(double _fraction, double _sigma, uint _nMutations):fraction(_fraction), sigma(_sigma), nMutations(_nMutations)
    {
        if(fraction>1.0 || fraction <0.0)
            throw std::invalid_argument("Fraction out of bounds.");
        if(sigma<0)
            throw std::invalid_argument("Negative sigma not possible.");
        rEngine.seed(std::clock());
    }

    MutateFractionGauss::MutateFractionGauss(const MutateFractionGauss& orig):fraction(orig.fraction), sigma(orig.sigma), nMutations(orig.nMutations), rEngine(orig.rEngine)
    {}

    MutateFractionGauss::~MutateFractionGauss()
    {}

    uint MutateFractionGauss::evolve(vector<Chromosome> &_population)
    {
        size_t popSize=_population.size();
        quickSort(_population, 0, popSize);
        uint nMutating=std::round(fraction*popSize);
        uint notMutating=popSize-nMutating;

        for(uint i=notMutating;i<popSize;++i)
        {
            mutateChromosome(_population[i]);
        }
        return popSize;
    }

    void MutateFractionGauss::mutateChromosome(Chromosome &_chr)
    {
        std::uniform_int_distribution<> geneMutate(0,_chr.getSize()-1);
        std::normal_distribution<double> mutationSize(0.0, sigma);
        double* geneSet=new double[_chr.getSize()];
        std::memcpy(geneSet,_chr.getGenes().data(),_chr.getSize()*sizeof(double));

        for(uint i=0;i<nMutations;++i)
        {
            int geneId=geneMutate(rEngine);
            double amount=mutationSize(rEngine);
            geneSet[geneId]+=amount;
        }
        _chr.setGene(geneSet);
        delete[] geneSet;
    }
}