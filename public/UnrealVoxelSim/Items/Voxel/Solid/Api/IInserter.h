#pragma once

#include <expected>
#include "UnrealVoxelSim/Ecs/Api/EntityId.h"
#include "UnrealVoxelSim/Items/Voxel/Solid/Api/StoreError.h"

namespace UnrealVoxelSim::Items::Voxel::Solid::Api
{
	// Synchronous, simulation-thread-affine capability. Implementations add no implicit locking.
	class IInserter
	{
	public:
		virtual ~IInserter() = default;

		// Validates voxel-item acceptance and StorageComponent capacity, then delegates to ItemStorage.
		// Moves the whole entity. Storing in its current container succeeds without using another slot.
		// Failure preserves original containment and position; rejects destroying entities and cycles.
		[[nodiscard]] virtual std::expected<void, StoreError> Store(Ecs::Api::EntityId item,
																	Ecs::Api::EntityId container) = 0;
	};
}
