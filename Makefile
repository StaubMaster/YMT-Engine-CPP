


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
	PH/PolyHedra_MainData.cpp \
	PH/PolyHedra_MainAttrib.cpp \
	PH/PolyHedra_MainBuffer.cpp \
	PH/PH_3D/PolyHedra_3D_BufferArray.cpp \
	PH/PH_3D/PolyHedra_3D_Instances.cpp \
	PH/PH_3D/PolyHedra_3D_Shader.cpp \
\
	Simple3D/Simple3D_InstData.cpp \
	Simple3D/Simple3D_InstAttrib.cpp \
	Simple3D/Simple3D_InstBuffer.cpp \
\
	Physics3D/Physics3D_InstData.cpp \
	Physics3D/Physics3D_InstAttrib.cpp \
	Physics3D/Physics3D_InstBuffer.cpp \
\
	OBJ/OBJ.cpp \
	OBJ/OBJ_Main.cpp \
	OBJ/OBJ_3D_BufferArray.cpp \
	OBJ/OBJ_3D_Shader.cpp \
	OBJ/MTL.cpp \
\
	TextureArray.cpp \
	PolyHedra.cpp \
	PolyHedraData.cpp \
	TimeMeasure.cpp \
	Window.cpp

FILES_OBJ := $(FILES_SRC:.cpp=.o)

DIR_SRC := src
DIR_OBJ := obj

FILES_ABS_OBJ := $(addprefix $(DIR_OBJ)/, $(FILES_OBJ))





################################################################
#                  Standard Makefile Commands                  #
################################################################

$(NAME) : $(FILES_ABS_OBJ)
#	ar -x $(ARC_OPENGL) --output ./obj/arc
#	ar -x E:/Utility/glfw-3.4.bin.WIN64/lib-mingw-w64/libglfw3.a --output ./obj/arc
#	ar -rcs $(NAME) $(FILES_ABS_OBJ) $(ARC_X_DIR)*
#	ar -rcs $(NAME) $(FILES_ABS_OBJ) -lgdi32
	@echo "[ Compiling Archive ]" $@
	@ar -rcs $(NAME) $(FILES_ABS_OBJ)

all:
	@$(MAKE) $(ARCS)
	@$(MAKE) $(FILES_ABS_OBJ)
	@$(MAKE) $(NAME)

clean:
	@echo "[ Removing all Objects ]"
	@rm -f $(FILES_ABS_OBJ)
	rm -f $(ARC_X_DIR)/*

fclean:
	@$(MAKE) clean
	@echo "[ Removing Archive ]"
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re arc

################################################################





################################################################
#                     Environment Variables                    #
################################################################

#	right now the plan is to make it so the example Makefile
#	which acts as the "end project" should have as little hardcoded stuff as possible
#	right now it needs to know the Includes for FileManager
#	it does not currently know the .a of FileManager since thats compiled into .YMT
#	so the plan is to use EnvVars to tell the example Makefile what to include
#	this could also be used for the .a, so no more extracting
#	this could also be done recursivly
#	so YMT can ask the EnvVars of FileManager and OpenGL and assamble those together with its own

INCLUDES := include other

env_include:
	@echo $(INCLUDES)

args_include:
	$(eval INCLUDE_ARGS := $(foreach inc, $(INCLUDES), \
		-I$(inc) \
	))

test: args_include
	@echo $(INCLUDE_ARGS)

################################################################





$(DIR_OBJ)/%.o : $(DIR_SRC)/%.cpp args_include
#	should create FM_REPO if it dosent exist, currently dosent do that
	@mkdir -p $(dir $@)
	@echo "[ Compiling Object ]" $@
#	the lines are getting long so I added an echo here
	@$(COMPILER) $(FLAGS) $(INCLUDE_ARGS) -c $< -o $@





################################################################
#                 Interaction with Repositroys                 #
################################################################

ARCS := 
ARC_X_DIR := obj/arc

arc_all:
	$(foreach arc, $(ARCS), \
		$(MAKE) $(arc) \
	)

$(ARCS) :
	$(foreach arc, $(ARCS), \
		$(MAKE) $(arc) \
	)

#arc_ext:
#	@echo "[ Extracting Archives ]"
#	@mkdir -p $(ARC_X_DIR)
#	@cd $(ARC_X_DIR) && $(foreach arc, $(ARCS), \
#		ar -x ../../$(arc) \
#	)

################################################################





################################################################
#                 Interaction with Repositroys                 #
################################################################

REPO_DIR := other
REPOS := 

#	clean on all other repos
rclean:
	@echo "[ CLeaning Repos ]"
	@$(foreach repo, $(REPOS), \
		$(MAKE) -C $(repo) clean \
	)

#	fclean on all other repos
rfclean:
	@echo "[ FCLeaning Repos ]"
	@$(foreach repo, $(REPOS), \
		$(MAKE) -C $(repo) fclean \
	)

#	remove directory of repos
rrm:
	@echo "[ Removing Repos ]"
	@rm -rf $(REPOS)


################################################################





################################################################
#                         File Manager                         #
################################################################

FM_HTTPS := https://github.com/StaubMaster/CPP-FileManager.git
FM_REPO := $(REPO_DIR)/FileManager
FM_ARC := $(FM_REPO)/FileManager.a

INCLUDES += $(FM_REPO)/include
REPOS += $(FM_REPO)
ARCS += $(FM_ARC)

$(FM_REPO) :
	git clone $(FM_HTTPS) $@

$(FM_ARC) : $(FM_REPO)
	$(MAKE) -C $(FM_REPO) all

################################################################


