MOSQUITTO_PORT_DIR := $(call select_from_ports,mosquitto)/src/lib/mosquitto

SRC_C_lib = logging_mosq.c logging_mosq.h \
	memory_mosq.c memory_mosq.h \
	messages_mosq.c messages_mosq.h \
	mosquitto.c mosquitto.h \
	mosquitto_internal.h \
	mqtt3_protocol.h \
	net_mosq.c net_mosq.h \
	read_handle.c read_handle.h \
	read_handle_client.c \
	read_handle_shared.c \
	send_client_mosq.c \
	send_mosq.c send_mosq.h \
	socks_mosq.c \
	srv_mosq.c \
	thread_mosq.c \
	time_mosq.c \
	tls_mosq.c \
	util_mosq.c util_mosq.h

SRC_C    = $(addprefix $(MOSQUITTO_PORT_DIR)/lib/, $(SRC_C_lib))

vpath %.c $(MOSQUITTO_PORT_DIR)/src/lib

INC_DIR += $(MOSQUITTO_PORT_DIR)

LIBS += libc

SHARED_LIB = yes
