#pragma once

#include "mc/_HeaderOutputPredefine.h"
#include "mc/entity/EntityContext.h"

class Actor;

class OwnerStorageEntity {
public:
    std::optional<EntityContext> mContext;

    template <class Entity = Actor, bool IncludeRemoved = false>
    [[nodiscard]] optional_ref<Entity> tryUnwrap() const {
        if (_hasValue()) {
            return Entity::tryGetFromEntity(_getStackRef(), IncludeRemoved);
        }
        return nullptr;
    }

    [[nodiscard]] inline operator bool() const { return _hasValue(); } // NOLINT

public:
    // prevent constructor by default
    OwnerStorageEntity& operator=(OwnerStorageEntity const&);
    OwnerStorageEntity(OwnerStorageEntity const&);

    // protected:
    // NOLINTBEGIN
    MCAPI OwnerStorageEntity();

    MCAPI explicit OwnerStorageEntity(class EntityRegistry&);

    MCAPI OwnerStorageEntity(class OwnerStorageEntity&& other);

    MCAPI class EntityContext& _getStackRef() const;

    MCAPI bool _hasValue() const;

    MCAPI void _reset();

    MCAPI class OwnerStorageEntity& operator=(class OwnerStorageEntity&& other);

    MCAPI ~OwnerStorageEntity();

    // NOLINTEND
};
