# Copyright (c) 2017, Pensando Systems Inc.

TOPDIR = ..
CAPTOPDIR = ../..
SKNOB = /home/asic/tools/src/0.25/


LCFLAGS = \
	-I$(CAPTOPDIR)/capri/model/cap_base \
	-I$(CAPTOPDIR)/../ip/verif/pcpp \
	-I$(CAPTOPDIR)/capri/model/utils \
	-I$(CAPTOPDIR)/capri/model/cap_dpa \
	-I$(CAPTOPDIR)/capri/model/cap_he \
	-I$(CAPTOPDIR)/capri/model/cap_intr \
	-I$(CAPTOPDIR)/capri/model/cap_mdma \
	-I$(CAPTOPDIR)/capri/model/cap_mpu \
	-I$(CAPTOPDIR)/capri/model/cap_npv \
	-I$(CAPTOPDIR)/capri/model/cap_pb \
	-I$(CAPTOPDIR)/capri/model/cap_pc \
	-I$(CAPTOPDIR)/capri/model/cap_pcie \
	-I$(CAPTOPDIR)/capri/model/cap_pic \
	-I$(CAPTOPDIR)/capri/model/cap_pip \
	-I$(CAPTOPDIR)/capri/model/cap_ppa \
	-I$(CAPTOPDIR)/capri/model/cap_prd \
	-I$(CAPTOPDIR)/capri/model/cap_psp \
	-I$(CAPTOPDIR)/capri/model/cap_ptd \
	-I$(CAPTOPDIR)/capri/model/cap_rxd \
	-I$(CAPTOPDIR)/capri/model/cap_sc \
	-I$(CAPTOPDIR)/capri/model/cap_sdp \
	-I$(CAPTOPDIR)/capri/model/cap_sema \
	-I$(CAPTOPDIR)/capri/model/cap_sg \
	-I$(CAPTOPDIR)/capri/model/cap_stg \
	-I$(CAPTOPDIR)/capri/model/cap_sw_phv \
	-I$(CAPTOPDIR)/capri/model/cap_tce \
	-I$(CAPTOPDIR)/capri/model/cap_te \
	-I$(CAPTOPDIR)/capri/model/cap_top \
	-I$(CAPTOPDIR)/capri/model/cap_txd \
	-I$(CAPTOPDIR)/capri/model/cap_txs \
	-I$(CAPTOPDIR)/capri/model/cap_wa \
	-I$(CAPTOPDIR)/ip/verif/pcpp \
	-I$(CAPTOPDIR)/capri/model/cap_he/readonly \
	-I$(SKNOB)/include \
	-I$(TOPDIR)/include \
	$(NULL)

PROGRAM = asicview

LDFLAGS = \
	/home/sborikar/asic/gen/capri/verif/common/manifest/libcommon_cc.so \
	/home/sborikar/asic/gen/capri/verif/common/manifest/libtop_csr_compile.so \
	/home/asic/tools/src/0.25/x86_64/lib64/libsknobs.so \
	$(NULL)

SYSTEM_LIBRARIES = -lreadline

LCXXFLAGS = $(LCFLAGS) -Wno-write-strings -g

SOURCES = \
	asicview.cc \
	regcmd.cc \
    cli.cc \
	$(NULL)

include $(TOPDIR)/make/Makefile.inc
