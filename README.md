# UnrealVoxelSim.Items.Voxel.Solid.Api

Header-only capabilities for placeable solid voxel items: material attachment, stack addition/consumption, voxel
placement, storage attachment, and specialized storage insertion. Material identity uses `Voxel.Solid.Api::MaterialId`
directly. `MaterialComponent` and `StorageComponent` are public data contracts.

`AttachMaterial` initializes an existing item without material or stack data. It validates a known material and a
positive initial quantity against implementation-defined per-material limits. It is not a conversion operation.
`Add` rejects zero, overflow, and quantities exceeding the limit. `Consume` rejects zero or insufficient supply and
destroys the item when its final unit is consumed. Destruction must perform ordinary containment cleanup.

`Place` places the item's material and consumes exactly one unit iff placement succeeds. Implementations must commit
both effects coherently without an observable intermediate state. Failed operations preserve item and world state.

`StorageComponent::ItemSlots` limits the number of contained entities, not their total unit count. A pawn uses one
slot; a chest uses N slots. Zero capacity is valid. `AttachStorage` initializes storage without replacing an existing
component. `Store` moves a whole voxel-item entity, requires valid storage with capacity, and preserves the original
location on failure. Same-container insertion requires no additional slot.

Composition gives gameplay callers this specialized inserter. Its implementation validates acceptance/capacity and
receives `ItemStorage.Api::IInserter` for the generic transition. Lower layers do not duplicate voxel-item policy.
Tree harvesting, log conversion, equipment, and weight are outside this API.

All capabilities are synchronous and confined to the owning simulation thread. Returned query containers are owned
snapshots. Entity references are non-owning and scoped to one registry; they are not persistent save identities.
Components are public read contracts; composition grants mutation authority only to the owning domain.

## Build validation

Use a Visual Studio developer environment with CMake, Ninja, and `VCPKG_ROOT` available:

```powershell
cmake --preset windows-msvc-debug
cmake --build --preset windows-msvc-debug
cmake --preset windows-msvc-release
cmake --build --preset windows-msvc-release
```

The default build compiles each public header in isolation and verifies that interfaces remain abstract with virtual
destructors. This module contains no runtime implementation or behavioral tests yet. Linux Clang presets are also provided.
