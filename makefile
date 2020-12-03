SPEECHSDK_ROOT:=/change/to/point/extracted/SpeechSDK

TARGET_PLATFORM:=x86

CHECK_FOR_SPEECHSDK := $(shell test -f $(SPEECHSDK_ROOT)/lib/$(TARGET_PLATFORM)/libMicrosoft.CognitiveServices.Speech.core.so && echo Success)
ifneq ("$(CHECK_FOR_SPEECHSDK)","Success")
  $(error Please set SPEECHSDK_ROOT to point to your extracted Speech SDK, $$SPEECHSDK_ROOT/lib/$(TARGET_PLATFORM)/libMicrosoft.CognitiveServices.Speech.core.so should exist.)
endif

LIBPATH:=$(SPEECHSDK_ROOT)/lib/$(TARGET_PLATFORM)

INCPATH:=$(SPEECHSDK_ROOT)/include/cxx_api $(SPEECHSDK_ROOT)/include/c_api

LIBS:=-lMicrosoft.CognitiveServices.Speech.core -lpthread -l:libasound.so.2

all: blackjack

# Note: to run, LD_LIBRARY_PATH should point to $LIBPATH.
blackjack: Main.cpp models/*.cpp
	g++ $^ -o $@ \
	    --std=c++14 \
	    $(patsubst %,-I%, $(INCPATH)) \
	    $(patsubst %,-L%, $(LIBPATH)) \
	    $(LIBS)
