//
// (C) LetsMakeGames 2019
// http://www.letsmake.games/
//

#pragma once

#include "Engine.hh"

#include <cstdint>
#include <limits>
#include <ostream>
#include <string>

namespace Engine
{

//
// IdClass ////////////////////////////////////////////////////////////////////
// A base class for id

template<
    typename IdType_
    , typename TypesafeType_
    , IdType_ InvalidValue_ = (IdType_)0 >
class IdClass final
{
public: // types //////////////////////////////////////////////////////////////

    //
    // internal id type
    //
    using IdType = IdType_;

    //
    // static invalid id value
    //
    static constexpr IdType InvalidValue = InvalidValue_;

    //
    // Invalid Id
    //
    static const IdClass InvalidId;

public: // constructor / destructor ///////////////////////////////////////////

    //
    //
    //
    IdClass()
        : IdClass(InvalidValue_)
    {
    }

    //
    // 
    //
    IdClass(IdType value)
        : id(value)
    {
    }

    //
    // 
    //
    IdClass(const IdClass& copy) = default;

    //
    // 
    //
    IdClass(IdClass&& move) = default;

public: // public methods //////////////////////////////////////////////////////

    //
    //
    //
    inline const IdType& getRawId() const                       { return id; }

    //
    //
    //
    inline void setRawId(const IdType& id)                      { id = id; }
    
public: // operators //////////////////////////////////////////////////////////

    //
    //
    //
    std::string to_string() const                               { return std::to_string(id); }

    //
    //
    //
    inline IdClass& operator=(const IdClass& rhs)               = default;

    //
    // 
    //
    inline IdClass& operator=(IdClass&& rhs)                    = default;

    //
    //
    //
    inline bool operator==(const IdClass& rhs) const            { return id == rhs.id; }

    //
    //
    //
    inline bool operator!=(const IdClass& rhs) const            { return id != rhs.id; }

    //
    //
    //
    inline bool operator<(const IdClass& rhs) const             { return id < rhs.id; }

    //
    //
    //
    inline bool operator<=(const IdClass& rhs) const            { return id <= rhs.id; }

    //
    //
    //
    inline bool operator>(const IdClass& rhs) const             { return id > rhs.id; }

    //
    //
    //
    inline bool operator>=(const IdClass& rhs) const            { return id >= rhs.id; }

    //
    //
    //
    friend std::ostream& operator<<(std::ostream& os, const IdClass& id)
    {
        os << id.to_string();
        return os;
    }

private: // members ///////////////////////////////////////////////////////////

    IdType id;

};

//
// static members /////////////////////////////////////////////////////////////
//

template<typename IdType_, typename TypesafeType_, IdType_ InvalidValue_>
const IdClass<IdType_, TypesafeType_, InvalidValue_> 
      IdClass<IdType_, TypesafeType_, InvalidValue_>::InvalidId = IdClass();

}

//
// macros /////////////////////////////////////////////////////////////////////
//

#define DECLARE_IDCLASS_EX(IdName_, IdType_, InvalidValue_) \
    struct TYPE_##_IDNAME##__ {}; \
    using IdName_ = Engine::IdClass<IdType_, TYPE_##_IDNAME##__, InvalidValue_>;

//
// ----------------------------------------------------------------------------
//

#define DECLARE_IDCLASS(IdName_, IdType_) \
    DECLARE_IDCLASS_EX(IdName_, IdType_, std::numeric_limits<IdType_>::max())
