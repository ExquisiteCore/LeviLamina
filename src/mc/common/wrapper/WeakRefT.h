#pragma once

#include "mc/_HeaderOutputPredefine.h"
#include "mc/common/wrapper/Ref.h"

template <typename T0>
class WeakRefT : public T0::WeakStorage {};
