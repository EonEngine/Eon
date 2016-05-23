find_path(SOIL_INCLUDE_DIR SOIL.h
  PATHS /usr/include/SOIL /usr/local/include/SOIL /opt/local/include/SOIL
)

find_library(SOIL_LIBRARY
  NAMES SOIL libSOIL
  PATHS /usr/lib64 /usr/lib /usr/local/lib /opt/local/lib
)

IF(SOIL_INCLUDE_DIR AND SOIL_LIBRARY)
  set(SOIL_INCLUDE_DIRS ${SOIL_INCLUDE_DIR})
  set(SOIL_LIBRARIES ${SOIL_LIBRARY})
  set(SOUL_FOUND)
  message("SOIL found")
ELSE()
  message("SOIL not found")
ENDIF()
