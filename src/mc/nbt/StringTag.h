#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/deps/core/common/bedrock/Result.h"
#include "mc/nbt/Tag.h"

class StringTag : public ::Tag, public std::string {
public:
    using Tag::operator==;

    [[nodiscard]] constexpr StringTag() = default;

    [[nodiscard]] constexpr StringTag(std::string str) : std::string(std::move(str)) {}
    [[nodiscard]] constexpr StringTag(std::string_view str) : std::string(str) {}
    template <size_t N>
    [[nodiscard]] constexpr StringTag(char const (&str)[N]) : std::string(str) {}

public:
    // NOLINTBEGIN
    // vIndex: 0
    virtual ~StringTag() = default;

    // vIndex: 2
    virtual void write(class IDataOutput& dos) const;

    // vIndex: 3
    virtual class Bedrock::Result<void> load(class IDataInput& dis);

    // vIndex: 4
    virtual std::string toString() const;

    // vIndex: 5
    virtual ::Tag::Type getId() const;

    // vIndex: 6
    virtual bool equals(class Tag const& rhs) const;

    // vIndex: 9
    virtual std::unique_ptr<class Tag> copy() const;

    // vIndex: 10
    virtual uint64 hash() const;

    // NOLINTEND
};
namespace ll::nbt_literals {
[[nodiscard]] inline StringTag operator""_tag(char const* x, size_t len) { return StringTag(std::string{x, len}); }
} // namespace ll::nbt_literals
