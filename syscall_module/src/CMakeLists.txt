SET (SYS_SRCS 
	Thread.cpp
	ThreadPool.cpp
	Simulate.cpp
	Syscalls.cpp
	main.cpp
)

ADD_EXECUTABLE (ospf ${SYS_SRCS})
TARGET_LINK_LIBRARIES (ospf pthread)

