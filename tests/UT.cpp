/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OPTIMES_TEST
#include <boost/test/unit_test.hpp>

struct output
{
    output()
    {
        //Be verbose.
        boost::unit_test::unit_test_log.set_threshold_level(boost::unit_test::output_format::OF_CLF,boost::unit_test::log_test_units);
    }
    ~output(){}
};

BOOST_GLOBAL_FIXTURE(output);