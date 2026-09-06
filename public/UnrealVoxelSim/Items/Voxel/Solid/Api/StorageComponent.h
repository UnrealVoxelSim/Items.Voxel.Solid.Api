#pragma once

#include <cstddef>

namespace UnrealVoxelSim::Items::Voxel::Solid::Api
{
	// Capacity counts contained item entities, not stack units. Zero slots accepts no items.
	struct StorageComponent final
	{
		std::size_t ItemSlots;
	};
}
