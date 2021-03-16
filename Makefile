#This Makefile is borrowed from one of stackoverflow answer at
#https://stackoverflow.com/questions/5178125/how-to-place-object-files-in-separate-subdirectory,
#and adapted to my use case.

#The comments to understand 'make' are derived from https://www.gnu.org/software/make/manual/make.html 

#Compiler and Linker
CC          := g++

#The Target Binary Program
TARGET      := unitTest

#The Directories, Source, Includes, Objects, Binary, and Resources
SRCDIR      := src
INCDIR      := inc
BUILDDIR    := obj
TARGETDIR   := bin
RESDIR      := res
SRCEXT      := cpp
DEPEXT      := d
OBJEXT      := o

#Flags, Libraries and Includes
#CFLAGS      := -fopenmp -Wall -O3 -g
#LIB         := -fopenmp -lm -larmadillo
#INC         := -I$(INCDIR) -I/usr/local/include
#INCDEP      := -I$(INCDIR)

# Linker options
# -L option indicates the directory for searching a library file
# -l option indicates a library file
# Sometimes one may have to specify the library location using -L option as below.  
#LIB         := -L/usr/local/lib -l:libgtest.a -l:libgtest_main.a -L/usr/lib/x86_64-linux-gnu -lpthread 
# For standard library paths like /usr/local/lib and /usr/lib -L option could be omitted

# gcc, by default, prefers to link to shared libraries(example abc.so), even if the corresponding
# archive(static library, example abc.a) exists. To tell gcc to prefer static library "-Wl, -Bstatic"
# option could be used or the static library could be explicity specified as "-l:libabc.a"
# The following is an example of using some of the libraries as static and some as dynamic.
# gcc -Wl,-Bstatic -lz -lfoo -Wl,-Bdynamic -lbar -Wl,--as-needed
# --as-needed will drop any unused dynamic library

# Gtest framework is used to test the features here hence gtest library files must be linked during
# linking stage. Linking the gtest files dynamically is causing seg fault (reason yet to be found),
# hence the linking is done statically.
# The libraries are parsed from right to left so for this use case lpthread should come to the
# right as libgtest_main and libgtest depends on it. If lpthread is specified as the first option
# from left linker will throw undefined reference error.

LIB         := -l:libgtest.a -l:libgtest_main.a -lpthread 
CFLAGS      := -std=c++11

#---------------------------------------------------------------------------------
#DO NOT EDIT BELOW THIS LINE
#---------------------------------------------------------------------------------
#Using the 'find' command of shell all sources file names inside SRCDIR are
#assigned to the variable SOURCES 
#Example: If source file paths are src/a.cpp, src/b.cpp and src/c.cpp, the variable
#SOURCES = 'src/a.cpp src/b.cpp src/c.cpp'
SOURCES     := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))

#The syntax for patsubst (pattern substitution) command is $(patsubst pattern,replacement,text)
#Every occurence of 'pattern' in the 'text' is replaced by the 'replacement'. '%" acts as a
#wildcard matching any number of characters in a word.
#The syntax '$(var:suffix=replacement)' is equivalent to '$(patsubst %suffix,%replacement,$(var))'
#So the summary of steps for OBJECTS is
#    - Replace SRCEXT with OBJEXT for all source files in the SRCDIR.
#    - Replace the SRCDIR with BUILDCIR for each of the object file path.
#Example: For the source files mentioned above the variable
#OBJECTS = 'obj/a.o obj/b.o obj/c.o'
OBJECTS     := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

#Defauilt Make
all: directories $(TARGET) runUnitTest

#Remake
remake: deep-clean all

runUnitTest:
	./$(TARGETDIR)/$(TARGET)

##Copy Resources from Resources Directory to Target Directory
#resources: directories
#	@cp $(RESDIR)/* $(TARGETDIR)/

#Normally make prints each line of the recipe before it is executed. We call this echoing because it
#gives the appearance that you are typing the lines yourself. When a line starts with ‘@’, the echoing
#of that line is suppressed.
#The following shell command makes TARGETDIR and BUILDDIR if they are not already present
directories:
	@mkdir -p $(TARGETDIR)
	@mkdir -p $(BUILDDIR)

#$(RM) is variable expanded to 'rm -f'. So the below shell command forcefully removes the BUILDDIR, thus
#cleaning object files.
clean:
	@$(RM) -r $(BUILDDIR)

#Full Clean, Objects and Binaries
deep-clean: clean
	@$(RM) -r $(BUILDDIR)
	@$(RM) -r $(TARGETDIR)

#The include directive tells make to suspend reading the current makefile and read one or more other
#makefiles before continuing. Its syntax is as below:
#    include filenames...
#If you want make to simply ignore a makefile which does not exist or cannot be remade, with no error
#message, use the -include directive instead of include, like this:
#    -include filenames...
#Pull in dependency info for *existing* .o files
-include $(OBJECTS:.$(OBJEXT)=.$(DEPEXT))

#Automatic variables: Suppose you are writing a pattern rule to compile a ‘.c’ file into a ‘.o’ file:
#how do you write the ‘cc’ command so that it operates on the right source file name? You cannot write
#the name in the recipe, because the name is different each time the implicit rule is applied.
#What you do is use a special feature of make, the automatic variables. There are various automatic
#variables, let's understand the ones used in this file
#
# $^ : The names of all the prerequisites, with spaces between them.
# $@ : The file name of the target of the rule.
# $< : The name of the first prerequisite.

#The -o option places output in file. This applies to whatever sort of output is being produced,
#whether it be an executable file, an object file, an assembler file or preprocessed C code.
#If -o is not specified, the default is to put an executable file in a.out, the object file for
#source.suffix in source.o, its assembler file in source.s, a precompiled header file in source.suffix.gch,
#and all preprocessed C source on standard output.

#Link
$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGETDIR)/$(TARGET) $^ $(LIB)

#Compile
$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
#The -c option compiles or assembles the source files, but does not link. The linking stage simply is
#not done.  The ultimate output is in the form of an object file for each source file. By default, the object
#file name for a source file is made by replacing the suffix .c, .i, .s, etc., with .o.
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

#The following set of lines will create dependency list for each source ojbect file. The GNU make will compare
#the timestamp of dependent files with the object file, if the ojbect file is older than the dependent file
#then the source files are recompiled while running make
#Example:
# foo.h and foo.cpp are two source files
# foo.o is the object file that is generated by compiling foo.cpp.
# The contents of foo.d file is as below
#     obj/foo.o: src/foo.cpp src/foo.h
#     src/foo.cpp:
#     src/foo.h:
	@$(CC) $(CFLAGS) $(INCDEP) -MM $(SRCDIR)/$*.$(SRCEXT) > $(BUILDDIR)/$*.$(DEPEXT)
	@cp -f $(BUILDDIR)/$*.$(DEPEXT) $(BUILDDIR)/$*.$(DEPEXT).tmp
	@sed -e 's|.*:|$(BUILDDIR)/$*.$(OBJEXT):|' < $(BUILDDIR)/$*.$(DEPEXT).tmp > $(BUILDDIR)/$*.$(DEPEXT)
	@sed -e 's/.*://' -e 's/\\$$//' < $(BUILDDIR)/$*.$(DEPEXT).tmp | fmt -1 | sed -e 's/^ *//' -e 's/$$/:/' >> $(BUILDDIR)/$*.$(DEPEXT)
	@rm -f $(BUILDDIR)/$*.$(DEPEXT).tmp

#Non-File Targets
#.PHONY: all remake clean deep-clean resources
.PHONY: all remake clean deep-clean
