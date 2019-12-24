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

namespace blacktriangles
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
    typedef IdType_ IdType;

    //
    // static invalid id value
    //
    static const IdType InvalidValue;

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
const typename IdClass<IdType_, TypesafeType_, InvalidValue_>::IdType
      IdClass<IdType_, TypesafeType_, InvalidValue_>::InvalidValue = InvalidValue_;

//
// ----------------------------------------------------------------------------
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
    typedef blacktriangles::IdClass<IdType_, TYPE_##_IDNAME##__, InvalidValue_> IdName_;

//
// ----------------------------------------------------------------------------
//

#define DECLARE_IDCLASS(IdName_, IdType_) \
    DECLARE_IDCLASS_EX(IdName_, IdType_, std::numeric_limits<IdType_>::max())

//
// ----------------------------------------------------------------------------
//

#define DECLARE_SEQUENTIAL_IDGENERATOR(IdName_) \
    namespace IdGenerator { \
        struct IdName_##Generator \
        { \
            IdName_ next(bool reset = false) \
            { \
                if(reset) lastId = IdName_::InvalidValue; \
                    IdName_ result = IdName_::InvalidValue; \
                if((IdName_::IdType)(lastId + 1) != IdName_::InvalidValue) \
                { \
                    result = ++lastId; \
                } \
                return IdName_(result); \
            } \
            IdName_ last() \
            { \
                return IdName_(lastId); \
            } \
        private: \
            IdName_::IdType lastId = IdName_::InvalidValue; \
        }; \
        IdName_ generate##IdName_(bool reset = false) \
        { \
            static IdName_##Generator generator; \
            return generator.next(reset); \
        } \
    }
