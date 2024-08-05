#pragma once

#include "mc/_HeaderOutputPredefine.h"

class OwnerStorageFeature {
public:
    // prevent constructor by default
    OwnerStorageFeature& operator=(OwnerStorageFeature const&);
    OwnerStorageFeature(OwnerStorageFeature const&);
    OwnerStorageFeature();

    // protected:
    // NOLINTBEGIN
    MCAPI ~OwnerStorageFeature();

    // NOLINTEND
};
