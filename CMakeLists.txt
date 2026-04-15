cmake_minimum_required(VERSION 3.21)
cmake_policy(SET CMP0069 NEW) 
set(CMAKE_POLICY_DEFAULT_CMP0069 NEW)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

macro(set_build_dir_default TARGET_NAME_)
	set_target_properties(${TARGET_NAME_}
		PROPERTIES
		ARCHIVE_OUTPUT_DIRECTORY "Binary"
		LIBRARY_OUTPUT_DIRECTORY "Library"
		RUNTIME_OUTPUT_DIRECTORY "Binary"
	)
endmacro()

project(OpenBcd LANGUAGES C)

add_subdirectory("${OpenBcd_SOURCE_DIR}/Library/OpenRegistry")

set(OpenBcd_HEADER_FILES
	"${OpenBcd_SOURCE_DIR}/Include/OpenBcd.h"
	"${OpenBcd_SOURCE_DIR}/Source/Common.h"
)
set(OpenBcd_SOURCE_FILES
	"${OpenBcd_SOURCE_DIR}/Source/Element.c"
	"${OpenBcd_SOURCE_DIR}/Source/ElementDefined.c"
	"${OpenBcd_SOURCE_DIR}/Source/Object.c"
	"${OpenBcd_SOURCE_DIR}/Source/ObjectFriendlyName.c"
	"${OpenBcd_SOURCE_DIR}/Source/Store.c"
)

add_library(OpenBcd STATIC
	${OpenBcd_HEADER_FILES}
	${OpenBcd_SOURCE_FILES}
)
target_include_directories(OpenBcd
	PUBLIC  "${OpenBcd_SOURCE_DIR}/Include"
)
target_link_libraries(OpenBcd
	PUBLIC OpenRegistry
)
set_target_properties(OpenBcd PROPERTIES
	INTERPROCEDURAL_OPTIMIZATION TRUE
	C_STANDARD 99
)

set_build_dir_default(OpenBcd)
