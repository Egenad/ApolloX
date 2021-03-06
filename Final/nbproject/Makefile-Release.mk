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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Alien.o \
	${OBJECTDIR}/Alien2.o \
	${OBJECTDIR}/Bala.o \
	${OBJECTDIR}/Base.o \
	${OBJECTDIR}/Clock.o \
	${OBJECTDIR}/Escudo.o \
	${OBJECTDIR}/Event.o \
	${OBJECTDIR}/FactoriaNivel.o \
	${OBJECTDIR}/Font.o \
	${OBJECTDIR}/Game.o \
	${OBJECTDIR}/Jefe.o \
	${OBJECTDIR}/Logo.o \
	${OBJECTDIR}/Material.o \
	${OBJECTDIR}/Menu.o \
	${OBJECTDIR}/Meteorito.o \
	${OBJECTDIR}/Missions.o \
	${OBJECTDIR}/Motor2D.o \
	${OBJECTDIR}/Municion.o \
	${OBJECTDIR}/Music.o \
	${OBJECTDIR}/Nave.o \
	${OBJECTDIR}/Partida.o \
	${OBJECTDIR}/Pausa.o \
	${OBJECTDIR}/RenderWindow.o \
	${OBJECTDIR}/Resultado.o \
	${OBJECTDIR}/Sprite.o \
	${OBJECTDIR}/StrategyA.o \
	${OBJECTDIR}/StrategyA2.o \
	${OBJECTDIR}/StrategyB.o \
	${OBJECTDIR}/StrategyB2.o \
	${OBJECTDIR}/StrategyC.o \
	${OBJECTDIR}/Text.o \
	${OBJECTDIR}/Texture.o \
	${OBJECTDIR}/Vector2f.o \
	${OBJECTDIR}/View.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/resources/tinyxml/tinystr.o \
	${OBJECTDIR}/resources/tinyxml/tinyxml.o \
	${OBJECTDIR}/resources/tinyxml/tinyxmlerror.o \
	${OBJECTDIR}/resources/tinyxml/tinyxmlparser.o


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/apollox-2.4

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/apollox-2.4: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/apollox-2.4 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Alien.o: Alien.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Alien.o Alien.cpp

${OBJECTDIR}/Alien2.o: Alien2.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Alien2.o Alien2.cpp

${OBJECTDIR}/Bala.o: Bala.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Bala.o Bala.cpp

${OBJECTDIR}/Base.o: Base.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Base.o Base.cpp

${OBJECTDIR}/Clock.o: Clock.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Clock.o Clock.cpp

${OBJECTDIR}/Escudo.o: Escudo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Escudo.o Escudo.cpp

${OBJECTDIR}/Event.o: Event.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Event.o Event.cpp

${OBJECTDIR}/FactoriaNivel.o: FactoriaNivel.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FactoriaNivel.o FactoriaNivel.cpp

${OBJECTDIR}/Font.o: Font.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Font.o Font.cpp

${OBJECTDIR}/Game.o: Game.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game.o Game.cpp

${OBJECTDIR}/Jefe.o: Jefe.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Jefe.o Jefe.cpp

${OBJECTDIR}/Logo.o: Logo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Logo.o Logo.cpp

${OBJECTDIR}/Material.o: Material.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Material.o Material.cpp

${OBJECTDIR}/Menu.o: Menu.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Menu.o Menu.cpp

${OBJECTDIR}/Meteorito.o: Meteorito.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Meteorito.o Meteorito.cpp

${OBJECTDIR}/Missions.o: Missions.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Missions.o Missions.cpp

${OBJECTDIR}/Motor2D.o: Motor2D.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Motor2D.o Motor2D.cpp

${OBJECTDIR}/Municion.o: Municion.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Municion.o Municion.cpp

${OBJECTDIR}/Music.o: Music.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Music.o Music.cpp

${OBJECTDIR}/Nave.o: Nave.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Nave.o Nave.cpp

${OBJECTDIR}/Partida.o: Partida.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Partida.o Partida.cpp

${OBJECTDIR}/Pausa.o: Pausa.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Pausa.o Pausa.cpp

${OBJECTDIR}/RenderWindow.o: RenderWindow.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RenderWindow.o RenderWindow.cpp

${OBJECTDIR}/Resultado.o: Resultado.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Resultado.o Resultado.cpp

${OBJECTDIR}/Sprite.o: Sprite.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sprite.o Sprite.cpp

${OBJECTDIR}/StrategyA.o: StrategyA.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StrategyA.o StrategyA.cpp

${OBJECTDIR}/StrategyA2.o: StrategyA2.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StrategyA2.o StrategyA2.cpp

${OBJECTDIR}/StrategyB.o: StrategyB.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StrategyB.o StrategyB.cpp

${OBJECTDIR}/StrategyB2.o: StrategyB2.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StrategyB2.o StrategyB2.cpp

${OBJECTDIR}/StrategyC.o: StrategyC.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StrategyC.o StrategyC.cpp

${OBJECTDIR}/Text.o: Text.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Text.o Text.cpp

${OBJECTDIR}/Texture.o: Texture.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Texture.o Texture.cpp

${OBJECTDIR}/Vector2f.o: Vector2f.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Vector2f.o Vector2f.cpp

${OBJECTDIR}/View.o: View.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/View.o View.cpp

${OBJECTDIR}/main.o: main.cc
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cc

${OBJECTDIR}/resources/tinyxml/tinystr.o: resources/tinyxml/tinystr.cpp
	${MKDIR} -p ${OBJECTDIR}/resources/tinyxml
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/resources/tinyxml/tinystr.o resources/tinyxml/tinystr.cpp

${OBJECTDIR}/resources/tinyxml/tinyxml.o: resources/tinyxml/tinyxml.cpp
	${MKDIR} -p ${OBJECTDIR}/resources/tinyxml
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/resources/tinyxml/tinyxml.o resources/tinyxml/tinyxml.cpp

${OBJECTDIR}/resources/tinyxml/tinyxmlerror.o: resources/tinyxml/tinyxmlerror.cpp
	${MKDIR} -p ${OBJECTDIR}/resources/tinyxml
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/resources/tinyxml/tinyxmlerror.o resources/tinyxml/tinyxmlerror.cpp

${OBJECTDIR}/resources/tinyxml/tinyxmlparser.o: resources/tinyxml/tinyxmlparser.cpp
	${MKDIR} -p ${OBJECTDIR}/resources/tinyxml
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/resources/tinyxml/tinyxmlparser.o resources/tinyxml/tinyxmlparser.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
