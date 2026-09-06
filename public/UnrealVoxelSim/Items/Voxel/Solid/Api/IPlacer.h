#pragma once

#include <expected>
#include "UnrealVoxelSim/Ecs/Api/EntityId.h"
#include "UnrealVoxelSim/Items/Voxel/Solid/Api/PlaceError.h"
#include "UnrealVoxelSim/Voxel/Api/Position.h"

namespace UnrealVoxelSim::Items::Voxel::Solid::Api
{
	// Synchronous, simulation-thread-affine capability. Implementations add no implicit locking.
	class IPlacer
	{
	public:
		virtual ~IPlacer() = default;

		// Places the item's material and consumes exactly one unit iff placement succeeds.
		// Requires a valid voxel item with a positive stack. May destroy an exhausted item.
		// Consumption and placement are coherent; failure changes neither item nor world.
		[[nodiscard]] virtual std::expected<void, PlaceError>
		Place(Ecs::Api::EntityId item, const ::UnrealVoxelSim::Voxel::Api::Position& position) = 0;
	};
}
