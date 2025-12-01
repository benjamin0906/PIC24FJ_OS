#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/PIC24FJ_OS.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/PIC24FJ_OS.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=Config/OS_Tasklist_Stub.c OS/Src/GPIO.c OS/Src/I2C.c OS/Src/IC.c OS/Src/MemMap.c OS/Src/OS.c OS/Src/SC.c OS/Src/TIM.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/Config/OS_Tasklist_Stub.o ${OBJECTDIR}/OS/Src/GPIO.o ${OBJECTDIR}/OS/Src/I2C.o ${OBJECTDIR}/OS/Src/IC.o ${OBJECTDIR}/OS/Src/MemMap.o ${OBJECTDIR}/OS/Src/OS.o ${OBJECTDIR}/OS/Src/SC.o ${OBJECTDIR}/OS/Src/TIM.o ${OBJECTDIR}/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/Config/OS_Tasklist_Stub.o.d ${OBJECTDIR}/OS/Src/GPIO.o.d ${OBJECTDIR}/OS/Src/I2C.o.d ${OBJECTDIR}/OS/Src/IC.o.d ${OBJECTDIR}/OS/Src/MemMap.o.d ${OBJECTDIR}/OS/Src/OS.o.d ${OBJECTDIR}/OS/Src/SC.o.d ${OBJECTDIR}/OS/Src/TIM.o.d ${OBJECTDIR}/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/Config/OS_Tasklist_Stub.o ${OBJECTDIR}/OS/Src/GPIO.o ${OBJECTDIR}/OS/Src/I2C.o ${OBJECTDIR}/OS/Src/IC.o ${OBJECTDIR}/OS/Src/MemMap.o ${OBJECTDIR}/OS/Src/OS.o ${OBJECTDIR}/OS/Src/SC.o ${OBJECTDIR}/OS/Src/TIM.o ${OBJECTDIR}/main.o

