#set(
#        DIR_BASE
#        FileUtil.cpp
#)

aux_source_directory(. DIR_BASE)
find_package(Threads)
add_library(base ${DIR_BASE}  Thread.cpp Thread.h MutexLock.h Condition.h CountDownLatch.cpp CountDownLatch.h CurrentThread.h)
target_link_libraries(base ${CMAKE_THREAD_LIBS_INIT})