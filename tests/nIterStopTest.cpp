/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <boost/test/unit_test.hpp>
#include "Chromosome.h"
#include "NIterStop.h"

using OptimES::Chromosome;
using OptimES::NIterStop;

struct dummyChromosomePop
{
    dummyChromosomePop()
    {
        population.emplace_back(3);
    }
    std::vector<Chromosome> population;
};

BOOST_FIXTURE_TEST_SUITE(nIterSuit, dummyChromosomePop)
BOOST_AUTO_TEST_SUITE_END();