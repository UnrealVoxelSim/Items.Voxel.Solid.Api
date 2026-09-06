add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(
    ${PROJECT_NAME}
    INTERFACE
        "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/public>"
        "$<INSTALL_INTERFACE:include>"
)

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_23)
target_link_libraries(
    ${PROJECT_NAME}
    INTERFACE
        UnrealVoxelSim.Ecs.Api
        UnrealVoxelSim.Voxel.Api
        UnrealVoxelSim.Voxel.Solid.Api
)

UnrealVoxelSimConfigureTarget(${PROJECT_NAME})
