#pragma once

#include <cstddef>
#include <expected>
#include "UnrealVoxelSim/Ecs/Api/EntityId.h"
#include "UnrealVoxelSim/Items/Voxel/Solid/Api/CreateError.h"
#include "UnrealVoxelSim/Voxel/Solid/Api/MaterialId.h"

namespace UnrealVoxelSim::Items::Voxel::Solid::Api
{
	// Synchronous, simulation-thread-affine capability. Implementations add no implicit locking.
	class IItemCreator
	{
	public:
		virtual ~IItemCreator() = default;

		// Requires an item without material or stack data. Attaches MaterialComponent and StackComponent.
		// Validates the material, positive quantity, and the implementation's per-material stack limit.
		// Failure attaches neither component. This is initialization, not material conversion.
		[[nodiscard]] virtual std::expected<void, CreateError>
		AttachMaterial(Ecs::Api::EntityId entity,
					   ::UnrealVoxelSim::Voxel::Solid::Api::MaterialId material,
					   std::size_t initialStackSize) = 0;
	};
}
