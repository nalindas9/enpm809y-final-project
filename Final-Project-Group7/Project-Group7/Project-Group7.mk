##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Project-Group7
ConfigurationName      :=Debug
WorkspacePath          :="/home/raghav/Desktop/ENPM809Y Final Project/enpm809y-final-project/Final-Project-Group7"
ProjectPath            :="/home/raghav/Desktop/ENPM809Y Final Project/enpm809y-final-project/Final-Project-Group7/Project-Group7"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Raghav
Date                   :=28/11/19
CodeLitePath           :=/home/raghav/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Project-Group7.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_API_API.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_LandBasedTracked_LandBasedTracked.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_LandBasedRobot_LandBasedRobot.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_LandBasedWheeled_LandBasedWheeled.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_API_API.cpp$(ObjectSuffix): src/API/API.cpp $(IntermediateDirectory)/src_API_API.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/raghav/Desktop/ENPM809Y Final Project/enpm809y-final-project/Final-Project-Group7/Project-Group7/src/API/API.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_API_API.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_API_API.cpp$(DependSuffix): src/API/API.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_API_API.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_API_API.cpp$(DependSuffix) -MM src/API/API.cpp

$(IntermediateDirectory)/src_API_API.cpp$(PreprocessSuffix): src/API/API.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_API_API.cpp$(PreprocessSuffix) src/API/API.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/raghav/Desktop/ENPM809Y Final Project/enpm809y-final-project/Final-Project-Group7/Project-Group7/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/src_LandBasedTracked_LandBasedTracked.cpp$(ObjectSuffix): src/LandBasedTracked/LandBasedTracked.cpp $(IntermediateDirectory)/src_LandBasedTracked_LandBasedTracked.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/raghav/Desktop/ENPM809Y Final Project/enpm809y-final-project/Final-Project-Group7/Project-Group7/src/LandBasedTracked/LandBasedTracked.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_LandBasedTracked_LandBasedTracked.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_LandBasedTracked_LandBasedTracked.cpp$(DependSuffix): src/LandBasedTracked/LandBasedTracked.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_LandBasedTracked_LandBasedTracked.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_LandBasedTracked_LandBasedTracked.cpp$(DependSuffix) -MM src/LandBasedTracked/LandBasedTracked.cpp

$(IntermediateDirectory)/src_LandBasedTracked_LandBasedTracked.cpp$(PreprocessSuffix): src/LandBasedTracked/LandBasedTracked.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_LandBasedTracked_LandBasedTracked.cpp$(PreprocessSuffix) src/LandBasedTracked/LandBasedTracked.cpp

$(IntermediateDirectory)/src_LandBasedRobot_LandBasedRobot.cpp$(ObjectSuffix): src/LandBasedRobot/LandBasedRobot.cpp $(IntermediateDirectory)/src_LandBasedRobot_LandBasedRobot.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/raghav/Desktop/ENPM809Y Final Project/enpm809y-final-project/Final-Project-Group7/Project-Group7/src/LandBasedRobot/LandBasedRobot.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_LandBasedRobot_LandBasedRobot.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_LandBasedRobot_LandBasedRobot.cpp$(DependSuffix): src/LandBasedRobot/LandBasedRobot.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_LandBasedRobot_LandBasedRobot.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_LandBasedRobot_LandBasedRobot.cpp$(DependSuffix) -MM src/LandBasedRobot/LandBasedRobot.cpp

$(IntermediateDirectory)/src_LandBasedRobot_LandBasedRobot.cpp$(PreprocessSuffix): src/LandBasedRobot/LandBasedRobot.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_LandBasedRobot_LandBasedRobot.cpp$(PreprocessSuffix) src/LandBasedRobot/LandBasedRobot.cpp

$(IntermediateDirectory)/src_LandBasedWheeled_LandBasedWheeled.cpp$(ObjectSuffix): src/LandBasedWheeled/LandBasedWheeled.cpp $(IntermediateDirectory)/src_LandBasedWheeled_LandBasedWheeled.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/raghav/Desktop/ENPM809Y Final Project/enpm809y-final-project/Final-Project-Group7/Project-Group7/src/LandBasedWheeled/LandBasedWheeled.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_LandBasedWheeled_LandBasedWheeled.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_LandBasedWheeled_LandBasedWheeled.cpp$(DependSuffix): src/LandBasedWheeled/LandBasedWheeled.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_LandBasedWheeled_LandBasedWheeled.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_LandBasedWheeled_LandBasedWheeled.cpp$(DependSuffix) -MM src/LandBasedWheeled/LandBasedWheeled.cpp

$(IntermediateDirectory)/src_LandBasedWheeled_LandBasedWheeled.cpp$(PreprocessSuffix): src/LandBasedWheeled/LandBasedWheeled.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_LandBasedWheeled_LandBasedWheeled.cpp$(PreprocessSuffix) src/LandBasedWheeled/LandBasedWheeled.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


