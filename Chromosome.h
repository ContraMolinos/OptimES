/*
 * 
 * (c) Fratoria B.V.
 * 
 * Rivium 2e straat 22-24
 * 2909LG Capelle aan den IJssel
 * The Netherlands
 */

#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include<stddef.h>

/*! \brief Class to be used as container of the collection of parameters to be optimized in evolutionary algorithms.
 * 
 * This class is meant to be used as the set of parameter (genes) that are to be optimized. The size is fixed at construction and the only operations performed are setting and getting values.
 */
class Chromosome {
public:
    /*! \brief Constructor.
     * \param _size Number of genes (parameters) that contains the object.
     */
    Chromosome(size_t _size);
    /*! \brief Copy constructor.
     */
    Chromosome(const Chromosome& orig);
    virtual ~Chromosome();

    /*! \brief Less than comparison between chromosomes. The order is set by the fitness of each object.
     */
    bool operator<(const Chromosome& _other);
    bool operator>(const Chromosome& _other);

    size_t getSize() const;
    /*! \brief Set the fitness of this object.
     */
    void setFitness(double _fitness);
    double getFitness() const;
    
    /*! \brief Replaces the current set of genes.
     * 
     * \brief _gene Pointer to the array of parameters to be used as new set of genes. If it points to the same address of the genes already in the chromosome or it is null, no action is taken. If it overlaps the existing genes, the behavior is undefined.
     */
    void setGene(double* _gene);
    const double* getGenes() const;
    /*! \brief Returns a reference to the ith parameter. 
     * 
     * Throws out_of_range exception if the index is larger than the number of genes.
     */
    double& operator[](const unsigned int i) const;
private:
    size_t nGenes;
    double* geneSet;
    double fitness;
};

#endif /* CHROMOSOME_H */

