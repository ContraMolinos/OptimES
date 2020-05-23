/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <boost/test/unit_test.hpp>
#include "Chromosome.h"
#include "GaussianMutator.h"

using OptimES::Chromosome;
using OptimES::GaussianMutator;

struct mutFixt
{
    mutFixt():cr(3)
    {
        double gene[3]={0.0,0.0,0.0};
        cr.setGene(gene);
    }
    Chromosome cr;
    GaussianMutator mut;
};
BOOST_FIXTURE_TEST_SUITE(GaussianMutatorTest, mutFixt)

//If the mutation probability is 0, the chromosome doesn't change.
BOOST_AUTO_TEST_CASE(ZeroProbTest)
{
    Chromosome cr2(cr);
    mut.mutate(cr, 1.0, 0.0);
    std::vector<double> g1=cr.getGenes();
    std::vector<double> g2=cr2.getGenes();
    double error=0;
    for(size_t i=0;i<g1.size();++i)
        error+=g2[i]-g1[i];
    BOOST_CHECK_EQUAL(error,0.0);
    
    mut.mutate(cr,0.0,1.0);
    error=0;
    for(size_t i=0;i<g1.size();++i)
        error+=g2[i]-g1[i];
    BOOST_CHECK_EQUAL(error,0.0);
}

//If the mutation probability is 1, the genes should change (almost always of the time).
BOOST_AUTO_TEST_CASE(OneProbTest)
{
    Chromosome cr2(cr);
    mut.mutate(cr, 1.0, 1.0);
    std::vector<double> g1=cr.getGenes();
    std::vector<double> g2=cr2.getGenes();
    double error=0;
    for(size_t i=0;i<g1.size();++i)
    {
        error+=std::abs(g2[i]-g1[i]);
    }
    BOOST_CHECK_GT(error,0.0);
}

BOOST_AUTO_TEST_SUITE_END();