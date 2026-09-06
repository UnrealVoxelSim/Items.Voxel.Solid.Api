#pragma once

#include <cstddef>
#include <expected>
#include "UnrealVoxelSim/Ecs/Api/EntityId.h"
#include "UnrealVoxelSim/Items/Voxel/Solid/Api/CreateError.h"

namespace UnrealVoxelSim::Items::Voxel::Solid::Api
{
	// Synchronous, simulation-thread-affine capability. Implementations add no implicit locking.
	class IStorageCreator
	{
	public:
		virtual ~IStorageCreator() = default;

		// Attaches StorageComponent to a live, non-destroying entity without one.
		// Capacity counts item entities; zero is a valid empty-capacity storage. Failure changes nothing.
		[[nodiscard]] virtual std::expected<void, CreateError> AttachStorage(Ecs::Api::EntityId entity,
																			 std::size_t itemSlots) = 0;
	};
}
