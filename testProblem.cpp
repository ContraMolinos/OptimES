/*
 * 
 * (c) Fratoria B.V.
 * 
 * Rivium 2e straat 22-24
 * 2909LG Capelle aan den IJssel
 * The Netherlands
 */

#include <stdexcept>
#include <complex>

#include "testProblem.h"

testProblem::testProblem():nDimensions(5)
{
}

testProblem::testProblem(const testProblem& orig):nDimensions(orig.nDimensions)
{
}

testProblem::~testProblem()
{
}

double testProblem::evaluate(Chromosome& _param)
{
    if(_param.getSize()!=nDimensions)
        throw std::invalid_argument("Wrong chromosome size.");
    double res=0;
    /*for(int i=0;i<nDimensions;++i)
        res+=(_param[i]-i)*(_param[i]-i);
     */
    /*
    for(int i=0;i<nDimensions-1;++i) //Rosenbrock
    {
        res+=100*(_param[i+1]-_param[i]*_param[i])*(_param[i+1]-_param[i]*_param[i])+(1-_param[i])*(1-_param[i]);
    }*/
    
    for(int i=0;i<nDimensions;++i)  //Rastrigin
    {
        res+=_param[i]*_param[i]-10*std::cos(2*M_PI*_param[i]);
    }
    res+=10*nDimensions;
    _param.setFitness(res);
    return res;
}

unsigned int testProblem::getDim()
{
    return nDimensions;
}

