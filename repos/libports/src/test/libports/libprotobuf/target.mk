TARGET 	= test-libprotobuf
LIBS	= libprotobuf stdcxx pthread
SRC_CC	= main.cc vehicle.pb.cc position.pb.cc

vpath main.cc $(PRG_DIR)
