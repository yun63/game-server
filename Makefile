#############################################################################
#
# Generic Makefile for C/C++ Program
#
# Author:  yun63<thewardsthe@mail.com>
#
#############################################################################

ROOT=$(shell pwd)

## DEBUG开关选项
DEBUG	:= 1

## 头文件搜索路径 
INCPATH ?= -I. -I$(GTEST_DIR)/include -I./protobuf/include

## 源代码目录
SRCDIRS ?= base base/utils src src/test 

## 生成目标目录
OBJ_DIR = object.dir

## 可执行程序目录
BIN = bin

## 测试代码目录
TEST_DIR = test

## GTest测试框架目录
GTEST_DIR := ./3rd/gtest-1.7.0
GTEST_HEADERS := $(GTEST_DIR)/include/gtest/*.h \
				$(GTEST_DIR)/include/gtest/internal/*.h 
GTEST_SRCS_ := $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

export LD_LIBRARY_PATH+=:./protobuf/lib/

## 可执行文件名称
TARGETS ?= cloud add_person list_people

## 源文件类型
SRCEXTS := .c .cc .cpp .cxx 
## 头文件类型
HDREXTS := .h .hh .hpp .hxx 


CPPFLAGS += -isystem $(GTEST_DIR)/include

## C/C++编译器编译选项
CFLAGS += -Wall -fPIC
CXXFLAGS += --std=c++11 -Wall -fPIC

## 自定义编译选项
MYCFLAGS = #-DENCODING_UTF8 -DCHARSET_SHOW_GBK 

## 指定C/C++编译器
CC := gcc
CXX := g++

ifeq ($(DEBUG), 1)
	CFLAGS += -g
	CXXFLAGS += -g
else
	CFLAGS += -O2
	CXXFLAGS += -O2
endif

SOURCES := $(foreach d,$(SRCDIRS),$(wildcard $(addprefix $(d)/*, $(SRCEXTS))))
HEADERS := $(foreach d,$(SRCDIRS),$(wildcard $(addprefix $(d)/*, $(HDREXTS))))

#$(warning $(SOURCES))
#$(warning $(HEADERS))

SRC_CXX := $(filter-out %.c,$(SOURCES))
OBJECTS := $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(SOURCES))))
#TEST_OBJS := $(addsuffix .o, $(basename $(TESTSRCS)))

PROTO_INC := $(patsubst %.proto, %.pb.h,  $(wildcard base/pb/*.proto))
PROTO_CXX := $(patsubst %.proto, %.pb.cc, $(wildcard base/pb/*.proto))
PROTO_OBJS := $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(PROTO_CXX))))


## 库文件
LIBS = -L/usr/local/lib \
	   -L./lib -lgtest -lgtest_main \
	   -L./protobuf/lib -lprotobuf \
	   -lpthread -lz -lm

COMPILE_C := $(CC) $(CFLAGS) $(MYCFLAGS) $(INCPATH)
COMPILE_CXX := $(CXX) $(CXXFLAGS) $(MYCFLAGS) $(INCPATH)

ifeq ($(SRC_CXX),)
	LINK := $(CC) $(CFLAGS) $(LDFLAGS) $(MYCFLAGS)
else
	LINK := $(CXX) $(CXXFLAGS) $(LDFLAGS) $(MYCFLAGS)
endif


.PHONY: deps gtest protobuf clean 

.SUFFIXES:

all: pb $(addprefix $(BIN)/, $(TARGETS))

## 生成所有(.o)文件规则.
#----------------------------------------
$(OBJ_DIR)/%.o:%.c
	@mkdir -p $(@D)
	$(COMPILE_C) -c $< -o $@

$(OBJ_DIR)/%.o:%.cc
	@mkdir -p $(@D)
	$(COMPILE_CXX) -c $< -o $@

$(OBJ_DIR)/%.o:%.cpp
	@mkdir -p $(@D)
	$(COMPILE_CXX) -c $< -o $@

$(OBJ_DIR)/%.o:%.cxx
	@mkdir -p $(@D)
	$(COMPILE_CXX) -c $< -o $@

%.o:%.c
	$(COMPILE_C) -c $< -o $@

%.o:%.cpp
	$(COMPILE_CXX) -c $< -o $@

%.o:%.cc
	$(COMPILE_CXX) -c $< -o $@

%.pb.cc: %.proto
	./protobuf/bin/protoc -I=base/pb/ --cpp_out=base/pb/ $<

## 依赖
deps : gtest protobuf

gtest :
	(cd $(ROOT)/3rd/gtest-1.7.0 && mkdir -p build && \
	 cd build && cmake .. && make && \
	 cp -f libgtest.a libgtest_main.a $(ROOT)/lib)

protobuf :
	(cd $(ROOT)/3rd/protobuf-2.6.1 && \
	 ./configure --prefix=$(ROOT)/protobuf && \
	 make && make install)

## 生成目标
#-------------------------------------
pb : $(PROTO_CXX)

$(BIN)/cloud : test/test_main.o $(OBJECTS) 
	$(LINK) -o $@ $^ $(LIBS)

$(BIN)/add_person: test/add_person.o $(PROTO_OBJS)
	$(LINK) -o $@ $^ $(LIBS)

$(BIN)/list_people : test/list_people.o $(PROTO_OBJS)
	$(LINK) -o $@ $^ $(LIBS)

clean:
	-rm -f $(TEST_DIR)/*.o
	-rm -f *~ core *.core
	-rm -rf $(OBJ_DIR) 
	-rm -f $(TARGETS) 

#############################################################################
