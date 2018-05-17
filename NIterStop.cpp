/*
 * 
 * (c) Fratoria B.V.
 * 
 * Rivium 2e straat 22-24
 * 2909LG Capelle aan den IJssel
 * The Netherlands
 */

#include "NIterStop.h"

NIterStop::NIterStop(unsigned long int _maxCalls):maxCalls(_maxCalls),nCalls(0)
{
}

NIterStop::NIterStop(const NIterStop& orig):maxCalls(orig.maxCalls),nCalls(orig.nCalls)
{
}

NIterStop::~NIterStop()
{
}

bool NIterStop::stopCondition(const Chromosome * const* _population, const uint _popSize)
{
    if((++nCalls)>maxCalls)
        return true;
    return false;
}
