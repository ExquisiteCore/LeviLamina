#pragma once

#include <utility>

#include "mc/_HeaderOutputPredefine.h"
#include "mc/entity/utilities/ActorDataIDs.h"
#include "mc/enums/DataItemType.h"
#include "mc/math/vec2.h"
#include "mc/math/vec3.h"
#include "mc/nbt/CompoundTag.h"
#include "mc/world/level/BlockPos.h"

class DataItem {

public:
    enum class DataItemType mType;
    unsigned short          mId;
    bool                    mDirty = true;

    template <typename T>
    inline T const& getData() const;
    template <typename T>
    inline T& getData();
    template <typename T>
    inline bool setData(T const& value);

    DataItem(DataItemType type, unsigned short id) : mId(id), mType(type) {}

    template <typename T>
    inline static std::unique_ptr<DataItem> create(unsigned short key, T const& value);

    template <typename T>
    inline static std::unique_ptr<DataItem> create(enum class ActorDataIDs key, T const& value);

public:
    /**
     * @vftbl 0
     * @symbol __unk_vfn_0
     */
    virtual void __unk_vfn_0(); // NOLINT
    /**
     * @vftbl 1
     * @symbol ?isDataEqual\@DataItem\@\@UEBA_NAEBV1\@\@Z
     */
    virtual bool isDataEqual(class DataItem const&) const; // NOLINT
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_DATAITEM
    /**
     * @symbol __unk_destructor_-1
     */
    MCVAPI ~DataItem(); // NOLINT
#endif
};

template <typename T>
class DataItem2 : public DataItem {
    T mValue;

    friend class DataItem;

public:
    [[nodiscard]] virtual std::unique_ptr<DataItem> clone() const;

    [[nodiscard]] T const& getData() const { return mValue; };
    // T& getData()
    //{
    //     mDirty = true;
    //     return mValue;
    // };
    inline void setData(T const& value) {
        mDirty = true;
        mValue = value;
    }
    inline DataItem2<T>& operator=(T const& value) {
        setData(value);
        return *this;
    }
    inline DataItem2(unsigned short key, T value) = delete;
    inline static std::unique_ptr<DataItem> create(unsigned short key, T const& value) {
        return std::unique_ptr<DataItem>(new DataItem2(key, value));
    }
    static DataItemType const DATA_ITEM_TYPE;
};

template <typename T>
DataItemType const DataItem2<T>::DATA_ITEM_TYPE = static_cast<DataItemType>(-1);

template <>
DataItemType const DataItem2<signed char>::DATA_ITEM_TYPE = DataItemType::Byte;
template <>
DataItemType const DataItem2<short>::DATA_ITEM_TYPE = DataItemType::Short;
template <>
DataItemType const DataItem2<int>::DATA_ITEM_TYPE = DataItemType::Int;
template <>
DataItemType const DataItem2<float>::DATA_ITEM_TYPE = DataItemType::Float;
template <>
DataItemType const DataItem2<std::string>::DATA_ITEM_TYPE = DataItemType::String;
template <>
DataItemType const DataItem2<CompoundTag>::DATA_ITEM_TYPE = DataItemType::CompoundTag;
template <>
DataItemType const DataItem2<BlockPos>::DATA_ITEM_TYPE = DataItemType::BlockPos;
template <>
DataItemType const DataItem2<__int64>::DATA_ITEM_TYPE = DataItemType::Int64;
template <>
DataItemType const DataItem2<Vec3>::DATA_ITEM_TYPE = DataItemType::Vec3;

template <>
inline void DataItem2<CompoundTag>::setData(CompoundTag const& value) {
    mValue.deepCopy(value);
}

template <>
inline DataItem2<signed char>::DataItem2(unsigned short key, signed char const& value)
: DataItem(DATA_ITEM_TYPE, key), mValue(value) {
    //*(void**)this = dlsym_real("??_7?$DataItem2@C@@6B@");
}
template <>
inline DataItem2<short>::DataItem2(unsigned short key, short const& value)
: DataItem(DATA_ITEM_TYPE, key), mValue(value) {
    //*(void**)this = dlsym_real("??_7?$DataItem2@F@@6B@");
}
template <>
inline DataItem2<int>::DataItem2(unsigned short key, int const& value) : DataItem(DATA_ITEM_TYPE, key), mValue(value) {
    //*(void**)this = dlsym_real("??_7?$DataItem2@M@@6B@");
}
template <>
inline DataItem2<float>::DataItem2(unsigned short key, float const& value)
: DataItem(DATA_ITEM_TYPE, key), mValue(value) {
    //*(void**)this = dlsym_real("??_7?$DataItem2@M@@6B@");
}
template <>
inline DataItem2<std::string>::DataItem2(unsigned short key, std::string const& value) // NOLINT
: DataItem(DATA_ITEM_TYPE, key), mValue(value) {
    //*(void**)this = dlsym_real("??_7?$DataItem2@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@6B@");
}
template <>
inline DataItem2<class CompoundTag>::DataItem2(unsigned short key, class CompoundTag const& value)
: DataItem(DATA_ITEM_TYPE, key) {
    mValue.deepCopy(value);
    //*(void**)this = dlsym_real("??_7?$DataItem2@VCompoundTag@@@@6B@");
}
template <>
inline DataItem2<BlockPos>::DataItem2(unsigned short key, BlockPos const& value)
: DataItem(DATA_ITEM_TYPE, key), mValue(value) {
    //*(void**)this = dlsym_real("??_7?$DataItem2@VBlockPos@@@@6B@");
}
template <>
inline DataItem2<__int64>::DataItem2(unsigned short key, __int64 const& value)
: DataItem(DATA_ITEM_TYPE, key), mValue(value) {
    //*(void**)this = dlsym_real("??_7?$DataItem2@_J@@6B@");
}
template <>
inline DataItem2<Vec3>::DataItem2(unsigned short key, Vec3 const& value)
: DataItem(DATA_ITEM_TYPE, key), mValue(value) {
    //*(void**)this = dlsym_real("??_7?$DataItem2@VVec3@@@@6B@");
}

template <typename T>
inline T const& DataItem::getData() const {
    if (this->mType == DataItem2<T>::DATA_ITEM_TYPE)
        return ((DataItem2<T>*)this)->mValue;
    // throw("DataItemType Not Match");
    return *(T*)0;
}

template <typename T>
inline T& DataItem::getData() {
    if (this->mType == DataItem2<T>::DATA_ITEM_TYPE)
        return ((DataItem2<T>*)this)->mValue;
    // throw("DataItemType Not Match");
    return *(T*)0;
}

template <typename T>
inline bool DataItem::setData(T const& value) {
    if (this->mType != DataItem2<T>::DATA_ITEM_TYPE)
        return false;
    ((DataItem2<T>*)this)->setData(value);
    return true;
}

template <typename T>
inline static std::unique_ptr<DataItem> DataItem::create(unsigned short key, T const& value) {
    return std::unique_ptr<DataItem>(new DataItem2(key, value));
}

template <typename T>
inline static std::unique_ptr<DataItem> DataItem::create(ActorDataIDs key, T const& value) {
    return std::unique_ptr<DataItem>(new DataItem2((unsigned short)key, value));
}
