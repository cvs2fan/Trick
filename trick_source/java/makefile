
# Get JAVAC definition
include ${TRICK_HOME}/makefiles/Makefile.common

JAVAC ?= javac
JAVAC_FLAGS = -g -Xlint:unchecked -Xlint:deprecation

SRC_DIR   = src
SRC_FILES = $(shell find ${SRC_DIR} -type f -name \*.java)
BUILD_DIR = build
DEST_DIR  = ${BUILD_DIR}/classes
LIB_DIR   = ${TRICK_HOME}/bin/java/lib
DIST_DIR  = ${TRICK_HOME}/bin/java/dist
RESOURCES_DIR  = ${TRICK_HOME}/bin/java/resources
DOCS_API_DIR   = docs/api
TEST_REPORTS_DIR = test/reports

empty :=
space := $(empty) $(empty)
CLASS_PATH = $(subst $(space),:,$(wildcard ${LIB_DIR}/*.jar))

RESOURCES = $(subst src/,,$(shell find src/trick -name resources))

all: ${DIST_DIR}/trick.jar resources
	@echo "[32mJava build successful[0m"

${DEST_DIR} ${DIST_DIR} ${RESOURCES_DIR} ${DOCS_API_DIR}:
	mkdir -p $@

${DIST_DIR}/trick.jar: compile ${DIST_DIR}
	@echo "[36mCreating jar file...[0m"
	@jar cf ${DIST_DIR}/trick.jar -C ${DEST_DIR} .
	@cd ${SRC_DIR} && jar uf ${DIST_DIR}/trick.jar ${RESOURCES}

external_jars:
	@ $(MAKE) -C  $(LIB_DIR)

compile: ${DEST_DIR} external_jars
	@echo "[36mBuilding Trick GUIs...[0m"
	@${JAVAC} ${JAVAC_FLAGS} -classpath ${CLASS_PATH} -d ${DEST_DIR} -sourcepath ${SRC_DIR} ${SRC_FILES}

resources: ${RESOURCES_DIR}/trick_icon.png

${RESOURCES_DIR}/trick_icon.png: ${SRC_DIR}/trick/common/resources/trick_icon.png ${RESOURCES_DIR}
	@cp $< $@

JAVA_DOC_LINKS = \
 -link "http://docs.oracle.com/javase/6/docs/api/" \
 -link "http://www.jdocs.com/swingx/1.0/overview-summary.html" \
 -link "http://www.jfree.org/jfreechart/api/javadoc/" \
 -link "http://junit.sourceforge.net/javadoc/"

docs: ${DOCS_API_DIR}
	javadoc -d ${DOCS_API_DIR} -classpath ${CLASS_PATH} -sourcepath ${SRC_DIR} -windowtitle "Trick GUI API" ${JAVA_DOC_LINKS} trick ${SRC_FILES}

clean:
	rm -rf ${BUILD_DIR}
	rm -rf ${DIST_DIR}
	rm -rf ${RESOURCES_DIR}
	rm -rf ${TEST_REPORTS_DIR}

clean_docs:
	rm -rf ${DOCS_API_DIR}
