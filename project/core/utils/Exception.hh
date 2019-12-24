//
// (C) LetsMakeGames 2019
// http://www.letsmake.games
//

#pragma once

#include "Engine.hh"
#include "core/utils/String.hh"

#include <exception>
#include <sstream>
#include <string>

namespace blacktriangles
{

//
// Exception
//
class Exception
    : public std::exception
{
public: // constructor / destructor ///////////////////////////////////////////
    
    //
    //
    //
    explicit Exception()
        : m_code(0)
        , m_what()
        , m_cache()
    {
    }

    //
    //
    //
    Exception(Exception&& move)
        : m_code(move.m_code)
        , m_what(std::move(move.m_what))
        , m_cache()
    {
    }

    //
    //
    //
    Exception(const Exception& copy)
        : m_code(copy.m_code)
        , m_what(copy.m_what.str())
        , m_cache()
    {
    }

    //
    //
    //
    virtual ~Exception() = default;


public: // public methods /////////////////////////////////////////////////////

    inline virtual uint32_t code() const noexcept               { return m_code; }

    //
    //
    //
    inline virtual const char* what() const noexcept override   { m_cache = m_what.str(); return m_cache.c_str(); }

public: // operators //////////////////////////////////////////////////////////

    //
    //
    //
    template<typename T>
    Exception& operator<<(T val)
    {
        m_what << val;
        return (*this);
    }

private: // members ///////////////////////////////////////////////////////////

    uint32_t m_code = 0;

    std::stringstream m_what;
    mutable std::string m_cache;

};

} // blacktriangles
