/*
 * 
 * (c) Fratoria B.V.
 * 
 * Rivium 2e straat 22-24
 * 2909LG Capelle aan den IJssel
 * The Netherlands
 */

#include <stdexcept>
#include <cstring>

#include "Chromosome.h"

Chromosome::Chromosome(size_t _size):nGenes(_size)
{
    geneSet=new double[_size];
}

Chromosome::Chromosome(const Chromosome& orig):nGenes(orig.nGenes), fitness(orig.fitness)
{
    geneSet=new double[nGenes];
    std::memcpy(geneSet,orig.geneSet,nGenes*sizeof(double));
}

Chromosome::~Chromosome()
{
    delete[] geneSet;
}

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
    if(_gene!=nullptr && _gene!=geneSet)
        std::memcpy(geneSet,_gene,nGenes*sizeof(double));
}

const double* Chromosome::getGenes() const
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


double& Chromosome::operator[](const unsigned int i) const
{
    if(i>nGenes-1)
        throw std::out_of_range("Index out of bounds.");
    return geneSet[i];
}
