TARGET	= poe
PBDIR		= $(REP_DIR)/src/protobuf
SRC_CC	= main.cc $(PBDIR)/position.pb.cc $(PBDIR)/setup.pb.cc $(PBDIR)/state.pb.cc $(PBDIR)/vehicle.pb.cc
LIBS		= base libprotobuf stdcxx
