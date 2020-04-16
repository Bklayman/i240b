COURSE = cs240
COURSE_DIR = $(HOME)/$(COURSE)

CPPFLAGS = -I $(COURSE_DIR)/include
CXX = g++
CXXFLAGS = -g -Wall -std=c++17

#produce a list of all cc files which do not have main in their name
CXX_FILES = $(shell ls *.cc | grep -v main)

#main cc files:
MAIN_CXX_FILES = $(wildcard *main*.cc)

#produce a list of all *.o files by substituting cc in CXX_FILES with o.
OFILES = $(CXX_FILES:cc=o)

#dir in which to generate dependences
DEPDIR = .deps

TARGETS = main test-main

all:		$(TARGETS) .gitignore

main:		main.o $(OFILES) 
		$(CXX) $< $(OFILES) -o $@

test-main:	test-main.o $(OFILES) 
		$(CXX) $< $(OFILES) -o $@

.phony:		clean
clean:
		rm -rf *.o *~ $(TARGETS) $(DEPDIR) .gitignore

.gitignore:	$(CXX_FILES)
		cat </dev/null >$@
		echo $(DEPDIR) >$@
		for t in $(TARGETS) $(OFILES); do echo $$t >>$@; done


#auto-dependences
#<http://make.mad-scientist.net/papers/advanced-auto-dependency-generation/>

#have DEPDIR/*.d file for each *.cc file
DEPFILES = $(CXX_FILES:%.cc=$(DEPDIR)/%.d) \
           $(MAIN_CXX_FILES:%.cc=$(DEPDIR)/%.d)

x:
	echo $(DEPFILES) $($(wildcard *main*.cc):%.cc=$(DEPDIR)/%.d)

#-MT $@ sets target name in dependency file
#-MMD tells compiler to generate prereqs without including system headers
#-MP adds target for each prereq
#-MF $(DEPDIR)/$*.d sets name of output dependency file
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

#delete built-in implicit rule for building .o from .cc
%.o: %.cc

#create our own implicit rule for building %.o from %.cc
#| $(DEPDIR) makes DEPDIR an order only prereq
%.o:		%.cc $(DEPDIR)/%.d | $(DEPDIR)
		$(CXX) $(CPPFLAGS) $(DEPFLAGS) $(CXXFLAGS) -c $<

#create DEPDIR if it does not exist
$(DEPDIR):
		@mkdir -p $@

#add a target to include all DEPFILES
$(DEPFILES):    $(CXX_FILES)
include $(wildcard $(DEPFILES))
