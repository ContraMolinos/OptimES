/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   auxFunctions.h
 * Author: F.J Salguero <contramolinosdeviento@gmail.com>
 *
 * Created on 15 de mayo de 2018, 13:01
 */

#ifndef AUXFUNCTIONS_H
#define AUXFUNCTIONS_H

#include<sys/types.h>
#include "Chromosome.h"

using OptimES::Chromosome;

void quickSort(Chromosome** _population, uint _low, uint _high);
uint partition(Chromosome** _population, uint _low, uint _high);


#endif /* AUXFUNCTIONS_H */

