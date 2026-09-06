#pragma once

namespace UnrealVoxelSim::Items::Voxel::Solid::Api
{
	enum class StoreError
	{
		ItemNotAlive,
		ContainerNotAlive,
		ItemDestroying,
		ContainerDestroying,
		NotVoxelItem,
		NotStorage,
		StorageFull,
		ContainmentCycle,
	};
}
