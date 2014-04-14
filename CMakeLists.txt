cmake_minimum_required(VERSION 2.8)
find_package(OpenCV REQUIRED)

project (Live)
add_executable (Live Live.cpp )
target_link_libraries( Live ${OpenCV_LIBS})

project (LiveCaptureFPS)
add_executable ( LiveCaptureFPS LiveCaptureFPS.cpp)
target_link_libraries( LiveCaptureFPS ${OpenCV_LIBS})

project (how_to_scan_images)
add_executable (how_to_scan_images how_to_scan_images.cpp)
target_link_libraries(how_to_scan_images ${OpenCV_LIBS})

project ( scan_image_with_LUT)
add_executable (scan_image_with_LUT scan_image_with_LUT.cpp)
target_link_libraries(scan_image_with_LUT ${OpenCV_LIBS})

project (ShowVideoFromFile)
add_executable ( ShowVideoFromFile ShowVideoFromFile.cpp)
target_link_libraries( ShowVideoFromFile ${OpenCV_LIBS})

project ( ShowVideoFromCamera)
add_executable (ShowVideoFromCamera ShowVideoFromCamera.cpp)
target_link_libraries( ShowVideoFromCamera ${OpenCV_LIBS})

project ( ColorThresholding)
add_executable (ColorThresholding ColorThresholding.cpp)
target_link_libraries( ColorThresholding ${OpenCV_LIBS})

