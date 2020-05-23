/*
 * 
 * (c) Fratoria B.V.
 * 
 * Rivium 2e straat 22-24
 * 2909LG Capelle aan den IJssel
 * The Netherlands
 */


#include "Chromosome.h"
#include <iostream>

namespace OptimES
{
    Chromosome::Chromosome(size_t _size):nGenes(_size)
    {
        //geneSet=new double[_size];
        geneSet.resize(_size);
    }

    Chromosome::Chromosome(double* _val, size_t _size):nGenes(_size)
    {
        //geneSet=new double[nGenes];
        geneSet.resize(nGenes);
        setGene(_val);
    }


    Chromosome::Chromosome(const Chromosome& orig):nGenes(orig.nGenes), fitness(orig.fitness)
    {
        geneSet=orig.geneSet;
        //std::memcpy(geneSet,orig.geneSet,nGenes*sizeof(double));
    }

    Chromosome::~Chromosome()
    {}

    size_t Chromosome::getSize() const
    {
        return nGenes;
    }

    void Chromosome::setFitness(double _fitness)
    {
        fitness = _fitness;
    }

    double Chromosome::getFitness() const
    {
        return fitness;
    }

    void Chromosome::setGene(double* _gene)
    {
        //if(_gene!=nullptr && _gene!=geneSet)
        //    std::memcpy(geneSet,_gene,nGenes*sizeof(double));
        if(_gene)
            std::memcpy(geneSet.data(),_gene,nGenes*sizeof(double));
        else
            throw std::invalid_argument("Null gene pointer.");
    }

    /*!\todo This has to change to either a vector or a smart pointer.*/
    vector<double> Chromosome::getGenes() const
    {
        return geneSet;
    }

    bool Chromosome::operator<(const Chromosome& _other)
    {
        return fitness<_other.fitness;
    }

    bool Chromosome::operator>(const Chromosome& _other)
    {
        return fitness>_other.fitness;
    }


    double& Chromosome::operator[](const size_t i)
    {
        return geneSet.at(i);
    }

}