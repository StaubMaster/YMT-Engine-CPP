


################################################################
#                           OS Stuff                           #
################################################################

ifeq ($(OS), Windows_NT)
	CheckOS := Windows
else
	CheckOS := $(shell uname -s)
endif

FANCY_NAME := YMT

ifeq ($(CheckOS), Windows)

FANCY_ECHO := echo -e
COLOR_REPO := \e[38;2;127;127;127m
COLOR_TYPE := \e[38;2;127;255;127m
COLOR_FILE := \e[38;2;127;127;255m
COLOR_NONE := \e[m

endif

ifeq ($(CheckOS), Darwin)

FANCY_ECHO := echo
COLOR_REPO := \033[38;2;127;127;127m
COLOR_TYPE := \033[38;2;127;255;127m
COLOR_FILE := \033[38;2;127;127;255m
COLOR_NONE := \033[m

endif

################################################################





NAME := Engine.a
COMPILER := c++ -std=c++11
FLAGS := -Wall -Wextra -Werror -D ENGINE_DIR='"$(shell pwd)"'



FILES_SRC := \
\
	DataStruct/Point3D.cpp \
	DataStruct/Angle3D.cpp \
	DataStruct/Trans3D.cpp \
	DataStruct/Undex3D.cpp \
	DataStruct/AxisBox3D.cpp \
	DataStruct/Point2D.cpp \
	DataStruct/SizeRatio2D.cpp \
	DataStruct/Range.cpp \
	DataStruct/LInter.cpp \
	DataStruct/DepthFactors.cpp \
	DataStruct/Point4D.cpp \
	DataStruct/Color.cpp \
	DataStruct/Depth.cpp \
	DataStruct/LightBase.cpp \
	DataStruct/LightSolar.cpp \
	DataStruct/LightSpot.cpp \
	DataStruct/Ray3D.cpp \
	DataStruct/Matrix3x3.cpp \
	DataO.cpp \
\
	Graphics/Shader/ShaderCode.cpp \
	Graphics/Shader/BaseShader.cpp \
\
	Graphics/Uniform/Base/UniformBase.cpp \
	Graphics/Uniform/Base/FloatN.cpp \
	Graphics/Uniform/Base/Float1.cpp \
	Graphics/Uniform/Base/Float2.cpp \
	Graphics/Uniform/Base/Float3.cpp \
	Graphics/Uniform/Base/UIntN.cpp \
	Graphics/Uniform/Base/UInt1.cpp \
\
	Graphics/Uniform/Data/Point3D.cpp \
	Graphics/Uniform/Data/Angle3D.cpp \
	Graphics/Uniform/Data/Trans3D.cpp \
	Graphics/Uniform/Data/Point2D.cpp \
	Graphics/Uniform/Data/SizeRatio2D.cpp \
	Graphics/Uniform/Data/DepthFactors.cpp \
	Graphics/Uniform/Data/Range.cpp \
	Graphics/Uniform/Data/Depth.cpp \
	Graphics/Uniform/Data/LInter.cpp \
	Graphics/Uniform/Data/Color.cpp \
	Graphics/Uniform/Data/LightBase.cpp \
	Graphics/Uniform/Data/LightSolar.cpp \
	Graphics/Uniform/Data/LightSpot.cpp \
\
	Graphics/Multiform/Base/MultiformBase.cpp \
	Graphics/Multiform/Data/Trans3D.cpp \
	Graphics/Multiform/Data/SizeRatio2D.cpp \
	Graphics/Multiform/Data/DepthFactors.cpp \
	Graphics/Multiform/Data/Range.cpp \
	Graphics/Multiform/Data/Depth.cpp \
	Graphics/Multiform/Data/LInter.cpp \
	Graphics/Multiform/Data/Color.cpp \
\
	Graphics/Buffer/BaseBufferArray.cpp \
	Graphics/Buffer/BaseBuffer.cpp \
\
	Graphics/Attribute/Base/AttributeLocation.cpp \
	Graphics/Attribute/Base/AttributeBase.cpp \
	Graphics/Attribute/Base/FloatN.cpp \
\
	Graphics/Attribute/Data/Point3D.cpp \
	Graphics/Attribute/Data/Angle3D.cpp \
	Graphics/Attribute/Data/Trans3D.cpp \
	Graphics/Attribute/Data/Point2D.cpp \
	Graphics/Attribute/Data/Point4D.cpp \
	Graphics/Attribute/Data/Color.cpp \
\
	Graphics/Texture/TextureBase.cpp \
	Graphics/Texture/Texture2DArray.cpp \
	Graphics/Texture/TextureGen.cpp \
\
	DataStruct/Main/PolyHedra/PolyHedra_MainData.cpp \
	DataStruct/Main/PolyHedra/PolyHedra_MainAttrib.cpp \
	DataStruct/Main/PolyHedra/PolyHedra_MainBuffer.cpp \
	DataStruct/Full/PolyHedra_3D/PolyHedra_3D_BufferArray.cpp \
	DataStruct/Full/PolyHedra_3D/PolyHedra_3D_Instances.cpp \
	DataStruct/Full/PolyHedra_3D/PolyHedra_3D_Shader.cpp \
\
	DataStruct/Inst/Simple3D/Simple3D_InstData.cpp \
	DataStruct/Inst/Simple3D/Simple3D_InstAttrib.cpp \
	DataStruct/Inst/Simple3D/Simple3D_InstBuffer.cpp \
\
	DataStruct/Inst/Physics3D/Physics3D_InstData.cpp \
	DataStruct/Inst/Physics3D/Physics3D_InstAttrib.cpp \
	DataStruct/Inst/Physics3D/Physics3D_InstBuffer.cpp \
\
	DataStruct/Main/Waveform/OBJ.cpp \
	DataStruct/Main/Waveform/OBJ_Main.cpp \
	DataStruct/Main/Waveform/OBJ_3D_BufferArray.cpp \
	DataStruct/Main/Waveform/OBJ_3D_Shader.cpp \
	DataStruct/Main/Waveform/MTL.cpp \
\
	PolyHedra/PolyHedraData.cpp \
	PolyHedra/PolyHedra.cpp \
	PolyHedra/PolyHedra_Load.cpp \
\
	PolyHedra/Skin/SkinBase.cpp \
	PolyHedra/Skin/Skin2DA.cpp \
	PolyHedra/Skin/Skin2D_Data.cpp \
\
	TimeMeasure.cpp \
	Keys.cpp \
	Window.cpp \
	Debug.cpp

FILES_OBJ := $(FILES_SRC:.cpp=.o)

DIR_SRC := src/
DIR_OBJ := obj/

FILES_ABS_OBJ := $(addprefix $(DIR_OBJ)/, $(FILES_OBJ))
WORKING_FILES_ABS_OBJ := $(addprefix $(DIR_OBJ)/, $(WORKING_FILES_OBJ))





################################################################
#                  Standard Makefile Commands                  #
################################################################

$(NAME) : repos $(FILES_ABS_OBJ)
	@$(FANCY_ECHO) "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@ar -rcs $(NAME) $(FILES_ABS_OBJ)

all: repos
	@$(FANCY_ECHO) "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(MAKE) -s $(REPOS)
	@$(MAKE) -s $(FILES_ABS_OBJ)
	@$(MAKE) -s $(NAME)

clean:
	@$(FANCY_ECHO) "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@rm -f $(FILES_ABS_OBJ)

fclean:
	@$(FANCY_ECHO) "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(MAKE) -s clean
	@rm -f $(NAME)

re:
	@$(FANCY_ECHO) "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(MAKE) -s fclean
	@$(MAKE) -s all

.PHONY: all clean fclean re

################################################################





$(DIR_OBJ)/%.o : $(DIR_SRC)/%.cpp
	@$(FANCY_ECHO) "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Compiling: $(COLOR_FILE)$@$(COLOR_NONE)"
	@mkdir -p $(dir $@)
	@$(COMPILER) $(FLAGS) $(ARGS_INCLUDES) -c $< -o $@





################################################################
#                     Environment Variables                    #
################################################################

LIBRARYS = $(NAME)
INCLUDES = include/

ARGS_LIBRARYS = $(foreach library,$(LIBRARYS),$(library))
ARGS_INCLUDES = $(foreach include,$(INCLUDES),-I$(include))

librarys: repos_clone
	@echo $(LIBRARYS)

includes: repos_clone
	@echo $(INCLUDES)

.PHONY: librarys includes

################################################################





################################################################
#                 Interaction with Repositorys                 #
################################################################

REPOS_DIR := other/
REPOS = 

repos: repos_clone
#	$(FANCY_ECHO) "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
#	@$(FANCY_ECHO) "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Compiling: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(foreach repo, $(REPOS), \
		$(MAKE) -C $(repo) -s ; \
	)

repos_all: repos_clone
#	@$(FANCY_ECHO) "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(foreach repo, $(REPOS), \
		$(MAKE) -C $(repo) -s all ; \
	)

repos_clean:
#	@$(FANCY_ECHO) "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(foreach repo, $(REPOS), \
		if [ -d $(repo) ] ; then \
			$(MAKE) -C $(repo) -s clean ; \
		fi ; \
	)

repos_fclean:
#	@$(FANCY_ECHO) "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(foreach repo, $(REPOS), \
		if [ -d $(repo) ] ; then \
			$(MAKE) -C $(repo) -s fclean ; \
		fi ; \
	)

repos_clone:
#	$(FANCY_ECHO) "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(foreach repo, $(REPOS), \
		$(MAKE) $(repo)_clone -s ; \
	)

repos_rm:
#	@$(FANCY_ECHO) "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(foreach repo, $(REPOS), \
		$(MAKE) $(repo)_rm -s ; \
	)
#	@rm -rf $(REPOS)

.PHONY: repos repos_all repos_clean repos_fclean repos_clone repos_rm

################################################################





################################################################
#                            OpenGL                            #
################################################################

OPENGL_REPO := $(REPOS_DIR)/OpenGL

REPOS += $(OPENGL_REPO)
LIBRARYS += $(foreach library, $(shell $(MAKE) -C $(OPENGL_REPO) -s librarys), $(OPENGL_REPO)/$(library))
INCLUDES += $(foreach include, $(shell $(MAKE) -C $(OPENGL_REPO) -s includes), $(OPENGL_REPO)/$(include))

$(OPENGL_REPO)_clone : ;

$(OPENGL_REPO)_rm : ;

################################################################





################################################################
#                         File Manager                         #
################################################################

FM_HTTPS := https://github.com/StaubMaster/CPP-FileManager.git
FM_REPO := $(REPOS_DIR)/FileManager

REPOS += $(FM_REPO)
LIBRARYS += $(foreach library, $(shell $(MAKE) -C $(FM_REPO) -s librarys), $(FM_REPO)/$(library))
INCLUDES += $(foreach include, $(shell $(MAKE) -C $(FM_REPO) -s includes), $(FM_REPO)/$(include))

$(FM_REPO)_clone :
	@if ! [ -d $(FM_REPO) ] ; then \
		git clone $(FM_HTTPS) $(FM_REPO) -q ; \
	fi

$(FM_REPO)_rm :
	@rm -rf $(FM_REPO)

################################################################


