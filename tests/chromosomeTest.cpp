/*
 * 
 * (c) Fratoria B.V.
 * 
 * Rivium 2e straat 22-24
 * 2909LG Capelle aan den IJssel
 * The Netherlands
 */

#include <boost/test/unit_test.hpp>
#include "Chromosome.h"

using OptimES::Chromosome;

struct initChromosome
{
    initChromosome():size(7), chrom(size)
    {
        double gene[size];
        for(int i=0;i<size;++i)
            gene[i]=i*2.3;
        chrom.setGene(gene);
    }
    
    ~initChromosome()
    {}
    
    size_t size;
    Chromosome chrom;
};

BOOST_FIXTURE_TEST_SUITE(chromosomeSuite, initChromosome)
BOOST_AUTO_TEST_CASE(constructor)
{
    BOOST_CHECK_EQUAL(chrom.getSize(),size);
}

BOOST_AUTO_TEST_CASE(copyConstructor)
{
    Chromosome copyChrom(chrom);
    BOOST_CHECK_EQUAL(chrom.getSize(),copyChrom.getSize());
    for(int i=0;i<size;++i)
        BOOST_CHECK_EQUAL(chrom[i],copyChrom[i]); //Although they are both double, the result should be exactly the same.
}

BOOST_AUTO_TEST_CASE(ordering)
{
    Chromosome chrom2(size);
    chrom.setFitness(583.549);
    chrom2.setFitness(94823.9432);
    BOOST_CHECK_EQUAL(chrom2>chrom,true);
    BOOST_CHECK_EQUAL(chrom2<chrom,false);
    chrom2.setFitness(-0.294324);
    BOOST_CHECK_EQUAL(chrom2<chrom,true);
    BOOST_CHECK_EQUAL(chrom2>chrom,false);    
}

BOOST_AUTO_TEST_CASE(exceptions)
{
    BOOST_CHECK_THROW(chrom[size],std::out_of_range);
}

BOOST_AUTO_TEST_CASE(setGene)
{
    BOOST_CHECK_THROW(chrom.setGene(nullptr),std::invalid_argument);
    
}
BOOST_AUTO_TEST_SUITE_END();