# Source Files
SOURCEFILES=Config/OS_Tasklist_Stub.c OS/Src/GPIO.c OS/Src/I2C.c OS/Src/IC.c OS/Src/MemMap.c OS/Src/OS.c OS/Src/SC.c OS/Src/TIM.c main.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/PIC24FJ_OS.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ128GB202
MP_LINKER_FILE_OPTION=,--script=p24FJ128GB202.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/Config/OS_Tasklist_Stub.o: Config/OS_Tasklist_Stub.c  .generated_files/flags/default/855bb408825a97010acd062307c57c8f2eb6b7ed .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Config" 
	@${RM} ${OBJECTDIR}/Config/OS_Tasklist_Stub.o.d 
	@${RM} ${OBJECTDIR}/Config/OS_Tasklist_Stub.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Config/OS_Tasklist_Stub.c  -o ${OBJECTDIR}/Config/OS_Tasklist_Stub.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Config/OS_Tasklist_Stub.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/OS/Src/GPIO.o: OS/Src/GPIO.c  .generated_files/flags/default/985cb981a8c2130f7d2076c21b25caa9ef4c3ef5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/OS/Src" 
	@${RM} ${OBJECTDIR}/OS/Src/GPIO.o.d 
	@${RM} ${OBJECTDIR}/OS/Src/GPIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  OS/Src/GPIO.c  -o ${OBJECTDIR}/OS/Src/GPIO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/OS/Src/GPIO.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/OS/Src/I2C.o: OS/Src/I2C.c  .generated_files/flags/default/ac8a95f6b67957c48fb05fdad110e14eb5eba34d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/OS/Src" 
	@${RM} ${OBJECTDIR}/OS/Src/I2C.o.d 
	@${RM} ${OBJECTDIR}/OS/Src/I2C.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  OS/Src/I2C.c  -o ${OBJECTDIR}/OS/Src/I2C.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/OS/Src/I2C.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/OS/Src/IC.o: OS/Src/IC.c  .generated_files/flags/default/71994fee1351bea8d6f993e171c9c9f231264133 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/OS/Src" 
	@${RM} ${OBJECTDIR}/OS/Src/IC.o.d 
	@${RM} ${OBJECTDIR}/OS/Src/IC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  OS/Src/IC.c  -o ${OBJECTDIR}/OS/Src/IC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/OS/Src/IC.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/OS/Src/MemMap.o: OS/Src/MemMap.c  .generated_files/flags/default/2360b73717522fece76e68f30360ddce040b16b5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/OS/Src" 
	@${RM} ${OBJECTDIR}/OS/Src/MemMap.o.d 
	@${RM} ${OBJECTDIR}/OS/Src/MemMap.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  OS/Src/MemMap.c  -o ${OBJECTDIR}/OS/Src/MemMap.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/OS/Src/MemMap.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/OS/Src/OS.o: OS/Src/OS.c  .generated_files/flags/default/4577d5daed89bb66e2bff2a7f2e917277e93ff7a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/OS/Src" 
	@${RM} ${OBJECTDIR}/OS/Src/OS.o.d 
	@${RM} ${OBJECTDIR}/OS/Src/OS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  OS/Src/OS.c  -o ${OBJECTDIR}/OS/Src/OS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/OS/Src/OS.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/OS/Src/SC.o: OS/Src/SC.c  .generated_files/flags/default/9ee970872e7609abda679339ec7ab6d30d266717 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/OS/Src" 
	@${RM} ${OBJECTDIR}/OS/Src/SC.o.d 
	@${RM} ${OBJECTDIR}/OS/Src/SC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  OS/Src/SC.c  -o ${OBJECTDIR}/OS/Src/SC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/OS/Src/SC.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/OS/Src/TIM.o: OS/Src/TIM.c  .generated_files/flags/default/fda2ece759ecb1af4d50de29df96f8c7cbdd8515 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/OS/Src" 
	@${RM} ${OBJECTDIR}/OS/Src/TIM.o.d 
	@${RM} ${OBJECTDIR}/OS/Src/TIM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  OS/Src/TIM.c  -o ${OBJECTDIR}/OS/Src/TIM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/OS/Src/TIM.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/4b79f29bba4613c7e420664aed98910071bdb339 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/Config/OS_Tasklist_Stub.o: Config/OS_Tasklist_Stub.c  .generated_files/flags/default/7450f5a3f5d4195feb24f4775aa83d8ae5b31b71 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Config" 
	@${RM} ${OBJECTDIR}/Config/OS_Tasklist_Stub.o.d 
	@${RM} ${OBJECTDIR}/Config/OS_Tasklist_Stub.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Config/OS_Tasklist_Stub.c  -o ${OBJECTDIR}/Config/OS_Tasklist_Stub.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/Config/OS_Tasklist_Stub.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/OS/Src/GPIO.o: OS/Src/GPIO.c  .generated_files/flags/default/78540621365cdec212c7949388576a3af348cb50 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/OS/Src" 
	@${RM} ${OBJECTDIR}/OS/Src/GPIO.o.d 
	@${RM} ${OBJECTDIR}/OS/Src/GPIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  OS/Src/GPIO.c  -o ${OBJECTDIR}/OS/Src/GPIO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/OS/Src/GPIO.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/OS/Src/I2C.o: OS/Src/I2C.c  .generated_files/flags/default/b061af7887c8b6c6cca868690646219c7a53716a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/OS/Src" 
	@${RM} ${OBJECTDIR}/OS/Src/I2C.o.d 
	@${RM} ${OBJECTDIR}/OS/Src/I2C.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  OS/Src/I2C.c  -o ${OBJECTDIR}/OS/Src/I2C.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/OS/Src/I2C.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/OS/Src/IC.o: OS/Src/IC.c  .generated_files/flags/default/fc2ca4077b91fa5514e928a8793bd42513a275bc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/OS/Src" 
	@${RM} ${OBJECTDIR}/OS/Src/IC.o.d 
	@${RM} ${OBJECTDIR}/OS/Src/IC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  OS/Src/IC.c  -o ${OBJECTDIR}/OS/Src/IC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/OS/Src/IC.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/OS/Src/MemMap.o: OS/Src/MemMap.c  .generated_files/flags/default/25e59f394fb0390fa6ff34fbe452c666a6db48e5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/OS/Src" 
	@${RM} ${OBJECTDIR}/OS/Src/MemMap.o.d 
	@${RM} ${OBJECTDIR}/OS/Src/MemMap.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  OS/Src/MemMap.c  -o ${OBJECTDIR}/OS/Src/MemMap.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/OS/Src/MemMap.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/OS/Src/OS.o: OS/Src/OS.c  .generated_files/flags/default/1c6f5f967845f9c701dc21c1c55c231ec60bb6d5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/OS/Src" 
	@${RM} ${OBJECTDIR}/OS/Src/OS.o.d 
	@${RM} ${OBJECTDIR}/OS/Src/OS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  OS/Src/OS.c  -o ${OBJECTDIR}/OS/Src/OS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/OS/Src/OS.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/OS/Src/SC.o: OS/Src/SC.c  .generated_files/flags/default/34cfb755f0a091b27d41b9553abe0aac64e4de14 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/OS/Src" 
	@${RM} ${OBJECTDIR}/OS/Src/SC.o.d 
	@${RM} ${OBJECTDIR}/OS/Src/SC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  OS/Src/SC.c  -o ${OBJECTDIR}/OS/Src/SC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/OS/Src/SC.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/OS/Src/TIM.o: OS/Src/TIM.c  .generated_files/flags/default/4e237fc0526217a9e04cfc14bb018202851b41e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/OS/Src" 
	@${RM} ${OBJECTDIR}/OS/Src/TIM.o.d 
	@${RM} ${OBJECTDIR}/OS/Src/TIM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  OS/Src/TIM.c  -o ${OBJECTDIR}/OS/Src/TIM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/OS/Src/TIM.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/bd0cb70a37ccbd8287d1cb31bd7ff5942f868295 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/PIC24FJ_OS.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/PIC24FJ_OS.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)      -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/PIC24FJ_OS.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/PIC24FJ_OS.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/PIC24FJ_OS.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
