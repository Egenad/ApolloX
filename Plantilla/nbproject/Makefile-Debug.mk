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
	${OBJECTDIR}/Agente.o \
	${OBJECTDIR}/Alien.o \
	${OBJECTDIR}/Bala.o \
	${OBJECTDIR}/Bomba.o \
	${OBJECTDIR}/Canyon.o \
	${OBJECTDIR}/Carbon.o \
	${OBJECTDIR}/Escudo.o \
	${OBJECTDIR}/Estado.o \
	${OBJECTDIR}/FactoriaNivel.o \
	${OBJECTDIR}/Hierro.o \
	${OBJECTDIR}/Jefe.o \
	${OBJECTDIR}/Magnesio.o \
	${OBJECTDIR}/Material.o \
	${OBJECTDIR}/Menu.o \
	${OBJECTDIR}/Meteorito.o \
	${OBJECTDIR}/Motor2D.o \
	${OBJECTDIR}/NPC.o \
	${OBJECTDIR}/Nave.o \
	${OBJECTDIR}/Nivel.o \
	${OBJECTDIR}/Normal.o \
	${OBJECTDIR}/Obstaculo.o \
	${OBJECTDIR}/Partida.o \
	${OBJECTDIR}/Pausa.o \
	${OBJECTDIR}/Rafaga.o \
	${OBJECTDIR}/Resultado.o \
	${OBJECTDIR}/Tienda.o \
	${OBJECTDIR}/Titanio.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libsfml-graphics.so /usr/lib/x86_64-linux-gnu/libsfml-system.so /usr/lib/x86_64-linux-gnu/libsfml-window.so

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/interpolacion

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/interpolacion: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/interpolacion: /usr/lib/x86_64-linux-gnu/libsfml-system.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/interpolacion: /usr/lib/x86_64-linux-gnu/libsfml-window.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/interpolacion: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/interpolacion ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Agente.o: Agente.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Agente.o Agente.cpp

${OBJECTDIR}/Alien.o: Alien.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Alien.o Alien.cpp

${OBJECTDIR}/Bala.o: Bala.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Bala.o Bala.cpp

${OBJECTDIR}/Bomba.o: Bomba.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Bomba.o Bomba.cpp

${OBJECTDIR}/Canyon.o: Canyon.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Canyon.o Canyon.cpp

${OBJECTDIR}/Carbon.o: Carbon.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Carbon.o Carbon.cpp

${OBJECTDIR}/Escudo.o: Escudo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Escudo.o Escudo.cpp

${OBJECTDIR}/Estado.o: Estado.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Estado.o Estado.cpp

${OBJECTDIR}/FactoriaNivel.o: FactoriaNivel.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FactoriaNivel.o FactoriaNivel.cpp

${OBJECTDIR}/Hierro.o: Hierro.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Hierro.o Hierro.cpp

${OBJECTDIR}/Jefe.o: Jefe.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Jefe.o Jefe.cpp

${OBJECTDIR}/Magnesio.o: Magnesio.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Magnesio.o Magnesio.cpp

${OBJECTDIR}/Material.o: Material.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Material.o Material.cpp

${OBJECTDIR}/Menu.o: Menu.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Menu.o Menu.cpp

${OBJECTDIR}/Meteorito.o: Meteorito.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Meteorito.o Meteorito.cpp

${OBJECTDIR}/Motor2D.o: Motor2D.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Motor2D.o Motor2D.cpp

${OBJECTDIR}/NPC.o: NPC.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/NPC.o NPC.cpp

${OBJECTDIR}/Nave.o: Nave.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Nave.o Nave.cpp

${OBJECTDIR}/Nivel.o: Nivel.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Nivel.o Nivel.cpp

${OBJECTDIR}/Normal.o: Normal.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Normal.o Normal.cpp

${OBJECTDIR}/Obstaculo.o: Obstaculo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Obstaculo.o Obstaculo.cpp

${OBJECTDIR}/Partida.o: Partida.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Partida.o Partida.cpp

${OBJECTDIR}/Pausa.o: Pausa.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Pausa.o Pausa.cpp

${OBJECTDIR}/Rafaga.o: Rafaga.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Rafaga.o Rafaga.cpp

${OBJECTDIR}/Resultado.o: Resultado.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Resultado.o Resultado.cpp

${OBJECTDIR}/Tienda.o: Tienda.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Tienda.o Tienda.cpp

${OBJECTDIR}/Titanio.o: Titanio.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Titanio.o Titanio.cpp

${OBJECTDIR}/main.o: main.cc
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cc

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} -r ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsfml-window.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsfml-graphics.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsfml-system.so
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/interpolacion

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
