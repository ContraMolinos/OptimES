#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc-10
CCC=g++-10
CXX=g++-10
FC=gfortran-10
AS=as

# Macros
CND_PLATFORM=GNU_10-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/Chromosome.o \
	${OBJECTDIR}/src/DeltaStop.o \
	${OBJECTDIR}/src/GaussianMutator.o \
	${OBJECTDIR}/src/IncreasingGaussianMutator.o \
	${OBJECTDIR}/src/MutateFractionGauss.o \
	${OBJECTDIR}/src/NIterStop.o \
	${OBJECTDIR}/src/auxFunctions.o \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/src/testProblem.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/UT.o \
	${TESTDIR}/tests/chromosomeTest.o \
	${TESTDIR}/tests/deltaStopTest.o \
	${TESTDIR}/tests/elitistRecombinationTest.o \
	${TESTDIR}/tests/evolutionaryAlgTest.o \
	${TESTDIR}/tests/gaussianMutatorTest.o \
	${TESTDIR}/tests/mutateFractionGaussTest.o \
	${TESTDIR}/tests/nIterStopTest.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=--verbose
CXXFLAGS=--verbose

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/optimes

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/optimes: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/optimes ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/Chromosome.o: src/Chromosome.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Chromosome.o src/Chromosome.cpp

${OBJECTDIR}/src/DeltaStop.o: src/DeltaStop.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/DeltaStop.o src/DeltaStop.cpp

${OBJECTDIR}/src/GaussianMutator.o: src/GaussianMutator.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GaussianMutator.o src/GaussianMutator.cpp

${OBJECTDIR}/src/IncreasingGaussianMutator.o: src/IncreasingGaussianMutator.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/IncreasingGaussianMutator.o src/IncreasingGaussianMutator.cpp

${OBJECTDIR}/src/MutateFractionGauss.o: src/MutateFractionGauss.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/MutateFractionGauss.o src/MutateFractionGauss.cpp

${OBJECTDIR}/src/NIterStop.o: src/NIterStop.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/NIterStop.o src/NIterStop.cpp

${OBJECTDIR}/src/auxFunctions.o: src/auxFunctions.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/auxFunctions.o src/auxFunctions.cpp

${OBJECTDIR}/src/main.o: src/main.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/src/testProblem.o: src/testProblem.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/testProblem.o src/testProblem.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/UT.o ${TESTDIR}/tests/chromosomeTest.o ${TESTDIR}/tests/deltaStopTest.o ${TESTDIR}/tests/elitistRecombinationTest.o ${TESTDIR}/tests/evolutionaryAlgTest.o ${TESTDIR}/tests/gaussianMutatorTest.o ${TESTDIR}/tests/mutateFractionGaussTest.o ${TESTDIR}/tests/nIterStopTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} -lboost_unit_test_framework --verbose  


${TESTDIR}/tests/UT.o: tests/UT.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -I. -std=c++14 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/UT.o tests/UT.cpp


${TESTDIR}/tests/chromosomeTest.o: tests/chromosomeTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -I. -std=c++14 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/chromosomeTest.o tests/chromosomeTest.cpp


${TESTDIR}/tests/deltaStopTest.o: tests/deltaStopTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -I. -std=c++14 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/deltaStopTest.o tests/deltaStopTest.cpp


${TESTDIR}/tests/elitistRecombinationTest.o: tests/elitistRecombinationTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -I. -std=c++14 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/elitistRecombinationTest.o tests/elitistRecombinationTest.cpp


${TESTDIR}/tests/evolutionaryAlgTest.o: tests/evolutionaryAlgTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -I. -std=c++14 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/evolutionaryAlgTest.o tests/evolutionaryAlgTest.cpp


${TESTDIR}/tests/gaussianMutatorTest.o: tests/gaussianMutatorTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -I. -std=c++14 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/gaussianMutatorTest.o tests/gaussianMutatorTest.cpp


${TESTDIR}/tests/mutateFractionGaussTest.o: tests/mutateFractionGaussTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -I. -std=c++14 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/mutateFractionGaussTest.o tests/mutateFractionGaussTest.cpp


${TESTDIR}/tests/nIterStopTest.o: tests/nIterStopTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude -I. -std=c++14 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/nIterStopTest.o tests/nIterStopTest.cpp


${OBJECTDIR}/src/Chromosome_nomain.o: ${OBJECTDIR}/src/Chromosome.o src/Chromosome.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/Chromosome.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Iinclude -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Chromosome_nomain.o src/Chromosome.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/Chromosome.o ${OBJECTDIR}/src/Chromosome_nomain.o;\
	fi

${OBJECTDIR}/src/DeltaStop_nomain.o: ${OBJECTDIR}/src/DeltaStop.o src/DeltaStop.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/DeltaStop.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Iinclude -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/DeltaStop_nomain.o src/DeltaStop.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/DeltaStop.o ${OBJECTDIR}/src/DeltaStop_nomain.o;\
	fi

${OBJECTDIR}/src/GaussianMutator_nomain.o: ${OBJECTDIR}/src/GaussianMutator.o src/GaussianMutator.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/GaussianMutator.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Iinclude -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GaussianMutator_nomain.o src/GaussianMutator.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/GaussianMutator.o ${OBJECTDIR}/src/GaussianMutator_nomain.o;\
	fi

${OBJECTDIR}/src/IncreasingGaussianMutator_nomain.o: ${OBJECTDIR}/src/IncreasingGaussianMutator.o src/IncreasingGaussianMutator.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/IncreasingGaussianMutator.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Iinclude -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/IncreasingGaussianMutator_nomain.o src/IncreasingGaussianMutator.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/IncreasingGaussianMutator.o ${OBJECTDIR}/src/IncreasingGaussianMutator_nomain.o;\
	fi

${OBJECTDIR}/src/MutateFractionGauss_nomain.o: ${OBJECTDIR}/src/MutateFractionGauss.o src/MutateFractionGauss.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/MutateFractionGauss.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Iinclude -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/MutateFractionGauss_nomain.o src/MutateFractionGauss.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/MutateFractionGauss.o ${OBJECTDIR}/src/MutateFractionGauss_nomain.o;\
	fi

${OBJECTDIR}/src/NIterStop_nomain.o: ${OBJECTDIR}/src/NIterStop.o src/NIterStop.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/NIterStop.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Iinclude -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/NIterStop_nomain.o src/NIterStop.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/NIterStop.o ${OBJECTDIR}/src/NIterStop_nomain.o;\
	fi

${OBJECTDIR}/src/auxFunctions_nomain.o: ${OBJECTDIR}/src/auxFunctions.o src/auxFunctions.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/auxFunctions.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Iinclude -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/auxFunctions_nomain.o src/auxFunctions.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/auxFunctions.o ${OBJECTDIR}/src/auxFunctions_nomain.o;\
	fi

${OBJECTDIR}/src/main_nomain.o: ${OBJECTDIR}/src/main.o src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Iinclude -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main_nomain.o src/main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/main_nomain.o;\
	fi

${OBJECTDIR}/src/testProblem_nomain.o: ${OBJECTDIR}/src/testProblem.o src/testProblem.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/testProblem.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Iinclude -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/testProblem_nomain.o src/testProblem.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/testProblem.o ${OBJECTDIR}/src/testProblem_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
