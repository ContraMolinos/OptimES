/*
 * 
 * (c) Fratoria B.V.
 * 
 * Rivium 2e straat 22-24
 * 2909LG Capelle aan den IJssel
 * The Netherlands
 */

#ifndef TESTPROBLEM_H
#define TESTPROBLEM_H

#include "Chromosome.h"

/*! \brief  Class to model a problem to test the optimization algorithm. Only for developing purposes.
 */
class testProblem {
public:
    testProblem();
    testProblem(const testProblem& orig);
    double evaluate(Chromosome& _param);
    unsigned int getDim();
    
    virtual ~testProblem();
private:
    unsigned int nDimensions;
    

};

#endif /* TESTPROBLEM_H */

