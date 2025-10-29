


FANCY_NAME := YMT
COLOR_REPO := \e[38;2;127;127;127m
COLOR_TYPE := \e[38;2;127;255;127m
COLOR_FILE := \e[38;2;127;127;255m
COLOR_NONE := \e[m



NAME := YMT.a
COMPILER := c++ -std=c++11
FLAGS := -Wall -Wextra -Werror



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
	DataO.cpp \
\
	Graphics/Shader/ShaderCode.cpp \
	Graphics/Shader/BaseShader.cpp \
\
	Graphics/Uniform/Base/UniformBase.cpp \
	Graphics/Uniform/Data/Float1.cpp \
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
	Graphics/Attribute/Data/Point3D.cpp \
	Graphics/Attribute/Data/Angle3D.cpp \
	Graphics/Attribute/Data/Trans3D.cpp \
	Graphics/Attribute/Data/Point2D.cpp \
	Graphics/Attribute/Data/Point4D.cpp \
	Graphics/Attribute/Data/Color.cpp \
	Graphics/Attribute/Data/Float1.cpp \
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
	TimeMeasure.cpp \
	Window.cpp

WORKING_FILES_SRC := \
	Texture/TextureBase.cpp \
	Texture/Texture2DArray.cpp \
	Texture/TextureGen.cpp \
\
	PolyHedra/PolyHedraData.cpp \
	PolyHedra/PolyHedra.cpp \
	PolyHedra/PolyHedra_Load.cpp \
\
	PolyHedra/Skin/SkinBase.cpp \
	PolyHedra/Skin/Skin2DA.cpp \
	PolyHedra/Skin/Skin2D_Data.cpp \

WORKING_FILES_OBJ := $(WORKING_FILES_SRC:.cpp=.o)

FILES_SRC += $(WORKING_FILES_SRC)

FILES_OBJ := $(FILES_SRC:.cpp=.o)

DIR_SRC := src/
DIR_OBJ := obj/

FILES_ABS_OBJ := $(addprefix $(DIR_OBJ)/, $(FILES_OBJ))
WORKING_FILES_ABS_OBJ := $(addprefix $(DIR_OBJ)/, $(WORKING_FILES_OBJ))





################################################################
#                  Standard Makefile Commands                  #
################################################################

$(NAME) : repos $(FILES_ABS_OBJ)
	@echo -e "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@ar -rcs $(NAME) $(FILES_ABS_OBJ)

work:
	@echo -e "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@rm -f $(WORKING_FILES_ABS_OBJ)
	@$(MAKE) $(WORKING_FILES_ABS_OBJ)
	@$(MAKE) $(NAME)

all: repos_all
	@echo -e "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(MAKE) $(REPOS)
	@$(MAKE) $(FILES_ABS_OBJ)
	@$(MAKE) $(NAME)

clean: repos_clean
	@echo -e "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@rm -f $(FILES_ABS_OBJ)

fclean: repos_fclean
	@echo -e "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(MAKE) clean
	@rm -f $(NAME)

re:
	@echo -e "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re

################################################################





$(DIR_OBJ)/%.o : $(DIR_SRC)/%.cpp
	@echo -e "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Compiling: $(COLOR_FILE)$@$(COLOR_NONE)"
	@mkdir -p $(dir $@)
	@$(COMPILER) $(FLAGS) $(ARGS_INCLUDES) -c $< -o $@





################################################################
#                     Environment Variables                    #
################################################################

LIBRARYS = $(NAME)
INCLUDES = include/

ARGS_LIBRARYS = $(foreach library, $(LIBRARYS), $(library))
ARGS_INCLUDES = $(foreach include, $(INCLUDES), -I$(include))

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
#	echo -e "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@echo -e "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Compiling: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(foreach repo, $(REPOS), \
		$(MAKE) -C $(repo) ; \
	)

repos_all: repos_clone
#	@echo -e "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(foreach repo, $(REPOS), \
		$(MAKE) -C $(repo) all ; \
	)

repos_clean:
#	@echo -e "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(foreach repo, $(REPOS), \
		if [ -d $(repo) ] ; then \
			$(MAKE) -C $(repo) clean ; \
		fi ; \
	)

repos_fclean:
#	@echo -e "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(foreach repo, $(REPOS), \
		if [ -d $(repo) ] ; then \
			$(MAKE) -C $(repo) fclean ; \
		fi ; \
	)

repos_clone:
#	echo -e "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	$(foreach repo, $(REPOS), \
		$(MAKE) $(repo)_clone ; \
	)

repos_rm:
#	@echo -e "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
#	@rm -rf $(REPOS)
	@$(foreach repo, $(REPOS), \
		$(MAKE) $(repo)_rm ; \
	)

.PHONY: repos repos_all repos_clean repos_fclean repos_clone repos_rm

################################################################





################################################################
#                            OpenGL                            #
################################################################

OPENGL_REPO := $(REPOS_DIR)/OpenGL

REPOS += $(OPENGL_REPO)
LIBRARYS += $(OPENGL_REPO)/OpenGL.a
INCLUDES += $(OPENGL_REPO)/../

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
#		echo -e "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Cloning: $(COLOR_FILE)FileManager$(COLOR_NONE)"; \

$(FM_REPO)_rm :
	@rm -rf $(FM_REPO)

################################################################


