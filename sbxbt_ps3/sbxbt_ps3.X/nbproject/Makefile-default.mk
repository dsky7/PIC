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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/sbxbt_ps3.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/sbxbt_ps3.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../btstack/btstack_memory.c ../btstack/hci.c ../btstack/hci_cmds.c ../btstack/hci_dump.c ../btstack/hci_transport_picusb.c ../btstack/l2cap.c ../btstack/l2cap_signaling.c ../btstack/linked_list.c ../btstack/memory_pool.c ../btstack/remote_device_db_memory.c ../btstack/rfcomm.c ../btstack/run_loop.c ../btstack/run_loop_embedded.c ../btstack/sdp.c ../btstack/sdp_util.c ../btstack/utils.c ../Common/uart2.c ../Common/uart1.c ../USB/usb_host.c ../USB/usb_host_bluetooth.c ../main.c ../usb_config.c ../xprintf.c ../flash.c ../dev_dragonrise.c ../dev_elecom_u3312s.c ../dev_elecom_u3412s.c ../dev_logicool_f710.c ../dev_sony_ps3.c ../dev_logicool_f510.c ../TimeDelay.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1468720089/btstack_memory.o ${OBJECTDIR}/_ext/1468720089/hci.o ${OBJECTDIR}/_ext/1468720089/hci_cmds.o ${OBJECTDIR}/_ext/1468720089/hci_dump.o ${OBJECTDIR}/_ext/1468720089/hci_transport_picusb.o ${OBJECTDIR}/_ext/1468720089/l2cap.o ${OBJECTDIR}/_ext/1468720089/l2cap_signaling.o ${OBJECTDIR}/_ext/1468720089/linked_list.o ${OBJECTDIR}/_ext/1468720089/memory_pool.o ${OBJECTDIR}/_ext/1468720089/remote_device_db_memory.o ${OBJECTDIR}/_ext/1468720089/rfcomm.o ${OBJECTDIR}/_ext/1468720089/run_loop.o ${OBJECTDIR}/_ext/1468720089/run_loop_embedded.o ${OBJECTDIR}/_ext/1468720089/sdp.o ${OBJECTDIR}/_ext/1468720089/sdp_util.o ${OBJECTDIR}/_ext/1468720089/utils.o ${OBJECTDIR}/_ext/2108356922/uart2.o ${OBJECTDIR}/_ext/2108356922/uart1.o ${OBJECTDIR}/_ext/1360907413/usb_host.o ${OBJECTDIR}/_ext/1360907413/usb_host_bluetooth.o ${OBJECTDIR}/_ext/1472/main.o ${OBJECTDIR}/_ext/1472/usb_config.o ${OBJECTDIR}/_ext/1472/xprintf.o ${OBJECTDIR}/_ext/1472/flash.o ${OBJECTDIR}/_ext/1472/dev_dragonrise.o ${OBJECTDIR}/_ext/1472/dev_elecom_u3312s.o ${OBJECTDIR}/_ext/1472/dev_elecom_u3412s.o ${OBJECTDIR}/_ext/1472/dev_logicool_f710.o ${OBJECTDIR}/_ext/1472/dev_sony_ps3.o ${OBJECTDIR}/_ext/1472/dev_logicool_f510.o ${OBJECTDIR}/_ext/1472/TimeDelay.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1468720089/btstack_memory.o.d ${OBJECTDIR}/_ext/1468720089/hci.o.d ${OBJECTDIR}/_ext/1468720089/hci_cmds.o.d ${OBJECTDIR}/_ext/1468720089/hci_dump.o.d ${OBJECTDIR}/_ext/1468720089/hci_transport_picusb.o.d ${OBJECTDIR}/_ext/1468720089/l2cap.o.d ${OBJECTDIR}/_ext/1468720089/l2cap_signaling.o.d ${OBJECTDIR}/_ext/1468720089/linked_list.o.d ${OBJECTDIR}/_ext/1468720089/memory_pool.o.d ${OBJECTDIR}/_ext/1468720089/remote_device_db_memory.o.d ${OBJECTDIR}/_ext/1468720089/rfcomm.o.d ${OBJECTDIR}/_ext/1468720089/run_loop.o.d ${OBJECTDIR}/_ext/1468720089/run_loop_embedded.o.d ${OBJECTDIR}/_ext/1468720089/sdp.o.d ${OBJECTDIR}/_ext/1468720089/sdp_util.o.d ${OBJECTDIR}/_ext/1468720089/utils.o.d ${OBJECTDIR}/_ext/2108356922/uart2.o.d ${OBJECTDIR}/_ext/2108356922/uart1.o.d ${OBJECTDIR}/_ext/1360907413/usb_host.o.d ${OBJECTDIR}/_ext/1360907413/usb_host_bluetooth.o.d ${OBJECTDIR}/_ext/1472/main.o.d ${OBJECTDIR}/_ext/1472/usb_config.o.d ${OBJECTDIR}/_ext/1472/xprintf.o.d ${OBJECTDIR}/_ext/1472/flash.o.d ${OBJECTDIR}/_ext/1472/dev_dragonrise.o.d ${OBJECTDIR}/_ext/1472/dev_elecom_u3312s.o.d ${OBJECTDIR}/_ext/1472/dev_elecom_u3412s.o.d ${OBJECTDIR}/_ext/1472/dev_logicool_f710.o.d ${OBJECTDIR}/_ext/1472/dev_sony_ps3.o.d ${OBJECTDIR}/_ext/1472/dev_logicool_f510.o.d ${OBJECTDIR}/_ext/1472/TimeDelay.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1468720089/btstack_memory.o ${OBJECTDIR}/_ext/1468720089/hci.o ${OBJECTDIR}/_ext/1468720089/hci_cmds.o ${OBJECTDIR}/_ext/1468720089/hci_dump.o ${OBJECTDIR}/_ext/1468720089/hci_transport_picusb.o ${OBJECTDIR}/_ext/1468720089/l2cap.o ${OBJECTDIR}/_ext/1468720089/l2cap_signaling.o ${OBJECTDIR}/_ext/1468720089/linked_list.o ${OBJECTDIR}/_ext/1468720089/memory_pool.o ${OBJECTDIR}/_ext/1468720089/remote_device_db_memory.o ${OBJECTDIR}/_ext/1468720089/rfcomm.o ${OBJECTDIR}/_ext/1468720089/run_loop.o ${OBJECTDIR}/_ext/1468720089/run_loop_embedded.o ${OBJECTDIR}/_ext/1468720089/sdp.o ${OBJECTDIR}/_ext/1468720089/sdp_util.o ${OBJECTDIR}/_ext/1468720089/utils.o ${OBJECTDIR}/_ext/2108356922/uart2.o ${OBJECTDIR}/_ext/2108356922/uart1.o ${OBJECTDIR}/_ext/1360907413/usb_host.o ${OBJECTDIR}/_ext/1360907413/usb_host_bluetooth.o ${OBJECTDIR}/_ext/1472/main.o ${OBJECTDIR}/_ext/1472/usb_config.o ${OBJECTDIR}/_ext/1472/xprintf.o ${OBJECTDIR}/_ext/1472/flash.o ${OBJECTDIR}/_ext/1472/dev_dragonrise.o ${OBJECTDIR}/_ext/1472/dev_elecom_u3312s.o ${OBJECTDIR}/_ext/1472/dev_elecom_u3412s.o ${OBJECTDIR}/_ext/1472/dev_logicool_f710.o ${OBJECTDIR}/_ext/1472/dev_sony_ps3.o ${OBJECTDIR}/_ext/1472/dev_logicool_f510.o ${OBJECTDIR}/_ext/1472/TimeDelay.o

