#############################################################################
#
# Generic Makefile for C/C++ Program
#
# Author:  yun63<thewardsthe@mail.com>
#
#############################################################################

include ../define.mk

ROOT=$(shell pwd)

## DEBUG开关选项
DEBUG	:= 1

## 头文件搜索路径 
INCPATH ?= -I. -I$(GTEST_DIR)/include -I../protobuf/include

## 源代码目录
SRCDIRS ?= utils pb

## 生成目标目录
OBJ_DIR = object.dir

## 可执行程序目录
BIN = bin

## 测试代码目录
TEST_DIR = test

## GTest测试框架目录
GTEST_DIR := ../3rd/gtest-1.7.0
GTEST_HEADERS := $(GTEST_DIR)/include/gtest/*.h \
				$(GTEST_DIR)/include/gtest/internal/*.h 
GTEST_SRCS_ := $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./protobuf/lib/

## 可执行文件名称
TARGETS ?= cloud add_person list_people

CPPFLAGS += -isystem $(GTEST_DIR)/include

SOURCES := \
	$(foreach e, $(addprefix *, $(SRCEXTS)), $(wildcard $(e))) \
	$(foreach d, $(SRCDIRS), $(wildcard $(addprefix $(d)/*, $(SRCEXTS)))) 

ifeq ($(DEBUG), 1)
	CFLAGS += -g
	CXXFLAGS += -g
else
	CFLAGS += -O2
	CXXFLAGS += -O2
endif

#$(warning $(SOURCES))

OBJECTS := $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(SOURCES))))

PROTO_INC := $(patsubst %.proto, %.pb.h,  $(wildcard pb/*.proto))
PROTO_CXX := $(patsubst %.proto, %.pb.cc, $(wildcard pb/*.proto))
PROTO_OBJS := $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(PROTO_CXX))))


## 库文件
LIBS = -L/usr/local/lib \
	   -L../lib -lgtest -lgtest_main \
	   -L../protobuf/lib -lprotobuf \
	   -lpthread -lz -lm

LINK := $(CXX) $(CXXFLAGS) $(LDFLAGS)

.PHONY: deps gtest protobuf clean 

.SUFFIXES:

all: pb libcommon.a

## 生成所有(.o)文件规则.
#----------------------------------------
$(OBJ_DIR)/%.o:%.c
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(MYCFLAGS) $(INCPATH) -c $< -o $@

$(OBJ_DIR)/%.o:%.cc
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(MYCFLAGS) $(INCPATH) -c $< -o $@

$(OBJ_DIR)/%.o:%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(MYCFLAGS) $(INCPATH) -c $< -o $@

$(OBJ_DIR)/%.o:%.cxx
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(MYCFLAGS) $(INCPATH) -c $< -o $@

%.o:%.c
	$(CXX) $(CXXFLAGS) $(MYCFLAGS) $(INCPATH) -c $< -o $@

%.o:%.cpp 
	$(CXX) $(CXXFLAGS) $(MYCFLAGS) $(INCPATH) -c $< -o $@

%.o:%.cc
	$(CXX) $(CXXFLAGS) $(MYCFLAGS) $(INCPATH) -c $< -o $@

%.pb.cc: %.proto
	../protobuf/bin/protoc -I=pb/ --cpp_out=pb/ $<

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

lib/libgtest.so : $(GTEST_DIR)/src/gtest-all.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -fPIC --shared $^ -o $@ -I$(GTEST_DIR) -lpthread

lib/libgtest_main.so : $(GTEST_DIR)/src/gtest-all.cc $(GTEST_DIR)/src/gtest_main.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -fPIC --shared $^ -o $@ -I$(GTEST_DIR) -lpthread

libcommon.a : $(OBJECTS) $(PROTO_OBJS)
	$(AR) $(ARFLAGS) $@ $^

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
