//
// (C) LetsMakeGames 2019
// http://www.letsmake.games
//

#include "Engine.hh"
#include "core/id/IdClass.hh"

#include <functional>
#include <string>

namespace Engine
{

//
// HashIdClass ////////////////////////////////////////////////////////////////
//

template<typename TypesafeType_, size_t InvalidHashValue_>
class HashIdClass
{
public: // types //////////////////////////////////////////////////////////////

    typedef size_t HashType;

    typedef IdClass<HashType, TypesafeType_, InvalidHashValue_> BaseIdClass;

    static const HashType InvalidHashValue;

    static const HashIdClass InvalidHash;

public: // constructor / destructor ///////////////////////////////////////////
    
    //
    //
    //
    HashIdClass()
        : id(BaseIdClass::InvalidValue)
    {
    }

    //
    //
    //
    HashIdClass(size_t hash)
        : id(hash)
    {
    }

    //
    //
    //
    HashIdClass(std::string str)
        : id(std::hash<std::string>()(str))
    {
    }

    //
    //
    //
    HashIdClass(std::wstring str)
        : id(std::hash<std::wstring>()(str))
    {
    }

    //
    //
    //
    HashIdClass(const HashIdClass& copy)                        = default;

    //
    //
    //
    HashIdClass(HashIdClass&& move)                             = default;

public: // operators //////////////////////////////////////////////////////////

    //
    //
    //
    inline size_t hash() const                                  { return id.getRawId(); }

    //
    //
    //
    inline std::string to_string() const                        { return id.to_string(); }

    //
    //
    //
    inline HashIdClass& operator=(const HashIdClass& rhs)       = default;

    //
    // 
    //
    inline HashIdClass& operator=(HashIdClass&& rhs)            = default;

    //
    //
    //
    inline bool operator==(const HashIdClass& rhs) const        { return id == rhs.id; }

    //
    //
    //
    inline bool operator!=(const HashIdClass& rhs) const        { return id != rhs.id; }

    //
    //
    //
    inline bool operator<(const HashIdClass& rhs) const         { return id < rhs.id; }

    //
    //
    //
    inline bool operator<=(const HashIdClass& rhs) const        { return id <= rhs.id; }

    //
    //
    //
    inline bool operator>(const HashIdClass& rhs) const         { return id > rhs.id; }

    //
    //
    //
    inline bool operator>=(const HashIdClass& rhs) const        { return id >= rhs.id; }

    //
    //
    //
    friend std::ostream& operator<<(std::ostream& os, const HashIdClass& id)
    {
        os << id.to_string();
        return os;
    }

private: // members ///////////////////////////////////////////////////////////

    BaseIdClass id;

};

//
// static members /////////////////////////////////////////////////////////////
//

template<typename TypesafeType_, size_t InvalidHashValue_>
const typename HashIdClass<TypesafeType_, InvalidHashValue_>::HashType
      HashIdClass<TypesafeType_, InvalidHashValue_>::InvalidHashValue = InvalidHashValue_;

//
// ----------------------------------------------------------------------------
//

template<typename TypesafeType_, size_t InvalidHashValue_>
const HashIdClass<TypesafeType_, InvalidHashValue_> HashIdClass<TypesafeType_, InvalidHashValue_>::InvalidHash(InvalidHashValue_);

}

//
// macros /////////////////////////////////////////////////////////////////////
//

#define DECLARE_HASHIDCLASS_EX(IdName_, _InvalidValue) \
    struct TYPE_##_IDNAME##__ {}; \
    typedef Engine::HashIdClass<TYPE_##_IDNAME##__, _InvalidValue> IdName_;


//
// ----------------------------------------------------------------------------
//

#define DECLARE_HASHIDCLASS(IdName_) \
    DECLARE_HASHIDCLASS_EX(IdName_, 0)
