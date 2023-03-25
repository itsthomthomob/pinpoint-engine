cmake_minimum_required(VERSION 3.9)

project(Pinpoint-Engine LANGUAGES C CXX)

set(SOURCES
	"src/main.cpp"
)

add_subdirectory(vendor)
add_executable(Pinpoint-Engine ${SOURCES})

target_link_libraries(Pinpoint-Engine
	PRIVATE
		glfw
		glad
)
target_include_directories(Pinpoint-Engine
	PRIVATE
		"src/"
)
