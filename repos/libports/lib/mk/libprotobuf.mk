LIBPROTOBUF_DIR := $(call select_from_ports,libprotobuf)/src/lib/libprotobuf

libprotobuf_files = $(LIBPROTOBUF_DIR)/src/google/protobuf/any.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/any.pb.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/api.pb.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/compiler/importer.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/compiler/parser.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/descriptor.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/descriptor.pb.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/descriptor_database.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/duration.pb.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/dynamic_message.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/empty.pb.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/extension_set_heavy.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/field_mask.pb.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/generated_message_reflection.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/io/gzip_stream.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/io/printer.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/io/strtod.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/io/tokenizer.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/io/zero_copy_stream_impl.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/map_field.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/message.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/reflection_ops.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/service.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/source_context.pb.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/struct.pb.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/stubs/mathlimits.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/stubs/substitute.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/text_format.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/timestamp.pb.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/type.pb.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/unknown_field_set.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/util/field_comparator.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/util/field_mask_util.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/util/internal/datapiece.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/util/internal/default_value_objectwriter.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/util/internal/error_listener.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/util/internal/field_mask_utility.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/util/internal/json_escaping.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/util/internal/json_objectwriter.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/util/internal/json_stream_parser.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/util/internal/object_writer.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/util/internal/proto_writer.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/util/internal/protostream_objectsource.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/util/internal/protostream_objectwriter.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/util/internal/type_info.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/util/internal/type_info_test_helper.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/util/internal/utility.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/util/json_util.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/util/message_differencer.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/util/time_util.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/util/type_resolver_util.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/wire_format.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/wrappers.pb.cc

libprotobuf_lite_files = $(LIBPROTOBUF_DIR)/src/google/protobuf/arena.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/arenastring.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/extension_set.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/generated_message_util.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/io/coded_stream.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/io/zero_copy_stream.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/io/zero_copy_stream_impl_lite.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/message_lite.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/repeated_field.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/stubs/atomicops_internals_x86_gcc.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/stubs/atomicops_internals_x86_msvc.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/stubs/bytestream.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/stubs/common.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/stubs/int128.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/stubs/once.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/stubs/status.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/stubs/statusor.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/stubs/stringpiece.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/stubs/stringprintf.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/stubs/structurally_valid.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/stubs/strutil.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/stubs/time.cc \
$(LIBPROTOBUF_DIR)/src/google/protobuf/wire_format_lite.cc

SRC_CC = $(libprotobuf_lite_files) $(libprotobuf_files)

INC_DIR += $(LIBPROTOBUF_DIR)/src

LIBS += stdcxx pthread

CXX_DEF += -DHAVE_PTHREAD -DGOOGLE_PROTOBUF_NO_THREADLOCAL # disable tls

CC_WARN = -Wno-sign-compare

SHARED_LIB = yes
