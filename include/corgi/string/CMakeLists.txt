target_sources(${PROJECT_NAME} PUBLIC 
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/string.h>
      $<INSTALL_INTERFACE:include/corgi/string/string.h> )