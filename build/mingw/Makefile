# phony
.PHONY: all clean

# global utils
ECHO = @echo
MKDIR_P = mkdir -p
RM_RF = rm -rf

# global objects path (please, DO NOT use "./" in path, f.e "./obj/app", but use ONLY "obj/app")
OBJ_PATH = obj
LIB_PATH = lib

# app compiling
APP_CXX      = g++
APP_CXXFLAGS = -g -Wall -std=c++17
APP_DEFINES  =
APP_INCLUDES = -I ./deps/qt/include
# app linking
APP_LD        = g++
APP_LDFLAGS   = -mwindows -mconsole
APP_LIBRARIES = -L ./deps/qt/lib -l Qt6Core -l Qt6Gui -l Qt6Widgets
# app qt mocing
APP_MOC = moc
# targets
APP_TARGET_PATH = .
APP_TARGET_NAME = $(APP_TARGET_PATH)/main.exe
# app sources
APP_SOURCES_PATH = app
APP_SOURCES    := $(wildcard $(APP_SOURCES_PATH)/*.cpp)
APP_HEADERS    := $(wildcard $(APP_SOURCES_PATH)/*.hpp)
APP_SOURCES_QT := $(wildcard $(APP_SOURCES_PATH)/widgets/*.cpp)
APP_HEADERS_QT := $(wildcard $(APP_SOURCES_PATH)/widgets/*.hpp)
# app objects
APP_SOURCES_OBJ        := $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(APP_SOURCES)))
APP_SOURCES_QT_OBJ     := $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(APP_SOURCES_QT)))
APP_HEADERS_QT_MOC_OBJ := $(foreach file,$(APP_HEADERS_QT),$(OBJ_PATH)/$(dir $(file))moc_$(notdir $(file)).cpp.o)

# create app
all: $(APP_TARGET_NAME)

# link application
$(APP_TARGET_NAME): $(APP_SOURCES_OBJ) $(APP_SOURCES_QT_OBJ) $(APP_HEADERS_QT_MOC_OBJ)
	$(MKDIR_P) $(@D)
	$(APP_LD) $(APP_LDFLAGS) $^ $(APP_LIBRARIES) -o $@

# compile source code
$(APP_SOURCES_OBJ): $(APP_SOURCES) $(APP_HEADERS) $(APP_HEADERS_QT)
	$(MKDIR_P) $(@D)
	$(APP_CXX) $(APP_CXXFLAGS) $(APP_INCLUDES) $(APP_DEFINES) -c $(@:$(OBJ_PATH)/%.o=%) -o $@

# compile qt source code
$(APP_SOURCES_QT_OBJ): $(APP_SOURCES_QT) $(APP_HEADERS) $(APP_HEADERS_QT)
	$(MKDIR_P) $(@D)
	$(APP_CXX) $(APP_CXXFLAGS) $(APP_INCLUDES) $(APP_DEFINES) -c $(@:$(OBJ_PATH)/%.o=%) -o $@

# compile qt moc source code
$(APP_HEADERS_QT_MOC_OBJ): $(APP_HEADERS_QT)
	$(MKDIR_P) $(@D)
	$(APP_MOC) $(@D:$(OBJ_PATH)/%=%)/$(@F:moc_%.cpp.o=%) -o $(@:%.o=%)
	$(APP_CXX) $(APP_CXXFLAGS) $(APP_INCLUDES) $(APP_DEFINES) -c $(@:%.o=%) -o $@

# clean all
clean:
	$(RM_RF) $(APP_TARGET_NAME)
	$(RM_RF) $(OBJ_PATH)
	$(RM_RF) $(LIB_PATH)