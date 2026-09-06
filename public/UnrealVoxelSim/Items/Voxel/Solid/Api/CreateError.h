#pragma once

namespace UnrealVoxelSim::Items::Voxel::Solid::Api
{
	enum class CreateError
	{
		EntityNotAlive,
		EntityDestroying,
		NotItem,
		UnknownMaterial,
		InvalidQuantity,
		StackLimitExceeded,
		AlreadyHasMaterial,
		AlreadyHasStack,
		AlreadyHasStorage,
	};
}
