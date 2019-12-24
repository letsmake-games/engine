//
// (C) LetsMakeGames 2019
// http://www.letsmake.games
//

#include "Engine.hh"
#include "core/id/HashIdClass.hh"
#include "core/utils/TypeCast.hh"

#include <string>

namespace Engine
{

//
// ClassId ////////////////////////////////////////////////////////////////////
//

class ClassId final
{
public: // constructor / destructor ///////////////////////////////////////////

    //
    //
    //
    ClassId();

    //
    //
    //
    ClassId(const std::string& name);

    //
    //
    //
    ClassId(const std::string& name, const ClassId& base);

    //
    //
    //
    ClassId(const ClassId& copy)                                = default;

    //
    //
    //
    ClassId(ClassId&& move)                                     = default;

public: // public methods /////////////////////////////////////////////////////

    //
    //
    //
    bool isTypeOf(const ClassId& class_id) const;

    //
    //
    //
    inline const std::string& getName() const                   { return name; }


    //
    //
    //
    inline bool isValid() const                                 { return id != ClassHashId::InvalidHash; }

    //
    //
    //
    const ClassId* getBaseClassId() const                       { return base_id; }

public: // operators //////////////////////////////////////////////////////////

    //
    //
    //
    inline ClassId& operator=(const ClassId& rhs)               = default;

    //
    // 
    //
    inline ClassId& operator=(ClassId&& rhs)                    = default;

    //
    //
    //
    inline bool operator==(const ClassId& rhs) const            { return id == rhs.id; }

    //
    //
    //
    inline bool operator!=(const ClassId& rhs) const            { return id != rhs.id; }

    //
    //
    //
    inline bool operator<(const ClassId& rhs) const             { return id < rhs.id; }

    //
    //
    //
    inline bool operator<=(const ClassId& rhs) const            { return id <= rhs.id; }

    //
    //
    //
    inline bool operator>(const ClassId& rhs) const             { return id > rhs.id; }

    //
    //
    //
    inline bool operator>=(const ClassId& rhs) const            { return id >= rhs.id; }

    //
    //
    //
    friend std::ostream& operator<<(std::ostream& os, const ClassId& id)
    {
        os << id.getName();
        return os;
    }

private: // types /////////////////////////////////////////////////////////////

    //
    //
    //
    typedef HashIdClass<ClassId, 0> ClassHashId;

private: // members ///////////////////////////////////////////////////////////

    std::string name;

    ClassHashId id;

    const ClassId* base_id;
};

}

//
// macros /////////////////////////////////////////////////////////////////////
//

#define DECLARE_CLASSID_INTERNAL_(ClassName_, SUFFIX_) \
    public: \
        typedef std::shared_ptr<ClassName_> Ptr; \
        typedef std::unique_ptr<ClassName_> Unique; \
        typedef std::weak_ptr<ClassName_> Handle; \
        virtual const Engine::ClassId& getClassId() const SUFFIX_ { return getStaticClassId(); } \
        static bool isTypeOf(const Engine::ClassId& type) { return getStaticClassId().isTypeOf(type); } \
        template<typename Class_> static bool isTypeOf() { return isTypeOf(Class_::getStaticClassId()); } \
        template<typename Inherit_> \
        static Ptr ptrCast(std::shared_ptr<Inherit_> from) \
        { \
            if(from != nullptr && from->getClassId().isTypeOf(getStaticClassId())) \
            { \
                return Engine::ptrCast<ClassName_>(from); \
            } \
            return Ptr(); \
        } \
        template<typename Inherit_> \
        static Handle handleCast(std::weak_ptr<Inherit_> from) \
        { \
            typename Inherit_::Ptr fromPtr = from.lock(); \
            if(fromPtr != nullptr && fromPtr->getClassId().isTypeOf(getStaticClassId())) \
            { \
                return Engine::handleCast<ClassName_>(from); \
            } \
            return Handle(); \
        }
            
//
// ----------------------------------------------------------------------------
//

#define DECLARE_CLASSID_NOBASE(ClassName_) \
    DECLARE_CLASSID_INTERNAL_(ClassName_, ) \
    public: \
        static const Engine::ClassId& getStaticClassId() \
        { \
            static Engine::ClassId sClassId(#ClassName_); \
            return sClassId; \
        }

//
// ----------------------------------------------------------------------------
//

#define DECLARE_CLASSID(ClassName_, BaseClass_) \
    DECLARE_CLASSID_INTERNAL_(ClassName_, override) \
    static const Engine::ClassId& getStaticClassId() \
    { \
        static Engine::ClassId sClassId(#ClassName_, BaseClass_::getStaticClassId()); \
        return sClassId; \
    }
