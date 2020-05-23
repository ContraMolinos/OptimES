/*
 * 
 * (c) Fratoria B.V.
 * 
 * Rivium 2e straat 22-24
 * 2909LG Capelle aan den IJssel
 * The Netherlands
 */

#ifndef NITERSTOP_H
#define NITERSTOP_H

#include <sys/types.h>
#include "Chromosome.h"

namespace OptimES
{
    class NIterStop {
    public:
	NIterStop(unsigned long int _maxCalls);
	NIterStop(const NIterStop& orig);
	virtual ~NIterStop();
	bool stopCondition(const std::vector<Chromosome>& _population);
    private:
	unsigned long int nCalls;
	const unsigned long int maxCalls;

    };
}

#endif /* NITERSTOP_H */

