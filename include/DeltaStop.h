/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   deltaStop.h
 * Author: F.J Salguero <j.salguero@fratoria.com>
 *
 * Created on 16 de abril de 2018, 20:05
 */

#ifndef DELTASTOP_H
#define DELTASTOP_H

#include <limits>
#include <stdexcept>
#include "Chromosome.h"

namespace OptimES
{
    /*!\class Stopping criteria for optimization.
     * 
     * The stop condition will be true when the difference of two consecutive calls is less than a threshold value.
     */
    class DeltaStop {
    public:
	/*!\brief Constructor.
	 * \param _delta Difference between two consecutive calls that will make the stopping condition true.
	 */
	DeltaStop(double _delta);
	DeltaStop(const DeltaStop& orig);
	virtual ~DeltaStop();
	/*!\brief Method to check whether the stopping condition is true.
	 * 
	 * The method will compare the current cost value with the previous one, and it will return true if the difference is less than delta.
	 * 
	 * \param _cost Current cost function value.
	 * \param _chromosome Current chromosome. Not used.
	 */
	bool stopCondition(const std::vector<Chromosome> &_population);
    private:
	double evaluateFitness(const std::vector<Chromosome> &_population) const;
	double lastVal;
	double delta;
	bool notCalledYet;
	const uint stoppingLimit=100;
	uint nWithoutImprovement;
    };
}

#endif /* DELTASTOP_H */

