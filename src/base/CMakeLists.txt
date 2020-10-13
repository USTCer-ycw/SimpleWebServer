#set(
#        DIR_BASE
#        FileUtil.cpp
#)

aux_source_directory(. DIR_BASE)

add_library(base ${DIR_BASE})