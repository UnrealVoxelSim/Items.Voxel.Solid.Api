#pragma once

namespace UnrealVoxelSim::Items::Voxel::Solid::Api
{
	enum class PlaceError
	{
		ItemNotAlive,
		ItemDestroying,
		NotVoxelItem,
		InsufficientQuantity,
		UnknownMaterial,
		OutOfBounds,
		Occupied,
		StorageConflict,
	};
}
