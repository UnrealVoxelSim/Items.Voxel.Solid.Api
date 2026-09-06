#pragma once

#include <cstddef>
#include <expected>
#include "UnrealVoxelSim/Ecs/Api/EntityId.h"
#include "UnrealVoxelSim/Items/Voxel/Solid/Api/UsageError.h"

namespace UnrealVoxelSim::Items::Voxel::Solid::Api
{
	// Synchronous, simulation-thread-affine capability. Implementations add no implicit locking.
	class IStackManager
	{
	public:
		virtual ~IStackManager() = default;

		// Requires a voxel item and positive amount. Rejects arithmetic overflow or exceeding the stack limit.
		// Failure leaves the stack unchanged.
		[[nodiscard]] virtual std::expected<void, UsageError> Add(Ecs::Api::EntityId entity, std::size_t amount) = 0;

		// Requires a voxel item and positive amount; rejects insufficient quantity without mutation.
		// Consuming the final unit destroys the item through ordinary entity cleanup.
		[[nodiscard]] virtual std::expected<void, UsageError> Consume(Ecs::Api::EntityId entity,
																	  std::size_t amount) = 0;
	};
}