# Source Files
SOURCEFILES=../btstack/btstack_memory.c ../btstack/hci.c ../btstack/hci_cmds.c ../btstack/hci_dump.c ../btstack/hci_transport_picusb.c ../btstack/l2cap.c ../btstack/l2cap_signaling.c ../btstack/linked_list.c ../btstack/memory_pool.c ../btstack/remote_device_db_memory.c ../btstack/rfcomm.c ../btstack/run_loop.c ../btstack/run_loop_embedded.c ../btstack/sdp.c ../btstack/sdp_util.c ../btstack/utils.c ../Common/uart2.c ../Common/uart1.c ../USB/usb_host.c ../USB/usb_host_bluetooth.c ../main.c ../usb_config.c ../xprintf.c ../flash.c ../dev_dragonrise.c ../dev_elecom_u3312s.c ../dev_elecom_u3412s.c ../dev_logicool_f710.c ../dev_sony_ps3.c ../dev_logicool_f510.c ../TimeDelay.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/sbxbt_ps3.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ64GB004
MP_LINKER_FILE_OPTION=,--script=p24FJ64GB004.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1468720089/btstack_memory.o: ../btstack/btstack_memory.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/btstack_memory.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/btstack_memory.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/btstack_memory.c  -o ${OBJECTDIR}/_ext/1468720089/btstack_memory.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/btstack_memory.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/btstack_memory.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/hci.o: ../btstack/hci.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/hci.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/hci.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/hci.c  -o ${OBJECTDIR}/_ext/1468720089/hci.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/hci.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/hci.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/hci_cmds.o: ../btstack/hci_cmds.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/hci_cmds.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/hci_cmds.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/hci_cmds.c  -o ${OBJECTDIR}/_ext/1468720089/hci_cmds.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/hci_cmds.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/hci_cmds.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/hci_dump.o: ../btstack/hci_dump.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/hci_dump.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/hci_dump.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/hci_dump.c  -o ${OBJECTDIR}/_ext/1468720089/hci_dump.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/hci_dump.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/hci_dump.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/hci_transport_picusb.o: ../btstack/hci_transport_picusb.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/hci_transport_picusb.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/hci_transport_picusb.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/hci_transport_picusb.c  -o ${OBJECTDIR}/_ext/1468720089/hci_transport_picusb.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/hci_transport_picusb.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/hci_transport_picusb.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/l2cap.o: ../btstack/l2cap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/l2cap.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/l2cap.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/l2cap.c  -o ${OBJECTDIR}/_ext/1468720089/l2cap.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/l2cap.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/l2cap.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/l2cap_signaling.o: ../btstack/l2cap_signaling.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/l2cap_signaling.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/l2cap_signaling.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/l2cap_signaling.c  -o ${OBJECTDIR}/_ext/1468720089/l2cap_signaling.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/l2cap_signaling.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/l2cap_signaling.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/linked_list.o: ../btstack/linked_list.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/linked_list.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/linked_list.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/linked_list.c  -o ${OBJECTDIR}/_ext/1468720089/linked_list.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/linked_list.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/linked_list.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/memory_pool.o: ../btstack/memory_pool.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/memory_pool.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/memory_pool.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/memory_pool.c  -o ${OBJECTDIR}/_ext/1468720089/memory_pool.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/memory_pool.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/memory_pool.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/remote_device_db_memory.o: ../btstack/remote_device_db_memory.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/remote_device_db_memory.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/remote_device_db_memory.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/remote_device_db_memory.c  -o ${OBJECTDIR}/_ext/1468720089/remote_device_db_memory.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/remote_device_db_memory.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/remote_device_db_memory.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/rfcomm.o: ../btstack/rfcomm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/rfcomm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/rfcomm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/rfcomm.c  -o ${OBJECTDIR}/_ext/1468720089/rfcomm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/rfcomm.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/rfcomm.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/run_loop.o: ../btstack/run_loop.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/run_loop.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/run_loop.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/run_loop.c  -o ${OBJECTDIR}/_ext/1468720089/run_loop.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/run_loop.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/run_loop.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/run_loop_embedded.o: ../btstack/run_loop_embedded.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/run_loop_embedded.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/run_loop_embedded.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/run_loop_embedded.c  -o ${OBJECTDIR}/_ext/1468720089/run_loop_embedded.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/run_loop_embedded.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/run_loop_embedded.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/sdp.o: ../btstack/sdp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/sdp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/sdp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/sdp.c  -o ${OBJECTDIR}/_ext/1468720089/sdp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/sdp.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/sdp.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/sdp_util.o: ../btstack/sdp_util.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/sdp_util.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/sdp_util.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/sdp_util.c  -o ${OBJECTDIR}/_ext/1468720089/sdp_util.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/sdp_util.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/sdp_util.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/utils.o: ../btstack/utils.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/utils.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/utils.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/utils.c  -o ${OBJECTDIR}/_ext/1468720089/utils.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/utils.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/utils.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2108356922/uart2.o: ../Common/uart2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2108356922" 
	@${RM} ${OBJECTDIR}/_ext/2108356922/uart2.o.d 
	@${RM} ${OBJECTDIR}/_ext/2108356922/uart2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Common/uart2.c  -o ${OBJECTDIR}/_ext/2108356922/uart2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2108356922/uart2.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/2108356922/uart2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2108356922/uart1.o: ../Common/uart1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2108356922" 
	@${RM} ${OBJECTDIR}/_ext/2108356922/uart1.o.d 
	@${RM} ${OBJECTDIR}/_ext/2108356922/uart1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Common/uart1.c  -o ${OBJECTDIR}/_ext/2108356922/uart1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2108356922/uart1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/2108356922/uart1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360907413/usb_host.o: ../USB/usb_host.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360907413" 
	@${RM} ${OBJECTDIR}/_ext/1360907413/usb_host.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360907413/usb_host.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../USB/usb_host.c  -o ${OBJECTDIR}/_ext/1360907413/usb_host.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360907413/usb_host.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360907413/usb_host.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360907413/usb_host_bluetooth.o: ../USB/usb_host_bluetooth.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360907413" 
	@${RM} ${OBJECTDIR}/_ext/1360907413/usb_host_bluetooth.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360907413/usb_host_bluetooth.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../USB/usb_host_bluetooth.c  -o ${OBJECTDIR}/_ext/1360907413/usb_host_bluetooth.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360907413/usb_host_bluetooth.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360907413/usb_host_bluetooth.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../main.c  -o ${OBJECTDIR}/_ext/1472/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/usb_config.o: ../usb_config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/usb_config.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/usb_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../usb_config.c  -o ${OBJECTDIR}/_ext/1472/usb_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/usb_config.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/usb_config.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/xprintf.o: ../xprintf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/xprintf.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/xprintf.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../xprintf.c  -o ${OBJECTDIR}/_ext/1472/xprintf.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/xprintf.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/xprintf.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/flash.o: ../flash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/flash.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/flash.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../flash.c  -o ${OBJECTDIR}/_ext/1472/flash.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/flash.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/flash.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/dev_dragonrise.o: ../dev_dragonrise.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/dev_dragonrise.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/dev_dragonrise.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../dev_dragonrise.c  -o ${OBJECTDIR}/_ext/1472/dev_dragonrise.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/dev_dragonrise.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/dev_dragonrise.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/dev_elecom_u3312s.o: ../dev_elecom_u3312s.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/dev_elecom_u3312s.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/dev_elecom_u3312s.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../dev_elecom_u3312s.c  -o ${OBJECTDIR}/_ext/1472/dev_elecom_u3312s.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/dev_elecom_u3312s.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/dev_elecom_u3312s.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/dev_elecom_u3412s.o: ../dev_elecom_u3412s.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/dev_elecom_u3412s.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/dev_elecom_u3412s.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../dev_elecom_u3412s.c  -o ${OBJECTDIR}/_ext/1472/dev_elecom_u3412s.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/dev_elecom_u3412s.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/dev_elecom_u3412s.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/dev_logicool_f710.o: ../dev_logicool_f710.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/dev_logicool_f710.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/dev_logicool_f710.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../dev_logicool_f710.c  -o ${OBJECTDIR}/_ext/1472/dev_logicool_f710.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/dev_logicool_f710.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/dev_logicool_f710.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/dev_sony_ps3.o: ../dev_sony_ps3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/dev_sony_ps3.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/dev_sony_ps3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../dev_sony_ps3.c  -o ${OBJECTDIR}/_ext/1472/dev_sony_ps3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/dev_sony_ps3.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/dev_sony_ps3.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/dev_logicool_f510.o: ../dev_logicool_f510.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/dev_logicool_f510.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/dev_logicool_f510.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../dev_logicool_f510.c  -o ${OBJECTDIR}/_ext/1472/dev_logicool_f510.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/dev_logicool_f510.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/dev_logicool_f510.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/TimeDelay.o: ../TimeDelay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/TimeDelay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/TimeDelay.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../TimeDelay.c  -o ${OBJECTDIR}/_ext/1472/TimeDelay.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/TimeDelay.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/TimeDelay.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/1468720089/btstack_memory.o: ../btstack/btstack_memory.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/btstack_memory.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/btstack_memory.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/btstack_memory.c  -o ${OBJECTDIR}/_ext/1468720089/btstack_memory.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/btstack_memory.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/btstack_memory.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/hci.o: ../btstack/hci.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/hci.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/hci.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/hci.c  -o ${OBJECTDIR}/_ext/1468720089/hci.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/hci.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/hci.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/hci_cmds.o: ../btstack/hci_cmds.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/hci_cmds.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/hci_cmds.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/hci_cmds.c  -o ${OBJECTDIR}/_ext/1468720089/hci_cmds.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/hci_cmds.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/hci_cmds.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/hci_dump.o: ../btstack/hci_dump.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/hci_dump.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/hci_dump.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/hci_dump.c  -o ${OBJECTDIR}/_ext/1468720089/hci_dump.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/hci_dump.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/hci_dump.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/hci_transport_picusb.o: ../btstack/hci_transport_picusb.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/hci_transport_picusb.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/hci_transport_picusb.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/hci_transport_picusb.c  -o ${OBJECTDIR}/_ext/1468720089/hci_transport_picusb.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/hci_transport_picusb.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/hci_transport_picusb.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/l2cap.o: ../btstack/l2cap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/l2cap.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/l2cap.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/l2cap.c  -o ${OBJECTDIR}/_ext/1468720089/l2cap.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/l2cap.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/l2cap.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/l2cap_signaling.o: ../btstack/l2cap_signaling.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/l2cap_signaling.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/l2cap_signaling.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/l2cap_signaling.c  -o ${OBJECTDIR}/_ext/1468720089/l2cap_signaling.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/l2cap_signaling.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/l2cap_signaling.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/linked_list.o: ../btstack/linked_list.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/linked_list.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/linked_list.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/linked_list.c  -o ${OBJECTDIR}/_ext/1468720089/linked_list.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/linked_list.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/linked_list.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/memory_pool.o: ../btstack/memory_pool.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/memory_pool.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/memory_pool.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/memory_pool.c  -o ${OBJECTDIR}/_ext/1468720089/memory_pool.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/memory_pool.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/memory_pool.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/remote_device_db_memory.o: ../btstack/remote_device_db_memory.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/remote_device_db_memory.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/remote_device_db_memory.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/remote_device_db_memory.c  -o ${OBJECTDIR}/_ext/1468720089/remote_device_db_memory.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/remote_device_db_memory.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/remote_device_db_memory.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/rfcomm.o: ../btstack/rfcomm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/rfcomm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/rfcomm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/rfcomm.c  -o ${OBJECTDIR}/_ext/1468720089/rfcomm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/rfcomm.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/rfcomm.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/run_loop.o: ../btstack/run_loop.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/run_loop.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/run_loop.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/run_loop.c  -o ${OBJECTDIR}/_ext/1468720089/run_loop.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/run_loop.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/run_loop.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/run_loop_embedded.o: ../btstack/run_loop_embedded.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/run_loop_embedded.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/run_loop_embedded.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/run_loop_embedded.c  -o ${OBJECTDIR}/_ext/1468720089/run_loop_embedded.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/run_loop_embedded.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/run_loop_embedded.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/sdp.o: ../btstack/sdp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/sdp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/sdp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/sdp.c  -o ${OBJECTDIR}/_ext/1468720089/sdp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/sdp.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/sdp.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/sdp_util.o: ../btstack/sdp_util.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/sdp_util.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/sdp_util.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/sdp_util.c  -o ${OBJECTDIR}/_ext/1468720089/sdp_util.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/sdp_util.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/sdp_util.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1468720089/utils.o: ../btstack/utils.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1468720089" 
	@${RM} ${OBJECTDIR}/_ext/1468720089/utils.o.d 
	@${RM} ${OBJECTDIR}/_ext/1468720089/utils.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../btstack/utils.c  -o ${OBJECTDIR}/_ext/1468720089/utils.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1468720089/utils.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1468720089/utils.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2108356922/uart2.o: ../Common/uart2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2108356922" 
	@${RM} ${OBJECTDIR}/_ext/2108356922/uart2.o.d 
	@${RM} ${OBJECTDIR}/_ext/2108356922/uart2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Common/uart2.c  -o ${OBJECTDIR}/_ext/2108356922/uart2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2108356922/uart2.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/2108356922/uart2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2108356922/uart1.o: ../Common/uart1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2108356922" 
	@${RM} ${OBJECTDIR}/_ext/2108356922/uart1.o.d 
	@${RM} ${OBJECTDIR}/_ext/2108356922/uart1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Common/uart1.c  -o ${OBJECTDIR}/_ext/2108356922/uart1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2108356922/uart1.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/2108356922/uart1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360907413/usb_host.o: ../USB/usb_host.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360907413" 
	@${RM} ${OBJECTDIR}/_ext/1360907413/usb_host.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360907413/usb_host.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../USB/usb_host.c  -o ${OBJECTDIR}/_ext/1360907413/usb_host.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360907413/usb_host.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360907413/usb_host.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360907413/usb_host_bluetooth.o: ../USB/usb_host_bluetooth.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360907413" 
	@${RM} ${OBJECTDIR}/_ext/1360907413/usb_host_bluetooth.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360907413/usb_host_bluetooth.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../USB/usb_host_bluetooth.c  -o ${OBJECTDIR}/_ext/1360907413/usb_host_bluetooth.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360907413/usb_host_bluetooth.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360907413/usb_host_bluetooth.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../main.c  -o ${OBJECTDIR}/_ext/1472/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/main.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/usb_config.o: ../usb_config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/usb_config.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/usb_config.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../usb_config.c  -o ${OBJECTDIR}/_ext/1472/usb_config.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/usb_config.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/usb_config.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/xprintf.o: ../xprintf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/xprintf.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/xprintf.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../xprintf.c  -o ${OBJECTDIR}/_ext/1472/xprintf.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/xprintf.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/xprintf.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/flash.o: ../flash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/flash.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/flash.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../flash.c  -o ${OBJECTDIR}/_ext/1472/flash.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/flash.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/flash.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/dev_dragonrise.o: ../dev_dragonrise.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/dev_dragonrise.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/dev_dragonrise.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../dev_dragonrise.c  -o ${OBJECTDIR}/_ext/1472/dev_dragonrise.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/dev_dragonrise.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/dev_dragonrise.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/dev_elecom_u3312s.o: ../dev_elecom_u3312s.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/dev_elecom_u3312s.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/dev_elecom_u3312s.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../dev_elecom_u3312s.c  -o ${OBJECTDIR}/_ext/1472/dev_elecom_u3312s.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/dev_elecom_u3312s.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/dev_elecom_u3312s.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/dev_elecom_u3412s.o: ../dev_elecom_u3412s.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/dev_elecom_u3412s.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/dev_elecom_u3412s.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../dev_elecom_u3412s.c  -o ${OBJECTDIR}/_ext/1472/dev_elecom_u3412s.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/dev_elecom_u3412s.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/dev_elecom_u3412s.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/dev_logicool_f710.o: ../dev_logicool_f710.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/dev_logicool_f710.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/dev_logicool_f710.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../dev_logicool_f710.c  -o ${OBJECTDIR}/_ext/1472/dev_logicool_f710.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/dev_logicool_f710.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/dev_logicool_f710.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/dev_sony_ps3.o: ../dev_sony_ps3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/dev_sony_ps3.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/dev_sony_ps3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../dev_sony_ps3.c  -o ${OBJECTDIR}/_ext/1472/dev_sony_ps3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/dev_sony_ps3.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/dev_sony_ps3.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/dev_logicool_f510.o: ../dev_logicool_f510.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/dev_logicool_f510.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/dev_logicool_f510.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../dev_logicool_f510.c  -o ${OBJECTDIR}/_ext/1472/dev_logicool_f510.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/dev_logicool_f510.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/dev_logicool_f510.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/TimeDelay.o: ../TimeDelay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/TimeDelay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/TimeDelay.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../TimeDelay.c  -o ${OBJECTDIR}/_ext/1472/TimeDelay.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/TimeDelay.o.d"        -g -omf=elf -O1 -I".." -I"../Common" -I"../fatfs" -I"../USB" -I"../btstack" -msmart-io=0 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/TimeDelay.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
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
dist/${CND_CONF}/${IMAGE_TYPE}/sbxbt_ps3.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/sbxbt_ps3.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf  -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--heap=2048,--stack=1024,--check-sections,--data-init,--pack-data,--handles,--isr,--gc-sections,--fill-upper=0,--stackguard=16,--library-path="..",--no-force-link,--smart-io,-Map="${DISTDIR}/sbxbt_ps3.X.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/sbxbt_ps3.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/sbxbt_ps3.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -Wl,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--heap=2048,--stack=1024,--check-sections,--data-init,--pack-data,--handles,--isr,--gc-sections,--fill-upper=0,--stackguard=16,--library-path="..",--no-force-link,--smart-io,-Map="${DISTDIR}/sbxbt_ps3.X.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/sbxbt_ps3.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
