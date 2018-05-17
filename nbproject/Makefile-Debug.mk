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
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
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
	${OBJECTDIR}/Chromosome.o \
	${OBJECTDIR}/DeltaStop.o \
	${OBJECTDIR}/ElitistEvolution.o \
	${OBJECTDIR}/MutateFractionGauss.o \
	${OBJECTDIR}/NIterStop.o \
	${OBJECTDIR}/auxFunctions.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/testProblem.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/UT.o \
	${TESTDIR}/chromosomeTest.o \
	${TESTDIR}/deltaStopTest.o \
	${TESTDIR}/mutateFractionGaussTest.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-lboost_unit_test_framework
CXXFLAGS=-lboost_unit_test_framework

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

${OBJECTDIR}/Chromosome.o: Chromosome.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../mlpack-master/build/include/ -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Chromosome.o Chromosome.cpp

${OBJECTDIR}/DeltaStop.o: DeltaStop.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../mlpack-master/build/include/ -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DeltaStop.o DeltaStop.cpp

${OBJECTDIR}/ElitistEvolution.o: ElitistEvolution.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../mlpack-master/build/include/ -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ElitistEvolution.o ElitistEvolution.cpp

${OBJECTDIR}/MutateFractionGauss.o: MutateFractionGauss.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../mlpack-master/build/include/ -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MutateFractionGauss.o MutateFractionGauss.cpp

${OBJECTDIR}/NIterStop.o: NIterStop.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../mlpack-master/build/include/ -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/NIterStop.o NIterStop.cpp

${OBJECTDIR}/auxFunctions.o: auxFunctions.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../mlpack-master/build/include/ -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/auxFunctions.o auxFunctions.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../mlpack-master/build/include/ -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/testProblem.o: testProblem.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../mlpack-master/build/include/ -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/testProblem.o testProblem.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${TESTDIR}/UT.o ${TESTDIR}/chromosomeTest.o ${TESTDIR}/deltaStopTest.o ${TESTDIR}/mutateFractionGaussTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   


${TESTDIR}/UT.o: UT.cpp 
	${MKDIR} -p ${TESTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../mlpack-master/build/include/ -I. -std=c++14 -MMD -MP -MF "$@.d" -o ${TESTDIR}/UT.o UT.cpp


${TESTDIR}/chromosomeTest.o: chromosomeTest.cpp 
	${MKDIR} -p ${TESTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../mlpack-master/build/include/ -I. -std=c++14 -MMD -MP -MF "$@.d" -o ${TESTDIR}/chromosomeTest.o chromosomeTest.cpp


${TESTDIR}/deltaStopTest.o: deltaStopTest.cpp 
	${MKDIR} -p ${TESTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../mlpack-master/build/include/ -I. -std=c++14 -MMD -MP -MF "$@.d" -o ${TESTDIR}/deltaStopTest.o deltaStopTest.cpp


${TESTDIR}/mutateFractionGaussTest.o: mutateFractionGaussTest.cpp 
	${MKDIR} -p ${TESTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../mlpack-master/build/include/ -I. -std=c++14 -MMD -MP -MF "$@.d" -o ${TESTDIR}/mutateFractionGaussTest.o mutateFractionGaussTest.cpp


${OBJECTDIR}/Chromosome_nomain.o: ${OBJECTDIR}/Chromosome.o Chromosome.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Chromosome.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../mlpack-master/build/include/ -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Chromosome_nomain.o Chromosome.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Chromosome.o ${OBJECTDIR}/Chromosome_nomain.o;\
	fi

${OBJECTDIR}/DeltaStop_nomain.o: ${OBJECTDIR}/DeltaStop.o DeltaStop.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/DeltaStop.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../mlpack-master/build/include/ -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DeltaStop_nomain.o DeltaStop.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/DeltaStop.o ${OBJECTDIR}/DeltaStop_nomain.o;\
	fi

${OBJECTDIR}/ElitistEvolution_nomain.o: ${OBJECTDIR}/ElitistEvolution.o ElitistEvolution.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ElitistEvolution.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../mlpack-master/build/include/ -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ElitistEvolution_nomain.o ElitistEvolution.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ElitistEvolution.o ${OBJECTDIR}/ElitistEvolution_nomain.o;\
	fi

${OBJECTDIR}/MutateFractionGauss_nomain.o: ${OBJECTDIR}/MutateFractionGauss.o MutateFractionGauss.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/MutateFractionGauss.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../mlpack-master/build/include/ -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MutateFractionGauss_nomain.o MutateFractionGauss.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/MutateFractionGauss.o ${OBJECTDIR}/MutateFractionGauss_nomain.o;\
	fi

${OBJECTDIR}/NIterStop_nomain.o: ${OBJECTDIR}/NIterStop.o NIterStop.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/NIterStop.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../mlpack-master/build/include/ -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/NIterStop_nomain.o NIterStop.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/NIterStop.o ${OBJECTDIR}/NIterStop_nomain.o;\
	fi

${OBJECTDIR}/auxFunctions_nomain.o: ${OBJECTDIR}/auxFunctions.o auxFunctions.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/auxFunctions.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../mlpack-master/build/include/ -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/auxFunctions_nomain.o auxFunctions.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/auxFunctions.o ${OBJECTDIR}/auxFunctions_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../mlpack-master/build/include/ -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/testProblem_nomain.o: ${OBJECTDIR}/testProblem.o testProblem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/testProblem.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../mlpack-master/build/include/ -std=c++14 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/testProblem_nomain.o testProblem.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/testProblem.o ${OBJECTDIR}/testProblem_nomain.o;\
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
