SET ( CMAKE_C_COMPILER "g++")
SET ( CMAKE_RUNTIME_OUTPUT_DIRECTORY bin )
SET ( CMAKE_LIBRARY_OUTPUT_DIRECTORY lib )
SET ( CMAKE_ARCHIVE_OUTPUT_DIRECTORY arc )

SET ( SRC_FILES  
    ./cpp/ort.cpp 
    ./cpp/heap.cpp 
    ./cpp/quick.cpp 
    ./cpp/countHeap.cpp 
    ./cpp/countQuick.cpp)
ADD_EXECUTABLE ( sort.out ${SRC_FILES} )