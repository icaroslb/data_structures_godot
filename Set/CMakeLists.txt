add_library(Set
	 "Set/Set.h" "Set.cpp"
	 "Set/SetOperations.h" "SetOperations.cpp")

target_include_directories(Set PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(Set rb_tree)