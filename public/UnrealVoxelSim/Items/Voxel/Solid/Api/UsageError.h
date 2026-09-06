#pragma once

namespace UnrealVoxelSim::Items::Voxel::Solid::Api
{
	enum class UsageError
	{
		EntityNotAlive,
		EntityDestroying,
		NotVoxelItem,
		InvalidQuantity,
		StackLimitExceeded,
		InsufficientQuantity,
	};
}
